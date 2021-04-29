#ifndef _BARECTF_H
#define _BARECTF_H

/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-2020 Philippe Proulx <pproulx@efficios.com>
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
 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *
 * The following code was generated by barectf v3.0.1
 * on 2021-04-29T07:31:55.151835.
 *
 * For more details, see <https://barectf.org/>.
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


#define barectf_trace_hip_activity_begin barectf_default_trace_hip_activity_begin
#define barectf_trace_hip_activity_end barectf_default_trace_hip_activity_end
#define barectf_trace_hip_api_begin barectf_default_trace_hip_api_begin
#define barectf_trace_hip_api_end barectf_default_trace_hip_api_end
#define barectf_trace_hip_function_name barectf_default_trace_hip_function_name
#define barectf_trace_hsa_activity barectf_default_trace_hsa_activity
#define barectf_trace_hsa_begin barectf_default_trace_hsa_begin
#define barectf_trace_hsa_end barectf_default_trace_hsa_end
#define barectf_trace_hsa_function_name barectf_default_trace_hsa_function_name
#define barectf_trace_kernel_event_begin barectf_default_trace_kernel_event_begin
#define barectf_trace_kernel_event_end barectf_default_trace_kernel_event_end
#define barectf_trace_kfd_begin barectf_default_trace_kfd_begin
#define barectf_trace_kfd_end barectf_default_trace_kfd_end
#define barectf_trace_kfd_function_name barectf_default_trace_kfd_function_name
#define barectf_trace_metrics_table barectf_default_trace_metrics_table
#define barectf_trace_metrics_values barectf_default_trace_metrics_values

struct barectf_ctx;

uint32_t barectf_packet_size(const void *vctx);
int barectf_packet_is_full(const void *vctx);
int barectf_packet_is_empty(const void *vctx);
uint32_t barectf_packet_events_discarded(const void *vctx);
uint32_t barectf_discarded_event_records_count(const void * const vctx);
uint8_t *barectf_packet_buf(const void *vctx);
uint8_t *barectf_packet_buf_addr(const void * const vctx);
void barectf_packet_set_buf(void *vctx, uint8_t *buf, uint32_t buf_size);
uint32_t barectf_packet_buf_size(const void *vctx);
int barectf_packet_is_open(const void *vctx);
int barectf_is_in_tracing_section(const void *vctx);
volatile const int *barectf_is_in_tracing_section_ptr(const void *vctx);
int barectf_is_tracing_enabled(const void *vctx);
void barectf_enable_tracing(void *vctx, int enable);

/* barectf platform callbacks */
struct barectf_platform_callbacks {
	/* Clock source callbacks */
	uint64_t (*default_clock_get_value)(void *);

	/* Is the back end full? */
	int (*is_backend_full)(void *);

	/* Open packet */
	void (*open_packet)(void *);

	/* Close packet */
	void (*close_packet)(void *);
};

/* Common barectf context */
struct barectf_ctx {
	/* Platform callbacks */
	struct barectf_platform_callbacks cbs;

	/* Platform data (passed to callbacks) */
	void *data;

	/* Output buffer (will contain a CTF binary packet) */
	uint8_t *buf;

	/* Packet's total size (bits) */
	uint32_t packet_size;

	/* Packet's content size (bits) */
	uint32_t content_size;

	/* Current position from beginning of packet (bits) */
	uint32_t at;

	/* Size of packet header + context fields (content offset) */
	uint32_t off_content;

	/* Discarded event records counter snapshot */
	uint32_t events_discarded;

	/* Current packet is open? */
	int packet_is_open;

	/* In tracing code? */
	volatile int in_tracing_section;

	/* Tracing is enabled? */
	volatile int is_tracing_enabled;

	/* Use current/last event record timestamp when opening/closing packets */
	int use_cur_last_event_ts;
};

/* Context for data stream type `default` */
struct barectf_default_ctx {
	/* Parent */
	struct barectf_ctx parent;

	/* Config-specific members follow */
	uint32_t off_ph_magic;
	uint32_t off_ph_stream_id;
	uint32_t off_pc_packet_size;
	uint32_t off_pc_content_size;
	uint32_t off_pc_timestamp_begin;
	uint32_t off_pc_timestamp_end;
	uint32_t off_pc_events_discarded;
	uint64_t cur_last_event_ts;
};

/* Initialize context */
void barectf_init(void *vctx,
	uint8_t *buf, uint32_t buf_size,
	const struct barectf_platform_callbacks cbs, void *data);

/* Open packet for data stream type `default` */
void barectf_default_open_packet(
	struct barectf_default_ctx *sctx);

/* Close packet for data stream type `default` */
void barectf_default_close_packet(struct barectf_default_ctx *sctx);

/* Trace (data stream type `default`, event record type `hip_activity_begin`) */
void barectf_default_trace_hip_activity_begin(struct barectf_default_ctx *sctx,
	uint32_t p_device_id,
	uint64_t p_queue_id,
	const char *p_name,
	uint64_t p_correlation_id,
	uint32_t p_pid);

/* Trace (data stream type `default`, event record type `hip_activity_end`) */
void barectf_default_trace_hip_activity_end(struct barectf_default_ctx *sctx,
	uint64_t p_correlation_id);

/* Trace (data stream type `default`, event record type `hip_api_begin`) */
void barectf_default_trace_hip_api_begin(struct barectf_default_ctx *sctx,
	uint32_t p_cid,
	uint32_t p_pid,
	uint32_t p_tid,
	const char *p_args);

/* Trace (data stream type `default`, event record type `hip_api_end`) */
void barectf_default_trace_hip_api_end(struct barectf_default_ctx *sctx,
	uint32_t p_tid);

/* Trace (data stream type `default`, event record type `hip_function_name`) */
void barectf_default_trace_hip_function_name(struct barectf_default_ctx *sctx,
	uint64_t p_correlation_id,
	const char *p_name);

/* Trace (data stream type `default`, event record type `hsa_activity`) */
void barectf_default_trace_hsa_activity(struct barectf_default_ctx *sctx,
	uint32_t p_pid,
	uint64_t p_index);

/* Trace (data stream type `default`, event record type `hsa_begin`) */
void barectf_default_trace_hsa_begin(struct barectf_default_ctx *sctx,
	uint32_t p_cid,
	uint32_t p_pid,
	uint32_t p_tid,
	const char *p_args,
	const char *p_retval);

/* Trace (data stream type `default`, event record type `hsa_end`) */
void barectf_default_trace_hsa_end(struct barectf_default_ctx *sctx,
	uint32_t p_tid);

/* Trace (data stream type `default`, event record type `hsa_function_name`) */
void barectf_default_trace_hsa_function_name(struct barectf_default_ctx *sctx,
	uint64_t p_correlation_id,
	const char *p_name);

/* Trace (data stream type `default`, event record type `kernel_event_begin`) */
void barectf_default_trace_kernel_event_begin(struct barectf_default_ctx *sctx,
	uint32_t p_dispatch,
	uint32_t p_gpu_id,
	uint32_t p_queue_id,
	uint64_t p_queue_index,
	uint32_t p_pid,
	uint32_t p_tid,
	uint32_t p_grd,
	uint32_t p_wgr,
	uint32_t p_lds,
	uint32_t p_scr,
	uint32_t p_vgpr,
	uint32_t p_sgpr,
	uint32_t p_fbar,
	uint64_t p_sig,
	uint64_t p_obj,
	const char *p_kernel_name,
	uint64_t p_dispatch_time,
	uint64_t p_complete_time);

/* Trace (data stream type `default`, event record type `kernel_event_end`) */
void barectf_default_trace_kernel_event_end(struct barectf_default_ctx *sctx,
	uint32_t p_dispatch,
	uint32_t p_gpu_id);

/* Trace (data stream type `default`, event record type `kfd_begin`) */
void barectf_default_trace_kfd_begin(struct barectf_default_ctx *sctx,
	uint32_t p_cid,
	uint32_t p_pid,
	uint32_t p_tid,
	const char *p_args,
	const char *p_retval);

/* Trace (data stream type `default`, event record type `kfd_end`) */
void barectf_default_trace_kfd_end(struct barectf_default_ctx *sctx,
	uint32_t p_tid);

/* Trace (data stream type `default`, event record type `kfd_function_name`) */
void barectf_default_trace_kfd_function_name(struct barectf_default_ctx *sctx,
	uint64_t p_correlation_id,
	const char *p_name);

/* Trace (data stream type `default`, event record type `metrics_table`) */
void barectf_default_trace_metrics_table(struct barectf_default_ctx *sctx,
	uint32_t p___metrics_names_len,
	const char * const *p_metrics_names);

/* Trace (data stream type `default`, event record type `metrics_values`) */
void barectf_default_trace_metrics_values(struct barectf_default_ctx *sctx,
	uint32_t p_dispatch,
	uint32_t p_gpu_id,
	uint32_t p___metrics_len,
	const uint64_t *p_metrics);

#ifdef __cplusplus
}
#endif

#endif /* _BARECTF_H */
