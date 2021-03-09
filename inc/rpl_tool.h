#ifndef RPL_TOOL_H_
#define RPL_TOOL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <sstream>
#include "rocprofiler.h"
#include <hsa_ext_amd.h>
#include "util/hsa_rsrc_factory.h"
#include "util/xml.h"
hsa_status_t rocprofiler_get_metrics(const rocprofiler_t* context);

static inline void check_env_var(const char* var_name, uint32_t& val) {
  const char* str = getenv(var_name);
  if (str != NULL ) val = atol(str);
}

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

std::string filtr_kernel_name(const std::string name);
#endif