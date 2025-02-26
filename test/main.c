/*
 *  The Main Test Entry for Qlibc Test Framework. 
 *  Don't Modify anything here !
*/

#ifdef __cplusplus
#error "Please Use a GNU or LLVM for C Compiler"
#endif

#define MAIN_TEST
#include "test.h"

int main(int argc, char *argv[]){

    RUN_TEST(assert);
    RUN_TEST(ctype);

    return 0;
}