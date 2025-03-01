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
#ifndef _QLIBC_LIMITS_H
#define _QLIBC_LIMITS_H

// Undefine Macros form other system headers
#undef  SCHAR_MIN
#undef  SCHAR_MAX
#undef  UCHAR_MAX
#undef  SHRT_MIN
#undef  SHRT_MAX
#undef  USHRT_MAX
#undef  INT_MIN
#undef  INT_MAX
#undef  UINT_MAX
#undef  LONG_MIN
#undef  LONG_MAX
#undef  ULONG_MAX

#undef  CHAR_BIT
#undef  CHAR_MIN
#undef  CHAR_MAX

#include <features.h>
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= _STDC_C23))
#define BOOL_WIDTH      8
#define BOOL_MAX        1
#endif

#define CHAR_BIT        8

#if (defined(QLIBC_WCHAR_SUPPORT) && (QLIBC_WCHAR_SUPPORT == 1))
#include <bits/limits>
#define MB_LEN_MAX      __MB_LEN_MAX__ 
#else
#define MB_LEN_MAX      4
#endif

#if '\0' - 1 > 0
// Unsigned char
#define CHAR_MIN        0
#define CHAR_MAX        255
#else
// Signed char
#define CHAR_MIN        (-128)
#define CHAR_MAX        127
#endif

#include <bits/limits.h>

#define SCHAR_MAX       127
#define SHRT_MAX        0x7fff
#define INT_MAX         0x7fffffff
#define LONG_MAX        __LONG_MAX__
#define LLONG_MAX       __LLONG_MAX__

#define SCHAR_MIN       (-128)
#define SHRT_MIN        (-1-SHRT_MAX)
#define INT_MIN         (-1-INT_MAX)
#define LONG_MIN        __LONG_MIN__
#define LLONG_MIN       __LLONG_MIN__

#define UCHAR_MAX       255
#define USHRT_MAX       0xffff
#define UINT_MAX        0xffffffffU
#define ULONG_MAX       __ULONG_MAX__
#define ULLONG_MAX      __ULLONG_MAX__

#endif