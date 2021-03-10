if [ -z "$ROCM_PATH" ]; then export ROCM_PATH=/opt/rocm; fi
#if [ -z "$ROCTRACER_PATH" ]; then export ROCTRACER_PATH=/opt/rocm/roctracer; fi
#if [ -z "$ROCPROFILER_PATH" ]; then export ROCPROFILER_PATH=/opt/rocm/rocprofiler; fi
if [ -z "$HSA_INCLUDE" ]; then export HSA_INCLUDE=/opt/rocm/include/hsa; fi
if [ -z "$HIP_PATH" ]; then export HIP_PATH=/opt/rocm/include/hip; fi

#To change
if [ -z "$ROCTRACER_SRC" ]; then export ROCTRACER_SRC=/opt/rocm/roctracer/src; fi
if [ -z "$ROCTRACER_INCLUDES" ]; then export ROCTRACER_INCLUDES=/opt/rocm/roctracer/include; fi
if [ -z "$ROCPROFILER_TEST" ]; then export ROCPROFILER_TEST=/opt/rocm/rocprofiler/test; fi
if [ -z "$ROCPROFILER_INCLUDES" ]; then export ROCPROFILER_INCLUDES=/opt/rocm/rocprofiler/include; fi

#Generate headers and cpp files for parsing
python3 ./scripts/kfd_args_gen.py $ROCTRACER_INCLUDES/kfd_prof_str.h
python3 ./scripts/hsa_args_gen.py $ROCTRACER_INCLUDES/hsa_prof_str.h
python3 ./scripts/hip_args_gen.py $HIP_PATH/hcc_detail/hip_prof_str.h

#Generate barectf files
if [ -n "$CLOCK_FREQUENCY" ]; then
	python3 ./scripts/update_frequency.py;
	barectf generate ./barectf_files/config.yaml --metadata-dir=./ --code-dir=./src --headers-dir=./inc;
fi

make all