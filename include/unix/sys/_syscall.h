/**
 *  MIT License
 *
 *  Copyright (c) 2025 QIU YIXIANG
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */
// internal implementation of syscall
#ifndef _QLIBC_SYS__SYSCALL
#define _QLIBC_SYS__SYSCALL

#include <bits/syscall.h>

#ifndef SYSCALL_ARG_T
#error "Need SYSCALL_ARG_T"
#endif

#ifndef SYSCALL_RET_T
#error "Need SYSCALL_RET_T"
#endif

#define cast_arg(X)         ((SYSCALL_ARG_T) (X))
#define cast_ret(X)         ((SYSCALL_RET_T) (X))

// all arch implementation of syscall must comply these interfaces
// must support functions __syscall0 - __syscall6
// and type or macros for SYSCALL_ARG_T and SYSCALL_RET_T

#undef _syscall0
#undef _syscall1
#undef _syscall2
#undef _syscall3
#undef _syscall4
#undef _syscall5
#undef _syscall6

#define _syscall0(NR)                   cast_ret(__syscall0(cast_arg(NR)))
#define _syscall1(NR, ARG1)             cast_ret(__syscall1(cast_arg(NR), cast_arg(ARG1)))
#define _syscall2(NR, ARG1, ARG2)       cast_ret(__syscall2(cast_arg(NR), cast_arg(ARG1), cast_arg(ARG2)))

#define _syscall3(NR, ARG1, ARG2, ARG3)                     \
    cast_ret(__syscall3(cast_arg(NR), cast_arg(ARG1),       \
    cast_arg(ARG2), cast_arg(ARG3)))

#define _syscall4(NR, ARG1, ARG2, ARG3, ARG4)               \
    cast_ret(__syscall4(cast_arg(NR), cast_arg(ARG1),       \
    cast_arg(ARG2), cast_arg(ARG3)), cast_arg(ARG4))

#define _syscall5(NR, ARG1, ARG2, ARG3, ARG4, ARG5)         \
    cast_ret(__syscall5(cast_arg(NR), cast_arg(ARG1),       \
    cast_arg(ARG2), cast_arg(ARG3)), cast_arg(ARG4),        \
    cast_arg(ARG5))

#define _syscall6(NR, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6)   \
    cast_ret(__syscall6(cast_arg(NR), cast_arg(ARG1),       \
    cast_arg(ARG2), cast_arg(ARG3)), cast_arg(ARG4),        \
    cast_arg(ARG5), cast_arg(ARG6))

#define __SYSCALL_CONCAT_X(X, Y)    X##Y
#define __SYSCALL_CONCAT(X, Y)      __SYSCALL_CONCAT_X(X, Y)
#define __SYSCALL_NARGS_X(arg1, arg2, arg3, arg4, arg5, arg6, arg7, n, ...)    n      
#define __SYSCALL_NARGS(...)        __SYSCALL_NARGS_X(__VA_ARGS__,6,5,4,3,2,1,0)
#define __SYSCALL(PREFIX, ...)      __SYSCALL_CONCAT(PREFIX, __SYSCALL_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define syscall(...)                __SYSCALL(_syscall, __VA_ARGS__)

#endif