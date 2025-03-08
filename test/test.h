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
#include <stdio.h>
#include <assert.h>

/// A Simple Utility Test Macros
#define CONCAT(LHS, RHS)                        LHS ## RHS
#define CONCAT3(VAL1, VAL2, VAL3)               VAL1 ## VAL2 ## VAL3   
#define CONCAT4(VAL1, VAL2, VAL3, VAL4)         VAL1 ## VAL2 ## VAL3 ## VAL4

#define STRING(VAR)         #VAR
#define BEGIN_DECL          {
#define END_DECL            }

#define EXPECT_TRUE(EXPR)                       assert((EXPR))
#define EXPECT_FALSE(EXPR)                      assert(!(EXPR))
#define EXPECT_EQ(VAL1, VAL2)                   assert((VAL1) == (VAL2))
#define EXPECT_NE(VAL1, VAL2)                   assert((VAL1) != (VAL2))

#define TEST_CASE(CASE)                         void CONCAT(test_, CASE)()
#define SUB_TEST_CASE(CASE)                     TEST_CASE(CASE)
#define RUN_SUB_CASE(CASE)                      CONCAT(test_, CASE)()


/**
 * The Macro TEST_ARCH and TEST_WORD is the two main control macros
 * for the test framework, they mainly support machine specific test
 * cases control. 
 */

/// Macros for Machine Architecture
#undef TEST_ARCH
#define NONE_ARCH       0
#define x86_64          1
#define i386            2
#define x86             3
#define arm             4
#define aarch64         5

/// Make sure that the consistence between target architecture and host architecture
#if ((defined(__x86_64__)) || defined(__amd64__)) && (defined(QLIBC_ARCH_x86_64))
#define TEST_ARCH       x86_64
#elif (defined(__i386__)) && (defined(QLIBC_ARCH_i386))
#define TEST_ARCH       i386
#elif (defined(__x86__)) && (defined(QLIBC_ARCH_x86))
#define TEST_ARCH       x86
#elif (defined(__arm__)) && (defined(QLIBC_ARCH_arm))
#define TEST_ARCH       arm
#elif (defined(__aarch64__)) && (defined(QLIBC_ARCH_aarch64))
#define TEST_ARCH       aarch64
#else
#define TEST_ARCH       NONE_ARCH
#endif

/// Macros for Machine word size
#undef TEST_WORD
#define BITS32          32
#define BITS64          64
#define NON_WORD_SIZE   0

#if (TEST_ARCH == i386) || (TEST_ARCH == x86) || (TEST_ARCH == arm)
#define TEST_WORD       BITS32
#elif (TEST_ARCH == x86_64) || (TEST_ARCH == aarch64)
#define TEST_WORD       BITS64
#else
#define TEST_WORD       NON_WORD_SIZE
#endif


/// Only main.c needs these interfaces
#ifdef MAIN_TEST

#define _COLOR_RESET        "\033[0m"
#define _COLOR_BLACK        "\033[30m"  
#define _COLOR_RED          "\033[31m"  
#define _COLOR_GREEN        "\033[32m"  
#define _COLOR_YELLOW       "\033[33m"  
#define _COLOR_BLUE         "\033[34m"  
#define _COLOR_MAGENTA      "\033[35m"  
#define _COLOR_CYAN         "\033[36m"  
#define _COLOR_WHITE        "\033[37m"  

// Macros for Host Machine Architecture String
#if (defined(__x86_64__)) || (defined(__amd64__))
#define HOST_MACHINE    "x86_64"
#endif
#ifdef __i386__
#define HOST_MACHINE    "i386"
#endif
#ifdef __x86__
#define HOST_MACHINE    "x86"
#endif
#ifdef __arm__
#define HOST_MACHINE    "arm"
#endif
#ifdef __aarch64__
#define HOST_MACHINE    "aarch64"
#endif

#ifndef HOST_MACHINE
#define HOST_MACHINE    "Unknown"
#endif

#define _RUN_SUCCESS(CASE)      fprintf(stdout, "[" _COLOR_GREEN "%s" _COLOR_RESET "] "         \
                                "\tTest Case Success\n", STRING(CASE))
#define RUN_TEST(CASE)          CONCAT(test_, CASE)();                                          \
                                _RUN_SUCCESS(CASE)    

#define SHOW_MACHINE(ARCH)      fprintf(stdout, "Test framework for qlibc %.1f \nIf the test "  \
                                "machine differ from host machine some if the test cases will " \
                                "be ignored !\n"                                                \
                                "Host Machine Architecture: " HOST_MACHINE   "\n"               \
                                "Test Machine Architecture: " QLIBC_ARCH_STR "\n\n",            \
                                _QLIBC_VERSION_)
                        
extern TEST_CASE(assert);
extern TEST_CASE(ctype);
extern TEST_CASE(stdbool);
extern TEST_CASE(stddef);
extern TEST_CASE(stdalign);
extern TEST_CASE(stdnoreturn);
extern TEST_CASE(stdint);
extern TEST_CASE(limits);
extern TEST_CASE(string);
extern TEST_CASE(unistd);

extern TEST_CASE(stdio);
extern TEST_CASE(stdlib);

#define RUN_ALL_TEST()          \
        RUN_TEST(assert);       \
        RUN_TEST(ctype);        \
        RUN_TEST(stdbool);      \
        RUN_TEST(stddef);       \
        RUN_TEST(stdalign);     \
        RUN_TEST(stdnoreturn);  \
        RUN_TEST(stdint);       \
        RUN_TEST(limits);       \
        RUN_TEST(string);       \
        RUN_TEST(unistd);

#ifdef assert
#undef assert
#endif

#endif 

#endif