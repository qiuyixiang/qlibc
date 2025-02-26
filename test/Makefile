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
BUILD_DIR			:=		./build

# GNU C Compiler Flags
CC_WARNING			+=		-Wno-unused-parameter
CC_ENVIRONMENT		:=		-fno-builtin
CC_FLAGS			:=		-std=c$(STD)
CC_FLAGS			+=		$(CC_WARNING) $(CC_OPTIMIZER) $(CC_DEBUGGER) $(CC_ENVIRONMENT)
CC_FLAGS			+=		-isystem $(INCLUDE_DIR)

# Directory Search
CASES_SRC			:=		$(sort $(shell find $(TEST_DIR) -name "*.c"))
CASES_OBJ			:=		$(CASES_SRC:.c=.o)
CASES_LIST			:=		$(addprefix $(BUILD_DIR)/, $(notdir $(CASES_OBJ)))
# Object File List
OBJ_LIST			:=		$(CASES_LIST) $(BUILD_DIR)/main.o

.DEFAULT_GOAL		:=		all
.PHONY				:=		all clean dir_check

all: dir_check main

main: $(OBJ_LIST)
ifeq ($(METHOD), static)
	@$(CC) $^ -L$(LIB_DIR) -l$(LIB)-$(VERSION) -o ../main.out
	@echo "+ LD\t\tmain.out"
endif

dir_check:
	@mkdir -p $(BUILD_DIR)
clean:
	@rm -rf $(BUILD_DIR)
	@rm -f ../main.out 

$(BUILD_DIR)/%.o : $(TEST_DIR)/%.c
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "+ CC\t\t$(notdir $<)"

$(BUILD_DIR)/main.o: main.c test.h
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "+ CC\t\t$<"