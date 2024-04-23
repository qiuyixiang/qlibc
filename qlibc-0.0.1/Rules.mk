# Global Variables For qlibc
# Create On : 2024-04-23
# Copyright : QiuYiXiang

# Define Some Tools
GCC		?=		gcc
CXX		?=		g++-11
AR		:=		ar
MKDIR	:=		mkdir
DELETE	:=		-rm

# Specify File Path
INCLUDE_DIR		:=		./include
SOURCE_DIR		:=		./src
BUILD_DIR		:=		./build
TEST_DIR		:=		./test
LIBRARY_DIR		:=		./lib

# GNU CC Flags

WARNING		:=	-Wall -Wextra -Wshadow
INCLUDES	:=	-iquote $(INCLUDE_DIR) -isystem $(INCLUDE_DIR)
SANITIZER	:=	-fsanitize=address

FLAGS	:=	-O3 $(STD_VERSION)
FLAGS	+=	$(WARNING) $(INCLUDES) 

# Library Macro
LIBRARY_NAME		:=	qlibc
LIBRARY_VERSION		:=	0.0.1
NAME				:=	$(LIBRARY_NAME)-$(LIBRARY_VERSION)

# Define Some General Functions Here !

# The Switch For The Whole Project
# Show All Information Related about Compilation
V ?= 0
# If V == 0 (default) it will show nothing
ifeq ($(V), 0)
define _cmd
	@$(1)
endef
else
define _cmd
	$(1)
endef
endif

# Define Functions For Check Whether a File Exist
define _check
	$(call _cmd, $(MKDIR) -p $(1))
endef
 




