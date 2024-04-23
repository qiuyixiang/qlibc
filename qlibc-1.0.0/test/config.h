#ifndef __QLIBC_TEST_CASES__
#define __QLIBC_TEST_CASES__ 1

/*
    This file is just used for Configuration and some auxiliary
    functions also defined here !

    To Condense The Test Cases All of the information and some helper function 
    will also defined here !

    Create on : 2024-04-23
    Copyright : QiuYiXiang
*/

// Include Header File
#include <stdio.h>

#define QLIBC_VERSION   "1.0.0"
#define QLIBC_NAME      "qlibc"

#define _SRT(_) ""#_ 

void show_info(const char * __component){
    fprintf(stdout, "Test Cases : \t %s\t Successfully !!!\n", __component);
}


#endif