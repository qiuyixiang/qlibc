/*
 *  The Main Test Entry for Qlibc Test Framework. 
 *  Don't Modify anything here !
*/

#ifdef __cplusplus
#error "Please Use a GNU or LLVM for C Compiler"
#endif

int test_case_counter = 0;

#define MAIN_TEST
#include "test.h"

int main(int argc, char *argv[]){

    RUN_ALL_TEST();

    return 0;
}