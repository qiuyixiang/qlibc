/*
 * The Main Entrance For All Test Cases 
 * Test Program
 * The Utility of this Program is to ensure that every file or 
 * Library Component in the qlibc 0.0.2 will run properly !
 * 
 * Create on : 2024-04-23
 * Copyright : QiuYiXiang
*/

// Include Some Important Header File !
// These File Mainly In qlibc
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
/*
Notes : If the Header File Exist in the Include Path (Which 
        Implicitly Specify In Makefile) it will automatically 
        include it the include path, otherwise it will search 
        it in the standard library
*/

// Include Configuration Header File For Information and Auxiliary Function 
#include "config.h"

// Test Cases For Different Components in qlibc

// Test Cases For <assert.h>
void cases_assert(){
    assert(sizeof(int) == 4);
    assert(1);
    assert(sizeof(long) == 8);
    assert(sizeof(void*) == 8);
    assert(QLIBC_NAME);
}
// Test Cases For <stddef.h>
struct test_stddef_offset_p{
    char _CHAR_OFF;
    int _INT_OFF;
    long _LONG_OFF;
    double _DOUBLE_OFF;
};
void cases_stddef(){
    assert(_USING_QLIBC_STDDEF);
    assert(sizeof(size_t) == sizeof(unsigned long));
    assert(sizeof(ptrdiff_t) == sizeof(ptrdiff_t));
    // assert(!__X86__);
    assert(sizeof(wchar_t) == sizeof(unsigned int));
    assert(sizeof(struct test_stddef_offset_p) == 24);
    assert(offsetof(struct test_stddef_offset_p, _CHAR_OFF) == (size_t)0);
    assert(offsetof(struct test_stddef_offset_p, _INT_OFF) == (size_t)4);
    assert(offsetof(struct test_stddef_offset_p, _LONG_OFF) == (size_t)8);
    assert(offsetof(struct test_stddef_offset_p, _DOUBLE_OFF) == (size_t)16);
}
// The Main SubFunction Which Control All Test Cases
void test_all(){
    // Test Assert
    cases_assert();
    show_info("assert");
    // Test Stddef
    cases_stddef();
    show_info("stddef");
}
int main(int argc, char * argv[]){
    // Start Point of All Test Cases

    // Ignore the parameter unused warning !
    if (argc > 1){
        fprintf(stderr, "Too Many Argument !\n");
        exit(-1);
    }

    fprintf(stdout, "Running Test Program in : %s\t", argv[0]);
    fprintf(stdout, "Using All Test Cases For %s-%s\n\n", QLIBC_NAME, QLIBC_VERSION);
    test_all();

    fprintf(stdout, "\nAll Cases Have Passed Successfully !\n");
    return 0;
}