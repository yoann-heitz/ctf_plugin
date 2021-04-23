CC = clang
CXX = clang++
BASIC_FLAGS = -fPIC -O3 -Wall
CXXFLAGS = $(BASIC_FLAGS) -std=c++11
RTR_FLAGS = $(CXXFLAGS) -D __HIP_PLATFORM_HCC__=1 -D __HIP_ROCclr__=1 -D HIP_VDI=1 -D AMD_INTERNAL_BUILD
AUX_FLAGS = $(RTR_FLAGS) -D HIP_PROF_HIP_API_STRING -D PROF_API_IMPL 
LINKFLAGS = --shared -lc -lstdc++
CIMP = -I ./inc -I $(ROCTRACER_SRC) -I $(HSA_INCLUDE) -I $(ROCM_PATH)/include -I $(ROCTRACER_INCLUDES) 
CIMP2 = -I ./inc -I $(ROCPROFILER_TEST) -I $(ROCPROFILER_INCLUDES) -I $(HSA_INCLUDE)
SRC_DIR = src
AUX_DIR := src/aux
ROCTRACER_FILES_DIR := src/roctracer_files
ROCPROFILER_FILES_DIR := src/rocprofiler_files
OBJ_DIR:= obj
C_NAMES := barectf barectf-platform-linux-fs
AUX_NAMES := roctracer_hip_aux roctracer_hsa_aux roctracer_kfd_aux
CPP_NAMES := hsa_args_str kfd_args_str hip_args_str 
ROCTRACER_NAMES := roctracer_tool roctracer_tracers.o
ROCPROFILER_NAMES := rocprofiler_tool.o rocprofiler_tracers.o
C_OBJECTS := $(addsuffix $(addprefix $(OBJ_DIR)/, $(C_NAMES)), .o)
AUX_OBJECTS := $(addsuffix $(addprefix $(OBJ_DIR)/, $(AUX_NAMES)), .o)
CPP_OBJECTS := $(addsuffix $(addprefix $(OBJ_DIR)/, $(CPP_NAMES)), .o)
ROCTRACER_OBJECTS := $(addsuffix $(addprefix $(OBJ_DIR)/, $(ROCTRACER_NAMES)), .o)
ROCPROFILER_OBJECTS := $(addsuffix $(addprefix $(OBJ_DIR)/, $(ROCPROFILER_NAMES)), .o)
all: rocprofiler_ctf_tool.so roctracer_ctf_tool.so


rocprofiler_ctf_tool.so: $(C_OBJECTS) $(AUX_OBJECTS) $(CPP_OBJECTS) $(ROCPROFILER_OBJECTS) $(ROCM_PATH)/lib/libhsa-runtime64.so 
	$(CXX)	$(LINKFLAGS) $^	-o $@
	
roctracer_ctf_tool.so: $(C_OBJECTS) $(AUX_OBJECTS) $(CPP_OBJECTS) $(ROCTRACER_OBJECTS) $(ROCM_PATH)/lib/libhsa-runtime64.so 
	$(CXX)	$(LINKFLAGS) $^	-o $@ 
		 
clean:
	$(RM) $(OBJ_DIR)/*.o rocprofiler_ctf_tool.so roctracer_ctf_tool.so
.PHONY : all clean

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(BASIC_FLAGS) $(CIMP) -c $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(RTR_FLAGS) $(CIMP) -c $^ -o $@

$(OBJ_DIR)/%.o: $(AUX_DIR)/%.cpp
	$(CXX) $(AUX_FLAGS)	$(CIMP) -c $^ -o $@
	
$(OBJ_DIR)/%.o: $(RTR_DIR)/%.cpp
	$(CXX) $(RTR_FLAGS)	$(CIMP) -c $^ -o $@

$(OBJ_DIR)/%.o: $(RPL_DIR)/%.cpp
	$(CXX) $(CXXFLAGS)	$(CIMP2) -c $^ -o $@
