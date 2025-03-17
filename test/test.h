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

#ifndef QLIBC_TEST_H
#define QLIBC_TEST_H

// using utest test framework
#include <utest.h>

// Test Configuration Argument

// Test Interactive (Explicit Output) Test flag
#define TEST_INTERACTIVE                0

// Macros for Host Machine Architecture String
#if (TEST_ARCH == X86_64)
#define HOST_MACHINE    "x86_64"
#endif
#if (TEST_ARCH == I386)
#define HOST_MACHINE    "i386"
#endif
#if (TEST_ARCH == ARM)
#define HOST_MACHINE    "arm"
#endif
#if (TEST_ARCH == AARCH64)
#define HOST_MACHINE    "aarch64"
#endif
#ifndef HOST_MACHINE
#define HOST_MACHINE    "Unknown"
#endif

#define QLIBC_TEST_INFO()       fprintf(stdout, "Test framework for qlibc %.1f \nIf the test "  \
                                "machine differ from host machine some if the test cases will " \
                                "be ignored !\n"                                                \
                                "Host Machine Architecture: " HOST_MACHINE   "\n"               \
                                "Test Machine Architecture: " QLIBC_ARCH_STR "\n\n",            \
                                (double)_QLIBC_VERSION_ / 10)

#define TEST_LIBC_BEGIN()       fprintf(stdout, "Start test for libc\n")
#define TEST_LIBC_END()         fputc('\n', stdout)

#define TEST_UNIX_BEGIN()       fprintf(stdout, "Start test for unix\n")
#define TEST_UNIX_END()         

// libc Test Module
extern TEST_CASE(assert);
extern TEST_CASE(stdbool);
extern TEST_CASE(ctype);
extern TEST_CASE(error);
extern TEST_CASE(limits);
extern TEST_CASE(stdnoreturn);
extern TEST_CASE(stdalign);
extern TEST_CASE(stddef);
extern TEST_CASE(stdint);
extern TEST_CASE(string);
extern TEST_CASE(stdarg);

#define RUN_LIBC_MODULE()               \
        TEST_LIBC_BEGIN();              \
        RUN_TEST_CASE(assert);          \
        RUN_TEST_CASE(stdbool);         \
        RUN_TEST_CASE(ctype);           \
        RUN_TEST_CASE(error);           \
        RUN_TEST_CASE(limits);          \
        RUN_TEST_CASE(stdnoreturn);     \
        RUN_TEST_CASE(stdalign);        \
        RUN_TEST_CASE(stddef);          \
        RUN_TEST_CASE(stdint);          \
        RUN_TEST_CASE(string);          \
        RUN_TEST_CASE(stdarg);          \
        TEST_LIBC_END();

// unix Test Module
extern TEST_CASE(fcntl);
extern TEST_CASE(sys);
extern TEST_CASE(unistd);

#define RUN_UNIX_MODULE()               \
        TEST_UNIX_BEGIN();              \
        RUN_TEST_CASE(fcntl);           \
        RUN_TEST_CASE(sys);             \
        RUN_TEST_CASE(unistd);          \
        TEST_UNIX_END();                

#define INIT_QLIBC_TEST()               \
        QLIBC_TEST_INFO();              \
        SET_OUTPUT_FORMAT               \
        (FORMAT_DEFAULT);               \

#ifdef RUN_ALL_TEST
#undef RUN_ALL_TEST
#endif

#define RUN_ALL_TEST()                  \
        INIT_QLIBC_TEST();              \
        RUN_LIBC_MODULE();              \
        RUN_UNIX_MODULE();

#endif 
