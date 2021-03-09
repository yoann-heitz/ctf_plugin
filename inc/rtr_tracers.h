#ifndef RTR_TRACERS_H_
#define RTR_TRACERS_H_



#include "tracer.h"
#include "roctracer_hsa_aux.h"
#include "roctracer_hip_aux.h"
#include "roctracer_kfd_aux.h"
#include "hsa_args_str.h"
#include "kfd_args_str.h"
#include "hip_args_str.h"

#include "core/trace_buffer.h"

//HSA API tracing structures 

struct hsa_api_trace_entry_t {
  std::atomic<uint32_t> valid;
  roctracer::entry_type_t type;
  uint32_t cid;
  timestamp_t begin;
  timestamp_t end;
  uint32_t pid;
  uint32_t tid;
  hsa_api_data_t data;
};

struct hsa_api_event_t : event_t{
	uint32_t tid;
	event_phase phase;
	union {
		struct {
			uint32_t cid;
			uint32_t pid;
			hsa_api_data_t data;
		};
	};
	hsa_api_event_t(uint64_t time_s, uint32_t tid_s, event_phase phase_s):
		event_t(time_s), tid(tid_s), phase(phase_s){}
	hsa_api_event_t(uint64_t time_s, uint32_t tid_s, event_phase phase_s, uint32_t cid_s, uint32_t pid_s, hsa_api_data_t data_s):
		event_t(time_s), tid(tid_s), phase(phase_s), cid(cid_s), pid(pid_s), data(data_s){}
	
};

class HSA_API_Tracer: public Tracer<hsa_api_event_t>{
   public:
      HSA_API_Tracer(const char* prefix, const char* suffix) : Tracer<hsa_api_event_t>(prefix, suffix){}
	  ~HSA_API_Tracer(){}
	  void hsa_api_flush_cb(hsa_api_trace_entry_t* entry);	
};


//HSA activity tracing structures 

struct hsa_activity_event_t : event_t{
	uint32_t pid;
	uint64_t record_index;
	hsa_activity_event_t(uint64_t time_s, uint32_t pid_s, uint64_t record_index_s):
		event_t(time_s), pid(pid_s), record_index(record_index_s){}
};


class HSA_Activity_Tracer: public Tracer<hsa_activity_event_t> {
	private:
	  uint64_t index;
    public:
      
      HSA_Activity_Tracer(const char* prefix, const char* suffix) : Tracer<hsa_activity_event_t>(prefix, suffix){index = 0;}
	  ~HSA_Activity_Tracer(){}
	  void hsa_activity_callback(uint32_t op, activity_record_t* record, void* arg);
};

//KFD API tracing structures

struct kfd_api_event_t : event_t{
	uint32_t tid;
	event_phase phase;
	union {
		struct {
			uint32_t cid;
			uint32_t pid;
			kfd_api_data_t data;
		};
	};
	kfd_api_event_t(uint64_t time_s, uint32_t tid_s, event_phase phase_s):
		event_t(time_s), tid(tid_s), phase(phase_s){}
	kfd_api_event_t(uint64_t time_s, uint32_t tid_s, event_phase phase_s, uint32_t cid_s, uint32_t pid_s, kfd_api_data_t data_s):
		event_t(time_s), tid(tid_s), phase(phase_s), cid(cid_s), pid(pid_s), data(data_s){}
	
};

class KFD_API_Tracer: public Tracer<kfd_api_event_t> {
   public:
      KFD_API_Tracer(const char* prefix, const char* suffix) : Tracer<kfd_api_event_t>(prefix, suffix){}
	  ~KFD_API_Tracer(){}
	  void kfd_api_flush_cb(uint64_t begin, uint64_t end, uint32_t cid, const kfd_api_data_t* data);
};

//HIP API tracing structures

struct hip_api_trace_entry_t {
  std::atomic<uint32_t> valid;
  roctracer::entry_type_t type;
  uint32_t domain;
  uint32_t cid;
  timestamp_t begin;
  timestamp_t end;
  uint32_t pid;
  uint32_t tid;
  hip_api_data_t data;
  const char* name;
  void* ptr;
};


struct hip_api_event_t : event_t{
	uint32_t tid;
	event_phase phase;
	union{
		struct{
			uint32_t cid;
			uint32_t pid;
			hip_api_data_t data;
			const char* name;
		};
	};
	hip_api_event_t(uint64_t time_s, uint32_t tid_s, event_phase phase_s):
		event_t(time_s), tid(tid_s), phase(phase_s){}
	hip_api_event_t(uint64_t time_s, uint32_t tid_s, event_phase phase_s, uint32_t cid_s, uint32_t pid_s, hip_api_data_t data_s, const char* name_s):
		event_t(time_s), tid(tid_s), phase(phase_s), cid(cid_s), pid(pid_s), data(data_s), name(name_s){}
};

class HIP_API_Tracer: public Tracer<hip_api_event_t> {
   public:
      HIP_API_Tracer(const char* prefix, const char* suffix) : Tracer<hip_api_event_t>(prefix, suffix){}
	  ~HIP_API_Tracer(){}
	  void hip_api_flush_cb(hip_api_trace_entry_t* entry);
};


//HIP activity tracing structures
struct hip_activity_event_t : event_t{
	event_phase phase;
	union{
		struct{
			const char * name;
			roctracer_record_t record;
		};
		uint64_t correlation_id;
	};
	hip_activity_event_t(uint64_t time_s, event_phase phase_s, uint64_t correlation_id_s):
		event_t(time_s), phase(phase_s), correlation_id(correlation_id_s){}
	hip_activity_event_t(uint64_t time_s, event_phase phase_s, const char * name_s, roctracer_record_t record_s):
		event_t(time_s), phase(phase_s), name(name_s), record(record_s){}
};

class HIP_Activity_Tracer: public Tracer<hip_activity_event_t> {
   public:
      HIP_Activity_Tracer(const char* prefix, const char* suffix) : Tracer<hip_activity_event_t>(prefix, suffix){}
	  ~HIP_Activity_Tracer(){}
	  void hip_activity_callback(const roctracer_record_t* record, const char * name);
};

void trace_hip_activity(hip_activity_event_t* hip_activity_event, struct barectf_default_ctx* ctx);
void trace_hip_api(hip_api_event_t* hip_api_event, struct barectf_default_ctx* ctx);
void trace_kfd_api(kfd_api_event_t* kfd_event, struct barectf_default_ctx* ctx);
void trace_hsa_activity(hsa_activity_event_t* hsa_activity_event, struct barectf_default_ctx* ctx);
void trace_hsa_api(hsa_api_event_t* hsa_api_event, struct barectf_default_ctx* ctx);
#endif