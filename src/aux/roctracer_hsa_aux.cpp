#include <stdint.h>
#include <roctracer_cb_table.h>
#include <roctracer_hsa.h>

const char* GetHSAApiName(const uint32_t& id){
	return roctracer::hsa_support::GetApiName(id);
};