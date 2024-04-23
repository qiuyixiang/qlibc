/**
 * The Implementation of C Diagnostic Library
 * Create On : 2024-04-23
 * Copyright : QiuYiXiang
*/

// These Header File Belongs To qlibc
#include <stdio.h>
#include <stdlib.h>

void __qlibc_assert(const char * __assert_msg, const char * __func, const char * __file, int __line){
    fprintf(stderr,"Assertion failed : (%s), function %s, file %s, line %d.\n",
            __assert_msg, __func, __file, __line);
    exit(-1);
}