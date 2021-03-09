//Declaration of callbacks and tracing functions for kernel events
#import "tracer.h"
#import "rpl_tracers.h"
#include "rpl_tool.h"

void trace_kernel_event(kernel_event_t* kernel_event, struct barectf_default_ctx* ctx){
	switch(kernel_event->phase){
		case BEGIN: {
			barectf_default_trace_kernel_event_begin(ctx, 
													 kernel_event->dispatch,
													 kernel_event->gpu_id,
													 kernel_event->queue_id,
													 kernel_event->queue_index,
													 kernel_event->pid,
													 kernel_event->tid,
													 kernel_event->grd,
													 kernel_event->wgr,
													 kernel_event->lds,
													 kernel_event->scr,
													 kernel_event->vgpr,
													 kernel_event->sgpr,
													 kernel_event->fbar,
													 kernel_event->sig,
													 kernel_event->obj,
													 kernel_event->kernel_name,
													 kernel_event->dispatch_time,
													 kernel_event->complete_time);
			break;
		}
		case END: {
			barectf_trace_kernel_event_end(ctx, kernel_event->dispatch, kernel_event->gpu_id);
			break;
		}
	}
}

void Kernel_Event_Tracer::write_context_entry(context_entry_t* entry, const rocprofiler_dispatch_record_t* record, const std::string nik_name,const AgentInfo* agent_info)
{
  uint64_t begin = (record ? record->begin : 0);
  uint64_t end = (record ? record->end : 0);
  kernel_event_t* begin_event = new kernel_event_t(begin, BEGIN);
  kernel_event_t* end_event = new kernel_event_t(end, END);	
  
  end_event->dispatch = entry->index;
  end_event->gpu_id = agent_info->dev_index;
  end_event->phase = END;
 
  begin_event->phase = BEGIN;
  begin_event->dispatch = entry->index;
  begin_event->gpu_id = agent_info->dev_index;
  begin_event->queue_id = entry->data.queue_id;
  begin_event->queue_index = entry->data.queue_index;
  begin_event->pid = my_pid;
  begin_event->tid = entry->data.thread_id;
  begin_event->grd = entry->kernel_properties.grid_size;
  begin_event->wgr = entry->kernel_properties.workgroup_size;
  begin_event->lds = (entry->kernel_properties.lds_size + (AgentInfo::lds_block_size - 1)) & ~(AgentInfo::lds_block_size - 1);
  begin_event->scr = entry->kernel_properties.scratch_size; 
  begin_event->vgpr = (entry->kernel_properties.vgpr_count + 1) * agent_info->vgpr_block_size;
  begin_event->sgpr = (entry->kernel_properties.sgpr_count + agent_info->sgpr_block_dflt) * agent_info->sgpr_block_size;
  begin_event->fbar = entry->kernel_properties.fbarrier_count;
  begin_event->sig = entry->kernel_properties.signal.handle;
  begin_event->obj = entry->kernel_properties.object;
  begin_event->kernel_name = strdup(nik_name.c_str());
  begin_event->dispatch_time = (record ? record->dispatch : 0);
  begin_event->complete_time = (record ? record->complete : 0);

  callback(begin, (tracing_function)trace_kernel_event, begin_event);
  callback(end, (tracing_function)trace_kernel_event, end_event);
}
