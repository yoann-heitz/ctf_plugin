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

#include <fstream>
#include <unistd.h>
#include <sstream>
#include <mutex>

#include "ext/prof_protocol.h"
#include "ext/hsa_rt_utils.hpp"

#include "barectf-platform-linux-fs.h"
#include "barectf.h"

#include "tracer.h"
#include "roctracer_tracers.h"

#include "roctracer_hsa_aux.h"
#include "roctracer_hip_aux.h"
#include "roctracer_kfd_aux.h"
#include "hsa_args_str.h"
#include "kfd_args_str.h"
#include "hip_args_str.h"

//Objects for CID/Names tables generation
barectf_platform_linux_fs_ctx *tables_platform_ctx;
barectf_default_ctx *tables_ctx;
uint64_t tables_clock = 0;

bool rtr_plugin_initialized = false;
bool hsa_api_trace = false;
bool hsa_activity_trace = false;
bool kfd_api_trace = false;
bool hip_api_trace = false;
bool hip_activity_trace = false;

//Tracing objects for HSA/HIP APIs and activity
HSA_API_Tracer *hsa_api_tracer;
HSA_Activity_Tracer *hsa_activity_tracer;
HIP_API_Tracer *hip_api_tracer;
HIP_Activity_Tracer *hip_activity_tracer;

//Tracing objects for KFD API
const char *output_dir;
int nb_kfd_thread = 0;
thread_local bool kfd_thread_initialized = false;
thread_local int kfd_class_idx;
std::mutex kfd_mutex;
typedef KFD_API_Tracer **kfd_tracer_array_t;
kfd_tracer_array_t kfd_tracer_array;
hsa_rt_utils::Timer **timer_ptr;
thread_local uint64_t kfd_begin_timestamp = 0;
static thread_local bool in_kfd_api_callback = false;

//Create the table that associates cids to function names and write it in a stream
void write_table(barectf_default_ctx *ctx, activity_domain_t domain)
{
	switch (domain)
	{
	case (ACTIVITY_DOMAIN_HSA_API):
	{
		const hsa_api_id_t *hsa_table = hsa_api_table();
		uint32_t hsa_table_size = GetHSAApiSize();
		for (int i = 0; i < hsa_table_size; i++)
		{
			barectf_trace_hsa_function_name(ctx, hsa_table[i], GetHSAApiName(hsa_table[i]));
		}
		break;
	}
	case (ACTIVITY_DOMAIN_KFD_API):
	{
		const kfd_api_id_t *kfd_table = kfd_api_table();
		int kfd_table_size = GetKFDApiSize();
		for (int i = 0; i < kfd_table_size; i++)
		{
			barectf_trace_kfd_function_name(ctx, kfd_table[i], GetKFDApiName(kfd_table[i]));
		}
		break;
	}
	case (ACTIVITY_DOMAIN_HIP_API):
	{
		const hip_api_id_t *hip_table = hip_api_table();
		int hip_table_size = GetHIPApiSize();
		for (int i = 0; i < hip_table_size; i++)
		{
			barectf_trace_hip_function_name(ctx, hip_table[i], GetHIPApiName(hip_table[i]));
		}
		break;
	}
	default:
		break;
	}
}

//Initialize tracing for some APIS
extern "C" void load_ctf_lib(const char *output_prefix, activity_domain_t domain, void *data)
{
	if (!rtr_plugin_initialized)
	{
		rtr_plugin_initialized = true;
		std::stringstream ss;
		ss << output_prefix << "/CTF_trace/strings_association_stream";
		tables_platform_ctx = barectf_platform_linux_fs_init(512, ss.str().c_str(), 0, 0, 0, &tables_clock);
		tables_ctx = barectf_platform_linux_fs_get_barectf_ctx(tables_platform_ctx);
	}

	switch (domain)
	{
	case ACTIVITY_DOMAIN_HSA_API:
	{
		if (hsa_api_trace)
		{
			printf("HSA API tracing already rtr_plugin_initialized\n");
		}
		else
		{
			hsa_api_tracer = new HSA_API_Tracer(output_prefix, "hsa_api_");
			hsa_api_trace = true;
			write_table(tables_ctx, ACTIVITY_DOMAIN_HSA_API);
		}
		break;
	}
	case ACTIVITY_DOMAIN_HSA_OPS:
	{
		if (hsa_activity_trace)
		{
			printf("HSA activity tracing already rtr_plugin_initialized\n");
		}
		else
		{
			hsa_activity_tracer = new HSA_Activity_Tracer(output_prefix, "hsa_activity_");
			hsa_activity_trace = true;
		}
		break;
	}
	case ACTIVITY_DOMAIN_KFD_API:
	{
		if (kfd_api_trace)
		{
			printf("kfd_api tracing already rtr_plugin_initialized\n");
		}
		else
		{
			timer_ptr = (reinterpret_cast<hsa_rt_utils::Timer **>(data));
			output_dir = output_prefix;
			kfd_api_trace = true;
			write_table(tables_ctx, ACTIVITY_DOMAIN_KFD_API);
		}
		break;
	}
	case ACTIVITY_DOMAIN_HIP_API:
	{
		if (hip_api_trace)
		{
			printf("hip_api tracing already rtr_plugin_initialized\n");
		}
		else
		{
			hip_api_tracer = new HIP_API_Tracer(output_prefix, "hip_api_");
			hip_api_trace = true;
			write_table(tables_ctx, ACTIVITY_DOMAIN_HIP_API);
		}
		break;
	}
	case ACTIVITY_DOMAIN_HCC_OPS:
	{
		if (hip_activity_trace)
		{
			printf("hip_activity tracing already rtr_plugin_initialized\n");
		}
		else
		{
			hip_activity_tracer = new HIP_Activity_Tracer(output_prefix, "hip_activity_");
			hip_activity_trace = true;
		}
		break;
	}
	default:
		printf("Domain unrecognized\n");
		break;
	}
}

//Flush the priority queues
extern "C" void flush_ctf()
{
	if (hsa_api_trace)
	{
		hsa_api_tracer->flush((Tracer<hsa_api_event_t>::tracing_function)trace_hsa_api);
	}
	if (hsa_activity_trace)
	{
		hsa_activity_tracer->flush((Tracer<hsa_activity_event_t>::tracing_function)trace_hsa_activity);
	}
	if (kfd_api_trace)
	{
		for (int i = 0; i < nb_kfd_thread; i++)
		{
			kfd_tracer_array[i]->flush((Tracer<kfd_api_event_t>::tracing_function)trace_kfd_api);
		}
	}
	if (hip_api_trace)
	{
		hip_api_tracer->flush((Tracer<hip_api_event_t>::tracing_function)trace_hip_api);
	}
	if (hip_activity_trace)
	{
		hip_activity_tracer->flush((Tracer<hip_activity_event_t>::tracing_function)trace_hip_activity);
	}
}

//Flush then unload the plugin
extern "C" void unload_ctf_lib()
{
	flush_ctf();
	if (rtr_plugin_initialized)
	{
		if (hsa_api_trace)
		{
			delete hsa_api_tracer;
		}
		if (hsa_activity_trace)
		{
			delete hsa_activity_tracer;
		}
		if (kfd_api_trace)
		{
			for (int i = 0; i < nb_kfd_thread; i++)
			{
				delete kfd_tracer_array[i];
			}
			delete[] kfd_tracer_array;
		}
		if (hip_api_trace)
		{
			delete hip_api_tracer;
		}
		if (hip_activity_trace)
		{
			delete hip_activity_tracer;
		}
	}
	barectf_platform_linux_fs_fini(tables_platform_ctx);
}

//Functions that will be loaded in tool files and call tracing methodes
extern "C" void hsa_activity_callback(
	uint32_t op,
	activity_record_t *record,
	void *arg)
{
	hsa_activity_tracer->hsa_activity_callback(op, record, arg);
}

extern "C" void hsa_api_flush_cb(hsa_api_trace_entry_t *entry)
{
	hsa_api_tracer->hsa_api_flush_cb(entry);
}

void add_kfd_class()
{
	if (nb_kfd_thread > 0)
	{
		kfd_tracer_array_t kfd_tracer_array2 = new KFD_API_Tracer *[nb_kfd_thread + 1];
		std::copy(kfd_tracer_array, kfd_tracer_array + nb_kfd_thread, kfd_tracer_array2);
		delete[] kfd_tracer_array;
		kfd_tracer_array = kfd_tracer_array2;
	}
	else
	{
		kfd_tracer_array = new KFD_API_Tracer *[nb_kfd_thread + 1];
	}
}

extern "C" void kfd_api_callback(
	uint32_t domain,
	uint32_t cid,
	const void *callback_data,
	void *arg)
{
	if (in_kfd_api_callback)
		return;
	in_kfd_api_callback = true;
	if (!kfd_thread_initialized)
	{
		kfd_mutex.lock();
		add_kfd_class();
		kfd_thread_initialized = true;
		kfd_class_idx = nb_kfd_thread;
		std::stringstream ss;
		ss << "kfd_api_" << GetTid() << "_";
		const char *suffix = strdup(ss.str().c_str());
		kfd_tracer_array[kfd_class_idx] = new KFD_API_Tracer(output_dir, suffix);
		nb_kfd_thread++;
		kfd_mutex.unlock();
	}
	const kfd_api_data_t *data = reinterpret_cast<const kfd_api_data_t *>(callback_data);
	if (data->phase == ACTIVITY_API_PHASE_ENTER)
	{
		kfd_begin_timestamp = (*timer_ptr)->timestamp_fn_ns();
	}
	else
	{
		uint64_t kfd_end_timestamp = (*timer_ptr)->timestamp_fn_ns();
		kfd_tracer_array[kfd_class_idx]->kfd_api_flush_cb(kfd_begin_timestamp, kfd_end_timestamp, cid, data);
	}
	in_kfd_api_callback = false;
}

extern "C" void hip_api_flush_cb(hip_api_trace_entry_t *entry)
{
	hip_api_tracer->hip_api_flush_cb(entry);
}

extern "C" void hip_activity_callback(const roctracer_record_t *record, const char *name)
{
	hip_activity_tracer->hip_activity_callback(record, name);
}
