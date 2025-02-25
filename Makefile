# MIT License
#
# Copyright (c) 2025 unsigned
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


CC					:=		gcc

# Path Relative Variable
SOURCE_DIR			:=		./src
INCLUDE_DIR			:=		./include
CONFIG_DIR			:=		./config
BUILD_DIR			:=		./build
ARCH_DIR			:=		./arch
OBJ_DIR				:=		$(BUILD_DIR)/obj

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
FSE_CPP				:=		-nostdinc
FSE_CC				:=		-ffreestanding -fno-builtin
CC_ENVIRONMENT		+=		$(FSE_CPP) $(FSE_CC)
# Options for Preprocessor
CC_PREPROCESSOR		:=		
CC_PREPROCESSOR		+=		-I $(INCLUDE_DIR)

CC_FLAGS			:=		-std=c$(STD)
CC_FLAGS			+=		$(CC_WARNING) $(CC_OPTIMIZER) $(CC_DEBUGGER) \
							$(CC_ENVIRONMENT) $(CC_PREPROCESSOR)

# Source File List
SRC_LIST			:=		$(sort $(shell find $(SOURCE_DIR) -name "*.c"))
ARCH_LIST			:=		$(sort $(shell find $(ARCH_DIR) -name "*.c"))

ALL_SRC_LIST		:=		
ALL_SRC_LIST		+=		$(SRC_LIST)
ALL_SRC_LIST		+=		$(ARCH_LIST)

# Object File List
OBJ_LIST			:=		$(ALL_SRC_LIST:.c=.o)


.DEFAULT_GOAL		:=	all
all:
	@echo $(OBJ_LIST)