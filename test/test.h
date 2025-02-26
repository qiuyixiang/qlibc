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

/// A Simple Utility Test Macros
#define CONCAT(LHS, RHS)    LHS##RHS
#define STRING(VAR)         #VAR
#define BEGIN_DECL          {
#define END_DECL            }

#define TEST_CASE(CASE)     void CONCAT(test, CASE)()

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

#define RUN_SUCCESS(CASE)   fprintf(stdout, "[" _COLOR_GREEN "%s" _COLOR_RESET "] " \
                            "Test Case Success\n", STRING(CASE))
#define RUN_TEST(CASE)      CONCAT(test, CASE)(); \
                            RUN_SUCCESS(CASE)     \

extern TEST_CASE(assert);
extern TEST_CASE(ctype);
extern TEST_CASE(stdio);
extern TEST_CASE(stdlib);

#endif 

#endif