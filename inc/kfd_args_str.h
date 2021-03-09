#ifndef INC_KFD_ARGS_STR_H_
#define INC_KFD_ARGS_STR_H_
#include <roctracer_kfd_aux.h>

typedef std::pair<std::string, std::string> kfd_api_string_pair_t;
kfd_api_string_pair_t kfd_api_pair_of_args(uint32_t cid, kfd_api_data_t api_data);
const kfd_api_id_t* kfd_api_table();
uint32_t GetKFDApiSize();

#endif