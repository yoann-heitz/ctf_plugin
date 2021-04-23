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

#ifndef TRACER_H_
#define TRACER_H_

#include <sys/syscall.h>
#include <unistd.h>
#include <mutex>
#include <queue>
#include <iterator>
#include <sstream>

#include "barectf-platform-linux-fs.h"
#include "barectf.h"

#define MAX_SIZE 200

struct barectf_platform_linux_fs_ctx
{
	struct barectf_default_ctx ctx;
	FILE *fh;
	int simulate_full_backend;
	unsigned int full_backend_rand_lt;
	unsigned int full_backend_rand_max;
	uint64_t *clock_addr;
};

static inline uint32_t GetTid() { return syscall(__NR_gettid); }
static inline uint32_t GetPid() { return syscall(__NR_getpid); }

typedef uint64_t timestamp_t;
typedef struct barectf_platform_linux_fs_ctx **platform_array_t;
typedef struct barectf_default_ctx **ctx_array_t;

//Event structure and class comparison for priority queue
struct event_t
{
	uint64_t time;
	event_t(uint64_t time_s) : time(time_s) {}
};

enum event_phase
{
	BEGIN,
	END
};

class Compare
{
public:
	bool operator()(event_t *event1, event_t *event2)
	{
		return event1->time > event2->time;
	}
};

//Generic class for HSA/HIP/KFD/Kernels tracing
template <typename event_T>
class Tracer
{
protected:
	typedef std::priority_queue<event_T *, std::vector<event_T *>, Compare> *queue_array_t;
	uint32_t my_pid;
	const char *output_prefix;
	const char *trace_suffix;
	platform_array_t platform_array;
	ctx_array_t ctx_array;
	uint64_t *clock_array;
	uint32_t size;
	queue_array_t queue_array;

public:
	typedef void (*tracing_function)(event_T *event, struct barectf_default_ctx *ctx);
	Tracer(const char *prefix, const char *suffix);
	~Tracer();
	void add_stream();
	void add_queue();
	void callback(uint64_t begin, tracing_function function, event_T *new_event);
	void flush(tracing_function function);
};

#include <tracer.tpp>
#endif