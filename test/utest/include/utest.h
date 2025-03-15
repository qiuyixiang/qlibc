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

#ifndef UTIL_UTEST_H
#define UTIL_UTEST_H

// this module is part of project util and this header provide public interfaces of utest module
// utest is a simple unit test module which support many facility macros

// @version: utest 0.1
// @author: QIU YIXIANG

// test case assertion
#define ASSERT_TRUE(EXPR)
#define ASSERT_FALSE(EXPR)
#define ASSERT_EQ(VAL1, VAL2)
#define ASSERT_NE(VAL1, VAL2)

#define EXPECT_TRUE(EXPR)                    
#define EXPECT_FALSE(EXPR)                  
#define EXPECT_EQ(VAL1, VAL2)                 
#define EXPECT_NE(VAL1, VAL2)

#define EXPECT_STR_EQ(STR1, STR2)
#define EXPECT_STR_NE(STR1, STR2)

// simple test utility support
#define CONCAT(LHS, RHS)                        
#define CONCAT3(VAL1, VAL2, VAL3)              
#define CONCAT4(VAL1, VAL2, VAL3, VAL4)    
#define STRING(VAR)         

#define BEGIN_DECL   
#define END_DECL

// test arch information
#define BITS32          32
#define BITS64          64

#define NON_ARCH        0
#define I386            1
#define X86_64          2
#define ARM             3
#define AARCH64         4
#define RISC32          5
#define RISC64          6

// A macro specify the test machine architecture
#define TEST_ARCH 
// A macro specify the test machine word size
#define TEST_WORD

// test cases function

// create test case
#define TEST_CASE(CASE)
// create sub-test case
#define SUB_TEST_CASE(SUBCASE)
// will run test case and print success info 
#define RUN_TEST_CASE(CASE)
// similar to RUN_TEST_CASE but will not save status (no counter and info)
#define RUN_TEST_FUNC(FUNC)
// will run sub-test case and print success info
#define RUN_SUB_TEST_CASE(SUBCASE)

// In this version of utest RUN_ALL_TEST will do nothing which means you need run
// test functions manually by calling RUN_TEST_CASE or RUN_SUB_TEST_CASE
#define RUN_ALL_TEST()

#include <utest/_utest.h>
#endif