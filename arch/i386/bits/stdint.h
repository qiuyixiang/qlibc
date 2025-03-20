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

// Integer type implementation for i386 architecture

// Integer Fast Type
typedef int8_t                  int_fast8_t;
typedef int32_t                 int_fast16_t;
typedef int32_t                 int_fast32_t;
typedef int64_t                 int_fast64_t;

typedef uint8_t                 uint_fast8_t;
typedef uint32_t                uint_fast16_t;
typedef uint32_t                uint_fast32_t;
typedef uint64_t                uint_fast64_t;

#define INT_FAST8_MIN           INT8_MIN
#define INT_FAST16_MIN          INT32_MIN
#define INT_FAST32_MIN          INT32_MIN
#define INT_FAST64_MIN          INT64_MIN

#define INT_FAST8_MAX           INT8_MAX
#define INT_FAST16_MAX          INT32_MAX
#define INT_FAST32_MAX          INT32_MAX
#define INT_FAST64_MAX          INT64_MAX

#define UINT_FAST8_MAX          UINT8_MAX
#define UINT_FAST16_MAX         UINT32_MAX
#define UINT_FAST32_MAX         UINT32_MAX
#define UINT_FAST64_MAX         UINT64_MAX

typedef int32_t                 intptr_t;
typedef uint32_t                uintptr_t;

#define INTPTR_MIN              INT32_MIN      
#define INTPTR_MAX              INT32_MAX      
#define UINTPTR_MAX             UINT32_MAX
     
#define PTRDIFF_MIN             INT32_MIN     
#define PTRDIFF_MAX             INT32_MAX     
#define SIZE_MAX                UINT32_MAX   