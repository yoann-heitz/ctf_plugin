#ifndef RPL_TOOL_H_
#define RPL_TOOL_H_
#include "rocprofiler.h"
#include <hsa_ext_amd.h>
#include "util/hsa_rsrc_factory.h"
#include "util/xml.h"

struct kernel_properties_t {
  uint32_t grid_size;
  uint32_t workgroup_size;
  uint32_t lds_size;
  uint32_t scratch_size;
  uint32_t vgpr_count;
  uint32_t sgpr_count;
  uint32_t fbarrier_count;
  hsa_signal_t signal;
  uint64_t object;
};

struct context_entry_t {
  bool valid;
  bool active;
  uint32_t index;
  hsa_agent_t agent;
  rocprofiler_group_t group;
  rocprofiler_feature_t* features;
  unsigned feature_count;
  rocprofiler_callback_data_t data;
  kernel_properties_t kernel_properties;
  HsaRsrcFactory::symbols_map_it_t kernel_name_it;
  FILE* file_handle;
};

#endif