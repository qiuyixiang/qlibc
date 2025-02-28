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
CC					:=		gcc
AR					:=		ar

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
CC_PREPROCESSOR		:=		
CC_PREPROCESSOR		+=		-I $(INCLUDE_DIR) -I $(INCLUDE_ARCH_DIR)

CC_FLAGS			:=		-std=c$(STD)
CC_FLAGS			+=		$(CC_WARNING) $(CC_OPTIMIZER) $(CC_DEBUGGER) \
							$(CC_ENVIRONMENT) $(CC_PREPROCESSOR)

export CC_WARNING CC_OPTIMIZER CC_DEBUGGER
export CC

# Options for Linker
LD_FLAGS			:=	
LD_FLAGS			+=		-nolibc -nostdlib
LD_FLAGS			+=		-nostartfiles 
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
.PHONY				:=	clean check_obj test lib

all: lib

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

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c
ifeq ($(VERBOSE), 1)
	$(CC) $(CC_FLAGS) -c $< -o $@
else
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "+ CC\t\t$(notdir $<)"
endif