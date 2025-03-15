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

# Dependent Makefile for test qlibc
include ../config/config.mk

# Path Relative Variable
TEST_DIR			:=		./cases
LIB_DIR				:=		../build
INCLUDE_DIR			:=		../include
ARCH_DIR			:=		../arch
INCLUDE_ARCH_DIR	:=		$(ARCH_DIR)/$(ARCH)
BUILD_DIR			:=		./build
UTEST_DIR			:=		./utest

# Set Test Architecture
TEST_ARCH			:=		$(ARCH)

# GNU C Compiler Flags
# Import from outer Makefile
# CC_WARNING CC_OPTIMIZER CC_DEBUGGER CC_ARCH

# GNU GCC Warning flags
CC_WARNING			+=		-Wno-unused-parameter
# GNU GCC Environment flags
CC_ENVIRONMENT		:=		-fno-builtin
# GNU GCC Macros flags
CC_MACROS			:=		
CC_MACROS			+=		-D QLIBC_ARCH_$(TEST_ARCH)
CC_MACROS			+=		-D QLIBC_ARCH_STR='"$(TEST_ARCH)"'
# GNU GCC Includes flags
CC_INCLUDES			:=		
# System Headers from qlibc
CC_INCLUDES			+=		-isystem $(INCLUDE_DIR)
CC_INCLUDES			+=		-isystem $(INCLUDE_ARCH_DIR)
CC_INCLUDES			+=		-isystem $(INCLUDE_DIR)/unix
# extern headers form test module
CC_INCLUDES			+=		-isystem $(UTEST_DIR)/include

CC_FLAGS			:=		-std=c$(STD)
CC_FLAGS			+=		$(CC_WARNING) $(CC_OPTIMIZER) $(CC_DEBUGGER) $(CC_ENVIRONMENT)
CC_FLAGS			+=		$(CC_INCLUDES) $(CC_MACROS) $(CC_ARCH)

# Directory Search
CASES_SRC			:=		$(sort $(shell find $(TEST_DIR) -name "*.c"))
CASES_OBJ			:=		$(CASES_SRC:.c=.o)
CASES_LIST			:=		$(addprefix $(BUILD_DIR)/, $(notdir $(CASES_OBJ)))
# Object File List
OBJ_LIST			:=		$(CASES_LIST) $(BUILD_DIR)/main.o $(BUILD_DIR)/utest.o

.DEFAULT_GOAL		:=		all
.PHONY				:=		all clean dir_check

all: dir_check main

main: $(OBJ_LIST)
ifeq ($(METHOD), static)
	@$(CC) $(LD_FLAGS) $^ -L$(LIB_DIR) -l$(LIB)-$(VERSION) -o ../main.out
	@echo "+ LD\t\tmain.out"
endif

dir_check:
	@mkdir -p $(BUILD_DIR)
clean:
	@rm -rf $(BUILD_DIR)
	@rm -f ../main.out 

# Define for sub-test cases dependencies

# Special Rule define for test string
STRING_UNIT				:=		test_string
TEST_STRING_DIR			:=		$(TEST_DIR)/$(STRING_UNIT)
CASES_STRING_DEP		:=		$(TEST_STRING_DIR)/character_array.h 	\
								$(TEST_STRING_DIR)/examination.h		\
								$(TEST_STRING_DIR)/manipulation.h		
$(BUILD_DIR)/$(STRING_UNIT).o: 	$(CASES_STRING_DEP)

# Special Rule define for test stdlib
STDLIB_UNIT				:=		test_stdlib
TEST_STDLIB_DIR			:=		$(TEST_DIR)/$(STDLIB_UNIT)
CASES_STRING_DEP		:=	
$(BUILD_DIR)/$(STDLIB_UNIT).o:	$(CASES_STRING_DEP)

# Special Rule define for test stdio
STDIO_UNIT				:=		test_stdio
TEST_STDIO_DIR			:=		$(TEST_DIR)/$(STDIO_UNIT)
CASES_STDIO_DEP			:=	
$(BUILD_DIR)/$(STDIO_UNIT).o:	$(CASES_STDIO_DEP)

# Special Rule define for test unistd
UNISTD_UNIT				:=		test_unistd
TEST_UNISTD_DIR			:=		$(TEST_DIR)/$(UNISTD_UNIT)
CASES_UNISTD_DEP		:=		$(TEST_UNISTD_DIR)/types.h		\
								$(TEST_UNISTD_DIR)/io.h
$(BUILD_DIR)/$(UNISTD_UNIT).o:	$(CASES_UNISTD_DEP)

# Special Rule defined for test sys
SYS_UNIT				:=		test_sys
TEST_SYS_DIR			:=		$(TEST_DIR)/$(SYS_UNIT)
CASES_SYS_DEP			:=		$(TEST_SYS_DIR)/syscall.h
$(BUILD_DIR)/$(SYS_UNIT).o:		$(CASES_SYS_DEP)

# General Rules for build test cases file
$(BUILD_DIR)/%.o : $(TEST_DIR)/%.c
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "+ CC\t\t$(notdir $<)"

$(BUILD_DIR)/main.o: main.c test.h
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "+ CC\t\t$<"

$(BUILD_DIR)/utest.o: $(UTEST_DIR)/utest.c
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "+ CC\t\t$(notdir $<)"