#ifndef INC_ROCTRACER_HIP_AUX_H_
#define INC_ROCTRACER_HIP_AUX_H_

#ifdef __cplusplus
#include <iostream>

inline std::ostream& operator<<(std::ostream& out, const unsigned char& v) {
  out  << (unsigned int)v;
  return out;
}

inline std::ostream& operator<<(std::ostream& out, const char& v) {
  out  << (unsigned char)v;
  return out;
}
const char* GetHIPApiName(const uint32_t& id);
#endif  
#include <hip_ostream_ops.h>
#include <hip/hip_runtime.h>
#include <hip/hcc_detail/hip_prof_str.h>

#ifdef __cplusplus
extern "C" {
#endif  

typedef enum hip_api_id_t roctracer_hip_api_cid_t;

#ifdef __cplusplus
}  
#endif  

#endif  