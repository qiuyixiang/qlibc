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

// Implement Variable Arguments

// the implementation of this library utility depends on
// low level architecture and System ABI

#ifndef _QLIBC_STDARG_H
#define _QLIBC_STDARG_H

#if (defined(__GNU_LIBRARY__) && (!FINISH))
typedef __builtin_va_list   __gnuc_va_list;
#endif

#if __GNUC__ >= 3

typedef __builtin_va_list   va_list;

#define va_start(ap, last)          __builtin_va_start(ap, last)
#define va_arg(ap, type)            __builtin_va_arg(ap, type)
#define va_end(ap)                  __builtin_va_end(ap)
#define va_copy(dest, src)          __builtin_va_copy(dest, src)

#else

#undef __va_start
#undef __va_arg
#undef __va_end
#undef __va_copy

#include <bits/stdarg.h>

typedef __va_list           va_list;

#define va_start(ap, last)          __va_start(ap, last)
#define va_arg(ap, type)            __va_arg(ap, type)
#define va_end(ap)                  __va_end(ap)
#define va_copy(dest, src)          __va_copy(dest, src)

#endif

#endif