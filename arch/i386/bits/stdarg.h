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

#ifndef _QLIBC_I386_STDARG_H
#define _QLIBC_I386_STDARG_H

// implementation of variable arguments in i386
// all of the arguments in function are passed through
// stack in x86 or i386

typedef char * __va_list;

#define __va_start(arg_ptr, last_fixed_arg)         ((arg_ptr) = (__va_list)&last_fixed_arg + sizeof(last_fixed_arg))
#define __va_arg(arg_ptr, type)                     (*(type *)((arg_ptr += sizeof(type)) - sizeof(type)))
#define __va_end(arg_ptr)                           ((arg_ptr) = (__va_list)0)
#define __va_copy(dest, src)                        ((dest) = (src))

#endif