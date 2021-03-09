#include <tracer.h>
#include <rtr_tracers.h>
#include <roctracer_hsa_aux.h>
#include <roctracer_hip_aux.h>
#include <roctracer_kfd_aux.h>
#include <hsa_args_str.h>
#include <kfd_args_str.h>
#include <hip_args_str.h>
#include <mutex>
#include <cxxabi.h>




static inline bool is_hip_kernel_launch_api(const uint32_t& cid) {
  bool ret =
    (cid == HIP_API_ID_hipLaunchKernel) ||
    (cid == HIP_API_ID_hipLaunchCooperativeKernel) ||
    (cid == HIP_API_ID_hipLaunchCooperativeKernelMultiDevice) ||
    (cid == HIP_API_ID_hipExtLaunchMultiKernelMultiDevice) ||
    (cid == HIP_API_ID_hipModuleLaunchKernel) ||
    (cid == HIP_API_ID_hipExtModuleLaunchKernel) ||
    (cid == HIP_API_ID_hipHccModuleLaunchKernel);
  return ret;
}

static inline const char* cxx_demangle(const char* symbol) {
  size_t funcnamesize;
  int status;
  const char* ret = (symbol != NULL) ? abi::__cxa_demangle(symbol, NULL, &funcnamesize, &status) : symbol;
  return (ret != NULL) ? ret : strdup(symbol);
}
//HSA API tracing function
void trace_hsa_api(hsa_api_event_t* hsa_api_event, struct barectf_default_ctx* ctx){
	switch(hsa_api_event->phase){
		case BEGIN: {
			hsa_api_string_pair_t arguments = hsa_api_pair_of_args(hsa_api_event->cid, hsa_api_event->data);
			barectf_trace_hsa_begin(ctx, hsa_api_event->cid, hsa_api_event->pid, hsa_api_event->tid, arguments.first.c_str(), arguments.second.c_str());
			break;
		}
		case END: {
			barectf_trace_hsa_end(ctx, hsa_api_event->tid);
			break;
		}
	}
}

void HSA_API_Tracer::hsa_api_flush_cb(hsa_api_trace_entry_t* entry)
{
  callback(entry->begin, (tracing_function)trace_hsa_api, new hsa_api_event_t(entry->begin, entry->tid, BEGIN, entry->cid, entry->pid, entry->data));
  callback(entry->end, (tracing_function)trace_hsa_api, new hsa_api_event_t(entry->end, entry->tid, END));
}

//HSA activity tracing function
void trace_hsa_activity(hsa_activity_event_t* hsa_activity_event, struct barectf_default_ctx* ctx){
	barectf_trace_hsa_activity(ctx, hsa_activity_event->pid, hsa_activity_event->record_index);
}

void HSA_Activity_Tracer::hsa_activity_callback(
  uint32_t op,
  activity_record_t* record,
  void* arg)
{
  callback(record->begin_ns, (tracing_function)trace_hsa_activity, new hsa_activity_event_t(record->begin_ns, my_pid, index));
  callback(record->end_ns, (tracing_function)trace_hsa_activity, new hsa_activity_event_t(record->end_ns, my_pid, index));
  index++;
}

//KFD API tracing function

void trace_kfd_api(kfd_api_event_t* kfd_event, struct barectf_default_ctx* ctx){
	switch(kfd_event->phase){
		case BEGIN : {
			kfd_api_string_pair_t arguments = kfd_api_pair_of_args(kfd_event->cid, kfd_event->data);
			barectf_trace_kfd_begin(ctx, kfd_event->cid, kfd_event->pid, kfd_event->tid, arguments.first.c_str(), arguments.second.c_str());
		}
		case END : {
			barectf_trace_kfd_end(ctx, kfd_event->tid);
		}
	}
}

void KFD_API_Tracer::kfd_api_flush_cb(uint64_t begin, uint64_t end, uint32_t cid, const kfd_api_data_t* data)
{	
  callback(begin, (tracing_function)trace_kfd_api, new kfd_api_event_t(begin, GetTid(), BEGIN, cid, my_pid, *data));
  callback(end, (tracing_function)trace_kfd_api, new kfd_api_event_t(end, GetTid(), END));
}


//HIP API tracing function
void trace_hip_api(hip_api_event_t* hip_api_event, struct barectf_default_ctx* ctx){
	switch(hip_api_event->phase){
		case BEGIN : {
			std::stringstream ss; 
			std::string arguments = hip_api_arguments(hip_api_event->cid, &(hip_api_event->data));
			ss << arguments;
			if (is_hip_kernel_launch_api(hip_api_event->cid) && hip_api_event->name){
				const char* kernel_name = cxx_demangle(hip_api_event->name);
				ss << ", " << kernel_name;
			}
			ss<< ", " << (hip_api_event->data).correlation_id;
			barectf_trace_hip_api_begin(ctx, hip_api_event->cid, hip_api_event->pid, hip_api_event->tid, ss.str().c_str());		
		}
		case END : {
			barectf_trace_hip_api_end(ctx, hip_api_event->tid);
		}
	}
}

void HIP_API_Tracer::hip_api_flush_cb(hip_api_trace_entry_t* entry)
{
  callback(entry->begin, (tracing_function)trace_hip_api, new hip_api_event_t(entry->begin, GetTid(), BEGIN, entry->cid, my_pid, entry->data, entry->name));
  callback(entry->end, (tracing_function)trace_hip_api, new hip_api_event_t(entry->end, GetTid(), END));
}

//HIP activity callback function
void trace_hip_activity(hip_activity_event_t* hip_activity_event, struct barectf_default_ctx* ctx){
	switch(hip_activity_event->phase){
		case BEGIN : {
			roctracer_record_t record = hip_activity_event->record;
			barectf_trace_hip_activity_begin(ctx, record.device_id, record.queue_id, hip_activity_event->name, record.correlation_id, GetPid());
		}
		case END : {
			barectf_trace_hip_activity_end(ctx, hip_activity_event->correlation_id);
		}
	}

}

void HIP_Activity_Tracer::hip_activity_callback(
  const roctracer_record_t* record,
  const char* name
  )
{
  callback(record->begin_ns, (tracing_function)trace_hip_activity, new hip_activity_event_t(record->begin_ns, BEGIN, name, *record));
  callback(record->end_ns, (tracing_function)trace_hip_activity, new hip_activity_event_t(record->end_ns, END, record->correlation_id));
}

