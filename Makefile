# MIT License
#
# Copyright (c) 2025 QIU YIXIANG
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Makefile for qlibc Don't modify anything here 
# Change configuration variable in config/config.mk

include ./config/config.mk

# Tool Configuration
CC					:=		$(TOOL_CHAIN)-gcc
AR					:=		$(TOOL_CHAIN)-ar

# Path Relative Variable
SOURCE_DIR			:=		./src
INCLUDE_DIR			:=		./include
CONFIG_DIR			:=		./config
BUILD_DIR			:=		./build
ARCH_DIR			:=		./arch
TEST_DIR			:=		./test
OBJ_DIR				:=		$(BUILD_DIR)/obj
INCLUDE_ARCH_DIR	:=		$(ARCH_DIR)/$(ARCH)

# Check Command Line Argument
ifdef V
VERBOSE				:=		$(V)
endif

# Macro for Host OS
HOST_OS				:=		$(shell uname)

# GNU C Compiler Flags

# Options for Warning message
CC_WARNING			:=		-Wall -Wextra -Werror 
# Options for Optimization
CC_OPTIMIZER		:=		
ifeq ($(DEBUG), false)
CC_OPTIMIZER		+=		-O3
else
CC_OPTIMIZER		+=		-O0
endif
# Options for Debugger
CC_DEBUGGER			:=
ifeq ($(DEBUG), true)
CC_DEBUGGER			+=		-ggdb -g2
endif
# Options for Freestanding environment
CC_ENVIRONMENT		:=		
# FSE_CPP				:=		-nostdinc
FSE_CC				:=		-ffreestanding -fno-builtin
CC_ENVIRONMENT		+=		$(FSE_CPP) $(FSE_CC)

# Options for Preprocessor
# Include Search Directory List: 
#		include/ 	include/unix	arch/ARCH
CC_INCLUDES			:=		
CC_INCLUDES			+=		-I $(INCLUDE_DIR)
CC_INCLUDES			+=		-I $(INCLUDE_ARCH_DIR)
CC_INCLUDES			+=		-I $(INCLUDE_DIR)/unix
# Options for Architecture
CC_ARCH				:=		
ifeq ($(ARCH), i386)
CC_ARCH				+=		-m32
endif

CC_FLAGS			:=		-std=c$(STD)
CC_FLAGS			+=		$(CC_WARNING) $(CC_OPTIMIZER) $(CC_DEBUGGER) \
							$(CC_ENVIRONMENT) $(CC_INCLUDES) $(CC_ARCH)

export CC_WARNING CC_OPTIMIZER CC_DEBUGGER CC_ARCH
export CC

# Options for Linker
LD_FLAGS			:=	
# LD_FLAGS			+=		-nolibc -nostdlib
# LD_FLAGS			+=		-nostartfiles 
ifeq ($(ARCH), i386)
LD_FLAGS			+=		-m32
endif

export LD_FLAGS

# Source File List
SRC_LIST			:=		$(sort $(shell find $(SOURCE_DIR) -name "*.c"))
ARCH_LIST			:=		$(sort $(shell find $(ARCH_DIR) -name "*.c"))

ALL_SRC_LIST		:=		
ALL_SRC_LIST		+=		$(SRC_LIST)
ALL_SRC_LIST		+=		$(ARCH_LIST)

# Object File List
OBJ_LIST			:=		$(ALL_SRC_LIST:.c=.o)
OBJ_LIST			:=		$(addprefix $(OBJ_DIR)/, $(notdir $(OBJ_LIST)))

.DEFAULT_GOAL		:=	all
.PHONY				:=	clean check_obj test lib install check_arch

all: check_arch lib

# Build the qlibc library
lib: check_obj info $(OBJ_LIST)
# Build for static library
ifeq ($(METHOD), static)
ifeq ($(VERBOSE), 1)
	$(AR) rcs $(BUILD_DIR)/lib$(LIB)-$(VERSION).a $(OBJ_LIST)
else 
	@$(AR) rcs $(BUILD_DIR)/lib$(LIB)-$(VERSION).a $(OBJ_LIST)
	@echo "+ AR\t\tlib$(LIB)-$(VERSION).a"
endif
# Build for dynamic library

endif
	@echo "Successfully build the $(METHOD) library in : $(BUILD_DIR)/lib$(LIB)-$(VERSION).a\n"

# Show Qlibc Version Information
info:
	@echo "Qlibc A light-weighted C Standard Library Which is fully portable to any system."
	@echo "Current build Version: $(VERSION)"
	@echo "Copyright (C) QIU YIXIANG"
	@echo "For more information using the command <make help>\n"

test: lib
	@$(MAKE) -C $(TEST_DIR)

check_obj:
	@mkdir -p $(OBJ_DIR)
clean:
	@rm -rf	$(BUILD_DIR)
	@$(MAKE) -C $(TEST_DIR) clean

# Architecture Compatible Check for Host OS
check_arch:
ifeq ($(HOST_OS), Darwin)
ifneq ($(ARCH), aarch64)
ifndef TOOL_CHAIN
	$(error Your Host OS is incompatible with target arch $(ARCH) \
	please configure TOOL_CHAIN in config/config.mk)
endif
endif
endif

# install target
install: lib

# Build objs in src/*.c
$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c
ifeq ($(VERBOSE), 1)
	$(CC) $(CC_FLAGS) -c $< -o $@
else
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "+ CC\t\t$(notdir $<)"
endif

# Build objs in arch/*.c
$(OBJ_DIR)/%.o: $(ARCH_DIR)/$(ARCH)/%.c
ifeq ($(VERBOSE), 1)
	$(CC) $(CC_FLAGS) -c $< -o $@
else
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "+ CC\t\t$(notdir $<)"
endif