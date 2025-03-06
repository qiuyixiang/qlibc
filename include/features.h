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

// Define Some Feature Support For Qlibc Library
// This file is not part of ANSI/ISO C Standard Library
#ifndef _QLIBC_FEATURES_H
#define _QLIBC_FEATURES_H

#define _MACRO_CONCAT(_VAR1, _VAR2)     _VAR1##_VAR2
#define _MACRO_STR(_VAR)                #_VAR

#define _STDC_C90   199009L
#define _STDC_C95   199409L
#define _STDC_C99   199901L
#define _STDC_C11   201112L
#define _STDC_C17   201710L
#define _STDC_C23   202311L

// Macro for specify whether qlibc is finished
#define FINISH                      0
// Current Version of the qlibc doesn't support for unicode encoding
#define QLIBC_WCHAR_SUPPORT         0

// Macros for the qlibc library version
#ifndef QLIBC_VERSION
#define _QLIBC_VERSION_             0.1
#else
#define _QLIBC_VERSION_             QLIBC_VERSION     
#endif

// Macros for POSIX Consistency
#define QLIBC_POSIX_FINISH          0

/// Compatible with glibc features when qlibc is not finished
#if (defined(FINISH)) && (FINISH == 0) && (defined(__linux__))
#include </usr/include/features.h>
#endif

#endif