#include <roctracer_hsa_aux.h>
#include <kfd_args_str.h>
#include <sstream>

static const kfd_api_id_t all_kfd_api_func[] = { 
	KFD_API_ID_hsaKmtOpenKFD,
	KFD_API_ID_hsaKmtCloseKFD,
	KFD_API_ID_hsaKmtGetVersion,
	KFD_API_ID_hsaKmtAcquireSystemProperties,
	KFD_API_ID_hsaKmtReleaseSystemProperties,
	KFD_API_ID_hsaKmtGetNodeProperties,
	KFD_API_ID_hsaKmtGetNodeMemoryProperties,
	KFD_API_ID_hsaKmtGetNodeCacheProperties,
	KFD_API_ID_hsaKmtGetNodeIoLinkProperties,
	KFD_API_ID_hsaKmtCreateEvent,
	KFD_API_ID_hsaKmtDestroyEvent,
	KFD_API_ID_hsaKmtSetEvent,
	KFD_API_ID_hsaKmtResetEvent,
	KFD_API_ID_hsaKmtQueryEventState,
	KFD_API_ID_hsaKmtWaitOnEvent,
	KFD_API_ID_hsaKmtWaitOnMultipleEvents,
	KFD_API_ID_hsaKmtReportQueue,
	KFD_API_ID_hsaKmtCreateQueue,
	KFD_API_ID_hsaKmtUpdateQueue,
	KFD_API_ID_hsaKmtDestroyQueue,
	KFD_API_ID_hsaKmtSetQueueCUMask,
	KFD_API_ID_hsaKmtGetQueueInfo,
	KFD_API_ID_hsaKmtSetMemoryPolicy,
	KFD_API_ID_hsaKmtAllocMemory,
	KFD_API_ID_hsaKmtFreeMemory,
	KFD_API_ID_hsaKmtRegisterMemory,
	KFD_API_ID_hsaKmtRegisterMemoryToNodes,
	KFD_API_ID_hsaKmtRegisterMemoryWithFlags,
	KFD_API_ID_hsaKmtRegisterGraphicsHandleToNodes,
	KFD_API_ID_hsaKmtShareMemory,
	KFD_API_ID_hsaKmtRegisterSharedHandle,
	KFD_API_ID_hsaKmtRegisterSharedHandleToNodes,
	KFD_API_ID_hsaKmtProcessVMRead,
	KFD_API_ID_hsaKmtProcessVMWrite,
	KFD_API_ID_hsaKmtDeregisterMemory,
	KFD_API_ID_hsaKmtMapMemoryToGPU,
	KFD_API_ID_hsaKmtMapMemoryToGPUNodes,
	KFD_API_ID_hsaKmtUnmapMemoryToGPU,
	KFD_API_ID_hsaKmtMapGraphicHandle,
	KFD_API_ID_hsaKmtUnmapGraphicHandle,
	KFD_API_ID_hsaKmtAllocQueueGWS,
	KFD_API_ID_hsaKmtDbgRegister,
	KFD_API_ID_hsaKmtDbgUnregister,
	KFD_API_ID_hsaKmtDbgWavefrontControl,
	KFD_API_ID_hsaKmtDbgAddressWatch,
	KFD_API_ID_hsaKmtQueueSuspend,
	KFD_API_ID_hsaKmtQueueResume,
	KFD_API_ID_hsaKmtEnableDebugTrap,
	KFD_API_ID_hsaKmtEnableDebugTrapWithPollFd,
	KFD_API_ID_hsaKmtDisableDebugTrap,
	KFD_API_ID_hsaKmtQueryDebugEvent,
	KFD_API_ID_hsaKmtGetQueueSnapshot,
	KFD_API_ID_hsaKmtSetWaveLaunchTrapOverride,
	KFD_API_ID_hsaKmtSetWaveLaunchMode,
	KFD_API_ID_hsaKmtGetKernelDebugTrapVersionInfo,
	KFD_API_ID_hsaKmtGetThunkDebugTrapVersionInfo,
	KFD_API_ID_hsaKmtSetAddressWatch,
	KFD_API_ID_hsaKmtClearAddressWatch,
	KFD_API_ID_hsaKmtEnablePreciseMemoryOperations,
	KFD_API_ID_hsaKmtDisablePreciseMemoryOperations,
	KFD_API_ID_hsaKmtGetClockCounters,
	KFD_API_ID_hsaKmtPmcGetCounterProperties,
	KFD_API_ID_hsaKmtPmcRegisterTrace,
	KFD_API_ID_hsaKmtPmcUnregisterTrace,
	KFD_API_ID_hsaKmtPmcAcquireTraceAccess,
	KFD_API_ID_hsaKmtPmcReleaseTraceAccess,
	KFD_API_ID_hsaKmtPmcStartTrace,
	KFD_API_ID_hsaKmtPmcQueryTrace,
	KFD_API_ID_hsaKmtPmcStopTrace,
	KFD_API_ID_hsaKmtSetTrapHandler,
	KFD_API_ID_hsaKmtGetTileConfig,
	KFD_API_ID_hsaKmtQueryPointerInfo,
	KFD_API_ID_hsaKmtSetMemoryUserData,
	KFD_API_ID_NUMBER,
	KFD_API_ID_ANY
};

kfd_api_string_pair_t kfd_api_pair_of_args(uint32_t cid, kfd_api_data_t api_data)
{
  std::ostringstream ret;
  std::ostringstream out;
  switch(cid){
    case KFD_API_ID_hsaKmtOpenKFD: {
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtCloseKFD: {
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetVersion: {
      typedef decltype(api_data.args.hsaKmtGetVersion.VersionInfo) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetVersion.VersionInfo);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtAcquireSystemProperties: {
      typedef decltype(api_data.args.hsaKmtAcquireSystemProperties.SystemProperties) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtAcquireSystemProperties.SystemProperties);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtReleaseSystemProperties: {
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetNodeProperties: {
      typedef decltype(api_data.args.hsaKmtGetNodeProperties.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetNodeProperties.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtGetNodeProperties.NodeProperties) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetNodeProperties.NodeProperties);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetNodeMemoryProperties: {
      typedef decltype(api_data.args.hsaKmtGetNodeMemoryProperties.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetNodeMemoryProperties.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtGetNodeMemoryProperties.NumBanks) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetNodeMemoryProperties.NumBanks) << ", ";
      typedef decltype(api_data.args.hsaKmtGetNodeMemoryProperties.MemoryProperties) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtGetNodeMemoryProperties.MemoryProperties);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetNodeCacheProperties: {
      typedef decltype(api_data.args.hsaKmtGetNodeCacheProperties.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetNodeCacheProperties.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtGetNodeCacheProperties.ProcessorId) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetNodeCacheProperties.ProcessorId) << ", ";
      typedef decltype(api_data.args.hsaKmtGetNodeCacheProperties.NumCaches) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtGetNodeCacheProperties.NumCaches) << ", ";
      typedef decltype(api_data.args.hsaKmtGetNodeCacheProperties.CacheProperties) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtGetNodeCacheProperties.CacheProperties);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetNodeIoLinkProperties: {
      typedef decltype(api_data.args.hsaKmtGetNodeIoLinkProperties.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetNodeIoLinkProperties.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtGetNodeIoLinkProperties.NumIoLinks) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetNodeIoLinkProperties.NumIoLinks) << ", ";
      typedef decltype(api_data.args.hsaKmtGetNodeIoLinkProperties.IoLinkProperties) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtGetNodeIoLinkProperties.IoLinkProperties);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtCreateEvent: {
      typedef decltype(api_data.args.hsaKmtCreateEvent.EventDesc) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtCreateEvent.EventDesc) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateEvent.ManualReset) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtCreateEvent.ManualReset) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateEvent.IsSignaled) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtCreateEvent.IsSignaled) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateEvent.Event) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtCreateEvent.Event);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtDestroyEvent: {
      typedef decltype(api_data.args.hsaKmtDestroyEvent.Event) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtDestroyEvent.Event);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtSetEvent: {
      typedef decltype(api_data.args.hsaKmtSetEvent.Event) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtSetEvent.Event);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtResetEvent: {
      typedef decltype(api_data.args.hsaKmtResetEvent.Event) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtResetEvent.Event);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtQueryEventState: {
      typedef decltype(api_data.args.hsaKmtQueryEventState.Event) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtQueryEventState.Event);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtWaitOnEvent: {
      typedef decltype(api_data.args.hsaKmtWaitOnEvent.Event) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtWaitOnEvent.Event) << ", ";
      typedef decltype(api_data.args.hsaKmtWaitOnEvent.Milliseconds) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtWaitOnEvent.Milliseconds);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtWaitOnMultipleEvents: {
      typedef decltype(api_data.args.hsaKmtWaitOnMultipleEvents.Events) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtWaitOnMultipleEvents.Events) << ", ";
      typedef decltype(api_data.args.hsaKmtWaitOnMultipleEvents.NumEvents) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtWaitOnMultipleEvents.NumEvents) << ", ";
      typedef decltype(api_data.args.hsaKmtWaitOnMultipleEvents.WaitOnAll) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtWaitOnMultipleEvents.WaitOnAll) << ", ";
      typedef decltype(api_data.args.hsaKmtWaitOnMultipleEvents.Milliseconds) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtWaitOnMultipleEvents.Milliseconds);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtReportQueue: {
      typedef decltype(api_data.args.hsaKmtReportQueue.QueueId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtReportQueue.QueueId) << ", ";
      typedef decltype(api_data.args.hsaKmtReportQueue.QueueReport) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtReportQueue.QueueReport);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtCreateQueue: {
      typedef decltype(api_data.args.hsaKmtCreateQueue.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtCreateQueue.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateQueue.Type) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtCreateQueue.Type) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateQueue.QueuePercentage) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtCreateQueue.QueuePercentage) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateQueue.Priority) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtCreateQueue.Priority) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateQueue.QueueAddress) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtCreateQueue.QueueAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateQueue.QueueSizeInBytes) arg_val_type_t5;
      roctracer::kfd_support::output_streamer<arg_val_type_t5>::put(out, api_data.args.hsaKmtCreateQueue.QueueSizeInBytes) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateQueue.Event) arg_val_type_t6;
      roctracer::kfd_support::output_streamer<arg_val_type_t6>::put(out, api_data.args.hsaKmtCreateQueue.Event) << ", ";
      typedef decltype(api_data.args.hsaKmtCreateQueue.QueueResource) arg_val_type_t7;
      roctracer::kfd_support::output_streamer<arg_val_type_t7>::put(out, api_data.args.hsaKmtCreateQueue.QueueResource);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtUpdateQueue: {
      typedef decltype(api_data.args.hsaKmtUpdateQueue.QueueId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtUpdateQueue.QueueId) << ", ";
      typedef decltype(api_data.args.hsaKmtUpdateQueue.QueuePercentage) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtUpdateQueue.QueuePercentage) << ", ";
      typedef decltype(api_data.args.hsaKmtUpdateQueue.Priority) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtUpdateQueue.Priority) << ", ";
      typedef decltype(api_data.args.hsaKmtUpdateQueue.QueueAddress) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtUpdateQueue.QueueAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtUpdateQueue.QueueSize) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtUpdateQueue.QueueSize) << ", ";
      typedef decltype(api_data.args.hsaKmtUpdateQueue.Event) arg_val_type_t5;
      roctracer::kfd_support::output_streamer<arg_val_type_t5>::put(out, api_data.args.hsaKmtUpdateQueue.Event);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtDestroyQueue: {
      typedef decltype(api_data.args.hsaKmtDestroyQueue.QueueId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtDestroyQueue.QueueId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtSetQueueCUMask: {
      typedef decltype(api_data.args.hsaKmtSetQueueCUMask.QueueId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtSetQueueCUMask.QueueId) << ", ";
      typedef decltype(api_data.args.hsaKmtSetQueueCUMask.CUMaskCount) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtSetQueueCUMask.CUMaskCount) << ", ";
      typedef decltype(api_data.args.hsaKmtSetQueueCUMask.QueueCUMask) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtSetQueueCUMask.QueueCUMask);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetQueueInfo: {
      typedef decltype(api_data.args.hsaKmtGetQueueInfo.QueueId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetQueueInfo.QueueId) << ", ";
      typedef decltype(api_data.args.hsaKmtGetQueueInfo.QueueInfo) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetQueueInfo.QueueInfo);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtSetMemoryPolicy: {
      typedef decltype(api_data.args.hsaKmtSetMemoryPolicy.Node) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtSetMemoryPolicy.Node) << ", ";
      typedef decltype(api_data.args.hsaKmtSetMemoryPolicy.DefaultPolicy) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtSetMemoryPolicy.DefaultPolicy) << ", ";
      typedef decltype(api_data.args.hsaKmtSetMemoryPolicy.AlternatePolicy) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtSetMemoryPolicy.AlternatePolicy) << ", ";
      typedef decltype(api_data.args.hsaKmtSetMemoryPolicy.MemoryAddressAlternate) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtSetMemoryPolicy.MemoryAddressAlternate) << ", ";
      typedef decltype(api_data.args.hsaKmtSetMemoryPolicy.MemorySizeInBytes) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtSetMemoryPolicy.MemorySizeInBytes);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtAllocMemory: {
      typedef decltype(api_data.args.hsaKmtAllocMemory.PreferredNode) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtAllocMemory.PreferredNode) << ", ";
      typedef decltype(api_data.args.hsaKmtAllocMemory.SizeInBytes) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtAllocMemory.SizeInBytes) << ", ";
      typedef decltype(api_data.args.hsaKmtAllocMemory.MemoryAddress) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtAllocMemory.MemoryAddress);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtFreeMemory: {
      typedef decltype(api_data.args.hsaKmtFreeMemory.MemoryAddress) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtFreeMemory.MemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtFreeMemory.SizeInBytes) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtFreeMemory.SizeInBytes);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtRegisterMemory: {
      typedef decltype(api_data.args.hsaKmtRegisterMemory.MemoryAddress) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtRegisterMemory.MemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterMemory.MemorySizeInBytes) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtRegisterMemory.MemorySizeInBytes);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtRegisterMemoryToNodes: {
      typedef decltype(api_data.args.hsaKmtRegisterMemoryToNodes.MemoryAddress) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtRegisterMemoryToNodes.MemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterMemoryToNodes.MemorySizeInBytes) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtRegisterMemoryToNodes.MemorySizeInBytes) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterMemoryToNodes.NumberOfNodes) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtRegisterMemoryToNodes.NumberOfNodes) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterMemoryToNodes.NodeArray) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtRegisterMemoryToNodes.NodeArray);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtRegisterMemoryWithFlags: {
      typedef decltype(api_data.args.hsaKmtRegisterMemoryWithFlags.MemoryAddress) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtRegisterMemoryWithFlags.MemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterMemoryWithFlags.MemorySizeInBytes) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtRegisterMemoryWithFlags.MemorySizeInBytes) << ", ";
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtRegisterGraphicsHandleToNodes: {
      typedef decltype(api_data.args.hsaKmtRegisterGraphicsHandleToNodes.GraphicsResourceHandle) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtRegisterGraphicsHandleToNodes.GraphicsResourceHandle) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterGraphicsHandleToNodes.GraphicsResourceInfo) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtRegisterGraphicsHandleToNodes.GraphicsResourceInfo) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterGraphicsHandleToNodes.NumberOfNodes) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtRegisterGraphicsHandleToNodes.NumberOfNodes) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterGraphicsHandleToNodes.NodeArray) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtRegisterGraphicsHandleToNodes.NodeArray);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtShareMemory: {
      typedef decltype(api_data.args.hsaKmtShareMemory.MemoryAddress) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtShareMemory.MemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtShareMemory.SizeInBytes) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtShareMemory.SizeInBytes) << ", ";
      typedef decltype(api_data.args.hsaKmtShareMemory.SharedMemoryHandle) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtShareMemory.SharedMemoryHandle);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtRegisterSharedHandle: {
      typedef decltype(api_data.args.hsaKmtRegisterSharedHandle.SharedMemoryHandle) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtRegisterSharedHandle.SharedMemoryHandle) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterSharedHandle.MemoryAddress) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtRegisterSharedHandle.MemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterSharedHandle.SizeInBytes) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtRegisterSharedHandle.SizeInBytes);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtRegisterSharedHandleToNodes: {
      typedef decltype(api_data.args.hsaKmtRegisterSharedHandleToNodes.SharedMemoryHandle) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtRegisterSharedHandleToNodes.SharedMemoryHandle) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterSharedHandleToNodes.MemoryAddress) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtRegisterSharedHandleToNodes.MemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterSharedHandleToNodes.SizeInBytes) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtRegisterSharedHandleToNodes.SizeInBytes) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterSharedHandleToNodes.NumberOfNodes) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtRegisterSharedHandleToNodes.NumberOfNodes) << ", ";
      typedef decltype(api_data.args.hsaKmtRegisterSharedHandleToNodes.NodeArray) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtRegisterSharedHandleToNodes.NodeArray);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtProcessVMRead: {
      typedef decltype(api_data.args.hsaKmtProcessVMRead.Pid) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtProcessVMRead.Pid) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMRead.LocalMemoryArray) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtProcessVMRead.LocalMemoryArray) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMRead.LocalMemoryArrayCount) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtProcessVMRead.LocalMemoryArrayCount) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMRead.RemoteMemoryArray) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtProcessVMRead.RemoteMemoryArray) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMRead.RemoteMemoryArrayCount) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtProcessVMRead.RemoteMemoryArrayCount) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMRead.SizeCopied) arg_val_type_t5;
      roctracer::kfd_support::output_streamer<arg_val_type_t5>::put(out, api_data.args.hsaKmtProcessVMRead.SizeCopied);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtProcessVMWrite: {
      typedef decltype(api_data.args.hsaKmtProcessVMWrite.Pid) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtProcessVMWrite.Pid) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMWrite.LocalMemoryArray) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtProcessVMWrite.LocalMemoryArray) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMWrite.LocalMemoryArrayCount) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtProcessVMWrite.LocalMemoryArrayCount) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMWrite.RemoteMemoryArray) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtProcessVMWrite.RemoteMemoryArray) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMWrite.RemoteMemoryArrayCount) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtProcessVMWrite.RemoteMemoryArrayCount) << ", ";
      typedef decltype(api_data.args.hsaKmtProcessVMWrite.SizeCopied) arg_val_type_t5;
      roctracer::kfd_support::output_streamer<arg_val_type_t5>::put(out, api_data.args.hsaKmtProcessVMWrite.SizeCopied);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtDeregisterMemory: {
      typedef decltype(api_data.args.hsaKmtDeregisterMemory.MemoryAddress) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtDeregisterMemory.MemoryAddress);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtMapMemoryToGPU: {
      typedef decltype(api_data.args.hsaKmtMapMemoryToGPU.MemoryAddress) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtMapMemoryToGPU.MemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtMapMemoryToGPU.MemorySizeInBytes) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtMapMemoryToGPU.MemorySizeInBytes) << ", ";
      typedef decltype(api_data.args.hsaKmtMapMemoryToGPU.AlternateVAGPU) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtMapMemoryToGPU.AlternateVAGPU);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtMapMemoryToGPUNodes: {
      typedef decltype(api_data.args.hsaKmtMapMemoryToGPUNodes.MemoryAddress) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtMapMemoryToGPUNodes.MemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtMapMemoryToGPUNodes.MemorySizeInBytes) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtMapMemoryToGPUNodes.MemorySizeInBytes) << ", ";
      typedef decltype(api_data.args.hsaKmtMapMemoryToGPUNodes.AlternateVAGPU) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtMapMemoryToGPUNodes.AlternateVAGPU) << ", ";
      typedef decltype(api_data.args.hsaKmtMapMemoryToGPUNodes.MemMapFlags) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtMapMemoryToGPUNodes.MemMapFlags) << ", ";
      typedef decltype(api_data.args.hsaKmtMapMemoryToGPUNodes.NumberOfNodes) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtMapMemoryToGPUNodes.NumberOfNodes) << ", ";
      typedef decltype(api_data.args.hsaKmtMapMemoryToGPUNodes.NodeArray) arg_val_type_t5;
      roctracer::kfd_support::output_streamer<arg_val_type_t5>::put(out, api_data.args.hsaKmtMapMemoryToGPUNodes.NodeArray);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtUnmapMemoryToGPU: {
      typedef decltype(api_data.args.hsaKmtUnmapMemoryToGPU.MemoryAddress) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtUnmapMemoryToGPU.MemoryAddress);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtMapGraphicHandle: {
      typedef decltype(api_data.args.hsaKmtMapGraphicHandle.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtMapGraphicHandle.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtMapGraphicHandle.GraphicDeviceHandle) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtMapGraphicHandle.GraphicDeviceHandle) << ", ";
      typedef decltype(api_data.args.hsaKmtMapGraphicHandle.GraphicResourceHandle) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtMapGraphicHandle.GraphicResourceHandle) << ", ";
      typedef decltype(api_data.args.hsaKmtMapGraphicHandle.GraphicResourceOffset) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtMapGraphicHandle.GraphicResourceOffset) << ", ";
      typedef decltype(api_data.args.hsaKmtMapGraphicHandle.GraphicResourceSize) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtMapGraphicHandle.GraphicResourceSize) << ", ";
      typedef decltype(api_data.args.hsaKmtMapGraphicHandle.FlatMemoryAddress) arg_val_type_t5;
      roctracer::kfd_support::output_streamer<arg_val_type_t5>::put(out, api_data.args.hsaKmtMapGraphicHandle.FlatMemoryAddress);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtUnmapGraphicHandle: {
      typedef decltype(api_data.args.hsaKmtUnmapGraphicHandle.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtUnmapGraphicHandle.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtUnmapGraphicHandle.FlatMemoryAddress) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtUnmapGraphicHandle.FlatMemoryAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtUnmapGraphicHandle.SizeInBytes) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtUnmapGraphicHandle.SizeInBytes);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtAllocQueueGWS: {
      typedef decltype(api_data.args.hsaKmtAllocQueueGWS.QueueId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtAllocQueueGWS.QueueId) << ", ";
      typedef decltype(api_data.args.hsaKmtAllocQueueGWS.nGWS) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtAllocQueueGWS.nGWS) << ", ";
      typedef decltype(api_data.args.hsaKmtAllocQueueGWS.firstGWS) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtAllocQueueGWS.firstGWS);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtDbgRegister: {
      typedef decltype(api_data.args.hsaKmtDbgRegister.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtDbgRegister.NodeId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtDbgUnregister: {
      typedef decltype(api_data.args.hsaKmtDbgUnregister.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtDbgUnregister.NodeId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtDbgWavefrontControl: {
      typedef decltype(api_data.args.hsaKmtDbgWavefrontControl.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtDbgWavefrontControl.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtDbgWavefrontControl.Operand) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtDbgWavefrontControl.Operand) << ", ";
      typedef decltype(api_data.args.hsaKmtDbgWavefrontControl.Mode) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtDbgWavefrontControl.Mode) << ", ";
      typedef decltype(api_data.args.hsaKmtDbgWavefrontControl.TrapId) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtDbgWavefrontControl.TrapId) << ", ";
      typedef decltype(api_data.args.hsaKmtDbgWavefrontControl.DbgWaveMsgRing) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtDbgWavefrontControl.DbgWaveMsgRing);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtDbgAddressWatch: {
      typedef decltype(api_data.args.hsaKmtDbgAddressWatch.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtDbgAddressWatch.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtDbgAddressWatch.NumWatchPoints) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtDbgAddressWatch.NumWatchPoints) << ", ";
      typedef decltype(api_data.args.hsaKmtDbgAddressWatch.WatchMode) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtDbgAddressWatch.WatchMode) << ", ";
      typedef decltype(api_data.args.hsaKmtDbgAddressWatch.WatchAddress) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtDbgAddressWatch.WatchAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtDbgAddressWatch.WatchMask) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtDbgAddressWatch.WatchMask) << ", ";
      typedef decltype(api_data.args.hsaKmtDbgAddressWatch.WatchEvent) arg_val_type_t5;
      roctracer::kfd_support::output_streamer<arg_val_type_t5>::put(out, api_data.args.hsaKmtDbgAddressWatch.WatchEvent);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtQueueSuspend: {
      typedef decltype(api_data.args.hsaKmtQueueSuspend.Pid) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtQueueSuspend.Pid) << ", ";
      typedef decltype(api_data.args.hsaKmtQueueSuspend.NumQueues) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtQueueSuspend.NumQueues) << ", ";
      typedef decltype(api_data.args.hsaKmtQueueSuspend.Queues) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtQueueSuspend.Queues) << ", ";
      typedef decltype(api_data.args.hsaKmtQueueSuspend.GracePeriod) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtQueueSuspend.GracePeriod) << ", ";
      typedef decltype(api_data.args.hsaKmtQueueSuspend.Flags) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtQueueSuspend.Flags);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtQueueResume: {
      typedef decltype(api_data.args.hsaKmtQueueResume.Pid) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtQueueResume.Pid) << ", ";
      typedef decltype(api_data.args.hsaKmtQueueResume.NumQueues) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtQueueResume.NumQueues) << ", ";
      typedef decltype(api_data.args.hsaKmtQueueResume.Queues) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtQueueResume.Queues) << ", ";
      typedef decltype(api_data.args.hsaKmtQueueResume.Flags) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtQueueResume.Flags);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtEnableDebugTrap: {
      typedef decltype(api_data.args.hsaKmtEnableDebugTrap.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtEnableDebugTrap.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtEnableDebugTrap.QueueId) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtEnableDebugTrap.QueueId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtEnableDebugTrapWithPollFd: {
      typedef decltype(api_data.args.hsaKmtEnableDebugTrapWithPollFd.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtEnableDebugTrapWithPollFd.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtEnableDebugTrapWithPollFd.QueueId) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtEnableDebugTrapWithPollFd.QueueId) << ", ";
      typedef decltype(api_data.args.hsaKmtEnableDebugTrapWithPollFd.PollFd) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtEnableDebugTrapWithPollFd.PollFd);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtDisableDebugTrap: {
      typedef decltype(api_data.args.hsaKmtDisableDebugTrap.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtDisableDebugTrap.NodeId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtQueryDebugEvent: {
      typedef decltype(api_data.args.hsaKmtQueryDebugEvent.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtQueryDebugEvent.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtQueryDebugEvent.Pid) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtQueryDebugEvent.Pid) << ", ";
      typedef decltype(api_data.args.hsaKmtQueryDebugEvent.QueueId) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtQueryDebugEvent.QueueId) << ", ";
      typedef decltype(api_data.args.hsaKmtQueryDebugEvent.ClearEvents) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtQueryDebugEvent.ClearEvents) << ", ";
      typedef decltype(api_data.args.hsaKmtQueryDebugEvent.EventsReceived) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtQueryDebugEvent.EventsReceived) << ", ";
      typedef decltype(api_data.args.hsaKmtQueryDebugEvent.IsSuspended) arg_val_type_t5;
      roctracer::kfd_support::output_streamer<arg_val_type_t5>::put(out, api_data.args.hsaKmtQueryDebugEvent.IsSuspended) << ", ";
      typedef decltype(api_data.args.hsaKmtQueryDebugEvent.IsNew) arg_val_type_t6;
      roctracer::kfd_support::output_streamer<arg_val_type_t6>::put(out, api_data.args.hsaKmtQueryDebugEvent.IsNew);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetQueueSnapshot: {
      typedef decltype(api_data.args.hsaKmtGetQueueSnapshot.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetQueueSnapshot.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtGetQueueSnapshot.Pid) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetQueueSnapshot.Pid) << ", ";
      typedef decltype(api_data.args.hsaKmtGetQueueSnapshot.ClearEvents) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtGetQueueSnapshot.ClearEvents) << ", ";
      typedef decltype(api_data.args.hsaKmtGetQueueSnapshot.SnapshotBuf) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtGetQueueSnapshot.SnapshotBuf) << ", ";
      typedef decltype(api_data.args.hsaKmtGetQueueSnapshot.QssEntries) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtGetQueueSnapshot.QssEntries);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtSetWaveLaunchTrapOverride: {
      typedef decltype(api_data.args.hsaKmtSetWaveLaunchTrapOverride.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtSetWaveLaunchTrapOverride.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtSetWaveLaunchTrapOverride.TrapOverride) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtSetWaveLaunchTrapOverride.TrapOverride) << ", ";
      typedef decltype(api_data.args.hsaKmtSetWaveLaunchTrapOverride.TrapMask) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtSetWaveLaunchTrapOverride.TrapMask);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtSetWaveLaunchMode: {
      typedef decltype(api_data.args.hsaKmtSetWaveLaunchMode.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtSetWaveLaunchMode.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtSetWaveLaunchMode.WaveLaunchMode) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtSetWaveLaunchMode.WaveLaunchMode);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetKernelDebugTrapVersionInfo: {
      typedef decltype(api_data.args.hsaKmtGetKernelDebugTrapVersionInfo.Major) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetKernelDebugTrapVersionInfo.Major) << ", ";
      typedef decltype(api_data.args.hsaKmtGetKernelDebugTrapVersionInfo.Minor) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetKernelDebugTrapVersionInfo.Minor);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetThunkDebugTrapVersionInfo: {
      typedef decltype(api_data.args.hsaKmtGetThunkDebugTrapVersionInfo.Major) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetThunkDebugTrapVersionInfo.Major) << ", ";
      typedef decltype(api_data.args.hsaKmtGetThunkDebugTrapVersionInfo.Minor) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetThunkDebugTrapVersionInfo.Minor);
      ret << "void";
      break;
    }
    case KFD_API_ID_hsaKmtSetAddressWatch: {
      typedef decltype(api_data.args.hsaKmtSetAddressWatch.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtSetAddressWatch.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtSetAddressWatch.Pid) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtSetAddressWatch.Pid) << ", ";
      typedef decltype(api_data.args.hsaKmtSetAddressWatch.WatchMode) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtSetAddressWatch.WatchMode) << ", ";
      typedef decltype(api_data.args.hsaKmtSetAddressWatch.WatchAddress) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtSetAddressWatch.WatchAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtSetAddressWatch.WatchAddrMask) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtSetAddressWatch.WatchAddrMask) << ", ";
      typedef decltype(api_data.args.hsaKmtSetAddressWatch.WatchId) arg_val_type_t5;
      roctracer::kfd_support::output_streamer<arg_val_type_t5>::put(out, api_data.args.hsaKmtSetAddressWatch.WatchId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtClearAddressWatch: {
      typedef decltype(api_data.args.hsaKmtClearAddressWatch.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtClearAddressWatch.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtClearAddressWatch.Pid) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtClearAddressWatch.Pid) << ", ";
      typedef decltype(api_data.args.hsaKmtClearAddressWatch.WatchId) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtClearAddressWatch.WatchId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtEnablePreciseMemoryOperations: {
      typedef decltype(api_data.args.hsaKmtEnablePreciseMemoryOperations.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtEnablePreciseMemoryOperations.NodeId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtDisablePreciseMemoryOperations: {
      typedef decltype(api_data.args.hsaKmtDisablePreciseMemoryOperations.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtDisablePreciseMemoryOperations.NodeId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetClockCounters: {
      typedef decltype(api_data.args.hsaKmtGetClockCounters.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetClockCounters.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtGetClockCounters.Counters) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetClockCounters.Counters);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtPmcGetCounterProperties: {
      typedef decltype(api_data.args.hsaKmtPmcGetCounterProperties.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtPmcGetCounterProperties.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtPmcGetCounterProperties.CounterProperties) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtPmcGetCounterProperties.CounterProperties);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtPmcRegisterTrace: {
      typedef decltype(api_data.args.hsaKmtPmcRegisterTrace.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtPmcRegisterTrace.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtPmcRegisterTrace.NumberOfCounters) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtPmcRegisterTrace.NumberOfCounters) << ", ";
      typedef decltype(api_data.args.hsaKmtPmcRegisterTrace.Counters) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtPmcRegisterTrace.Counters) << ", ";
      typedef decltype(api_data.args.hsaKmtPmcRegisterTrace.TraceRoot) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtPmcRegisterTrace.TraceRoot);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtPmcUnregisterTrace: {
      typedef decltype(api_data.args.hsaKmtPmcUnregisterTrace.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtPmcUnregisterTrace.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtPmcUnregisterTrace.TraceId) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtPmcUnregisterTrace.TraceId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtPmcAcquireTraceAccess: {
      typedef decltype(api_data.args.hsaKmtPmcAcquireTraceAccess.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtPmcAcquireTraceAccess.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtPmcAcquireTraceAccess.TraceId) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtPmcAcquireTraceAccess.TraceId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtPmcReleaseTraceAccess: {
      typedef decltype(api_data.args.hsaKmtPmcReleaseTraceAccess.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtPmcReleaseTraceAccess.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtPmcReleaseTraceAccess.TraceId) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtPmcReleaseTraceAccess.TraceId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtPmcStartTrace: {
      typedef decltype(api_data.args.hsaKmtPmcStartTrace.TraceId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtPmcStartTrace.TraceId) << ", ";
      typedef decltype(api_data.args.hsaKmtPmcStartTrace.TraceBuffer) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtPmcStartTrace.TraceBuffer) << ", ";
      typedef decltype(api_data.args.hsaKmtPmcStartTrace.TraceBufferSizeBytes) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtPmcStartTrace.TraceBufferSizeBytes);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtPmcQueryTrace: {
      typedef decltype(api_data.args.hsaKmtPmcQueryTrace.TraceId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtPmcQueryTrace.TraceId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtPmcStopTrace: {
      typedef decltype(api_data.args.hsaKmtPmcStopTrace.TraceId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtPmcStopTrace.TraceId);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtSetTrapHandler: {
      typedef decltype(api_data.args.hsaKmtSetTrapHandler.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtSetTrapHandler.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtSetTrapHandler.TrapHandlerBaseAddress) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtSetTrapHandler.TrapHandlerBaseAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtSetTrapHandler.TrapHandlerSizeInBytes) arg_val_type_t2;
      roctracer::kfd_support::output_streamer<arg_val_type_t2>::put(out, api_data.args.hsaKmtSetTrapHandler.TrapHandlerSizeInBytes) << ", ";
      typedef decltype(api_data.args.hsaKmtSetTrapHandler.TrapBufferBaseAddress) arg_val_type_t3;
      roctracer::kfd_support::output_streamer<arg_val_type_t3>::put(out, api_data.args.hsaKmtSetTrapHandler.TrapBufferBaseAddress) << ", ";
      typedef decltype(api_data.args.hsaKmtSetTrapHandler.TrapBufferSizeInBytes) arg_val_type_t4;
      roctracer::kfd_support::output_streamer<arg_val_type_t4>::put(out, api_data.args.hsaKmtSetTrapHandler.TrapBufferSizeInBytes);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtGetTileConfig: {
      typedef decltype(api_data.args.hsaKmtGetTileConfig.NodeId) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtGetTileConfig.NodeId) << ", ";
      typedef decltype(api_data.args.hsaKmtGetTileConfig.config) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtGetTileConfig.config);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtQueryPointerInfo: {
      typedef decltype(api_data.args.hsaKmtQueryPointerInfo.Pointer) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtQueryPointerInfo.Pointer) << ", ";
      typedef decltype(api_data.args.hsaKmtQueryPointerInfo.PointerInfo) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtQueryPointerInfo.PointerInfo);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    case KFD_API_ID_hsaKmtSetMemoryUserData: {
      typedef decltype(api_data.args.hsaKmtSetMemoryUserData.Pointer) arg_val_type_t0;
      roctracer::kfd_support::output_streamer<arg_val_type_t0>::put(out, api_data.args.hsaKmtSetMemoryUserData.Pointer) << ", ";
      typedef decltype(api_data.args.hsaKmtSetMemoryUserData.UserData) arg_val_type_t1;
      roctracer::kfd_support::output_streamer<arg_val_type_t1>::put(out, api_data.args.hsaKmtSetMemoryUserData.UserData);
      ret << api_data.HSAKMT_STATUS_retval;
      break;
    }
    default:
      out << "ERROR: unknown API";
      abort();
  }
  return kfd_api_string_pair_t(out.str(), ret.str());
}

const kfd_api_id_t* kfd_api_table(){
	return all_kfd_api_func;
}

uint32_t GetKFDApiSize() {
	return sizeof(all_kfd_api_func)/sizeof(kfd_api_id_t);
}