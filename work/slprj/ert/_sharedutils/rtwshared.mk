###########################################################################
## Makefile generated for component 'rtwshared'. 
## 
## Makefile     : rtwshared.mk
## Generated on : Wed Nov 13 15:46:51 2024
## Final product: ./rtwshared.a
## Product type : static library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = rtwshared
MAKEFILE                  = rtwshared.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2023a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2023a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/jakub/MATLAB/Projects/examples/asbQuadcopter2/work
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
MODELLIB                  = rtwshared.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Sourcery G++ Lite GNU Toolchain for Drones
# Supported Version(s):    
# ToolchainInfo Version:   2023a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# PARROT_GCCCOMPILER_DIR
# PARROT_GCCCOMPILER_BIN_DIR
# PARROT_GCCCOMPILER_LIB_DIR
# PARROT_GCCSourceryLite

#-----------
# MACROS
#-----------

SHELL                      = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Sourcery G++ Lite GNU Toolchain for Drones C Compiler
CC_PATH = $(PARROT_GCCSourceryLite)
CC = "$(CC_PATH)/arm-none-linux-gnueabi-gcc"

# Linker: Sourcery G++ Lite GNU Toolchain for Drones Linker
LD_PATH = $(PARROT_GCCSourceryLite)
LD = "$(LD_PATH)/arm-none-linux-gnueabi-gcc"

# C++ Compiler: Sourcery G++ Lite GNU Toolchain for Drones C Compiler
CPP_PATH = $(PARROT_GCCSourceryLite)
CPP = "$(CPP_PATH)/arm-none-linux-gnueabi-g++"

# C++ Linker: Sourcery G++ Lite GNU Toolchain for Drones C++ Linker
CPP_LD_PATH = $(PARROT_GCCSourceryLite)
CPP_LD = "$(CPP_LD_PATH)/arm-none-linux-gnueabi-gcc"

# Archiver: Sourcery G++ Lite GNU Toolchain for Drones Archiver
AR_PATH = $(PARROT_GCCSourceryLite)
AR = "$(AR_PATH)/arm-none-linux-gnueabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = -r
CFLAGS               = -c \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@" -O3 \
                       -DDELOS \
                       -DDELOS_EDU \
                       -fPIC \
                       -Wall
CPPFLAGS             =
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -shared
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./rtwshared.a
PRODUCT_TYPE = "static library"
BUILD_TYPE = "Model Reference Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/slprj/ert/_sharedutils -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2023a/toolbox/target/SUPPOR~1/parrot/include -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/toolbox/vision/include -I$(MATLAB_ROOT)/toolbox/shared/dsp/vision/matlab/include -I$(MATLAB_ROOT)/toolbox/shared/spc/src_ml/extern/include -I$(MATLAB_ROOT)/extern/include/multimedia -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DMW_HAS_IMAGE_PROCESSING -DR_CHANNEL -DG_CHANNEL -DB_CHANNEL -DY_CHANNEL -DU_CHANNEL -DV_CHANNEL
DEFINES_BUILD_ARGS = -DINTEGER_CODE=0 -DEXT_MODE=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DON_TARGET_WAIT_FOR_START=0
DEFINES_SKIPFORSIL = -DNRT -DXCP_CUSTOM_PLATFORM -D__linux__ -DDELOS -DDELOS_EDU -DEXTMODE_DISABLETESTING -DEXTMODE_STATIC_SIZE=16384 -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DPARROT_LINUX_COMM -DSTACK_SIZE=64 -DSTOP_TIME=30 -DMAMBO=1 -DMATFILE_LOGGING=1

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/slprj/ert/_sharedutils/rtGetInf.c $(START_DIR)/slprj/ert/_sharedutils/rtGetNaN.c $(START_DIR)/slprj/ert/_sharedutils/rt_nonfinite.c $(START_DIR)/slprj/ert/_sharedutils/rt_powf_snf.c $(START_DIR)/slprj/ert/_sharedutils/const_params.c $(START_DIR)/slprj/ert/_sharedutils/rt_roundd_snf.c $(START_DIR)/slprj/ert/_sharedutils/mean_0sSgOgPG.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = rtGetInf.o rtGetNaN.o rt_nonfinite.o rt_powf_snf.o const_params.o rt_roundd_snf.o mean_0sSgOgPG.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = 
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = 
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = 

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = 

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = 

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = 

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/slprj/ert/_sharedutils/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/slprj/ert/_sharedutils/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/slprj/ert/_sharedutils/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_powf_snf.o : $(START_DIR)/slprj/ert/_sharedutils/rt_powf_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


const_params.o : $(START_DIR)/slprj/ert/_sharedutils/const_params.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_roundd_snf.o : $(START_DIR)/slprj/ert/_sharedutils/rt_roundd_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mean_0sSgOgPG.o : $(START_DIR)/slprj/ert/_sharedutils/mean_0sSgOgPG.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


