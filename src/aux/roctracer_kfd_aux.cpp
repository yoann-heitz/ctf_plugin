#include <stdint.h>
#include <roctracer_kfd.h>

const char* GetKFDApiName(const uint32_t& id){
	return roctracer::kfd_support::GetApiName(id);
};