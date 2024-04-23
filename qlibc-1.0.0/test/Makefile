# Makefile For Test Cases

# Formal Version qlibc 1.0.0

# Create on : 2024-04-23
# Copyright : QiuYiXiang


.DEFAULT_GOAL	:=	all

TEST_HEADERS	:=	config.h
TEST_NAME		:=	test
VERBOSE			?=  0
LIBRARY_DIR		:=	../lib
INCLUDE_DIR		:=	../include
LIBRARY			:=	$(LIBRARY_DIR)/$(NAME).a
TEST_INCLUDE	:=	-isystem $(INCLUDE_DIR) -iquote $(INCLUDE_DIR)

# Disable Detailed Information by Default
ifeq ($(VERBOSE), 0) 
define _CMD 
	@$(1)
endef
else
define _CMD
	$(1)
endef
endif

$(TEST_NAME).o : $(TEST_NAME).c $(TEST_HEADERS)
	$(call _CMD, $(GCC) $(FLAGS) $(TEST_INCLUDE) -c $< -o $@)

# Main Target For Building Test Cases
.PHONY: all 
all: $(TEST_NAME).o
	$(call _CMD, $(GCC) $(FLAGS) $< $(LIBRARY) -o $(TEST_NAME))
	$(call _CMD, -rm -f $(TEST_NAME).o)
	@echo "\\nBuild Test Cases Procedure for $(NAME) Successfully !"
