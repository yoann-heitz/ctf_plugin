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

#ifndef INC_ROCTRACER_HSA_AUX_H_
#define INC_ROCTRACER_HSA_AUX_H_

#ifdef __cplusplus
#include <hsa_api_trace.h>

namespace roctracer
{
    namespace hsa_support
    {
        struct ops_properties_t;
    }; // namespace hsa_support
    typedef hsa_support::ops_properties_t hsa_ops_properties_t;
}; // namespace roctracer

#include <hsa_ostream_ops.h>
std::ostream &operator<<(std::ostream &out, const hsa_amd_memory_pool_t &v);
std::ostream &operator<<(std::ostream &out, const hsa_ext_image_t &v);
std::ostream &operator<<(std::ostream &out, const hsa_ext_sampler_t &v);
const char *GetHSAApiName(const uint32_t &id);

#endif //! __cplusplus

#include <hsa_prof_str.h>
#endif // INC_ROCTRACER_HSA_H_AUX_