// test framework for system utilities

#include "test_sys/syscall.h"

TEST_CASE(sys){
    // test for syscall
    RUN_TEST_P(syscall);
}