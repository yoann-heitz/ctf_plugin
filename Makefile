CC = clang
CXX = clang++
BASIC_FLAGS = -fPIC -O3 -Wall
CXXFLAGS = $(BASIC_FLAGS) -std=c++11
RTR_FLAGS = $(CXXFLAGS) -D __HIP_PLATFORM_HCC__=1 -D __HIP_ROCclr__=1 -D HIP_VDI=1 -D AMD_INTERNAL_BUILD
AUX_FLAGS = $(RTR_FLAGS) -D HIP_PROF_HIP_API_STRING -D PROF_API_IMPL 
LINKFLAGS = --shared -lc -lstdc++
CIMP = -I ./inc -I $(ROCTRACER_SRC) -I $(HSA_INCLUDE) -I $(ROCM_PATH)/include -I $(ROCTRACER_INCLUDES) 
CIMP2 = -I ./inc -I $(ROCPROFILER_PATH)/test -I $(ROCPROFILER_PATH)/include -I $(HSA_INCLUDE)
SRC_DIR = src
AUX_DIR := src/aux
RTR_DIR := src/rtr
RPL_DIR := src/rpl
OBJ_DIR:= obj
C_NAMES := barectf.o barectf-platform-linux-fs.o
AUX_NAMES := roctracer_hip_aux.o roctracer_hsa_aux.o roctracer_kfd_aux.o
CPP_NAMES := hsa_args_str.o kfd_args_str.o hip_args_str.o 
RTR_NAMES := rtr_tool.o rtr_tracers.o
RPL_NAMES := rpl_tool.o rpl_tracers.o
COBJECTS := $(addprefix $(OBJ_DIR)/, $(C_NAMES))
AUXOBJECTS := $(addprefix $(OBJ_DIR)/, $(AUX_NAMES))
CPPOBJECTS := $(addprefix $(OBJ_DIR)/, $(CPP_NAMES))
RTROBJECTS := $(addprefix $(OBJ_DIR)/, $(RTR_NAMES))
RPLOBJECTS := $(addprefix $(OBJ_DIR)/, $(RPL_NAMES))
all: ctf_tool.so


ctf_tool.so: $(COBJECTS) $(AUXOBJECTS) $(CPPOBJECTS) $(RTROBJECTS) $(RPLOBJECTS) $(ROCM_PATH)/lib/libhsa-runtime64.so 
	$(CXX)	$(LINKFLAGS) $^	-o $@ 
clean:
	$(RM) $(OBJ_DIR)/*.o ctf_tool.so
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