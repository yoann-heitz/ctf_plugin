#ifndef INC_HSA_ARGS_STR_H_
#define INC_HSA_ARGS_STR_H_
#include <stdint.h>
#include <roctracer_hsa_aux.h>

typedef std::pair<std::string, std::string> hsa_api_string_pair_t;
hsa_api_string_pair_t hsa_api_pair_of_args(uint32_t cid, hsa_api_data_t api_data);
const hsa_api_id_t* hsa_api_table();
uint32_t GetHSAApiSize();
#endif