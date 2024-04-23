# This Makefile Is only used For Test Cases !!!

# Create On : 2024-04-23
# Copyright : QiuYiXiang

# Some Flags Used For GNU GCC
TEST_CASE	:=		main

INCLUDE_DIR_T 	:= 	../include
LIBRARY			:=	../lib/$(NAME).a

WARNING		:=	-Wall -Wextra -Wshadow
INCLUDES	:=	-iquote $(INCLUDE_DIR_T) -isystem $(INCLUDE_DIR_T)
SANITIZER	:=	-fsanitize=address 

FLAGS	:=	-O3  $(STD_VERSION)
FLAGS	+=	$(WARNING) $(INCLUDES)

TEST_NAME	:=	test

# If V == 0 (default) it will show nothing
ifeq ($(V), 0)
define CMD
	@$(1)
endef
else
define CMD
	$(1)
endef
endif

.DEFAULT_GOAL := all

all: $(TEST_CASE).c
	$(call CMD, $(GCC) $(FLAGS) $< $(LIBRARY) -o $(TEST_NAME))
	$(call CMD, rm -f $(TEST_CASE).o)
	@echo "Build Test Program Successfully !"