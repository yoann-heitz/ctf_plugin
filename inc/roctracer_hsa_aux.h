#ifndef INC_ROCTRACER_HSA_AUX_H_
#define INC_ROCTRACER_HSA_AUX_H_

#ifdef __cplusplus
#include <hsa_api_trace.h>

namespace roctracer {
namespace hsa_support {
struct ops_properties_t;
}; // namespace hsa_support
typedef hsa_support::ops_properties_t hsa_ops_properties_t;
}; // namespace roctracer

#include <hsa_ostream_ops.h>
std::ostream& operator<<(std::ostream& out, const hsa_amd_memory_pool_t& v);
std::ostream& operator<<(std::ostream& out, const hsa_ext_image_t& v);
std::ostream& operator<<(std::ostream& out, const hsa_ext_sampler_t& v);
const char* GetHSAApiName(const uint32_t& id);

#endif //! __cplusplus

#include <hsa_prof_str.h>
#endif // INC_ROCTRACER_HSA_H_AUX_
