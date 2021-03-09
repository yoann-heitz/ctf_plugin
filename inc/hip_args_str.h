#ifndef INC_HIP_ARGS_STR_H_
#define INC_HIP_ARGS_STR_H_
#include <stdint.h>
#include <roctracer_hip_aux.h>

std::string hip_api_arguments(uint32_t cid, hip_api_data_t* api_data);
const hip_api_id_t* hip_api_table();
uint32_t GetHIPApiSize();
#endif