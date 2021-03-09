#include "barectf-platform-linux-fs.h"
#include "barectf.h" 
#include "tracer.h"
#include "rpl_tracers.h"
#include "rpl_tool.h"
barectf_platform_linux_fs_ctx* platform_metrics;
barectf_default_ctx* ctx_metrics;
uint64_t metrics_clock = 0;

uint32_t dev_index = 0;
uint32_t verbose = 0;
bool kernel_event_initialized = false;
bool metrics_tables_dumped = false;
uint32_t idx = 0;
uint32_t metrics_number = 0;
uint32_t intermediate_metrics_number = 0;
const char** metrics_names;
uint64_t* metrics_values;
Kernel_Event_Tracer* kernel_event_tracer;


extern "C" void init_kernel_ctf_tracing(const char* prefix, std::vector<std::string> metrics_vector, uint32_t verbose_){
	if(!kernel_event_initialized){
		std::stringstream ss; 
		ss << prefix << "/CTF_trace/metrics_stream";
		platform_metrics = barectf_platform_linux_fs_init(15000, ss.str().c_str(), 0, 0, 0, &metrics_clock);
		ctx_metrics = barectf_platform_linux_fs_get_barectf_ctx(platform_metrics);
		kernel_event_tracer = new Kernel_Event_Tracer(prefix, "kernel_events_");
		verbose = verbose_;
		
		//Initialize stream for metrics
		metrics_number = metrics_vector.size();
		kernel_event_initialized = true;
	}else{
		printf("kernel events tracing already initialized");
	}
}

extern "C" void write_context_entry(context_entry_t* entry,const rocprofiler_dispatch_record_t* record, const std::string nik_name, const AgentInfo* agent_info){
	dev_index = agent_info->dev_index;
	kernel_event_tracer->write_context_entry(entry, record, nik_name, agent_info);
}

extern "C" void write_group(const context_entry_t* entry, const char* label){
	if(metrics_number > 0){
		const rocprofiler_group_t* group = &(entry->group);
		if(!metrics_tables_dumped){
			intermediate_metrics_number = group->feature_count;
			metrics_names = new const char*[intermediate_metrics_number + metrics_number];
			for(int i = 0; i < intermediate_metrics_number; i++){
				metrics_names[i] = strdup(group->features[i]->name);
			}
		}
		metrics_values  = new uint64_t[intermediate_metrics_number + metrics_number];
		for(int i = 0; i < intermediate_metrics_number; i++){
			if(group->features[i]->data.kind == ROCPROFILER_DATA_KIND_INT64){
				metrics_values[i] = group->features[i]->data.result_int64;
			}else{
				printf("Wrong data type : %u\n", group->features[i]->data.kind);
				abort();
			}
		}
	}
}

extern "C" void write_metrics(const context_entry_t* entry, const char* label){
	if(metrics_number > 0){
		int relative_idx = 0;
		if(!metrics_tables_dumped){
			if(verbose == 0){
				metrics_names = new const char*[metrics_number];
			}
			for(int i = intermediate_metrics_number; i < metrics_number + intermediate_metrics_number; i++){
				relative_idx = i - intermediate_metrics_number;
				metrics_names[i] = strdup(entry->features[relative_idx].name);
			}
			
			barectf_trace_metrics_table(ctx_metrics, metrics_number + intermediate_metrics_number, metrics_names);
			delete[] metrics_names;
			metrics_tables_dumped = true;
		}
		
		
		if(verbose == 0){
			metrics_values = new uint64_t[metrics_number];
		}
		for(int i = intermediate_metrics_number; i < metrics_number + intermediate_metrics_number; i++){
			relative_idx = i - intermediate_metrics_number;
			if(entry->features[relative_idx].data.kind == ROCPROFILER_DATA_KIND_INT64){
				metrics_values[i] = entry->features[relative_idx].data.result_int64;
			}else{
				printf("Wrong data type : %u\n", entry->features[relative_idx].data.kind);
				abort();
			}
		}	
		barectf_trace_metrics_values(ctx_metrics, entry->index, dev_index, metrics_number + intermediate_metrics_number, metrics_values);
		delete[] metrics_values;
	}
}

extern "C" void unload_kernel_tracing(){
	if(kernel_event_initialized){
		kernel_event_tracer->flush((Tracer<kernel_event_t>::tracing_function)trace_kernel_event);
		barectf_platform_linux_fs_fini(platform_metrics);
		delete kernel_event_tracer;    
	}
}