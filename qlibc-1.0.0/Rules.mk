# This File Is Part Of qlibc 1.0.0 Formal Version
# Create on : 2024-04-23
# Copyright : QiuYiXiang


# Global Makefile

# Macros For GNU CPP
GCC		?=		gcc
GXX		?=		g++
AR		:=		ar
DELETE	:=		-rm
MKDIR	:=		mkdir

FLAGS		:=	-O3
V			?= 	0
VERBOSE		:= $(V)

GNU_VERSION	:=	-std=gnu89
WARNING		:=	-Wall -Wextra -Wshadow
DEBUGGER	:=	-g
# Flags For GNU GCC
FLAGS		+=	$(WARNING) $(GNU_VERSION)

# Macros For qlibc
LIBRARY_NAME	:=	qlibc
LIBRARY_VERSION	:=	1.0.0
NAME			:=	$(LIBRARY_NAME)-$(LIBRARY_VERSION)

# Macros For Directories
INCLUDE_DIR		:=	./include
SOURCE_DIR		:=	./src
BUILD_DIR		:=	./build
LIBRARY_DIR		:=	./lib
TEST_DIR		:=	./test

# Export Variables
export GCC
export FLAGS
export NAME
# Define Some Auxiliary Function

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

define _CHECK
	$(call _CMD, $(MKDIR) -p $(1))
endef

define _SHOW
	@echo $(1)
endef