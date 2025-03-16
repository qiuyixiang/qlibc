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

#ifndef _UTIL_UTEST_H
#define _UTIL_UTEST_H

#ifndef UTIL_UTEST_H
#error "Never use <_utest.h> directly; include <utest.h> instead."
#endif

// this macro will force enable assert
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#undef ASSERT_TRUE
#undef ASSERT_FALSE
#undef ASSERT_EQ
#undef ASSERT_NE
#undef ASSERT_GT
#undef ASSERT_GE
#undef ASSERT_LT
#undef ASSERT_LE

#define ASSERT_TRUE(EXPR)                   assert((EXPR))
#define ASSERT_FALSE(EXPR)                  assert(!(EXPR))
#define ASSERT_EQ(VAL1, VAL2)               assert((VAL1) == (VAL2))
#define ASSERT_NE(VAL1, VAL2)               assert((VAL1) != (VAL2))
#define ASSERT_GT(VAL1, VAL2)               assert((VAL1) > (VAL2))
#define ASSERT_GE(VAL1, VAL2)               assert((VAL1) >= (VAL2))
#define ASSERT_LT(VAL1, VAL2)               assert((VAL1) < (VAL2))
#define ASSERT_LE(VAL1, VAL2)               assert((VAL1) <= (VAL2))

#undef EXPECT_TRUE
#undef EXPECT_FALSE
#undef EXPECT_EQ
#undef EXPECT_NE
#undef EXPECT_GT
#undef EXPECT_GE
#undef EXPECT_LT
#undef EXPECT_LE

#define EXPECT_TRUE(EXPR)                   ASSERT_TRUE(EXPR)               
#define EXPECT_FALSE(EXPR)                  ASSERT_FALSE(EXPR)                
#define EXPECT_EQ(VAL1, VAL2)               ASSERT_EQ(VAL1, VAL2)                  
#define EXPECT_NE(VAL1, VAL2)               ASSERT_NE(VAL1, VAL2)
#define EXPECT_GT(VAL1, VAL2)               ASSERT_GT(VAL1, VAL2)
#define EXPECT_GE(VAL1, VAL2)               ASSERT_GE(VAL1, VAL2)
#define EXPECT_LT(VAL1, VAL2)               ASSERT_LT(VAL1, VAL2)
#define EXPECT_LE(VAL1, VAL2)               ASSERT_LT(VAL1, VAL2)

#undef EXPECT_STR_EQ
#undef EXPECT_STR_NE

#define EXPECT_STR_EQ(STR1, STR2)           EXPECT_FALSE((strcmp(STR1, STR2)))
#define EXPECT_STR_NE(STR1, STR2)           EXPECT_TRUE((strcmp(STR1, STR2)))

#undef CONCAT
#undef CONCAT3
#undef CONCAT4
#undef STRING

#define CONCAT(LHS, RHS)                    LHS ## RHS
#define CONCAT3(VAL1, VAL2, VAL3)           VAL1 ## VAL2 ## VAL3   
#define CONCAT4(VAL1, VAL2, VAL3, VAL4)     VAL1 ## VAL2 ## VAL3 ## VAL4
#define STRING(VAR)                         #VAR

#undef BEGIN_DECL
#undef END_DECL

#define BEGIN_DECL                          {
#define END_DECL                            }

// macros for ascii color
#define _COLOR_RESET        "\033[0m"
#define _COLOR_BLACK        "\033[30m"
#define _COLOR_RED          "\033[31m"
#define _COLOR_GREEN        "\033[32m"
#define _COLOR_YELLOW       "\033[33m"
#define _COLOR_BLUE         "\033[34m"
#define _COLOR_MAGENTA      "\033[35m"
#define _COLOR_CYAN         "\033[36m"
#define _COLOR_WHITE        "\033[37m"

#define _ATTR_CONSTRUCTOR       __attribute__((constructor))
#define _ATTR_DESTRUCTOR        __attribute__((destructor))

#undef TEST_WORD    
#undef TEST_ARCH

// machine architecture detection
#if (defined(__i386__))
#define TEST_ARCH       I386
#define TEST_WORD       BITS32
#endif
#if (defined(__x86_64__))
#define TEST_ARCH       X86_64
#define TEST_WORD       BITS64
#endif
#if (defined(__arm__))
#define TEST_ARCH       ARM
#define TEST_WORD       BITS32
#endif
#if (defined(__aarch64__))
#define TEST_ARCH       AARCH64
#define TEST_WORD       BITS64
#endif

extern _ATTR_CONSTRUCTOR void _init_utest(void);
extern _ATTR_DESTRUCTOR void _fini_utest(void);
extern void _run_test(void(*__case_handler)(), const char * __case, uint32_t __flag);

extern uint32_t __global_test_counter;
extern uint32_t __global_subtest_counter;
extern uint32_t __global_ot_format;

#define FLAG_TEST_CASE                      1
#define FLAG_SUB_TEST_CASE                  (FLAG_TEST_CASE << 1)
#define FLAG_PURE_FUNC                      (FLAG_TEST_CASE << 2)
#define FLAG_HAS_SUB_CASE                   (FLAG_TEST_CASE | FLAG_SUB_TEST_CASE)

#define FORMAT_DEFAULT                      1
#define FORMAT_TIGHT                        (FORMAT_DEFAULT << 1)

#undef SET_OUTPUT_FORMAT
#define SET_OUTPUT_FORMAT(FORMAT)           __global_ot_format = FORMAT

#define _DECLARE_FUNC(NAME)                 void CONCAT(_test_, NAME)(void)
#define _RUN_FUNC(NAME)                     CONCAT(_test_, NAME)()
#define _RUN_TEST(CASE, FLAG)               _run_test(&CONCAT(_test_, CASE), STRING(CASE), FLAG)

#undef TEST_CASE
#undef SUB_TEST_CASE

#define TEST_CASE(CASE)                     _DECLARE_FUNC(CASE)
#define SUB_TEST_CASE(SUBCASE)              _DECLARE_FUNC(SUBCASE)

#undef RUN_TEST_CASE
#undef RUN_SUB_TEST_CASE
#undef RUN_TEST_FLAG

#define RUN_TEST_CASE(CASE)                 RUN_TEST_FLAG(CASE, FLAG_TEST_CASE)
#define RUN_SUB_TEST_CASE(CASE)             RUN_TEST_FLAG(CASE, FLAG_SUB_TEST_CASE)
#define RUN_TEST_FLAG(CASE, FLAG)           _RUN_TEST(CASE, FLAG)
               
#undef RUN_ALL_TEST
#define RUN_ALL_TEST()

#endif