/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Yoann Heitz <yoann.heitz@polymtl.ca>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ROCPROFILER_TOOL_H_
#define ROCPROFILER_TOOL_H_
#include "rocprofiler.h"
#include <hsa_ext_amd.h>
#include "util/hsa_rsrc_factory.h"
#include "util/xml.h"

struct kernel_properties_t
{
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

struct context_entry_t
{
	bool valid;
	bool active;
	uint32_t index;
	hsa_agent_t agent;
	rocprofiler_group_t group;
	rocprofiler_feature_t *features;
	unsigned feature_count;
	rocprofiler_callback_data_t data;
	kernel_properties_t kernel_properties;
	HsaRsrcFactory::symbols_map_it_t kernel_name_it;
	FILE *file_handle;
};

#endif