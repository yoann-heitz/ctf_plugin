#ifndef RPL_TRACERS_H_
#define RPL_TRACERS_H_
#include "tracer.h"
#include "rpl_tool.h"

struct kernel_event_t : event_t{
	uint32_t dispatch;
	uint32_t gpu_id;
	event_phase phase;
	union {
		struct {
			uint32_t queue_id;
			uint64_t queue_index;
			uint32_t pid;
			uint32_t tid;
			uint32_t grd;
			uint32_t wgr;
			uint32_t lds;
			uint32_t scr;
			uint32_t vgpr;
			uint32_t sgpr;
			uint32_t fbar;
			uint64_t sig;
			uint64_t obj;
			const char* kernel_name;
			uint64_t dispatch_time;
			uint64_t complete_time;
		};
	};
	kernel_event_t(uint64_t time_s, event_phase phase_s):
		event_t(time_s), phase(phase_s){}
	kernel_event_t(uint64_t time_s, uint32_t dispatch_s, uint32_t gpu_id_s, event_phase phase_s):
		event_t(time_s), dispatch(dispatch_s), gpu_id(gpu_id_s), phase(phase_s){}
	kernel_event_t(uint64_t time_s,
				   uint32_t dispatch_s,
				   uint32_t gpu_id_s,
				   event_phase phase_s,
				   uint32_t queue_id_s,
				   uint64_t queue_index_s,
				   uint32_t pid_s,
				   uint32_t tid_s,
				   uint32_t grd_s,
				   uint32_t wgr_s,
				   uint32_t lds_s,
				   uint32_t scr_s,
				   uint32_t vgpr_s,
				   uint32_t sgpr_s,
				   uint32_t fbar_s,
				   uint64_t sig_s,
				   uint64_t obj_s,
				   const char* kernel_name_s,
				   uint64_t dispatch_time_s,
				   uint64_t complete_time_s):
		event_t(time_s),
		dispatch(dispatch_s),
		gpu_id(gpu_id_s),
		phase(phase_s),
		queue_id(queue_id_s),
		queue_index(queue_index_s),
		pid(pid_s),
		tid(tid_s),
		grd(grd_s),
		wgr(wgr_s),
		lds(lds_s),
		scr(scr_s),
		vgpr(vgpr_s),
		sgpr(sgpr_s),
		fbar(fbar_s),
		sig(sig_s),
		obj(obj_s),
		kernel_name(kernel_name_s),
		dispatch_time(dispatch_time_s),
		complete_time(complete_time_s){}
};

class Kernel_Event_Tracer: public Tracer<kernel_event_t>{
   public:
      Kernel_Event_Tracer(const char* prefix, const char* suffix) : Tracer<kernel_event_t>(prefix, suffix){}
	  ~Kernel_Event_Tracer(){}
	  void write_context_entry(context_entry_t* entry, const rocprofiler_dispatch_record_t* record, const std::string nik_name, const AgentInfo*);	
};

void trace_kernel_event(kernel_event_t* kernel_event, struct barectf_default_ctx* ctx);
#endif