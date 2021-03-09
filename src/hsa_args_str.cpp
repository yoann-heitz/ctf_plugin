#include <roctracer_hsa_aux.h>
#include <hsa_args_str.h>
#include <sstream>

static const hsa_api_id_t all_hsa_api_func[] = { 
	HSA_API_ID_hsa_init,
	HSA_API_ID_hsa_shut_down,
	HSA_API_ID_hsa_system_get_info,
	HSA_API_ID_hsa_system_extension_supported,
	HSA_API_ID_hsa_system_get_extension_table,
	HSA_API_ID_hsa_iterate_agents,
	HSA_API_ID_hsa_agent_get_info,
	HSA_API_ID_hsa_queue_create,
	HSA_API_ID_hsa_soft_queue_create,
	HSA_API_ID_hsa_queue_destroy,
	HSA_API_ID_hsa_queue_inactivate,
	HSA_API_ID_hsa_queue_load_read_index_scacquire,
	HSA_API_ID_hsa_queue_load_read_index_relaxed,
	HSA_API_ID_hsa_queue_load_write_index_scacquire,
	HSA_API_ID_hsa_queue_load_write_index_relaxed,
	HSA_API_ID_hsa_queue_store_write_index_relaxed,
	HSA_API_ID_hsa_queue_store_write_index_screlease,
	HSA_API_ID_hsa_queue_cas_write_index_scacq_screl,
	HSA_API_ID_hsa_queue_cas_write_index_scacquire,
	HSA_API_ID_hsa_queue_cas_write_index_relaxed,
	HSA_API_ID_hsa_queue_cas_write_index_screlease,
	HSA_API_ID_hsa_queue_add_write_index_scacq_screl,
	HSA_API_ID_hsa_queue_add_write_index_scacquire,
	HSA_API_ID_hsa_queue_add_write_index_relaxed,
	HSA_API_ID_hsa_queue_add_write_index_screlease,
	HSA_API_ID_hsa_queue_store_read_index_relaxed,
	HSA_API_ID_hsa_queue_store_read_index_screlease,
	HSA_API_ID_hsa_agent_iterate_regions,
	HSA_API_ID_hsa_region_get_info,
	HSA_API_ID_hsa_agent_get_exception_policies,
	HSA_API_ID_hsa_agent_extension_supported,
	HSA_API_ID_hsa_memory_register,
	HSA_API_ID_hsa_memory_deregister,
	HSA_API_ID_hsa_memory_allocate,
	HSA_API_ID_hsa_memory_free,
	HSA_API_ID_hsa_memory_copy,
	HSA_API_ID_hsa_memory_assign_agent,
	HSA_API_ID_hsa_signal_create,
	HSA_API_ID_hsa_signal_destroy,
	HSA_API_ID_hsa_signal_load_relaxed,
	HSA_API_ID_hsa_signal_load_scacquire,
	HSA_API_ID_hsa_signal_store_relaxed,
	HSA_API_ID_hsa_signal_store_screlease,
	HSA_API_ID_hsa_signal_wait_relaxed,
	HSA_API_ID_hsa_signal_wait_scacquire,
	HSA_API_ID_hsa_signal_and_relaxed,
	HSA_API_ID_hsa_signal_and_scacquire,
	HSA_API_ID_hsa_signal_and_screlease,
	HSA_API_ID_hsa_signal_and_scacq_screl,
	HSA_API_ID_hsa_signal_or_relaxed,
	HSA_API_ID_hsa_signal_or_scacquire,
	HSA_API_ID_hsa_signal_or_screlease,
	HSA_API_ID_hsa_signal_or_scacq_screl,
	HSA_API_ID_hsa_signal_xor_relaxed,
	HSA_API_ID_hsa_signal_xor_scacquire,
	HSA_API_ID_hsa_signal_xor_screlease,
	HSA_API_ID_hsa_signal_xor_scacq_screl,
	HSA_API_ID_hsa_signal_exchange_relaxed,
	HSA_API_ID_hsa_signal_exchange_scacquire,
	HSA_API_ID_hsa_signal_exchange_screlease,
	HSA_API_ID_hsa_signal_exchange_scacq_screl,
	HSA_API_ID_hsa_signal_add_relaxed,
	HSA_API_ID_hsa_signal_add_scacquire,
	HSA_API_ID_hsa_signal_add_screlease,
	HSA_API_ID_hsa_signal_add_scacq_screl,
	HSA_API_ID_hsa_signal_subtract_relaxed,
	HSA_API_ID_hsa_signal_subtract_scacquire,
	HSA_API_ID_hsa_signal_subtract_screlease,
	HSA_API_ID_hsa_signal_subtract_scacq_screl,
	HSA_API_ID_hsa_signal_cas_relaxed,
	HSA_API_ID_hsa_signal_cas_scacquire,
	HSA_API_ID_hsa_signal_cas_screlease,
	HSA_API_ID_hsa_signal_cas_scacq_screl,
	HSA_API_ID_hsa_isa_from_name,
	HSA_API_ID_hsa_isa_get_info,
	HSA_API_ID_hsa_isa_compatible,
	HSA_API_ID_hsa_code_object_serialize,
	HSA_API_ID_hsa_code_object_deserialize,
	HSA_API_ID_hsa_code_object_destroy,
	HSA_API_ID_hsa_code_object_get_info,
	HSA_API_ID_hsa_code_object_get_symbol,
	HSA_API_ID_hsa_code_symbol_get_info,
	HSA_API_ID_hsa_code_object_iterate_symbols,
	HSA_API_ID_hsa_executable_create,
	HSA_API_ID_hsa_executable_destroy,
	HSA_API_ID_hsa_executable_load_code_object,
	HSA_API_ID_hsa_executable_freeze,
	HSA_API_ID_hsa_executable_get_info,
	HSA_API_ID_hsa_executable_global_variable_define,
	HSA_API_ID_hsa_executable_agent_global_variable_define,
	HSA_API_ID_hsa_executable_readonly_variable_define,
	HSA_API_ID_hsa_executable_validate,
	HSA_API_ID_hsa_executable_get_symbol,
	HSA_API_ID_hsa_executable_symbol_get_info,
	HSA_API_ID_hsa_executable_iterate_symbols,
	HSA_API_ID_hsa_status_string,
	HSA_API_ID_hsa_extension_get_name,
	HSA_API_ID_hsa_system_major_extension_supported,
	HSA_API_ID_hsa_system_get_major_extension_table,
	HSA_API_ID_hsa_agent_major_extension_supported,
	HSA_API_ID_hsa_cache_get_info,
	HSA_API_ID_hsa_agent_iterate_caches,
	HSA_API_ID_hsa_signal_silent_store_relaxed,
	HSA_API_ID_hsa_signal_silent_store_screlease,
	HSA_API_ID_hsa_signal_group_create,
	HSA_API_ID_hsa_signal_group_destroy,
	HSA_API_ID_hsa_signal_group_wait_any_scacquire,
	HSA_API_ID_hsa_signal_group_wait_any_relaxed,
	HSA_API_ID_hsa_agent_iterate_isas,
	HSA_API_ID_hsa_isa_get_info_alt,
	HSA_API_ID_hsa_isa_get_exception_policies,
	HSA_API_ID_hsa_isa_get_round_method,
	HSA_API_ID_hsa_wavefront_get_info,
	HSA_API_ID_hsa_isa_iterate_wavefronts,
	HSA_API_ID_hsa_code_object_get_symbol_from_name,
	HSA_API_ID_hsa_code_object_reader_create_from_file,
	HSA_API_ID_hsa_code_object_reader_create_from_memory,
	HSA_API_ID_hsa_code_object_reader_destroy,
	HSA_API_ID_hsa_executable_create_alt,
	HSA_API_ID_hsa_executable_load_program_code_object,
	HSA_API_ID_hsa_executable_load_agent_code_object,
	HSA_API_ID_hsa_executable_validate_alt,
	HSA_API_ID_hsa_executable_get_symbol_by_name,
	HSA_API_ID_hsa_executable_iterate_agent_symbols,
	HSA_API_ID_hsa_executable_iterate_program_symbols,
	HSA_API_ID_hsa_amd_coherency_get_type,
	HSA_API_ID_hsa_amd_coherency_set_type,
	HSA_API_ID_hsa_amd_profiling_set_profiler_enabled,
	HSA_API_ID_hsa_amd_profiling_async_copy_enable,
	HSA_API_ID_hsa_amd_profiling_get_dispatch_time,
	HSA_API_ID_hsa_amd_profiling_get_async_copy_time,
	HSA_API_ID_hsa_amd_profiling_convert_tick_to_system_domain,
	HSA_API_ID_hsa_amd_signal_async_handler,
	HSA_API_ID_hsa_amd_async_function,
	HSA_API_ID_hsa_amd_signal_wait_any,
	HSA_API_ID_hsa_amd_queue_cu_set_mask,
	HSA_API_ID_hsa_amd_memory_pool_get_info,
	HSA_API_ID_hsa_amd_agent_iterate_memory_pools,
	HSA_API_ID_hsa_amd_memory_pool_allocate,
	HSA_API_ID_hsa_amd_memory_pool_free,
	HSA_API_ID_hsa_amd_memory_async_copy,
	HSA_API_ID_hsa_amd_agent_memory_pool_get_info,
	HSA_API_ID_hsa_amd_agents_allow_access,
	HSA_API_ID_hsa_amd_memory_pool_can_migrate,
	HSA_API_ID_hsa_amd_memory_migrate,
	HSA_API_ID_hsa_amd_memory_lock,
	HSA_API_ID_hsa_amd_memory_unlock,
	HSA_API_ID_hsa_amd_memory_fill,
	HSA_API_ID_hsa_amd_interop_map_buffer,
	HSA_API_ID_hsa_amd_interop_unmap_buffer,
	HSA_API_ID_hsa_amd_image_create,
	HSA_API_ID_hsa_amd_pointer_info,
	HSA_API_ID_hsa_amd_pointer_info_set_userdata,
	HSA_API_ID_hsa_amd_ipc_memory_create,
	HSA_API_ID_hsa_amd_ipc_memory_attach,
	HSA_API_ID_hsa_amd_ipc_memory_detach,
	HSA_API_ID_hsa_amd_signal_create,
	HSA_API_ID_hsa_amd_ipc_signal_create,
	HSA_API_ID_hsa_amd_ipc_signal_attach,
	HSA_API_ID_hsa_amd_register_system_event_handler,
	HSA_API_ID_hsa_amd_queue_intercept_create,
	HSA_API_ID_hsa_amd_queue_intercept_register,
	HSA_API_ID_hsa_amd_queue_set_priority,
	HSA_API_ID_hsa_amd_memory_async_copy_rect,
	HSA_API_ID_hsa_amd_runtime_queue_create_register,
	HSA_API_ID_hsa_amd_memory_lock_to_pool,
	HSA_API_ID_hsa_amd_register_deallocation_callback,
	HSA_API_ID_hsa_amd_deregister_deallocation_callback,
	HSA_API_ID_hsa_ext_image_get_capability,
	HSA_API_ID_hsa_ext_image_data_get_info,
	HSA_API_ID_hsa_ext_image_create,
	HSA_API_ID_hsa_ext_image_import,
	HSA_API_ID_hsa_ext_image_export,
	HSA_API_ID_hsa_ext_image_copy,
	HSA_API_ID_hsa_ext_image_clear,
	HSA_API_ID_hsa_ext_image_destroy,
	HSA_API_ID_hsa_ext_sampler_create,
	HSA_API_ID_hsa_ext_sampler_destroy,
	HSA_API_ID_hsa_ext_image_get_capability_with_layout,
	HSA_API_ID_hsa_ext_image_data_get_info_with_layout,
	HSA_API_ID_hsa_ext_image_create_with_layout,
	HSA_API_ID_DISPATCH,
	HSA_API_ID_NUMBER
};

hsa_api_string_pair_t hsa_api_pair_of_args(uint32_t cid, hsa_api_data_t api_data)
{
  std::ostringstream ret;
  std::ostringstream out;
  switch(cid){
    case HSA_API_ID_hsa_init: {
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_shut_down: {
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_system_get_info: {
      out << api_data.args.hsa_system_get_info.attribute << ", ";
      out << api_data.args.hsa_system_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_system_extension_supported: {
      out << api_data.args.hsa_system_extension_supported.extension << ", ";
      out << api_data.args.hsa_system_extension_supported.version_major << ", ";
      out << api_data.args.hsa_system_extension_supported.version_minor << ", ";
      out << api_data.args.hsa_system_extension_supported.result;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_system_get_extension_table: {
      out << api_data.args.hsa_system_get_extension_table.extension << ", ";
      out << api_data.args.hsa_system_get_extension_table.version_major << ", ";
      out << api_data.args.hsa_system_get_extension_table.version_minor << ", ";
      out << api_data.args.hsa_system_get_extension_table.table;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_iterate_agents: {
      out << api_data.args.hsa_iterate_agents.callback << ", ";
      out << api_data.args.hsa_iterate_agents.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_agent_get_info: {
      out << api_data.args.hsa_agent_get_info.agent << ", ";
      out << api_data.args.hsa_agent_get_info.attribute << ", ";
      out << api_data.args.hsa_agent_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_create: {
      out << api_data.args.hsa_queue_create.agent << ", ";
      out << api_data.args.hsa_queue_create.size << ", ";
      out << api_data.args.hsa_queue_create.type << ", ";
      out << api_data.args.hsa_queue_create.callback << ", ";
      out << api_data.args.hsa_queue_create.data << ", ";
      out << api_data.args.hsa_queue_create.private_segment_size << ", ";
      out << api_data.args.hsa_queue_create.group_segment_size << ", ";
      out << api_data.args.hsa_queue_create.queue;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_soft_queue_create: {
      out << api_data.args.hsa_soft_queue_create.region << ", ";
      out << api_data.args.hsa_soft_queue_create.size << ", ";
      out << api_data.args.hsa_soft_queue_create.type << ", ";
      out << api_data.args.hsa_soft_queue_create.features << ", ";
      out << api_data.args.hsa_soft_queue_create.doorbell_signal << ", ";
      out << api_data.args.hsa_soft_queue_create.queue;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_destroy: {
      out << api_data.args.hsa_queue_destroy.queue;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_inactivate: {
      out << api_data.args.hsa_queue_inactivate.queue;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_load_read_index_scacquire: {
      out << api_data.args.hsa_queue_load_read_index_scacquire.queue;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_load_read_index_relaxed: {
      out << api_data.args.hsa_queue_load_read_index_relaxed.queue;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_load_write_index_scacquire: {
      out << api_data.args.hsa_queue_load_write_index_scacquire.queue;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_load_write_index_relaxed: {
      out << api_data.args.hsa_queue_load_write_index_relaxed.queue;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_store_write_index_relaxed: {
      out << api_data.args.hsa_queue_store_write_index_relaxed.queue << ", ";
      out << api_data.args.hsa_queue_store_write_index_relaxed.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_queue_store_write_index_screlease: {
      out << api_data.args.hsa_queue_store_write_index_screlease.queue << ", ";
      out << api_data.args.hsa_queue_store_write_index_screlease.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_queue_cas_write_index_scacq_screl: {
      out << api_data.args.hsa_queue_cas_write_index_scacq_screl.queue << ", ";
      out << api_data.args.hsa_queue_cas_write_index_scacq_screl.expected << ", ";
      out << api_data.args.hsa_queue_cas_write_index_scacq_screl.value;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_cas_write_index_scacquire: {
      out << api_data.args.hsa_queue_cas_write_index_scacquire.queue << ", ";
      out << api_data.args.hsa_queue_cas_write_index_scacquire.expected << ", ";
      out << api_data.args.hsa_queue_cas_write_index_scacquire.value;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_cas_write_index_relaxed: {
      out << api_data.args.hsa_queue_cas_write_index_relaxed.queue << ", ";
      out << api_data.args.hsa_queue_cas_write_index_relaxed.expected << ", ";
      out << api_data.args.hsa_queue_cas_write_index_relaxed.value;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_cas_write_index_screlease: {
      out << api_data.args.hsa_queue_cas_write_index_screlease.queue << ", ";
      out << api_data.args.hsa_queue_cas_write_index_screlease.expected << ", ";
      out << api_data.args.hsa_queue_cas_write_index_screlease.value;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_add_write_index_scacq_screl: {
      out << api_data.args.hsa_queue_add_write_index_scacq_screl.queue << ", ";
      out << api_data.args.hsa_queue_add_write_index_scacq_screl.value;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_add_write_index_scacquire: {
      out << api_data.args.hsa_queue_add_write_index_scacquire.queue << ", ";
      out << api_data.args.hsa_queue_add_write_index_scacquire.value;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_add_write_index_relaxed: {
      out << api_data.args.hsa_queue_add_write_index_relaxed.queue << ", ";
      out << api_data.args.hsa_queue_add_write_index_relaxed.value;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_add_write_index_screlease: {
      out << api_data.args.hsa_queue_add_write_index_screlease.queue << ", ";
      out << api_data.args.hsa_queue_add_write_index_screlease.value;
      ret << api_data.uint64_t_retval;
      break;
    }
    case HSA_API_ID_hsa_queue_store_read_index_relaxed: {
      out << api_data.args.hsa_queue_store_read_index_relaxed.queue << ", ";
      out << api_data.args.hsa_queue_store_read_index_relaxed.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_queue_store_read_index_screlease: {
      out << api_data.args.hsa_queue_store_read_index_screlease.queue << ", ";
      out << api_data.args.hsa_queue_store_read_index_screlease.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_agent_iterate_regions: {
      out << api_data.args.hsa_agent_iterate_regions.agent << ", ";
      out << api_data.args.hsa_agent_iterate_regions.callback << ", ";
      out << api_data.args.hsa_agent_iterate_regions.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_region_get_info: {
      out << api_data.args.hsa_region_get_info.region << ", ";
      out << api_data.args.hsa_region_get_info.attribute << ", ";
      out << api_data.args.hsa_region_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_agent_get_exception_policies: {
      out << api_data.args.hsa_agent_get_exception_policies.agent << ", ";
      out << api_data.args.hsa_agent_get_exception_policies.profile << ", ";
      out << api_data.args.hsa_agent_get_exception_policies.mask;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_agent_extension_supported: {
      out << api_data.args.hsa_agent_extension_supported.extension << ", ";
      out << api_data.args.hsa_agent_extension_supported.agent << ", ";
      out << api_data.args.hsa_agent_extension_supported.version_major << ", ";
      out << api_data.args.hsa_agent_extension_supported.version_minor << ", ";
      out << api_data.args.hsa_agent_extension_supported.result;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_memory_register: {
      out << api_data.args.hsa_memory_register.ptr << ", ";
      out << api_data.args.hsa_memory_register.size;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_memory_deregister: {
      out << api_data.args.hsa_memory_deregister.ptr << ", ";
      out << api_data.args.hsa_memory_deregister.size;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_memory_allocate: {
      out << api_data.args.hsa_memory_allocate.region << ", ";
      out << api_data.args.hsa_memory_allocate.size << ", ";
      out << api_data.args.hsa_memory_allocate.ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_memory_free: {
      out << api_data.args.hsa_memory_free.ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_memory_copy: {
      out << api_data.args.hsa_memory_copy.dst << ", ";
      out << api_data.args.hsa_memory_copy.src << ", ";
      out << api_data.args.hsa_memory_copy.size;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_memory_assign_agent: {
      out << api_data.args.hsa_memory_assign_agent.ptr << ", ";
      out << api_data.args.hsa_memory_assign_agent.agent << ", ";
      out << api_data.args.hsa_memory_assign_agent.access;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_create: {
      out << api_data.args.hsa_signal_create.initial_value << ", ";
      out << api_data.args.hsa_signal_create.num_consumers << ", ";
      out << api_data.args.hsa_signal_create.consumers << ", ";
      out << api_data.args.hsa_signal_create.signal;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_destroy: {
      out << api_data.args.hsa_signal_destroy.signal;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_load_relaxed: {
      out << api_data.args.hsa_signal_load_relaxed.signal;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_load_scacquire: {
      out << api_data.args.hsa_signal_load_scacquire.signal;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_store_relaxed: {
      out << api_data.args.hsa_signal_store_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_store_relaxed.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_store_screlease: {
      out << api_data.args.hsa_signal_store_screlease.signal << ", ";
      out << api_data.args.hsa_signal_store_screlease.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_wait_relaxed: {
      out << api_data.args.hsa_signal_wait_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_wait_relaxed.condition << ", ";
      out << api_data.args.hsa_signal_wait_relaxed.compare_value << ", ";
      out << api_data.args.hsa_signal_wait_relaxed.timeout_hint << ", ";
      out << api_data.args.hsa_signal_wait_relaxed.wait_state_hint;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_wait_scacquire: {
      out << api_data.args.hsa_signal_wait_scacquire.signal << ", ";
      out << api_data.args.hsa_signal_wait_scacquire.condition << ", ";
      out << api_data.args.hsa_signal_wait_scacquire.compare_value << ", ";
      out << api_data.args.hsa_signal_wait_scacquire.timeout_hint << ", ";
      out << api_data.args.hsa_signal_wait_scacquire.wait_state_hint;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_and_relaxed: {
      out << api_data.args.hsa_signal_and_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_and_relaxed.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_and_scacquire: {
      out << api_data.args.hsa_signal_and_scacquire.signal << ", ";
      out << api_data.args.hsa_signal_and_scacquire.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_and_screlease: {
      out << api_data.args.hsa_signal_and_screlease.signal << ", ";
      out << api_data.args.hsa_signal_and_screlease.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_and_scacq_screl: {
      out << api_data.args.hsa_signal_and_scacq_screl.signal << ", ";
      out << api_data.args.hsa_signal_and_scacq_screl.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_or_relaxed: {
      out << api_data.args.hsa_signal_or_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_or_relaxed.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_or_scacquire: {
      out << api_data.args.hsa_signal_or_scacquire.signal << ", ";
      out << api_data.args.hsa_signal_or_scacquire.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_or_screlease: {
      out << api_data.args.hsa_signal_or_screlease.signal << ", ";
      out << api_data.args.hsa_signal_or_screlease.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_or_scacq_screl: {
      out << api_data.args.hsa_signal_or_scacq_screl.signal << ", ";
      out << api_data.args.hsa_signal_or_scacq_screl.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_xor_relaxed: {
      out << api_data.args.hsa_signal_xor_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_xor_relaxed.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_xor_scacquire: {
      out << api_data.args.hsa_signal_xor_scacquire.signal << ", ";
      out << api_data.args.hsa_signal_xor_scacquire.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_xor_screlease: {
      out << api_data.args.hsa_signal_xor_screlease.signal << ", ";
      out << api_data.args.hsa_signal_xor_screlease.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_xor_scacq_screl: {
      out << api_data.args.hsa_signal_xor_scacq_screl.signal << ", ";
      out << api_data.args.hsa_signal_xor_scacq_screl.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_exchange_relaxed: {
      out << api_data.args.hsa_signal_exchange_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_exchange_relaxed.value;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_exchange_scacquire: {
      out << api_data.args.hsa_signal_exchange_scacquire.signal << ", ";
      out << api_data.args.hsa_signal_exchange_scacquire.value;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_exchange_screlease: {
      out << api_data.args.hsa_signal_exchange_screlease.signal << ", ";
      out << api_data.args.hsa_signal_exchange_screlease.value;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_exchange_scacq_screl: {
      out << api_data.args.hsa_signal_exchange_scacq_screl.signal << ", ";
      out << api_data.args.hsa_signal_exchange_scacq_screl.value;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_add_relaxed: {
      out << api_data.args.hsa_signal_add_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_add_relaxed.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_add_scacquire: {
      out << api_data.args.hsa_signal_add_scacquire.signal << ", ";
      out << api_data.args.hsa_signal_add_scacquire.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_add_screlease: {
      out << api_data.args.hsa_signal_add_screlease.signal << ", ";
      out << api_data.args.hsa_signal_add_screlease.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_add_scacq_screl: {
      out << api_data.args.hsa_signal_add_scacq_screl.signal << ", ";
      out << api_data.args.hsa_signal_add_scacq_screl.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_subtract_relaxed: {
      out << api_data.args.hsa_signal_subtract_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_subtract_relaxed.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_subtract_scacquire: {
      out << api_data.args.hsa_signal_subtract_scacquire.signal << ", ";
      out << api_data.args.hsa_signal_subtract_scacquire.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_subtract_screlease: {
      out << api_data.args.hsa_signal_subtract_screlease.signal << ", ";
      out << api_data.args.hsa_signal_subtract_screlease.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_subtract_scacq_screl: {
      out << api_data.args.hsa_signal_subtract_scacq_screl.signal << ", ";
      out << api_data.args.hsa_signal_subtract_scacq_screl.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_cas_relaxed: {
      out << api_data.args.hsa_signal_cas_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_cas_relaxed.expected << ", ";
      out << api_data.args.hsa_signal_cas_relaxed.value;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_cas_scacquire: {
      out << api_data.args.hsa_signal_cas_scacquire.signal << ", ";
      out << api_data.args.hsa_signal_cas_scacquire.expected << ", ";
      out << api_data.args.hsa_signal_cas_scacquire.value;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_cas_screlease: {
      out << api_data.args.hsa_signal_cas_screlease.signal << ", ";
      out << api_data.args.hsa_signal_cas_screlease.expected << ", ";
      out << api_data.args.hsa_signal_cas_screlease.value;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_cas_scacq_screl: {
      out << api_data.args.hsa_signal_cas_scacq_screl.signal << ", ";
      out << api_data.args.hsa_signal_cas_scacq_screl.expected << ", ";
      out << api_data.args.hsa_signal_cas_scacq_screl.value;
      ret << api_data.hsa_signal_value_t_retval;
      break;
    }
    case HSA_API_ID_hsa_isa_from_name: {
      out << api_data.args.hsa_isa_from_name.name << ", ";
      out << api_data.args.hsa_isa_from_name.isa;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_isa_get_info: {
      out << api_data.args.hsa_isa_get_info.isa << ", ";
      out << api_data.args.hsa_isa_get_info.attribute << ", ";
      out << api_data.args.hsa_isa_get_info.index << ", ";
      out << api_data.args.hsa_isa_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_isa_compatible: {
      out << api_data.args.hsa_isa_compatible.code_object_isa << ", ";
      out << api_data.args.hsa_isa_compatible.agent_isa << ", ";
      out << api_data.args.hsa_isa_compatible.result;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_serialize: {
      out << api_data.args.hsa_code_object_serialize.code_object << ", ";
      out << api_data.args.hsa_code_object_serialize.alloc_callback << ", ";
      out << api_data.args.hsa_code_object_serialize.callback_data << ", ";
      out << api_data.args.hsa_code_object_serialize.options << ", ";
      out << api_data.args.hsa_code_object_serialize.serialized_code_object << ", ";
      out << api_data.args.hsa_code_object_serialize.serialized_code_object_size;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_deserialize: {
      out << api_data.args.hsa_code_object_deserialize.serialized_code_object << ", ";
      out << api_data.args.hsa_code_object_deserialize.serialized_code_object_size << ", ";
      out << api_data.args.hsa_code_object_deserialize.options << ", ";
      out << api_data.args.hsa_code_object_deserialize.code_object;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_destroy: {
      out << api_data.args.hsa_code_object_destroy.code_object;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_get_info: {
      out << api_data.args.hsa_code_object_get_info.code_object << ", ";
      out << api_data.args.hsa_code_object_get_info.attribute << ", ";
      out << api_data.args.hsa_code_object_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_get_symbol: {
      out << api_data.args.hsa_code_object_get_symbol.code_object << ", ";
      out << api_data.args.hsa_code_object_get_symbol.symbol_name << ", ";
      out << api_data.args.hsa_code_object_get_symbol.symbol;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_symbol_get_info: {
      out << api_data.args.hsa_code_symbol_get_info.code_symbol << ", ";
      out << api_data.args.hsa_code_symbol_get_info.attribute << ", ";
      out << api_data.args.hsa_code_symbol_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_iterate_symbols: {
      out << api_data.args.hsa_code_object_iterate_symbols.code_object << ", ";
      out << api_data.args.hsa_code_object_iterate_symbols.callback << ", ";
      out << api_data.args.hsa_code_object_iterate_symbols.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_create: {
      out << api_data.args.hsa_executable_create.profile << ", ";
      out << api_data.args.hsa_executable_create.executable_state << ", ";
      out << api_data.args.hsa_executable_create.options << ", ";
      out << api_data.args.hsa_executable_create.executable;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_destroy: {
      out << api_data.args.hsa_executable_destroy.executable;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_load_code_object: {
      out << api_data.args.hsa_executable_load_code_object.executable << ", ";
      out << api_data.args.hsa_executable_load_code_object.agent << ", ";
      out << api_data.args.hsa_executable_load_code_object.code_object << ", ";
      out << api_data.args.hsa_executable_load_code_object.options;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_freeze: {
      out << api_data.args.hsa_executable_freeze.executable << ", ";
      out << api_data.args.hsa_executable_freeze.options;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_get_info: {
      out << api_data.args.hsa_executable_get_info.executable << ", ";
      out << api_data.args.hsa_executable_get_info.attribute << ", ";
      out << api_data.args.hsa_executable_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_global_variable_define: {
      out << api_data.args.hsa_executable_global_variable_define.executable << ", ";
      out << api_data.args.hsa_executable_global_variable_define.variable_name << ", ";
      out << api_data.args.hsa_executable_global_variable_define.address;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_agent_global_variable_define: {
      out << api_data.args.hsa_executable_agent_global_variable_define.executable << ", ";
      out << api_data.args.hsa_executable_agent_global_variable_define.agent << ", ";
      out << api_data.args.hsa_executable_agent_global_variable_define.variable_name << ", ";
      out << api_data.args.hsa_executable_agent_global_variable_define.address;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_readonly_variable_define: {
      out << api_data.args.hsa_executable_readonly_variable_define.executable << ", ";
      out << api_data.args.hsa_executable_readonly_variable_define.agent << ", ";
      out << api_data.args.hsa_executable_readonly_variable_define.variable_name << ", ";
      out << api_data.args.hsa_executable_readonly_variable_define.address;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_validate: {
      out << api_data.args.hsa_executable_validate.executable << ", ";
      out << api_data.args.hsa_executable_validate.result;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_get_symbol: {
      out << api_data.args.hsa_executable_get_symbol.executable << ", ";
      out << api_data.args.hsa_executable_get_symbol.module_name << ", ";
      out << api_data.args.hsa_executable_get_symbol.symbol_name << ", ";
      out << api_data.args.hsa_executable_get_symbol.agent << ", ";
      out << api_data.args.hsa_executable_get_symbol.call_convention << ", ";
      out << api_data.args.hsa_executable_get_symbol.symbol;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_symbol_get_info: {
      out << api_data.args.hsa_executable_symbol_get_info.executable_symbol << ", ";
      out << api_data.args.hsa_executable_symbol_get_info.attribute << ", ";
      out << api_data.args.hsa_executable_symbol_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_iterate_symbols: {
      out << api_data.args.hsa_executable_iterate_symbols.executable << ", ";
      out << api_data.args.hsa_executable_iterate_symbols.callback << ", ";
      out << api_data.args.hsa_executable_iterate_symbols.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_status_string: {
      out << api_data.args.hsa_status_string.status << ", ";
      out << api_data.args.hsa_status_string.status_string;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_extension_get_name: {
      out << api_data.args.hsa_extension_get_name.extension << ", ";
      out << api_data.args.hsa_extension_get_name.name;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_system_major_extension_supported: {
      out << api_data.args.hsa_system_major_extension_supported.extension << ", ";
      out << api_data.args.hsa_system_major_extension_supported.version_major << ", ";
      out << api_data.args.hsa_system_major_extension_supported.version_minor << ", ";
      out << api_data.args.hsa_system_major_extension_supported.result;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_system_get_major_extension_table: {
      out << api_data.args.hsa_system_get_major_extension_table.extension << ", ";
      out << api_data.args.hsa_system_get_major_extension_table.version_major << ", ";
      out << api_data.args.hsa_system_get_major_extension_table.table_length << ", ";
      out << api_data.args.hsa_system_get_major_extension_table.table;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_agent_major_extension_supported: {
      out << api_data.args.hsa_agent_major_extension_supported.extension << ", ";
      out << api_data.args.hsa_agent_major_extension_supported.agent << ", ";
      out << api_data.args.hsa_agent_major_extension_supported.version_major << ", ";
      out << api_data.args.hsa_agent_major_extension_supported.version_minor << ", ";
      out << api_data.args.hsa_agent_major_extension_supported.result;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_cache_get_info: {
      out << api_data.args.hsa_cache_get_info.cache << ", ";
      out << api_data.args.hsa_cache_get_info.attribute << ", ";
      out << api_data.args.hsa_cache_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_agent_iterate_caches: {
      out << api_data.args.hsa_agent_iterate_caches.agent << ", ";
      out << api_data.args.hsa_agent_iterate_caches.callback << ", ";
      out << api_data.args.hsa_agent_iterate_caches.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_silent_store_relaxed: {
      out << api_data.args.hsa_signal_silent_store_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_silent_store_relaxed.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_silent_store_screlease: {
      out << api_data.args.hsa_signal_silent_store_screlease.signal << ", ";
      out << api_data.args.hsa_signal_silent_store_screlease.value;
      ret << "void";
      break;
    }
    case HSA_API_ID_hsa_signal_group_create: {
      out << api_data.args.hsa_signal_group_create.num_signals << ", ";
      out << api_data.args.hsa_signal_group_create.signals << ", ";
      out << api_data.args.hsa_signal_group_create.num_consumers << ", ";
      out << api_data.args.hsa_signal_group_create.consumers << ", ";
      out << api_data.args.hsa_signal_group_create.signal_group;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_group_destroy: {
      out << api_data.args.hsa_signal_group_destroy.signal_group;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_group_wait_any_scacquire: {
      out << api_data.args.hsa_signal_group_wait_any_scacquire.signal_group << ", ";
      out << api_data.args.hsa_signal_group_wait_any_scacquire.conditions << ", ";
      out << api_data.args.hsa_signal_group_wait_any_scacquire.compare_values << ", ";
      out << api_data.args.hsa_signal_group_wait_any_scacquire.wait_state_hint << ", ";
      out << api_data.args.hsa_signal_group_wait_any_scacquire.signal << ", ";
      out << api_data.args.hsa_signal_group_wait_any_scacquire.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_signal_group_wait_any_relaxed: {
      out << api_data.args.hsa_signal_group_wait_any_relaxed.signal_group << ", ";
      out << api_data.args.hsa_signal_group_wait_any_relaxed.conditions << ", ";
      out << api_data.args.hsa_signal_group_wait_any_relaxed.compare_values << ", ";
      out << api_data.args.hsa_signal_group_wait_any_relaxed.wait_state_hint << ", ";
      out << api_data.args.hsa_signal_group_wait_any_relaxed.signal << ", ";
      out << api_data.args.hsa_signal_group_wait_any_relaxed.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_agent_iterate_isas: {
      out << api_data.args.hsa_agent_iterate_isas.agent << ", ";
      out << api_data.args.hsa_agent_iterate_isas.callback << ", ";
      out << api_data.args.hsa_agent_iterate_isas.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_isa_get_info_alt: {
      out << api_data.args.hsa_isa_get_info_alt.isa << ", ";
      out << api_data.args.hsa_isa_get_info_alt.attribute << ", ";
      out << api_data.args.hsa_isa_get_info_alt.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_isa_get_exception_policies: {
      out << api_data.args.hsa_isa_get_exception_policies.isa << ", ";
      out << api_data.args.hsa_isa_get_exception_policies.profile << ", ";
      out << api_data.args.hsa_isa_get_exception_policies.mask;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_isa_get_round_method: {
      out << api_data.args.hsa_isa_get_round_method.isa << ", ";
      out << api_data.args.hsa_isa_get_round_method.fp_type << ", ";
      out << api_data.args.hsa_isa_get_round_method.flush_mode << ", ";
      out << api_data.args.hsa_isa_get_round_method.round_method;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_wavefront_get_info: {
      out << api_data.args.hsa_wavefront_get_info.wavefront << ", ";
      out << api_data.args.hsa_wavefront_get_info.attribute << ", ";
      out << api_data.args.hsa_wavefront_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_isa_iterate_wavefronts: {
      out << api_data.args.hsa_isa_iterate_wavefronts.isa << ", ";
      out << api_data.args.hsa_isa_iterate_wavefronts.callback << ", ";
      out << api_data.args.hsa_isa_iterate_wavefronts.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_get_symbol_from_name: {
      out << api_data.args.hsa_code_object_get_symbol_from_name.code_object << ", ";
      out << api_data.args.hsa_code_object_get_symbol_from_name.module_name << ", ";
      out << api_data.args.hsa_code_object_get_symbol_from_name.symbol_name << ", ";
      out << api_data.args.hsa_code_object_get_symbol_from_name.symbol;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_reader_create_from_file: {
      out << api_data.args.hsa_code_object_reader_create_from_file.file << ", ";
      out << api_data.args.hsa_code_object_reader_create_from_file.code_object_reader;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_reader_create_from_memory: {
      out << api_data.args.hsa_code_object_reader_create_from_memory.code_object << ", ";
      out << api_data.args.hsa_code_object_reader_create_from_memory.size << ", ";
      out << api_data.args.hsa_code_object_reader_create_from_memory.code_object_reader;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_code_object_reader_destroy: {
      out << api_data.args.hsa_code_object_reader_destroy.code_object_reader;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_create_alt: {
      out << api_data.args.hsa_executable_create_alt.profile << ", ";
      out << api_data.args.hsa_executable_create_alt.default_float_rounding_mode << ", ";
      out << api_data.args.hsa_executable_create_alt.options << ", ";
      out << api_data.args.hsa_executable_create_alt.executable;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_load_program_code_object: {
      out << api_data.args.hsa_executable_load_program_code_object.executable << ", ";
      out << api_data.args.hsa_executable_load_program_code_object.code_object_reader << ", ";
      out << api_data.args.hsa_executable_load_program_code_object.options << ", ";
      out << api_data.args.hsa_executable_load_program_code_object.loaded_code_object;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_load_agent_code_object: {
      out << api_data.args.hsa_executable_load_agent_code_object.executable << ", ";
      out << api_data.args.hsa_executable_load_agent_code_object.agent << ", ";
      out << api_data.args.hsa_executable_load_agent_code_object.code_object_reader << ", ";
      out << api_data.args.hsa_executable_load_agent_code_object.options << ", ";
      out << api_data.args.hsa_executable_load_agent_code_object.loaded_code_object;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_validate_alt: {
      out << api_data.args.hsa_executable_validate_alt.executable << ", ";
      out << api_data.args.hsa_executable_validate_alt.options << ", ";
      out << api_data.args.hsa_executable_validate_alt.result;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_get_symbol_by_name: {
      out << api_data.args.hsa_executable_get_symbol_by_name.executable << ", ";
      out << api_data.args.hsa_executable_get_symbol_by_name.symbol_name << ", ";
      out << api_data.args.hsa_executable_get_symbol_by_name.agent << ", ";
      out << api_data.args.hsa_executable_get_symbol_by_name.symbol;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_iterate_agent_symbols: {
      out << api_data.args.hsa_executable_iterate_agent_symbols.executable << ", ";
      out << api_data.args.hsa_executable_iterate_agent_symbols.agent << ", ";
      out << api_data.args.hsa_executable_iterate_agent_symbols.callback << ", ";
      out << api_data.args.hsa_executable_iterate_agent_symbols.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_executable_iterate_program_symbols: {
      out << api_data.args.hsa_executable_iterate_program_symbols.executable << ", ";
      out << api_data.args.hsa_executable_iterate_program_symbols.callback << ", ";
      out << api_data.args.hsa_executable_iterate_program_symbols.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_coherency_get_type: {
      out << api_data.args.hsa_amd_coherency_get_type.agent << ", ";
      out << api_data.args.hsa_amd_coherency_get_type.type;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_coherency_set_type: {
      out << api_data.args.hsa_amd_coherency_set_type.agent << ", ";
      out << api_data.args.hsa_amd_coherency_set_type.type;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_profiling_set_profiler_enabled: {
      out << api_data.args.hsa_amd_profiling_set_profiler_enabled.queue << ", ";
      out << api_data.args.hsa_amd_profiling_set_profiler_enabled.enable;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_profiling_async_copy_enable: {
      out << api_data.args.hsa_amd_profiling_async_copy_enable.enable;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_profiling_get_dispatch_time: {
      out << api_data.args.hsa_amd_profiling_get_dispatch_time.agent << ", ";
      out << api_data.args.hsa_amd_profiling_get_dispatch_time.signal << ", ";
      out << api_data.args.hsa_amd_profiling_get_dispatch_time.time;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_profiling_get_async_copy_time: {
      out << api_data.args.hsa_amd_profiling_get_async_copy_time.signal << ", ";
      out << api_data.args.hsa_amd_profiling_get_async_copy_time.time;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_profiling_convert_tick_to_system_domain: {
      out << api_data.args.hsa_amd_profiling_convert_tick_to_system_domain.agent << ", ";
      out << api_data.args.hsa_amd_profiling_convert_tick_to_system_domain.agent_tick << ", ";
      out << api_data.args.hsa_amd_profiling_convert_tick_to_system_domain.system_tick;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_signal_async_handler: {
      out << api_data.args.hsa_amd_signal_async_handler.signal << ", ";
      out << api_data.args.hsa_amd_signal_async_handler.cond << ", ";
      out << api_data.args.hsa_amd_signal_async_handler.value << ", ";
      out << api_data.args.hsa_amd_signal_async_handler.handler << ", ";
      out << api_data.args.hsa_amd_signal_async_handler.arg;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_async_function: {
      out << api_data.args.hsa_amd_async_function.callback << ", ";
      out << api_data.args.hsa_amd_async_function.arg;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_signal_wait_any: {
      out << api_data.args.hsa_amd_signal_wait_any.signal_count << ", ";
      out << api_data.args.hsa_amd_signal_wait_any.signals << ", ";
      out << api_data.args.hsa_amd_signal_wait_any.conds << ", ";
      out << api_data.args.hsa_amd_signal_wait_any.values << ", ";
      out << api_data.args.hsa_amd_signal_wait_any.timeout_hint << ", ";
      out << api_data.args.hsa_amd_signal_wait_any.wait_hint << ", ";
      out << api_data.args.hsa_amd_signal_wait_any.satisfying_value;
      ret << api_data.uint32_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_queue_cu_set_mask: {
      out << api_data.args.hsa_amd_queue_cu_set_mask.queue << ", ";
      out << api_data.args.hsa_amd_queue_cu_set_mask.num_cu_mask_count << ", ";
      out << api_data.args.hsa_amd_queue_cu_set_mask.cu_mask;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_pool_get_info: {
      out << api_data.args.hsa_amd_memory_pool_get_info.memory_pool << ", ";
      out << api_data.args.hsa_amd_memory_pool_get_info.attribute << ", ";
      out << api_data.args.hsa_amd_memory_pool_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_agent_iterate_memory_pools: {
      out << api_data.args.hsa_amd_agent_iterate_memory_pools.agent << ", ";
      out << api_data.args.hsa_amd_agent_iterate_memory_pools.callback << ", ";
      out << api_data.args.hsa_amd_agent_iterate_memory_pools.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_pool_allocate: {
      out << api_data.args.hsa_amd_memory_pool_allocate.memory_pool << ", ";
      out << api_data.args.hsa_amd_memory_pool_allocate.size << ", ";
      out << api_data.args.hsa_amd_memory_pool_allocate.flags << ", ";
      out << api_data.args.hsa_amd_memory_pool_allocate.ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_pool_free: {
      out << api_data.args.hsa_amd_memory_pool_free.ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_async_copy: {
      out << api_data.args.hsa_amd_memory_async_copy.dst << ", ";
      out << api_data.args.hsa_amd_memory_async_copy.dst_agent << ", ";
      out << api_data.args.hsa_amd_memory_async_copy.src << ", ";
      out << api_data.args.hsa_amd_memory_async_copy.src_agent << ", ";
      out << api_data.args.hsa_amd_memory_async_copy.size << ", ";
      out << api_data.args.hsa_amd_memory_async_copy.num_dep_signals << ", ";
      out << api_data.args.hsa_amd_memory_async_copy.dep_signals << ", ";
      out << api_data.args.hsa_amd_memory_async_copy.completion_signal;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_agent_memory_pool_get_info: {
      out << api_data.args.hsa_amd_agent_memory_pool_get_info.agent << ", ";
      out << api_data.args.hsa_amd_agent_memory_pool_get_info.memory_pool << ", ";
      out << api_data.args.hsa_amd_agent_memory_pool_get_info.attribute << ", ";
      out << api_data.args.hsa_amd_agent_memory_pool_get_info.value;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_agents_allow_access: {
      out << api_data.args.hsa_amd_agents_allow_access.num_agents << ", ";
      out << api_data.args.hsa_amd_agents_allow_access.agents << ", ";
      out << api_data.args.hsa_amd_agents_allow_access.flags << ", ";
      out << api_data.args.hsa_amd_agents_allow_access.ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_pool_can_migrate: {
      out << api_data.args.hsa_amd_memory_pool_can_migrate.src_memory_pool << ", ";
      out << api_data.args.hsa_amd_memory_pool_can_migrate.dst_memory_pool << ", ";
      out << api_data.args.hsa_amd_memory_pool_can_migrate.result;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_migrate: {
      out << api_data.args.hsa_amd_memory_migrate.ptr << ", ";
      out << api_data.args.hsa_amd_memory_migrate.memory_pool << ", ";
      out << api_data.args.hsa_amd_memory_migrate.flags;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_lock: {
      out << api_data.args.hsa_amd_memory_lock.host_ptr << ", ";
      out << api_data.args.hsa_amd_memory_lock.size << ", ";
      out << api_data.args.hsa_amd_memory_lock.agents << ", ";
      out << api_data.args.hsa_amd_memory_lock.num_agent << ", ";
      out << api_data.args.hsa_amd_memory_lock.agent_ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_unlock: {
      out << api_data.args.hsa_amd_memory_unlock.host_ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_fill: {
      out << api_data.args.hsa_amd_memory_fill.ptr << ", ";
      out << api_data.args.hsa_amd_memory_fill.value << ", ";
      out << api_data.args.hsa_amd_memory_fill.count;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_interop_map_buffer: {
      out << api_data.args.hsa_amd_interop_map_buffer.num_agents << ", ";
      out << api_data.args.hsa_amd_interop_map_buffer.agents << ", ";
      out << api_data.args.hsa_amd_interop_map_buffer.interop_handle << ", ";
      out << api_data.args.hsa_amd_interop_map_buffer.flags << ", ";
      out << api_data.args.hsa_amd_interop_map_buffer.size << ", ";
      out << api_data.args.hsa_amd_interop_map_buffer.ptr << ", ";
      out << api_data.args.hsa_amd_interop_map_buffer.metadata_size << ", ";
      out << api_data.args.hsa_amd_interop_map_buffer.metadata;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_interop_unmap_buffer: {
      out << api_data.args.hsa_amd_interop_unmap_buffer.ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_image_create: {
      out << api_data.args.hsa_amd_image_create.agent << ", ";
      out << api_data.args.hsa_amd_image_create.image_descriptor << ", ";
      out << api_data.args.hsa_amd_image_create.image_layout << ", ";
      out << api_data.args.hsa_amd_image_create.image_data << ", ";
      out << api_data.args.hsa_amd_image_create.access_permission << ", ";
      out << api_data.args.hsa_amd_image_create.image;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_pointer_info: {
      out << api_data.args.hsa_amd_pointer_info.ptr << ", ";
      out << api_data.args.hsa_amd_pointer_info.info << ", ";
      out << api_data.args.hsa_amd_pointer_info.alloc << ", ";
      out << api_data.args.hsa_amd_pointer_info.num_agents_accessible << ", ";
      out << api_data.args.hsa_amd_pointer_info.accessible;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_pointer_info_set_userdata: {
      out << api_data.args.hsa_amd_pointer_info_set_userdata.ptr << ", ";
      out << api_data.args.hsa_amd_pointer_info_set_userdata.userdata;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_ipc_memory_create: {
      out << api_data.args.hsa_amd_ipc_memory_create.ptr << ", ";
      out << api_data.args.hsa_amd_ipc_memory_create.len << ", ";
      out << api_data.args.hsa_amd_ipc_memory_create.handle;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_ipc_memory_attach: {
      out << api_data.args.hsa_amd_ipc_memory_attach.handle << ", ";
      out << api_data.args.hsa_amd_ipc_memory_attach.len << ", ";
      out << api_data.args.hsa_amd_ipc_memory_attach.num_agents << ", ";
      out << api_data.args.hsa_amd_ipc_memory_attach.mapping_agents << ", ";
      out << api_data.args.hsa_amd_ipc_memory_attach.mapped_ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_ipc_memory_detach: {
      out << api_data.args.hsa_amd_ipc_memory_detach.mapped_ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_signal_create: {
      out << api_data.args.hsa_amd_signal_create.initial_value << ", ";
      out << api_data.args.hsa_amd_signal_create.num_consumers << ", ";
      out << api_data.args.hsa_amd_signal_create.consumers << ", ";
      out << api_data.args.hsa_amd_signal_create.attributes << ", ";
      out << api_data.args.hsa_amd_signal_create.signal;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_ipc_signal_create: {
      out << api_data.args.hsa_amd_ipc_signal_create.signal << ", ";
      out << api_data.args.hsa_amd_ipc_signal_create.handle;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_ipc_signal_attach: {
      out << api_data.args.hsa_amd_ipc_signal_attach.handle << ", ";
      out << api_data.args.hsa_amd_ipc_signal_attach.signal;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_register_system_event_handler: {
      out << api_data.args.hsa_amd_register_system_event_handler.callback << ", ";
      out << api_data.args.hsa_amd_register_system_event_handler.data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_queue_intercept_create: {
      out << api_data.args.hsa_amd_queue_intercept_create.agent_handle << ", ";
      out << api_data.args.hsa_amd_queue_intercept_create.size << ", ";
      out << api_data.args.hsa_amd_queue_intercept_create.type << ", ";
      out << api_data.args.hsa_amd_queue_intercept_create.callback << ", ";
      out << api_data.args.hsa_amd_queue_intercept_create.data << ", ";
      out << api_data.args.hsa_amd_queue_intercept_create.private_segment_size << ", ";
      out << api_data.args.hsa_amd_queue_intercept_create.group_segment_size << ", ";
      out << api_data.args.hsa_amd_queue_intercept_create.queue;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_queue_intercept_register: {
      out << api_data.args.hsa_amd_queue_intercept_register.queue << ", ";
      out << api_data.args.hsa_amd_queue_intercept_register.callback << ", ";
      out << api_data.args.hsa_amd_queue_intercept_register.user_data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_queue_set_priority: {
      out << api_data.args.hsa_amd_queue_set_priority.queue << ", ";
      out << api_data.args.hsa_amd_queue_set_priority.priority;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_async_copy_rect: {
      out << api_data.args.hsa_amd_memory_async_copy_rect.dst << ", ";
      out << api_data.args.hsa_amd_memory_async_copy_rect.dst_offset << ", ";
      out << api_data.args.hsa_amd_memory_async_copy_rect.src << ", ";
      out << api_data.args.hsa_amd_memory_async_copy_rect.src_offset << ", ";
      out << api_data.args.hsa_amd_memory_async_copy_rect.range << ", ";
      out << api_data.args.hsa_amd_memory_async_copy_rect.copy_agent << ", ";
      out << api_data.args.hsa_amd_memory_async_copy_rect.dir << ", ";
      out << api_data.args.hsa_amd_memory_async_copy_rect.num_dep_signals << ", ";
      out << api_data.args.hsa_amd_memory_async_copy_rect.dep_signals << ", ";
      out << api_data.args.hsa_amd_memory_async_copy_rect.completion_signal;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_runtime_queue_create_register: {
      out << api_data.args.hsa_amd_runtime_queue_create_register.callback << ", ";
      out << api_data.args.hsa_amd_runtime_queue_create_register.user_data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_memory_lock_to_pool: {
      out << api_data.args.hsa_amd_memory_lock_to_pool.host_ptr << ", ";
      out << api_data.args.hsa_amd_memory_lock_to_pool.size << ", ";
      out << api_data.args.hsa_amd_memory_lock_to_pool.agents << ", ";
      out << api_data.args.hsa_amd_memory_lock_to_pool.num_agent << ", ";
      out << api_data.args.hsa_amd_memory_lock_to_pool.pool << ", ";
      out << api_data.args.hsa_amd_memory_lock_to_pool.flags << ", ";
      out << api_data.args.hsa_amd_memory_lock_to_pool.agent_ptr;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_register_deallocation_callback: {
      out << api_data.args.hsa_amd_register_deallocation_callback.ptr << ", ";
      out << api_data.args.hsa_amd_register_deallocation_callback.callback << ", ";
      out << api_data.args.hsa_amd_register_deallocation_callback.user_data;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_amd_deregister_deallocation_callback: {
      out << api_data.args.hsa_amd_deregister_deallocation_callback.ptr << ", ";
      out << api_data.args.hsa_amd_deregister_deallocation_callback.callback;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_get_capability: {
      out << api_data.args.hsa_ext_image_get_capability.agent << ", ";
      out << api_data.args.hsa_ext_image_get_capability.geometry << ", ";
      out << api_data.args.hsa_ext_image_get_capability.image_format << ", ";
      out << api_data.args.hsa_ext_image_get_capability.capability_mask;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_data_get_info: {
      out << api_data.args.hsa_ext_image_data_get_info.agent << ", ";
      out << api_data.args.hsa_ext_image_data_get_info.image_descriptor << ", ";
      out << api_data.args.hsa_ext_image_data_get_info.access_permission << ", ";
      out << api_data.args.hsa_ext_image_data_get_info.image_data_info;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_create: {
      out << api_data.args.hsa_ext_image_create.agent << ", ";
      out << api_data.args.hsa_ext_image_create.image_descriptor << ", ";
      out << api_data.args.hsa_ext_image_create.image_data << ", ";
      out << api_data.args.hsa_ext_image_create.access_permission << ", ";
      out << api_data.args.hsa_ext_image_create.image;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_import: {
      out << api_data.args.hsa_ext_image_import.agent << ", ";
      out << api_data.args.hsa_ext_image_import.src_memory << ", ";
      out << api_data.args.hsa_ext_image_import.src_row_pitch << ", ";
      out << api_data.args.hsa_ext_image_import.src_slice_pitch << ", ";
      out << api_data.args.hsa_ext_image_import.dst_image << ", ";
      out << api_data.args.hsa_ext_image_import.image_region;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_export: {
      out << api_data.args.hsa_ext_image_export.agent << ", ";
      out << api_data.args.hsa_ext_image_export.src_image << ", ";
      out << api_data.args.hsa_ext_image_export.dst_memory << ", ";
      out << api_data.args.hsa_ext_image_export.dst_row_pitch << ", ";
      out << api_data.args.hsa_ext_image_export.dst_slice_pitch << ", ";
      out << api_data.args.hsa_ext_image_export.image_region;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_copy: {
      out << api_data.args.hsa_ext_image_copy.agent << ", ";
      out << api_data.args.hsa_ext_image_copy.src_image << ", ";
      out << api_data.args.hsa_ext_image_copy.src_offset << ", ";
      out << api_data.args.hsa_ext_image_copy.dst_image << ", ";
      out << api_data.args.hsa_ext_image_copy.dst_offset << ", ";
      out << api_data.args.hsa_ext_image_copy.range;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_clear: {
      out << api_data.args.hsa_ext_image_clear.agent << ", ";
      out << api_data.args.hsa_ext_image_clear.image << ", ";
      out << api_data.args.hsa_ext_image_clear.data << ", ";
      out << api_data.args.hsa_ext_image_clear.image_region;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_destroy: {
      out << api_data.args.hsa_ext_image_destroy.agent << ", ";
      out << api_data.args.hsa_ext_image_destroy.image;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_sampler_create: {
      out << api_data.args.hsa_ext_sampler_create.agent << ", ";
      out << api_data.args.hsa_ext_sampler_create.sampler_descriptor << ", ";
      out << api_data.args.hsa_ext_sampler_create.sampler;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_sampler_destroy: {
      out << api_data.args.hsa_ext_sampler_destroy.agent << ", ";
      out << api_data.args.hsa_ext_sampler_destroy.sampler;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_get_capability_with_layout: {
      out << api_data.args.hsa_ext_image_get_capability_with_layout.agent << ", ";
      out << api_data.args.hsa_ext_image_get_capability_with_layout.geometry << ", ";
      out << api_data.args.hsa_ext_image_get_capability_with_layout.image_format << ", ";
      out << api_data.args.hsa_ext_image_get_capability_with_layout.image_data_layout << ", ";
      out << api_data.args.hsa_ext_image_get_capability_with_layout.capability_mask;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_data_get_info_with_layout: {
      out << api_data.args.hsa_ext_image_data_get_info_with_layout.agent << ", ";
      out << api_data.args.hsa_ext_image_data_get_info_with_layout.image_descriptor << ", ";
      out << api_data.args.hsa_ext_image_data_get_info_with_layout.access_permission << ", ";
      out << api_data.args.hsa_ext_image_data_get_info_with_layout.image_data_layout << ", ";
      out << api_data.args.hsa_ext_image_data_get_info_with_layout.image_data_row_pitch << ", ";
      out << api_data.args.hsa_ext_image_data_get_info_with_layout.image_data_slice_pitch << ", ";
      out << api_data.args.hsa_ext_image_data_get_info_with_layout.image_data_info;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    case HSA_API_ID_hsa_ext_image_create_with_layout: {
      out << api_data.args.hsa_ext_image_create_with_layout.agent << ", ";
      out << api_data.args.hsa_ext_image_create_with_layout.image_descriptor << ", ";
      out << api_data.args.hsa_ext_image_create_with_layout.image_data << ", ";
      out << api_data.args.hsa_ext_image_create_with_layout.access_permission << ", ";
      out << api_data.args.hsa_ext_image_create_with_layout.image_data_layout << ", ";
      out << api_data.args.hsa_ext_image_create_with_layout.image_data_row_pitch << ", ";
      out << api_data.args.hsa_ext_image_create_with_layout.image_data_slice_pitch << ", ";
      out << api_data.args.hsa_ext_image_create_with_layout.image;
      ret << api_data.hsa_status_t_retval;
      break;
    }
    default:
      out << "ERROR: unknown API";
      abort();
  }
  return hsa_api_string_pair_t(out.str(), ret.str());
}

const hsa_api_id_t* hsa_api_table(){
	return all_hsa_api_func;
}

uint32_t GetHSAApiSize() {
	return sizeof(all_hsa_api_func)/sizeof(hsa_api_id_t);
}