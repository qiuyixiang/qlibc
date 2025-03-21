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

# All variables declared here

# Target Architecture 
# Current Support Architecture : i386, x86_64
ARCH 			:=		i386

# Library build information
LIB				:=		qlibc
VERSION			:=		0.1

# Library Build Method 
# Current Support Method : static
METHOD			:=		static

# Debugger flag
DEBUG			:=		false

# Compiler and toolchain
# Undefine this macro and add value when you want use 
# cross compiler
# TOOL_CHAIN		:=		x86_64-elf

# C ANSI/ISO standard version
STD				:=		11

# Verbose Display
VERBOSE			:=		0