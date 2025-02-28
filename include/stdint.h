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

// Implementation of stdint Standard Integer Type library
#ifndef _QLIBC_STDINT_H
#define _QLIBC_STDINT_H

#include <features.h>

/**
 * In Version 0.1 only consider that the host environemnt
 * is freestanding which means it is in a independent kernel or
 * bare bone environment in 32-bits or 64-bits formal machine. 
 * So the types defined here will not consider conflict
 */

/// Type Define for Fixed Width Integer Type

// Signed Integer types
typedef signed char             int8_t;
typedef short                   int16_t;
typedef int                     int32_t;
typedef long long               int64_t;

typedef int8_t                  int_fast8_t;
typedef int16_t                 int_fast16_t;
typedef int32_t                 int_fast32_t;
typedef int64_t                 int_fast64_t;

typedef int8_t                  int_least8_t;
typedef int16_t                 int_least16_t;
typedef int32_t                 int_least32_t;
typedef int64_t                 int_least64_t;

typedef long                    intmax_t;

// Unsigned Integer types
typedef unsigned char           uint8_t;
typedef unsigned short          uint16_t;
typedef unsigned int            uint32_t;
typedef unsigned long long      uint64_t;

typedef uint8_t                 uint_fast8_t;
typedef uint16_t                uint_fast16_t;
typedef uint32_t                uint_fast32_t;
typedef uint64_t                uint_fast64_t;

typedef uint8_t                 uint_least8_t;
typedef uint16_t                uint_least16_t;
typedef uint32_t                uint_least32_t;
typedef uint64_t                uint_least64_t;

typedef unsigned long           uintmax_t;

/// Type define for Max and Min Value

// Basic Integer types
#define INT8_MIN                (-1-INT8_MAX)
#define INT16_MIN               (-1-INT16_MAX)
#define INT32_MIN               (-1-INT32_MAX)
#define INT64_MIN               (-1-INT64_MAX)

#define INT8_MAX                (0x7f)
#define INT16_MAX               (0x7fff)
#define INT32_MAX               (0x7fffffff)
#define INT64_MAX               (0x7fffffffffffffff)

#define UINT8_MAX               (0xff)
#define UINT16_MAX              (0xffff)
#define UINT32_MAX              (0xffffffff)
#define UINT64_MAX              (0xffffffffffffffff)

// Integer Fast Type
#define INT_FAST8_MIN           INT8_MIN
#define INT_FAST16_MIN          INT16_MIN
#define INT_FAST32_MIN          INT32_MIN
#define INT_FAST64_MIN          INT64_MIN

#define INT_FAST8_MAX           INT8_MAX
#define INT_FAST16_MAX          INT16_MAX
#define INT_FAST32_MAX          INT32_MAX
#define INT_FAST64_MAX          INT64_MAX

#define UINT_FAST8_MAX          UINT8_MAX
#define UINT_FAST16_MAX         UINT16_MAX
#define UINT_FAST32_MAX         UINT32_MAX
#define UINT_FAST64_MAX         UINT64_MAX

// Integer Least Type
#define INT_LEAST8_MIN          INT8_MIN
#define INT_LEAST16_MIN         INT16_MIN
#define INT_LEAST32_MIN         INT32_MIN
#define INT_LEAST64_MIN         INT64_MIN

#define INT_LEAST8_MAX          INT8_MAX
#define INT_LEAST16_MAX         INT16_MAX
#define INT_LEAST32_MAX         INT32_MAX
#define INT_LEAST64_MAX         INT64_MAX

#define UINT_LEAST8_MAX         UINT8_MAX
#define UINT_LEAST16_MAX        UINT16_MAX
#define UINT_LEAST32_MAX        UINT32_MAX
#define UINT_LEAST64_MAX        UINT64_MAX

// Other Integer Types
#define INTMAX_MIN              INT64_MIN
#define INTMAX_MAX              INT64_MAX
#define UINTMAX_MAX             UINT64_MAX

#define SIG_ATOMIC_MIN          INT32_MIN
#define SIG_ATOMIC_MAX          INT32_MAX

// WCHAR_MIN and WCHAR_MAX is a type define for unicode character
// The default size is 4 (UINT32) 
// And In this library the wchar_t is treated as unsigned wchar type
#if (defined(QLIBC_WCHAR_SUPPORT) && (QLIBC_WCHAR_SUPPORT == 1))
#warning "The type define WCHAR_MIN and WCHAR_MAX in stdint.h does not fully compatible !"
#else
#define WCHAR_MIN               0
#define WCHAR_MAX               UINT32_MAX
#endif              

#define WINT_MIN                0
#define WINT_MAX                UINT32_MAX

/// The types below depends on specific machine architecture
#include <bits/stdint.h>

typedef __intptr_t__            intptr_t;
typedef __uintptr_t__           uintptr_t;

#define INTPTR_MIN              __INTPTR_MIN__      
#define INTPTR_MAX              __INTPTR_MAX__      
#define UINTPTR_MAX             __UINTPTR_MAX__     
#define PTRDIFF_MIN             __PTRDIFF_MIN__     
#define PTRDIFF_MAX             __PTRDIFF_MAX__     
#define SIZE_MAX                __SIZE_MAX__        

#endif