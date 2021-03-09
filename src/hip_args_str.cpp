#include <roctracer_hip_aux.h>
#include <hip_args_str.h>
#include <sstream>

static const hip_api_id_t all_hip_api_func[] = { 
	HIP_API_ID_hipDrvMemcpy3DAsync,
	HIP_API_ID_hipDeviceEnablePeerAccess,
	HIP_API_ID_hipFuncSetSharedMemConfig,
	HIP_API_ID_hipMemcpyToSymbolAsync,
	HIP_API_ID_hipModuleUnload,
	HIP_API_ID_hipMallocPitch,
	HIP_API_ID_hipMalloc,
	HIP_API_ID_hipMemsetD16,
	HIP_API_ID_hipDeviceGetName,
	HIP_API_ID_hipEventRecord,
	HIP_API_ID_hipCtxSynchronize,
	HIP_API_ID_hipSetDevice,
	HIP_API_ID_hipCtxGetApiVersion,
	HIP_API_ID_hipMemcpyFromSymbolAsync,
	HIP_API_ID_hipExtGetLinkTypeAndHopCount,
	HIP_API_ID___hipPopCallConfiguration,
	HIP_API_ID_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor,
	HIP_API_ID_hipMemset3D,
	HIP_API_ID_hipStreamCreateWithPriority,
	HIP_API_ID_hipMemcpy2DToArray,
	HIP_API_ID_hipMemsetD8Async,
	HIP_API_ID_hipCtxGetCacheConfig,
	HIP_API_ID_hipStreamWaitEvent,
	HIP_API_ID_hipDeviceGetStreamPriorityRange,
	HIP_API_ID_hipModuleLoad,
	HIP_API_ID_hipDevicePrimaryCtxSetFlags,
	HIP_API_ID_hipLaunchCooperativeKernel,
	HIP_API_ID_hipLaunchCooperativeKernelMultiDevice,
	HIP_API_ID_hipMemcpyAsync,
	HIP_API_ID_hipMalloc3DArray,
	HIP_API_ID_hipMallocHost,
	HIP_API_ID_hipCtxGetCurrent,
	HIP_API_ID_hipDevicePrimaryCtxGetState,
	HIP_API_ID_hipEventQuery,
	HIP_API_ID_hipEventCreate,
	HIP_API_ID_hipMemGetAddressRange,
	HIP_API_ID_hipMemcpyFromSymbol,
	HIP_API_ID_hipArrayCreate,
	HIP_API_ID_hipStreamAttachMemAsync,
	HIP_API_ID_hipStreamGetFlags,
	HIP_API_ID_hipMallocArray,
	HIP_API_ID_hipCtxGetSharedMemConfig,
	HIP_API_ID_hipModuleOccupancyMaxPotentialBlockSize,
	HIP_API_ID_hipMemPtrGetInfo,
	HIP_API_ID_hipFuncGetAttribute,
	HIP_API_ID_hipCtxGetFlags,
	HIP_API_ID_hipStreamDestroy,
	HIP_API_ID___hipPushCallConfiguration,
	HIP_API_ID_hipMemset3DAsync,
	HIP_API_ID_hipMemcpy3D,
	HIP_API_ID_hipInit,
	HIP_API_ID_hipMemcpyAtoH,
	HIP_API_ID_hipStreamGetPriority,
	HIP_API_ID_hipMemset2D,
	HIP_API_ID_hipMemset2DAsync,
	HIP_API_ID_hipDeviceCanAccessPeer,
	HIP_API_ID_hipLaunchByPtr,
	HIP_API_ID_hipLaunchKernel,
	HIP_API_ID_hipMemsetD16Async,
	HIP_API_ID_hipDeviceGetByPCIBusId,
	HIP_API_ID_hipHostUnregister,
	HIP_API_ID_hipProfilerStop,
	HIP_API_ID_hipExtStreamCreateWithCUMask,
	HIP_API_ID_hipStreamSynchronize,
	HIP_API_ID_hipFreeHost,
	HIP_API_ID_hipDeviceSetCacheConfig,
	HIP_API_ID_hipGetErrorName,
	HIP_API_ID_hipMemcpyHtoD,
	HIP_API_ID_hipModuleGetGlobal,
	HIP_API_ID_hipMemcpyHtoA,
	HIP_API_ID_hipCtxCreate,
	HIP_API_ID_hipMemcpy2D,
	HIP_API_ID_hipIpcCloseMemHandle,
	HIP_API_ID_hipChooseDevice,
	HIP_API_ID_hipDeviceSetSharedMemConfig,
	HIP_API_ID_hipDeviceComputeCapability,
	HIP_API_ID_hipMallocMipmappedArray,
	HIP_API_ID_hipSetupArgument,
	HIP_API_ID_hipProfilerStart,
	HIP_API_ID_hipCtxSetCacheConfig,
	HIP_API_ID_hipFuncSetCacheConfig,
	HIP_API_ID_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags,
	HIP_API_ID_hipModuleGetTexRef,
	HIP_API_ID_hipFuncSetAttribute,
	HIP_API_ID_hipMemcpyWithStream,
	HIP_API_ID_hipConfigureCall,
	HIP_API_ID_hipGetMipmappedArrayLevel,
	HIP_API_ID_hipMemcpy3DAsync,
	HIP_API_ID_hipMemRangeGetAttribute,
	HIP_API_ID_hipEventDestroy,
	HIP_API_ID_hipCtxPopCurrent,
	HIP_API_ID_hipMemPrefetchAsync,
	HIP_API_ID_hipGetSymbolAddress,
	HIP_API_ID_hipHostGetFlags,
	HIP_API_ID_hipHostMalloc,
	HIP_API_ID_hipDriverGetVersion,
	HIP_API_ID_hipFreeMipmappedArray,
	HIP_API_ID_hipMemGetInfo,
	HIP_API_ID_hipDeviceReset,
	HIP_API_ID_hipMemset,
	HIP_API_ID_hipMemsetD8,
	HIP_API_ID_hipMemcpyParam2DAsync,
	HIP_API_ID_hipHostRegister,
	HIP_API_ID_hipCtxSetSharedMemConfig,
	HIP_API_ID_hipArray3DCreate,
	HIP_API_ID_hipIpcOpenMemHandle,
	HIP_API_ID_hipGetLastError,
	HIP_API_ID_hipGetDeviceFlags,
	HIP_API_ID_hipDeviceGetSharedMemConfig,
	HIP_API_ID_hipDrvMemcpy3D,
	HIP_API_ID_hipMemcpy2DFromArray,
	HIP_API_ID_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags,
	HIP_API_ID_hipSetDeviceFlags,
	HIP_API_ID_hipHccModuleLaunchKernel,
	HIP_API_ID_hipFree,
	HIP_API_ID_hipOccupancyMaxPotentialBlockSize,
	HIP_API_ID_hipDeviceGetAttribute,
	HIP_API_ID_hipMemcpyDtoH,
	HIP_API_ID_hipCtxDisablePeerAccess,
	HIP_API_ID_hipMallocManaged,
	HIP_API_ID_hipCtxDestroy,
	HIP_API_ID_hipIpcGetMemHandle,
	HIP_API_ID_hipMemcpyHtoDAsync,
	HIP_API_ID_hipCtxGetDevice,
	HIP_API_ID_hipMemcpyDtoD,
	HIP_API_ID_hipModuleLoadData,
	HIP_API_ID_hipDeviceTotalMem,
	HIP_API_ID_hipOccupancyMaxActiveBlocksPerMultiprocessor,
	HIP_API_ID_hipCtxSetCurrent,
	HIP_API_ID_hipGetErrorString,
	HIP_API_ID_hipStreamCreate,
	HIP_API_ID_hipDevicePrimaryCtxRetain,
	HIP_API_ID_hipDeviceDisablePeerAccess,
	HIP_API_ID_hipStreamCreateWithFlags,
	HIP_API_ID_hipMemcpyFromArray,
	HIP_API_ID_hipMemcpy2DAsync,
	HIP_API_ID_hipFuncGetAttributes,
	HIP_API_ID_hipGetSymbolSize,
	HIP_API_ID_hipIpcGetEventHandle,
	HIP_API_ID_hipMemAdvise,
	HIP_API_ID_hipEventCreateWithFlags,
	HIP_API_ID_hipStreamQuery,
	HIP_API_ID_hipDeviceGetPCIBusId,
	HIP_API_ID_hipMemcpy,
	HIP_API_ID_hipPeekAtLastError,
	HIP_API_ID_hipExtLaunchMultiKernelMultiDevice,
	HIP_API_ID_hipStreamAddCallback,
	HIP_API_ID_hipMemcpyToArray,
	HIP_API_ID_hipMemsetD32,
	HIP_API_ID_hipExtModuleLaunchKernel,
	HIP_API_ID_hipDeviceSynchronize,
	HIP_API_ID_hipDeviceGetCacheConfig,
	HIP_API_ID_hipMalloc3D,
	HIP_API_ID_hipPointerGetAttributes,
	HIP_API_ID_hipMemsetAsync,
	HIP_API_ID_hipMemcpyToSymbol,
	HIP_API_ID_hipModuleOccupancyMaxPotentialBlockSizeWithFlags,
	HIP_API_ID_hipCtxPushCurrent,
	HIP_API_ID_hipMemcpyPeer,
	HIP_API_ID_hipEventSynchronize,
	HIP_API_ID_hipMemcpyDtoDAsync,
	HIP_API_ID_hipExtMallocWithFlags,
	HIP_API_ID_hipCtxEnablePeerAccess,
	HIP_API_ID_hipMemAllocHost,
	HIP_API_ID_hipMemcpyDtoHAsync,
	HIP_API_ID_hipModuleLaunchKernel,
	HIP_API_ID_hipMemAllocPitch,
	HIP_API_ID_hipExtLaunchKernel,
	HIP_API_ID_hipMemcpy2DFromArrayAsync,
	HIP_API_ID_hipDeviceGetLimit,
	HIP_API_ID_hipModuleLoadDataEx,
	HIP_API_ID_hipRuntimeGetVersion,
	HIP_API_ID_hipHostFree,
	HIP_API_ID_hipDeviceGetP2PAttribute,
	HIP_API_ID_hipMemcpyPeerAsync,
	HIP_API_ID_hipGetDeviceProperties,
	HIP_API_ID_hipDeviceGet,
	HIP_API_ID_hipFreeArray,
	HIP_API_ID_hipEventElapsedTime,
	HIP_API_ID_hipDevicePrimaryCtxRelease,
	HIP_API_ID_hipHostGetDevicePointer,
	HIP_API_ID_hipMemRangeGetAttributes,
	HIP_API_ID_hipMemcpyParam2D,
	HIP_API_ID_hipDevicePrimaryCtxReset,
	HIP_API_ID_hipModuleGetFunction,
	HIP_API_ID_hipMemsetD32Async,
	HIP_API_ID_hipGetDevice,
	HIP_API_ID_hipGetDeviceCount,
	HIP_API_ID_hipIpcOpenEventHandle,
	HIP_API_ID_NUMBER
};

std::string hip_api_arguments(uint32_t cid, hip_api_data_t* data)
{
  std::ostringstream oss;
  switch(cid){
    case HIP_API_ID_hipDrvMemcpy3DAsync:
      if (data->args.hipDrvMemcpy3DAsync.pCopy == NULL) oss << "NULL";
      else oss << data->args.hipDrvMemcpy3DAsync.pCopy__val;
      oss << ", " << data->args.hipDrvMemcpy3DAsync.stream;
    break;
    case HIP_API_ID_hipDeviceEnablePeerAccess:
      oss << data->args.hipDeviceEnablePeerAccess.peerDeviceId;
      oss << ", " << data->args.hipDeviceEnablePeerAccess.flags;
    break;
    case HIP_API_ID_hipFuncSetSharedMemConfig:
      oss << data->args.hipFuncSetSharedMemConfig.func;
      oss << ", " << data->args.hipFuncSetSharedMemConfig.config;
    break;
    case HIP_API_ID_hipMemcpyToSymbolAsync:
      oss << data->args.hipMemcpyToSymbolAsync.symbol;
      oss << ", " << data->args.hipMemcpyToSymbolAsync.src;
      oss << ", " << data->args.hipMemcpyToSymbolAsync.sizeBytes;
      oss << ", " << data->args.hipMemcpyToSymbolAsync.offset;
      oss << ", " << data->args.hipMemcpyToSymbolAsync.kind;
      oss << ", " << data->args.hipMemcpyToSymbolAsync.stream;
    break;
    case HIP_API_ID_hipModuleUnload:
      oss << data->args.hipModuleUnload.module;
    break;
    case HIP_API_ID_hipMallocPitch:
      if (data->args.hipMallocPitch.ptr == NULL) oss << "NULL";
      else oss << data->args.hipMallocPitch.ptr__val;
      if (data->args.hipMallocPitch.pitch == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMallocPitch.pitch__val;
      oss << ", " << data->args.hipMallocPitch.width;
      oss << ", " << data->args.hipMallocPitch.height;
    break;
    case HIP_API_ID_hipMalloc:
      if (data->args.hipMalloc.ptr == NULL) oss << "NULL";
      else oss << data->args.hipMalloc.ptr__val;
      oss << ", " << data->args.hipMalloc.size;
    break;
    case HIP_API_ID_hipMemsetD16:
      oss << data->args.hipMemsetD16.dest;
      oss << ", " << data->args.hipMemsetD16.value;
      oss << ", " << data->args.hipMemsetD16.count;
    break;
    case HIP_API_ID_hipDeviceGetName:
      if (data->args.hipDeviceGetName.name == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGetName.name__val;
      oss << ", " << data->args.hipDeviceGetName.len;
      oss << ", " << data->args.hipDeviceGetName.device;
    break;
    case HIP_API_ID_hipEventRecord:
      oss << data->args.hipEventRecord.event;
      oss << ", " << data->args.hipEventRecord.stream;
    break;
    case HIP_API_ID_hipCtxSynchronize:
    break;
    case HIP_API_ID_hipSetDevice:
      oss << data->args.hipSetDevice.deviceId;
    break;
    case HIP_API_ID_hipCtxGetApiVersion:
      oss << data->args.hipCtxGetApiVersion.ctx;
      if (data->args.hipCtxGetApiVersion.apiVersion == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipCtxGetApiVersion.apiVersion__val;
    break;
    case HIP_API_ID_hipMemcpyFromSymbolAsync:
      oss << data->args.hipMemcpyFromSymbolAsync.dst;
      oss << ", " << data->args.hipMemcpyFromSymbolAsync.symbol;
      oss << ", " << data->args.hipMemcpyFromSymbolAsync.sizeBytes;
      oss << ", " << data->args.hipMemcpyFromSymbolAsync.offset;
      oss << ", " << data->args.hipMemcpyFromSymbolAsync.kind;
      oss << ", " << data->args.hipMemcpyFromSymbolAsync.stream;
    break;
    case HIP_API_ID_hipExtGetLinkTypeAndHopCount:
      oss << data->args.hipExtGetLinkTypeAndHopCount.device1;
      oss << ", " << data->args.hipExtGetLinkTypeAndHopCount.device2;
      if (data->args.hipExtGetLinkTypeAndHopCount.linktype == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipExtGetLinkTypeAndHopCount.linktype__val;
      if (data->args.hipExtGetLinkTypeAndHopCount.hopcount == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipExtGetLinkTypeAndHopCount.hopcount__val;
    break;
    case HIP_API_ID___hipPopCallConfiguration:
      if (data->args.__hipPopCallConfiguration.gridDim == NULL) oss << "NULL";
      else oss << data->args.__hipPopCallConfiguration.gridDim__val;
      if (data->args.__hipPopCallConfiguration.blockDim == NULL) oss << ", NULL";
      else oss << ", " << data->args.__hipPopCallConfiguration.blockDim__val;
      if (data->args.__hipPopCallConfiguration.sharedMem == NULL) oss << ", NULL";
      else oss << ", " << data->args.__hipPopCallConfiguration.sharedMem__val;
      if (data->args.__hipPopCallConfiguration.stream == NULL) oss << ", NULL";
      else oss << ", " << data->args.__hipPopCallConfiguration.stream__val;
    break;
    case HIP_API_ID_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor:
      if (data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks == NULL) oss << "NULL";
      else oss << data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks__val;
      oss << ", " << data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.f;
      oss << ", " << data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.blockSize;
      oss << ", " << data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.dynSharedMemPerBlk;
    break;
    case HIP_API_ID_hipMemset3D:
      oss << data->args.hipMemset3D.pitchedDevPtr;
      oss << ", " << data->args.hipMemset3D.value;
      oss << ", " << data->args.hipMemset3D.extent;
    break;
    case HIP_API_ID_hipStreamCreateWithPriority:
      if (data->args.hipStreamCreateWithPriority.stream == NULL) oss << "NULL";
      else oss << data->args.hipStreamCreateWithPriority.stream__val;
      oss << ", " << data->args.hipStreamCreateWithPriority.flags;
      oss << ", " << data->args.hipStreamCreateWithPriority.priority;
    break;
    case HIP_API_ID_hipMemcpy2DToArray:
      if (data->args.hipMemcpy2DToArray.dst == NULL) oss << "NULL";
      else oss << data->args.hipMemcpy2DToArray.dst__val;
      oss << ", " << data->args.hipMemcpy2DToArray.wOffset;
      oss << ", " << data->args.hipMemcpy2DToArray.hOffset;
      oss << ", " << data->args.hipMemcpy2DToArray.src;
      oss << ", " << data->args.hipMemcpy2DToArray.spitch;
      oss << ", " << data->args.hipMemcpy2DToArray.width;
      oss << ", " << data->args.hipMemcpy2DToArray.height;
      oss << ", " << data->args.hipMemcpy2DToArray.kind;
    break;
    case HIP_API_ID_hipMemsetD8Async:
      oss << data->args.hipMemsetD8Async.dest;
      oss << ", " << data->args.hipMemsetD8Async.value;
      oss << ", " << data->args.hipMemsetD8Async.count;
      oss << ", " << data->args.hipMemsetD8Async.stream;
    break;
    case HIP_API_ID_hipCtxGetCacheConfig:
      if (data->args.hipCtxGetCacheConfig.cacheConfig == NULL) oss << "NULL";
      else oss << data->args.hipCtxGetCacheConfig.cacheConfig__val;
    break;
    case HIP_API_ID_hipStreamWaitEvent:
      oss << data->args.hipStreamWaitEvent.stream;
      oss << ", " << data->args.hipStreamWaitEvent.event;
      oss << ", " << data->args.hipStreamWaitEvent.flags;
    break;
    case HIP_API_ID_hipDeviceGetStreamPriorityRange:
      if (data->args.hipDeviceGetStreamPriorityRange.leastPriority == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGetStreamPriorityRange.leastPriority__val;
      if (data->args.hipDeviceGetStreamPriorityRange.greatestPriority == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipDeviceGetStreamPriorityRange.greatestPriority__val;
    break;
    case HIP_API_ID_hipModuleLoad:
      if (data->args.hipModuleLoad.module == NULL) oss << "NULL";
      else oss << data->args.hipModuleLoad.module__val;
      if (data->args.hipModuleLoad.fname == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleLoad.fname__val;
    break;
    case HIP_API_ID_hipDevicePrimaryCtxSetFlags:
      oss << data->args.hipDevicePrimaryCtxSetFlags.dev;
      oss << ", " << data->args.hipDevicePrimaryCtxSetFlags.flags;
    break;
    case HIP_API_ID_hipLaunchCooperativeKernel:
      oss << data->args.hipLaunchCooperativeKernel.f;
      oss << ", " << data->args.hipLaunchCooperativeKernel.gridDim;
      oss << ", " << data->args.hipLaunchCooperativeKernel.blockDimX;
      if (data->args.hipLaunchCooperativeKernel.kernelParams == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipLaunchCooperativeKernel.kernelParams__val;
      oss << ", " << data->args.hipLaunchCooperativeKernel.sharedMemBytes;
      oss << ", " << data->args.hipLaunchCooperativeKernel.stream;
    break;
    case HIP_API_ID_hipLaunchCooperativeKernelMultiDevice:
      if (data->args.hipLaunchCooperativeKernelMultiDevice.launchParamsList == NULL) oss << "NULL";
      else oss << data->args.hipLaunchCooperativeKernelMultiDevice.launchParamsList__val;
      oss << ", " << data->args.hipLaunchCooperativeKernelMultiDevice.numDevices;
      oss << ", " << data->args.hipLaunchCooperativeKernelMultiDevice.flags;
    break;
    case HIP_API_ID_hipMemcpyAsync:
      oss << data->args.hipMemcpyAsync.dst;
      oss << ", " << data->args.hipMemcpyAsync.src;
      oss << ", " << data->args.hipMemcpyAsync.sizeBytes;
      oss << ", " << data->args.hipMemcpyAsync.kind;
      oss << ", " << data->args.hipMemcpyAsync.stream;
    break;
    case HIP_API_ID_hipMalloc3DArray:
      if (data->args.hipMalloc3DArray.array == NULL) oss << "NULL";
      else oss << data->args.hipMalloc3DArray.array__val;
      if (data->args.hipMalloc3DArray.desc == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMalloc3DArray.desc__val;
      oss << ", " << data->args.hipMalloc3DArray.extent;
      oss << ", " << data->args.hipMalloc3DArray.flags;
    break;
    case HIP_API_ID_hipMallocHost:
      if (data->args.hipMallocHost.ptr == NULL) oss << "NULL";
      else oss << data->args.hipMallocHost.ptr__val;
      oss << ", " << data->args.hipMallocHost.size;
    break;
    case HIP_API_ID_hipCtxGetCurrent:
      if (data->args.hipCtxGetCurrent.ctx == NULL) oss << "NULL";
      else oss << data->args.hipCtxGetCurrent.ctx__val;
    break;
    case HIP_API_ID_hipDevicePrimaryCtxGetState:
      oss << data->args.hipDevicePrimaryCtxGetState.dev;
      if (data->args.hipDevicePrimaryCtxGetState.flags == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipDevicePrimaryCtxGetState.flags__val;
      if (data->args.hipDevicePrimaryCtxGetState.active == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipDevicePrimaryCtxGetState.active__val;
    break;
    case HIP_API_ID_hipEventQuery:
      oss << data->args.hipEventQuery.event;
    break;
    case HIP_API_ID_hipEventCreate:
      if (data->args.hipEventCreate.event == NULL) oss << "NULL";
      else oss << data->args.hipEventCreate.event__val;
    break;
    case HIP_API_ID_hipMemGetAddressRange:
      if (data->args.hipMemGetAddressRange.pbase == NULL) oss << "NULL";
      else oss << data->args.hipMemGetAddressRange.pbase__val;
      if (data->args.hipMemGetAddressRange.psize == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMemGetAddressRange.psize__val;
      oss << ", " << data->args.hipMemGetAddressRange.dptr;
    break;
    case HIP_API_ID_hipMemcpyFromSymbol:
      oss << data->args.hipMemcpyFromSymbol.dst;
      oss << ", " << data->args.hipMemcpyFromSymbol.symbol;
      oss << ", " << data->args.hipMemcpyFromSymbol.sizeBytes;
      oss << ", " << data->args.hipMemcpyFromSymbol.offset;
      oss << ", " << data->args.hipMemcpyFromSymbol.kind;
    break;
    case HIP_API_ID_hipArrayCreate:
      if (data->args.hipArrayCreate.pHandle == NULL) oss << "NULL";
      else oss << (void*)data->args.hipArrayCreate.pHandle__val;
      if (data->args.hipArrayCreate.pAllocateArray == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipArrayCreate.pAllocateArray__val;
    break;
    case HIP_API_ID_hipStreamAttachMemAsync:
      oss << data->args.hipStreamAttachMemAsync.stream;
      if (data->args.hipStreamAttachMemAsync.dev_ptr == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipStreamAttachMemAsync.dev_ptr__val;
      oss << ", " << data->args.hipStreamAttachMemAsync.length;
      oss << ", " << data->args.hipStreamAttachMemAsync.flags;
    break;
    case HIP_API_ID_hipStreamGetFlags:
      oss << data->args.hipStreamGetFlags.stream;
      if (data->args.hipStreamGetFlags.flags == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipStreamGetFlags.flags__val;
    break;
    case HIP_API_ID_hipMallocArray:
      if (data->args.hipMallocArray.array == NULL) oss << "NULL";
      else oss << (void*)data->args.hipMallocArray.array__val;
      if (data->args.hipMallocArray.desc == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMallocArray.desc__val;
      oss << ", " << data->args.hipMallocArray.width;
      oss << ", " << data->args.hipMallocArray.height;
      oss << ", " << data->args.hipMallocArray.flags;
    break;
    case HIP_API_ID_hipCtxGetSharedMemConfig:
      if (data->args.hipCtxGetSharedMemConfig.pConfig == NULL) oss << "NULL";
      else oss << data->args.hipCtxGetSharedMemConfig.pConfig__val;
    break;
    case HIP_API_ID_hipModuleOccupancyMaxPotentialBlockSize:
      if (data->args.hipModuleOccupancyMaxPotentialBlockSize.gridSize == NULL) oss << "NULL";
      else oss << data->args.hipModuleOccupancyMaxPotentialBlockSize.gridSize__val;
      if (data->args.hipModuleOccupancyMaxPotentialBlockSize.blockSize == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleOccupancyMaxPotentialBlockSize.blockSize__val;
      oss << ", " << data->args.hipModuleOccupancyMaxPotentialBlockSize.f;
      oss << ", " << data->args.hipModuleOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk;
      oss << ", " << data->args.hipModuleOccupancyMaxPotentialBlockSize.blockSizeLimit;
    break;
    case HIP_API_ID_hipMemPtrGetInfo:
      oss << data->args.hipMemPtrGetInfo.ptr;
      if (data->args.hipMemPtrGetInfo.size == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMemPtrGetInfo.size__val;
    break;
    case HIP_API_ID_hipFuncGetAttribute:
      if (data->args.hipFuncGetAttribute.value == NULL) oss << "NULL";
      else oss << data->args.hipFuncGetAttribute.value__val;
      oss << ", " << data->args.hipFuncGetAttribute.attrib;
      oss << ", " << data->args.hipFuncGetAttribute.hfunc;
    break;
    case HIP_API_ID_hipCtxGetFlags:
      if (data->args.hipCtxGetFlags.flags == NULL) oss << "NULL";
      else oss << data->args.hipCtxGetFlags.flags__val;
    break;
    case HIP_API_ID_hipStreamDestroy:
      oss << data->args.hipStreamDestroy.stream;
    break;
    case HIP_API_ID___hipPushCallConfiguration:
      oss << data->args.__hipPushCallConfiguration.gridDim;
      oss << ", " << data->args.__hipPushCallConfiguration.blockDim;
      oss << ", " << data->args.__hipPushCallConfiguration.sharedMem;
      oss << ", " << data->args.__hipPushCallConfiguration.stream;
    break;
    case HIP_API_ID_hipMemset3DAsync:
      oss << data->args.hipMemset3DAsync.pitchedDevPtr;
      oss << ", " << data->args.hipMemset3DAsync.value;
      oss << ", " << data->args.hipMemset3DAsync.extent;
      oss << ", " << data->args.hipMemset3DAsync.stream;
    break;
    case HIP_API_ID_hipMemcpy3D:
      if (data->args.hipMemcpy3D.p == NULL) oss << "NULL";
      else oss << data->args.hipMemcpy3D.p__val;
    break;
    case HIP_API_ID_hipInit:
      oss << data->args.hipInit.flags;
    break;
    case HIP_API_ID_hipMemcpyAtoH:
      oss << data->args.hipMemcpyAtoH.dst;
      if (data->args.hipMemcpyAtoH.srcArray == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMemcpyAtoH.srcArray__val;
      oss << ", " << data->args.hipMemcpyAtoH.srcOffset;
      oss << ", " << data->args.hipMemcpyAtoH.count;
    break;
    case HIP_API_ID_hipStreamGetPriority:
      oss << data->args.hipStreamGetPriority.stream;
      if (data->args.hipStreamGetPriority.priority == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipStreamGetPriority.priority__val;
    break;
    case HIP_API_ID_hipMemset2D:
      oss << data->args.hipMemset2D.dst;
      oss << ", " << data->args.hipMemset2D.pitch;
      oss << ", " << data->args.hipMemset2D.value;
      oss << ", " << data->args.hipMemset2D.width;
      oss << ", " << data->args.hipMemset2D.height;
    break;
    case HIP_API_ID_hipMemset2DAsync:
      oss << data->args.hipMemset2DAsync.dst;
      oss << ", " << data->args.hipMemset2DAsync.pitch;
      oss << ", " << data->args.hipMemset2DAsync.value;
      oss << ", " << data->args.hipMemset2DAsync.width;
      oss << ", " << data->args.hipMemset2DAsync.height;
      oss << ", " << data->args.hipMemset2DAsync.stream;
    break;
    case HIP_API_ID_hipDeviceCanAccessPeer:
      if (data->args.hipDeviceCanAccessPeer.canAccessPeer == NULL) oss << "NULL";
      else oss << data->args.hipDeviceCanAccessPeer.canAccessPeer__val;
      oss << ", " << data->args.hipDeviceCanAccessPeer.deviceId;
      oss << ", " << data->args.hipDeviceCanAccessPeer.peerDeviceId;
    break;
    case HIP_API_ID_hipLaunchByPtr:
      oss << data->args.hipLaunchByPtr.hostFunction;
    break;
    case HIP_API_ID_hipLaunchKernel:
      oss << data->args.hipLaunchKernel.function_address;
      oss << ", " << data->args.hipLaunchKernel.numBlocks;
      oss << ", " << data->args.hipLaunchKernel.dimBlocks;
      if (data->args.hipLaunchKernel.args == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipLaunchKernel.args__val;
      oss << ", " << data->args.hipLaunchKernel.sharedMemBytes;
      oss << ", " << data->args.hipLaunchKernel.stream;
    break;
    case HIP_API_ID_hipMemsetD16Async:
      oss << data->args.hipMemsetD16Async.dest;
      oss << ", " << data->args.hipMemsetD16Async.value;
      oss << ", " << data->args.hipMemsetD16Async.count;
      oss << ", " << data->args.hipMemsetD16Async.stream;
    break;
    case HIP_API_ID_hipDeviceGetByPCIBusId:
      if (data->args.hipDeviceGetByPCIBusId.device == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGetByPCIBusId.device__val;
      if (data->args.hipDeviceGetByPCIBusId.pciBusId == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipDeviceGetByPCIBusId.pciBusId__val;
    break;
    case HIP_API_ID_hipHostUnregister:
      oss << data->args.hipHostUnregister.hostPtr;
    break;
    case HIP_API_ID_hipProfilerStop:
    break;
    case HIP_API_ID_hipExtStreamCreateWithCUMask:
      if (data->args.hipExtStreamCreateWithCUMask.stream == NULL) oss << "NULL";
      else oss << data->args.hipExtStreamCreateWithCUMask.stream__val;
      oss << ", " << data->args.hipExtStreamCreateWithCUMask.cuMaskSize;
      if (data->args.hipExtStreamCreateWithCUMask.cuMask == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipExtStreamCreateWithCUMask.cuMask__val;
    break;
    case HIP_API_ID_hipStreamSynchronize:
      oss << data->args.hipStreamSynchronize.stream;
    break;
    case HIP_API_ID_hipFreeHost:
      oss << data->args.hipFreeHost.ptr;
    break;
    case HIP_API_ID_hipDeviceSetCacheConfig:
      oss << data->args.hipDeviceSetCacheConfig.cacheConfig;
    break;
    case HIP_API_ID_hipGetErrorName:
    break;
    case HIP_API_ID_hipMemcpyHtoD:
      oss << data->args.hipMemcpyHtoD.dst;
      oss << ", " << data->args.hipMemcpyHtoD.src;
      oss << ", " << data->args.hipMemcpyHtoD.sizeBytes;
    break;
    case HIP_API_ID_hipModuleGetGlobal:
      if (data->args.hipModuleGetGlobal.dptr == NULL) oss << "NULL";
      else oss << data->args.hipModuleGetGlobal.dptr__val;
      if (data->args.hipModuleGetGlobal.bytes == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleGetGlobal.bytes__val;
      oss << ", " << data->args.hipModuleGetGlobal.hmod;
      if (data->args.hipModuleGetGlobal.name == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleGetGlobal.name__val;
    break;
    case HIP_API_ID_hipMemcpyHtoA:
      if (data->args.hipMemcpyHtoA.dstArray == NULL) oss << "NULL";
      else oss << data->args.hipMemcpyHtoA.dstArray__val;
      oss << ", " << data->args.hipMemcpyHtoA.dstOffset;
      oss << ", " << data->args.hipMemcpyHtoA.srcHost;
      oss << ", " << data->args.hipMemcpyHtoA.count;
    break;
    case HIP_API_ID_hipCtxCreate:
      if (data->args.hipCtxCreate.ctx == NULL) oss << "NULL";
      else oss << data->args.hipCtxCreate.ctx__val;
      oss << ", " << data->args.hipCtxCreate.flags;
      oss << ", " << data->args.hipCtxCreate.device;
    break;
    case HIP_API_ID_hipMemcpy2D:
      oss << data->args.hipMemcpy2D.dst;
      oss << ", " << data->args.hipMemcpy2D.dpitch;
      oss << ", " << data->args.hipMemcpy2D.src;
      oss << ", " << data->args.hipMemcpy2D.spitch;
      oss << ", " << data->args.hipMemcpy2D.width;
      oss << ", " << data->args.hipMemcpy2D.height;
      oss << ", " << data->args.hipMemcpy2D.kind;
    break;
    case HIP_API_ID_hipIpcCloseMemHandle:
      oss << data->args.hipIpcCloseMemHandle.devPtr;
    break;
    case HIP_API_ID_hipChooseDevice:
      if (data->args.hipChooseDevice.device == NULL) oss << "NULL";
      else oss << data->args.hipChooseDevice.device__val;
      if (data->args.hipChooseDevice.prop == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipChooseDevice.prop__val;
    break;
    case HIP_API_ID_hipDeviceSetSharedMemConfig:
      oss << data->args.hipDeviceSetSharedMemConfig.config;
    break;
    case HIP_API_ID_hipDeviceComputeCapability:
      if (data->args.hipDeviceComputeCapability.major == NULL) oss << "NULL";
      else oss << data->args.hipDeviceComputeCapability.major__val;
      if (data->args.hipDeviceComputeCapability.minor == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipDeviceComputeCapability.minor__val;
      oss << ", " << data->args.hipDeviceComputeCapability.device;
    break;
    case HIP_API_ID_hipMallocMipmappedArray:
      if (data->args.hipMallocMipmappedArray.mipmappedArray == NULL) oss << "NULL";
      else oss << data->args.hipMallocMipmappedArray.mipmappedArray__val;
      if (data->args.hipMallocMipmappedArray.desc == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMallocMipmappedArray.desc__val;
      oss << ", " << data->args.hipMallocMipmappedArray.extent;
      oss << ", " << data->args.hipMallocMipmappedArray.numLevels;
      oss << ", " << data->args.hipMallocMipmappedArray.flags;
    break;
    case HIP_API_ID_hipSetupArgument:
      oss << data->args.hipSetupArgument.arg;
      oss << ", " << data->args.hipSetupArgument.size;
      oss << ", " << data->args.hipSetupArgument.offset;
    break;
    case HIP_API_ID_hipProfilerStart:
    break;
    case HIP_API_ID_hipCtxSetCacheConfig:
      oss << data->args.hipCtxSetCacheConfig.cacheConfig;
    break;
    case HIP_API_ID_hipFuncSetCacheConfig:
      oss << data->args.hipFuncSetCacheConfig.func;
      oss << ", " << data->args.hipFuncSetCacheConfig.config;
    break;
    case HIP_API_ID_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags:
      if (data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks == NULL) oss << "NULL";
      else oss << data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks__val;
      oss << ", " << data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.f;
      oss << ", " << data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize;
      oss << ", " << data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynSharedMemPerBlk;
      oss << ", " << data->args.hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags;
    break;
    case HIP_API_ID_hipModuleGetTexRef:
      if (data->args.hipModuleGetTexRef.texRef == NULL) oss << "NULL";
      else oss << (void*)data->args.hipModuleGetTexRef.texRef__val;
      oss << ", " << data->args.hipModuleGetTexRef.hmod;
      if (data->args.hipModuleGetTexRef.name == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleGetTexRef.name__val;
    break;
    case HIP_API_ID_hipFuncSetAttribute:
      oss << data->args.hipFuncSetAttribute.func;
      oss << ", " << data->args.hipFuncSetAttribute.attr;
      oss << ", " << data->args.hipFuncSetAttribute.value;
    break;
    case HIP_API_ID_hipMemcpyWithStream:
      oss << data->args.hipMemcpyWithStream.dst;
      oss << ", " << data->args.hipMemcpyWithStream.src;
      oss << ", " << data->args.hipMemcpyWithStream.sizeBytes;
      oss << ", " << data->args.hipMemcpyWithStream.kind;
      oss << ", " << data->args.hipMemcpyWithStream.stream;
    break;
    case HIP_API_ID_hipConfigureCall:
      oss << data->args.hipConfigureCall.gridDim;
      oss << ", " << data->args.hipConfigureCall.blockDim;
      oss << ", " << data->args.hipConfigureCall.sharedMem;
      oss << ", " << data->args.hipConfigureCall.stream;
    break;
    case HIP_API_ID_hipGetMipmappedArrayLevel:
      if (data->args.hipGetMipmappedArrayLevel.levelArray == NULL) oss << "NULL";
      else oss << data->args.hipGetMipmappedArrayLevel.levelArray__val;
      oss << ", " << data->args.hipGetMipmappedArrayLevel.mipmappedArray;
      oss << ", " << data->args.hipGetMipmappedArrayLevel.level;
    break;
    case HIP_API_ID_hipMemcpy3DAsync:
      if (data->args.hipMemcpy3DAsync.p == NULL) oss << "NULL";
      else oss << data->args.hipMemcpy3DAsync.p__val;
      oss << ", " << data->args.hipMemcpy3DAsync.stream;
    break;
    case HIP_API_ID_hipMemRangeGetAttribute:
      oss << data->args.hipMemRangeGetAttribute.data;
      oss << ", " << data->args.hipMemRangeGetAttribute.data_size;
      oss << ", " << data->args.hipMemRangeGetAttribute.attribute;
      oss << ", " << data->args.hipMemRangeGetAttribute.dev_ptr;
      oss << ", " << data->args.hipMemRangeGetAttribute.count;
    break;
    case HIP_API_ID_hipEventDestroy:
      oss << data->args.hipEventDestroy.event;
    break;
    case HIP_API_ID_hipCtxPopCurrent:
      if (data->args.hipCtxPopCurrent.ctx == NULL) oss << "NULL";
      else oss << data->args.hipCtxPopCurrent.ctx__val;
    break;
    case HIP_API_ID_hipMemPrefetchAsync:
      oss << data->args.hipMemPrefetchAsync.dev_ptr;
      oss << ", " << data->args.hipMemPrefetchAsync.count;
      oss << ", " << data->args.hipMemPrefetchAsync.device;
      oss << ", " << data->args.hipMemPrefetchAsync.stream;
    break;
    case HIP_API_ID_hipGetSymbolAddress:
      if (data->args.hipGetSymbolAddress.devPtr == NULL) oss << "NULL";
      else oss << data->args.hipGetSymbolAddress.devPtr__val;
      oss << ", " << data->args.hipGetSymbolAddress.symbol;
    break;
    case HIP_API_ID_hipHostGetFlags:
      if (data->args.hipHostGetFlags.flagsPtr == NULL) oss << "NULL";
      else oss << data->args.hipHostGetFlags.flagsPtr__val;
      oss << ", " << data->args.hipHostGetFlags.hostPtr;
    break;
    case HIP_API_ID_hipHostMalloc:
      if (data->args.hipHostMalloc.ptr == NULL) oss << "NULL";
      else oss << data->args.hipHostMalloc.ptr__val;
      oss << ", " << data->args.hipHostMalloc.size;
      oss << ", " << data->args.hipHostMalloc.flags;
    break;
    case HIP_API_ID_hipDriverGetVersion:
      if (data->args.hipDriverGetVersion.driverVersion == NULL) oss << "NULL";
      else oss << data->args.hipDriverGetVersion.driverVersion__val;
    break;
    case HIP_API_ID_hipFreeMipmappedArray:
      oss << data->args.hipFreeMipmappedArray.mipmappedArray;
    break;
    case HIP_API_ID_hipMemGetInfo:
      if (data->args.hipMemGetInfo.free == NULL) oss << "NULL";
      else oss << data->args.hipMemGetInfo.free__val;
      if (data->args.hipMemGetInfo.total == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMemGetInfo.total__val;
    break;
    case HIP_API_ID_hipDeviceReset:
    break;
    case HIP_API_ID_hipMemset:
      oss << data->args.hipMemset.dst;
      oss << ", " << data->args.hipMemset.value;
      oss << ", " << data->args.hipMemset.sizeBytes;
    break;
    case HIP_API_ID_hipMemsetD8:
      oss << data->args.hipMemsetD8.dest;
      oss << ", " << data->args.hipMemsetD8.value;
      oss << ", " << data->args.hipMemsetD8.count;
    break;
    case HIP_API_ID_hipMemcpyParam2DAsync:
      if (data->args.hipMemcpyParam2DAsync.pCopy == NULL) oss << "NULL";
      else oss << data->args.hipMemcpyParam2DAsync.pCopy__val;
      oss << ", " << data->args.hipMemcpyParam2DAsync.stream;
    break;
    case HIP_API_ID_hipHostRegister:
      oss << data->args.hipHostRegister.hostPtr;
      oss << ", " << data->args.hipHostRegister.sizeBytes;
      oss << ", " << data->args.hipHostRegister.flags;
    break;
    case HIP_API_ID_hipCtxSetSharedMemConfig:
      oss << data->args.hipCtxSetSharedMemConfig.config;
    break;
    case HIP_API_ID_hipArray3DCreate:
      if (data->args.hipArray3DCreate.array == NULL) oss << "NULL";
      else oss << (void*)data->args.hipArray3DCreate.array__val;
      if (data->args.hipArray3DCreate.pAllocateArray == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipArray3DCreate.pAllocateArray__val;
    break;
    case HIP_API_ID_hipIpcOpenMemHandle:
      if (data->args.hipIpcOpenMemHandle.devPtr == NULL) oss << "NULL";
      else oss << data->args.hipIpcOpenMemHandle.devPtr__val;
      oss << ", " << data->args.hipIpcOpenMemHandle.handle;
      oss << ", " << data->args.hipIpcOpenMemHandle.flags;
    break;
    case HIP_API_ID_hipGetLastError:
    break;
    case HIP_API_ID_hipGetDeviceFlags:
      if (data->args.hipGetDeviceFlags.flags == NULL) oss << "NULL";
      else oss << data->args.hipGetDeviceFlags.flags__val;
    break;
    case HIP_API_ID_hipDeviceGetSharedMemConfig:
      if (data->args.hipDeviceGetSharedMemConfig.pConfig == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGetSharedMemConfig.pConfig__val;
    break;
    case HIP_API_ID_hipDrvMemcpy3D:
      if (data->args.hipDrvMemcpy3D.pCopy == NULL) oss << "NULL";
      else oss << data->args.hipDrvMemcpy3D.pCopy__val;
    break;
    case HIP_API_ID_hipMemcpy2DFromArray:
      oss << data->args.hipMemcpy2DFromArray.dst;
      oss << ", " << data->args.hipMemcpy2DFromArray.dpitch;
      oss << ", " << data->args.hipMemcpy2DFromArray.src;
      oss << ", " << data->args.hipMemcpy2DFromArray.wOffset;
      oss << ", " << data->args.hipMemcpy2DFromArray.hOffset;
      oss << ", " << data->args.hipMemcpy2DFromArray.width;
      oss << ", " << data->args.hipMemcpy2DFromArray.height;
      oss << ", " << data->args.hipMemcpy2DFromArray.kind;
    break;
    case HIP_API_ID_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags:
      if (data->args.hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks == NULL) oss << "NULL";
      else oss << data->args.hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks__val;
      oss << ", " << data->args.hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.f;
      oss << ", " << data->args.hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize;
      oss << ", " << data->args.hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynamicSMemSize;
      oss << ", " << data->args.hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags;
    break;
    case HIP_API_ID_hipSetDeviceFlags:
      oss << data->args.hipSetDeviceFlags.flags;
    break;
    case HIP_API_ID_hipHccModuleLaunchKernel:
      oss << data->args.hipHccModuleLaunchKernel.f;
      oss << ", " << data->args.hipHccModuleLaunchKernel.globalWorkSizeX;
      oss << ", " << data->args.hipHccModuleLaunchKernel.globalWorkSizeY;
      oss << ", " << data->args.hipHccModuleLaunchKernel.globalWorkSizeZ;
      oss << ", " << data->args.hipHccModuleLaunchKernel.blockDimX;
      oss << ", " << data->args.hipHccModuleLaunchKernel.blockDimY;
      oss << ", " << data->args.hipHccModuleLaunchKernel.blockDimZ;
      oss << ", " << data->args.hipHccModuleLaunchKernel.sharedMemBytes;
      oss << ", " << data->args.hipHccModuleLaunchKernel.hStream;
      if (data->args.hipHccModuleLaunchKernel.kernelParams == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipHccModuleLaunchKernel.kernelParams__val;
      if (data->args.hipHccModuleLaunchKernel.extra == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipHccModuleLaunchKernel.extra__val;
      oss << ", " << data->args.hipHccModuleLaunchKernel.startEvent;
      oss << ", " << data->args.hipHccModuleLaunchKernel.stopEvent;
    break;
    case HIP_API_ID_hipFree:
      oss << data->args.hipFree.ptr;
    break;
    case HIP_API_ID_hipOccupancyMaxPotentialBlockSize:
      if (data->args.hipOccupancyMaxPotentialBlockSize.gridSize == NULL) oss << "NULL";
      else oss << data->args.hipOccupancyMaxPotentialBlockSize.gridSize__val;
      if (data->args.hipOccupancyMaxPotentialBlockSize.blockSize == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipOccupancyMaxPotentialBlockSize.blockSize__val;
      oss << ", " << data->args.hipOccupancyMaxPotentialBlockSize.f;
      oss << ", " << data->args.hipOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk;
      oss << ", " << data->args.hipOccupancyMaxPotentialBlockSize.blockSizeLimit;
    break;
    case HIP_API_ID_hipDeviceGetAttribute:
      if (data->args.hipDeviceGetAttribute.pi == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGetAttribute.pi__val;
      oss << ", " << data->args.hipDeviceGetAttribute.attr;
      oss << ", " << data->args.hipDeviceGetAttribute.deviceId;
    break;
    case HIP_API_ID_hipMemcpyDtoH:
      oss << data->args.hipMemcpyDtoH.dst;
      oss << ", " << data->args.hipMemcpyDtoH.src;
      oss << ", " << data->args.hipMemcpyDtoH.sizeBytes;
    break;
    case HIP_API_ID_hipCtxDisablePeerAccess:
      oss << data->args.hipCtxDisablePeerAccess.peerCtx;
    break;
    case HIP_API_ID_hipMallocManaged:
      if (data->args.hipMallocManaged.dev_ptr == NULL) oss << "NULL";
      else oss << data->args.hipMallocManaged.dev_ptr__val;
      oss << ", " << data->args.hipMallocManaged.size;
      oss << ", " << data->args.hipMallocManaged.flags;
    break;
    case HIP_API_ID_hipCtxDestroy:
      oss << data->args.hipCtxDestroy.ctx;
    break;
    case HIP_API_ID_hipIpcGetMemHandle:
      if (data->args.hipIpcGetMemHandle.handle == NULL) oss << "NULL";
      else oss << data->args.hipIpcGetMemHandle.handle__val;
      oss << ", " << data->args.hipIpcGetMemHandle.devPtr;
    break;
    case HIP_API_ID_hipMemcpyHtoDAsync:
      oss << data->args.hipMemcpyHtoDAsync.dst;
      oss << ", " << data->args.hipMemcpyHtoDAsync.src;
      oss << ", " << data->args.hipMemcpyHtoDAsync.sizeBytes;
      oss << ", " << data->args.hipMemcpyHtoDAsync.stream;
    break;
    case HIP_API_ID_hipCtxGetDevice:
      if (data->args.hipCtxGetDevice.device == NULL) oss << "NULL";
      else oss << data->args.hipCtxGetDevice.device__val;
    break;
    case HIP_API_ID_hipMemcpyDtoD:
      oss << data->args.hipMemcpyDtoD.dst;
      oss << ", " << data->args.hipMemcpyDtoD.src;
      oss << ", " << data->args.hipMemcpyDtoD.sizeBytes;
    break;
    case HIP_API_ID_hipModuleLoadData:
      if (data->args.hipModuleLoadData.module == NULL) oss << "NULL";
      else oss << data->args.hipModuleLoadData.module__val;
      oss << ", " << data->args.hipModuleLoadData.image;
    break;
    case HIP_API_ID_hipDeviceTotalMem:
      if (data->args.hipDeviceTotalMem.bytes == NULL) oss << "NULL";
      else oss << data->args.hipDeviceTotalMem.bytes__val;
      oss << ", " << data->args.hipDeviceTotalMem.device;
    break;
    case HIP_API_ID_hipOccupancyMaxActiveBlocksPerMultiprocessor:
      if (data->args.hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks == NULL) oss << "NULL";
      else oss << data->args.hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks__val;
      oss << ", " << data->args.hipOccupancyMaxActiveBlocksPerMultiprocessor.f;
      oss << ", " << data->args.hipOccupancyMaxActiveBlocksPerMultiprocessor.blockSize;
      oss << ", " << data->args.hipOccupancyMaxActiveBlocksPerMultiprocessor.dynamicSMemSize;
    break;
    case HIP_API_ID_hipCtxSetCurrent:
      oss << data->args.hipCtxSetCurrent.ctx;
    break;
    case HIP_API_ID_hipGetErrorString:
    break;
    case HIP_API_ID_hipStreamCreate:
      if (data->args.hipStreamCreate.stream == NULL) oss << "NULL";
      else oss << data->args.hipStreamCreate.stream__val;
    break;
    case HIP_API_ID_hipDevicePrimaryCtxRetain:
      if (data->args.hipDevicePrimaryCtxRetain.pctx == NULL) oss << "NULL";
      else oss << data->args.hipDevicePrimaryCtxRetain.pctx__val;
      oss << ", " << data->args.hipDevicePrimaryCtxRetain.dev;
    break;
    case HIP_API_ID_hipDeviceDisablePeerAccess:
      oss << data->args.hipDeviceDisablePeerAccess.peerDeviceId;
    break;
    case HIP_API_ID_hipStreamCreateWithFlags:
      if (data->args.hipStreamCreateWithFlags.stream == NULL) oss << "NULL";
      else oss << data->args.hipStreamCreateWithFlags.stream__val;
      oss << ", " << data->args.hipStreamCreateWithFlags.flags;
    break;
    case HIP_API_ID_hipMemcpyFromArray:
      oss << data->args.hipMemcpyFromArray.dst;
      oss << ", " << data->args.hipMemcpyFromArray.srcArray;
      oss << ", " << data->args.hipMemcpyFromArray.wOffset;
      oss << ", " << data->args.hipMemcpyFromArray.hOffset;
      oss << ", " << data->args.hipMemcpyFromArray.count;
      oss << ", " << data->args.hipMemcpyFromArray.kind;
    break;
    case HIP_API_ID_hipMemcpy2DAsync:
      oss << data->args.hipMemcpy2DAsync.dst;
      oss << ", " << data->args.hipMemcpy2DAsync.dpitch;
      oss << ", " << data->args.hipMemcpy2DAsync.src;
      oss << ", " << data->args.hipMemcpy2DAsync.spitch;
      oss << ", " << data->args.hipMemcpy2DAsync.width;
      oss << ", " << data->args.hipMemcpy2DAsync.height;
      oss << ", " << data->args.hipMemcpy2DAsync.kind;
      oss << ", " << data->args.hipMemcpy2DAsync.stream;
    break;
    case HIP_API_ID_hipFuncGetAttributes:
      if (data->args.hipFuncGetAttributes.attr == NULL) oss << "NULL";
      else oss << data->args.hipFuncGetAttributes.attr__val;
      oss << ", " << data->args.hipFuncGetAttributes.func;
    break;
    case HIP_API_ID_hipGetSymbolSize:
      if (data->args.hipGetSymbolSize.size == NULL) oss << "NULL";
      else oss << data->args.hipGetSymbolSize.size__val;
      oss << ", " << data->args.hipGetSymbolSize.symbol;
    break;
    case HIP_API_ID_hipIpcGetEventHandle:
      if (data->args.hipIpcGetEventHandle.handle == NULL) oss << "NULL";
      else oss << data->args.hipIpcGetEventHandle.handle__val;
      oss << ", " << data->args.hipIpcGetEventHandle.event;
    break;
    case HIP_API_ID_hipMemAdvise:
      oss << data->args.hipMemAdvise.dev_ptr;
      oss << ", " << data->args.hipMemAdvise.count;
      oss << ", " << data->args.hipMemAdvise.advice;
      oss << ", " << data->args.hipMemAdvise.device;
    break;
    case HIP_API_ID_hipEventCreateWithFlags:
      if (data->args.hipEventCreateWithFlags.event == NULL) oss << "NULL";
      else oss << data->args.hipEventCreateWithFlags.event__val;
      oss << ", " << data->args.hipEventCreateWithFlags.flags;
    break;
    case HIP_API_ID_hipStreamQuery:
      oss << data->args.hipStreamQuery.stream;
    break;
    case HIP_API_ID_hipDeviceGetPCIBusId:
      if (data->args.hipDeviceGetPCIBusId.pciBusId == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGetPCIBusId.pciBusId__val;
      oss << ", " << data->args.hipDeviceGetPCIBusId.len;
      oss << ", " << data->args.hipDeviceGetPCIBusId.device;
    break;
    case HIP_API_ID_hipMemcpy:
      oss << data->args.hipMemcpy.dst;
      oss << ", " << data->args.hipMemcpy.src;
      oss << ", " << data->args.hipMemcpy.sizeBytes;
      oss << ", " << data->args.hipMemcpy.kind;
    break;
    case HIP_API_ID_hipPeekAtLastError:
    break;
    case HIP_API_ID_hipExtLaunchMultiKernelMultiDevice:
      if (data->args.hipExtLaunchMultiKernelMultiDevice.launchParamsList == NULL) oss << "NULL";
      else oss << data->args.hipExtLaunchMultiKernelMultiDevice.launchParamsList__val;
      oss << ", " << data->args.hipExtLaunchMultiKernelMultiDevice.numDevices;
      oss << ", " << data->args.hipExtLaunchMultiKernelMultiDevice.flags;
    break;
    case HIP_API_ID_hipStreamAddCallback:
      oss << data->args.hipStreamAddCallback.stream;
      oss << ", " << data->args.hipStreamAddCallback.callback;
      oss << ", " << data->args.hipStreamAddCallback.userData;
      oss << ", " << data->args.hipStreamAddCallback.flags;
    break;
    case HIP_API_ID_hipMemcpyToArray:
      if (data->args.hipMemcpyToArray.dst == NULL) oss << "NULL";
      else oss << data->args.hipMemcpyToArray.dst__val;
      oss << ", " << data->args.hipMemcpyToArray.wOffset;
      oss << ", " << data->args.hipMemcpyToArray.hOffset;
      oss << ", " << data->args.hipMemcpyToArray.src;
      oss << ", " << data->args.hipMemcpyToArray.count;
      oss << ", " << data->args.hipMemcpyToArray.kind;
    break;
    case HIP_API_ID_hipMemsetD32:
      oss << data->args.hipMemsetD32.dest;
      oss << ", " << data->args.hipMemsetD32.value;
      oss << ", " << data->args.hipMemsetD32.count;
    break;
    case HIP_API_ID_hipExtModuleLaunchKernel:
      oss << data->args.hipExtModuleLaunchKernel.f;
      oss << ", " << data->args.hipExtModuleLaunchKernel.globalWorkSizeX;
      oss << ", " << data->args.hipExtModuleLaunchKernel.globalWorkSizeY;
      oss << ", " << data->args.hipExtModuleLaunchKernel.globalWorkSizeZ;
      oss << ", " << data->args.hipExtModuleLaunchKernel.localWorkSizeX;
      oss << ", " << data->args.hipExtModuleLaunchKernel.localWorkSizeY;
      oss << ", " << data->args.hipExtModuleLaunchKernel.localWorkSizeZ;
      oss << ", " << data->args.hipExtModuleLaunchKernel.sharedMemBytes;
      oss << ", " << data->args.hipExtModuleLaunchKernel.hStream;
      if (data->args.hipExtModuleLaunchKernel.kernelParams == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipExtModuleLaunchKernel.kernelParams__val;
      if (data->args.hipExtModuleLaunchKernel.extra == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipExtModuleLaunchKernel.extra__val;
      oss << ", " << data->args.hipExtModuleLaunchKernel.startEvent;
      oss << ", " << data->args.hipExtModuleLaunchKernel.stopEvent;
      oss << ", " << data->args.hipExtModuleLaunchKernel.flags;
    break;
    case HIP_API_ID_hipDeviceSynchronize:
    break;
    case HIP_API_ID_hipDeviceGetCacheConfig:
      if (data->args.hipDeviceGetCacheConfig.cacheConfig == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGetCacheConfig.cacheConfig__val;
    break;
    case HIP_API_ID_hipMalloc3D:
      if (data->args.hipMalloc3D.pitchedDevPtr == NULL) oss << "NULL";
      else oss << data->args.hipMalloc3D.pitchedDevPtr__val;
      oss << ", " << data->args.hipMalloc3D.extent;
    break;
    case HIP_API_ID_hipPointerGetAttributes:
      if (data->args.hipPointerGetAttributes.attributes == NULL) oss << "NULL";
      else oss << data->args.hipPointerGetAttributes.attributes__val;
      oss << ", " << data->args.hipPointerGetAttributes.ptr;
    break;
    case HIP_API_ID_hipMemsetAsync:
      oss << data->args.hipMemsetAsync.dst;
      oss << ", " << data->args.hipMemsetAsync.value;
      oss << ", " << data->args.hipMemsetAsync.sizeBytes;
      oss << ", " << data->args.hipMemsetAsync.stream;
    break;
    case HIP_API_ID_hipMemcpyToSymbol:
      oss << data->args.hipMemcpyToSymbol.symbol;
      oss << ", " << data->args.hipMemcpyToSymbol.src;
      oss << ", " << data->args.hipMemcpyToSymbol.sizeBytes;
      oss << ", " << data->args.hipMemcpyToSymbol.offset;
      oss << ", " << data->args.hipMemcpyToSymbol.kind;
    break;
    case HIP_API_ID_hipModuleOccupancyMaxPotentialBlockSizeWithFlags:
      if (data->args.hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize == NULL) oss << "NULL";
      else oss << data->args.hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize__val;
      if (data->args.hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize__val;
      oss << ", " << data->args.hipModuleOccupancyMaxPotentialBlockSizeWithFlags.f;
      oss << ", " << data->args.hipModuleOccupancyMaxPotentialBlockSizeWithFlags.dynSharedMemPerBlk;
      oss << ", " << data->args.hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSizeLimit;
      oss << ", " << data->args.hipModuleOccupancyMaxPotentialBlockSizeWithFlags.flags;
    break;
    case HIP_API_ID_hipCtxPushCurrent:
      oss << data->args.hipCtxPushCurrent.ctx;
    break;
    case HIP_API_ID_hipMemcpyPeer:
      oss << data->args.hipMemcpyPeer.dst;
      oss << ", " << data->args.hipMemcpyPeer.dstDeviceId;
      oss << ", " << data->args.hipMemcpyPeer.src;
      oss << ", " << data->args.hipMemcpyPeer.srcDeviceId;
      oss << ", " << data->args.hipMemcpyPeer.sizeBytes;
    break;
    case HIP_API_ID_hipEventSynchronize:
      oss << data->args.hipEventSynchronize.event;
    break;
    case HIP_API_ID_hipMemcpyDtoDAsync:
      oss << data->args.hipMemcpyDtoDAsync.dst;
      oss << ", " << data->args.hipMemcpyDtoDAsync.src;
      oss << ", " << data->args.hipMemcpyDtoDAsync.sizeBytes;
      oss << ", " << data->args.hipMemcpyDtoDAsync.stream;
    break;
    case HIP_API_ID_hipExtMallocWithFlags:
      if (data->args.hipExtMallocWithFlags.ptr == NULL) oss << "NULL";
      else oss << data->args.hipExtMallocWithFlags.ptr__val;
      oss << ", " << data->args.hipExtMallocWithFlags.sizeBytes;
      oss << ", " << data->args.hipExtMallocWithFlags.flags;
    break;
    case HIP_API_ID_hipCtxEnablePeerAccess:
      oss << data->args.hipCtxEnablePeerAccess.peerCtx;
      oss << ", " << data->args.hipCtxEnablePeerAccess.flags;
    break;
    case HIP_API_ID_hipMemAllocHost:
      if (data->args.hipMemAllocHost.ptr == NULL) oss << "NULL";
      else oss << data->args.hipMemAllocHost.ptr__val;
      oss << ", " << data->args.hipMemAllocHost.size;
    break;
    case HIP_API_ID_hipMemcpyDtoHAsync:
      oss << data->args.hipMemcpyDtoHAsync.dst;
      oss << ", " << data->args.hipMemcpyDtoHAsync.src;
      oss << ", " << data->args.hipMemcpyDtoHAsync.sizeBytes;
      oss << ", " << data->args.hipMemcpyDtoHAsync.stream;
    break;
    case HIP_API_ID_hipModuleLaunchKernel:
      oss << data->args.hipModuleLaunchKernel.f;
      oss << ", " << data->args.hipModuleLaunchKernel.gridDimX;
      oss << ", " << data->args.hipModuleLaunchKernel.gridDimY;
      oss << ", " << data->args.hipModuleLaunchKernel.gridDimZ;
      oss << ", " << data->args.hipModuleLaunchKernel.blockDimX;
      oss << ", " << data->args.hipModuleLaunchKernel.blockDimY;
      oss << ", " << data->args.hipModuleLaunchKernel.blockDimZ;
      oss << ", " << data->args.hipModuleLaunchKernel.sharedMemBytes;
      oss << ", " << data->args.hipModuleLaunchKernel.stream;
      if (data->args.hipModuleLaunchKernel.kernelParams == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleLaunchKernel.kernelParams__val;
      if (data->args.hipModuleLaunchKernel.extra == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleLaunchKernel.extra__val;
    break;
    case HIP_API_ID_hipMemAllocPitch:
      if (data->args.hipMemAllocPitch.dptr == NULL) oss << "NULL";
      else oss << data->args.hipMemAllocPitch.dptr__val;
      if (data->args.hipMemAllocPitch.pitch == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMemAllocPitch.pitch__val;
      oss << ", " << data->args.hipMemAllocPitch.widthInBytes;
      oss << ", " << data->args.hipMemAllocPitch.height;
      oss << ", " << data->args.hipMemAllocPitch.elementSizeBytes;
    break;
    case HIP_API_ID_hipExtLaunchKernel:
      oss << data->args.hipExtLaunchKernel.function_address;
      oss << ", " << data->args.hipExtLaunchKernel.numBlocks;
      oss << ", " << data->args.hipExtLaunchKernel.dimBlocks;
      if (data->args.hipExtLaunchKernel.args == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipExtLaunchKernel.args__val;
      oss << ", " << data->args.hipExtLaunchKernel.sharedMemBytes;
      oss << ", " << data->args.hipExtLaunchKernel.stream;
      oss << ", " << data->args.hipExtLaunchKernel.startEvent;
      oss << ", " << data->args.hipExtLaunchKernel.stopEvent;
      oss << ", " << data->args.hipExtLaunchKernel.flags;
    break;
    case HIP_API_ID_hipMemcpy2DFromArrayAsync:
      oss << data->args.hipMemcpy2DFromArrayAsync.dst;
      oss << ", " << data->args.hipMemcpy2DFromArrayAsync.dpitch;
      oss << ", " << data->args.hipMemcpy2DFromArrayAsync.src;
      oss << ", " << data->args.hipMemcpy2DFromArrayAsync.wOffset;
      oss << ", " << data->args.hipMemcpy2DFromArrayAsync.hOffset;
      oss << ", " << data->args.hipMemcpy2DFromArrayAsync.width;
      oss << ", " << data->args.hipMemcpy2DFromArrayAsync.height;
      oss << ", " << data->args.hipMemcpy2DFromArrayAsync.kind;
      oss << ", " << data->args.hipMemcpy2DFromArrayAsync.stream;
    break;
    case HIP_API_ID_hipDeviceGetLimit:
      if (data->args.hipDeviceGetLimit.pValue == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGetLimit.pValue__val;
      oss << ", " << data->args.hipDeviceGetLimit.limit;
    break;
    case HIP_API_ID_hipModuleLoadDataEx:
      if (data->args.hipModuleLoadDataEx.module == NULL) oss << "NULL";
      else oss << data->args.hipModuleLoadDataEx.module__val;
      oss << ", " << data->args.hipModuleLoadDataEx.image;
      oss << ", " << data->args.hipModuleLoadDataEx.numOptions;
      if (data->args.hipModuleLoadDataEx.options == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleLoadDataEx.options__val;
      if (data->args.hipModuleLoadDataEx.optionsValues == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleLoadDataEx.optionsValues__val;
    break;
    case HIP_API_ID_hipRuntimeGetVersion:
      if (data->args.hipRuntimeGetVersion.runtimeVersion == NULL) oss << "NULL";
      else oss << data->args.hipRuntimeGetVersion.runtimeVersion__val;
    break;
    case HIP_API_ID_hipHostFree:
      oss << data->args.hipHostFree.ptr;
    break;
    case HIP_API_ID_hipDeviceGetP2PAttribute:
      if (data->args.hipDeviceGetP2PAttribute.value == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGetP2PAttribute.value__val;
      oss << ", " << data->args.hipDeviceGetP2PAttribute.attr;
      oss << ", " << data->args.hipDeviceGetP2PAttribute.srcDevice;
      oss << ", " << data->args.hipDeviceGetP2PAttribute.dstDevice;
    break;
    case HIP_API_ID_hipMemcpyPeerAsync:
      oss << data->args.hipMemcpyPeerAsync.dst;
      oss << ", " << data->args.hipMemcpyPeerAsync.dstDeviceId;
      oss << ", " << data->args.hipMemcpyPeerAsync.src;
      oss << ", " << data->args.hipMemcpyPeerAsync.srcDevice;
      oss << ", " << data->args.hipMemcpyPeerAsync.sizeBytes;
      oss << ", " << data->args.hipMemcpyPeerAsync.stream;
    break;
    case HIP_API_ID_hipGetDeviceProperties:
      if (data->args.hipGetDeviceProperties.props == NULL) oss << "NULL";
      else oss << data->args.hipGetDeviceProperties.props__val;
      oss << ", " << data->args.hipGetDeviceProperties.device;
    break;
    case HIP_API_ID_hipDeviceGet:
      if (data->args.hipDeviceGet.device == NULL) oss << "NULL";
      else oss << data->args.hipDeviceGet.device__val;
      oss << ", " << data->args.hipDeviceGet.ordinal;
    break;
    case HIP_API_ID_hipFreeArray:
      if (data->args.hipFreeArray.array == NULL) oss << "NULL";
      else oss << data->args.hipFreeArray.array__val;
    break;
    case HIP_API_ID_hipEventElapsedTime:
      if (data->args.hipEventElapsedTime.ms == NULL) oss << "NULL";
      else oss << data->args.hipEventElapsedTime.ms__val;
      oss << ", " << data->args.hipEventElapsedTime.start;
      oss << ", " << data->args.hipEventElapsedTime.stop;
    break;
    case HIP_API_ID_hipDevicePrimaryCtxRelease:
      oss << data->args.hipDevicePrimaryCtxRelease.dev;
    break;
    case HIP_API_ID_hipHostGetDevicePointer:
      if (data->args.hipHostGetDevicePointer.devPtr == NULL) oss << "NULL";
      else oss << data->args.hipHostGetDevicePointer.devPtr__val;
      oss << ", " << data->args.hipHostGetDevicePointer.hstPtr;
      oss << ", " << data->args.hipHostGetDevicePointer.flags;
    break;
    case HIP_API_ID_hipMemRangeGetAttributes:
      if (data->args.hipMemRangeGetAttributes.data == NULL) oss << "NULL";
      else oss << data->args.hipMemRangeGetAttributes.data__val;
      if (data->args.hipMemRangeGetAttributes.data_sizes == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMemRangeGetAttributes.data_sizes__val;
      if (data->args.hipMemRangeGetAttributes.attributes == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipMemRangeGetAttributes.attributes__val;
      oss << ", " << data->args.hipMemRangeGetAttributes.num_attributes;
      oss << ", " << data->args.hipMemRangeGetAttributes.dev_ptr;
      oss << ", " << data->args.hipMemRangeGetAttributes.count;
    break;
    case HIP_API_ID_hipMemcpyParam2D:
      if (data->args.hipMemcpyParam2D.pCopy == NULL) oss << "NULL";
      else oss << data->args.hipMemcpyParam2D.pCopy__val;
    break;
    case HIP_API_ID_hipDevicePrimaryCtxReset:
      oss << data->args.hipDevicePrimaryCtxReset.dev;
    break;
    case HIP_API_ID_hipModuleGetFunction:
      if (data->args.hipModuleGetFunction.function == NULL) oss << "NULL";
      else oss << data->args.hipModuleGetFunction.function__val;
      oss << ", " << data->args.hipModuleGetFunction.module;
      if (data->args.hipModuleGetFunction.kname == NULL) oss << ", NULL";
      else oss << ", " << data->args.hipModuleGetFunction.kname__val;
    break;
    case HIP_API_ID_hipMemsetD32Async:
      oss << data->args.hipMemsetD32Async.dst;
      oss << ", " << data->args.hipMemsetD32Async.value;
      oss << ", " << data->args.hipMemsetD32Async.count;
      oss << ", " << data->args.hipMemsetD32Async.stream;
    break;
    case HIP_API_ID_hipGetDevice:
      if (data->args.hipGetDevice.deviceId == NULL) oss << "NULL";
      else oss << data->args.hipGetDevice.deviceId__val;
    break;
    case HIP_API_ID_hipGetDeviceCount:
      if (data->args.hipGetDeviceCount.count == NULL) oss << "NULL";
      else oss << data->args.hipGetDeviceCount.count__val;
    break;
    case HIP_API_ID_hipIpcOpenEventHandle:
      if (data->args.hipIpcOpenEventHandle.event == NULL) oss << "NULL";
      else oss << data->args.hipIpcOpenEventHandle.event__val;
      oss << ", " << data->args.hipIpcOpenEventHandle.handle;
    break;
    default: oss << "unknown";
  };
  return oss.str();
}

const hip_api_id_t* hip_api_table(){
	return all_hip_api_func;
}

uint32_t GetHIPApiSize() {
	return sizeof(all_hip_api_func)/sizeof(hip_api_id_t);
}