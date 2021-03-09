#include "roctracer_hip.h"
const char* GetHIPApiName(const uint32_t& id){
	return hip_api_name(id);
}