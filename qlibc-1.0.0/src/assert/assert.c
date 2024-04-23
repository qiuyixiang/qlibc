
// Implementation of qlibc Assert Library

#include <stdio.h>
#include <stdlib.h>

void __qlibc_assert(const char * __expr, const char * __file, const char * __func, int __line){
    fprintf(stderr, "Assertion failed : %s, function %s, file : %s, line %d.\n", 
        __expr, __func, __file, __line);
    exit(-1);
}