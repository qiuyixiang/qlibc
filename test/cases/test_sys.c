// test framework for system utilities
#include "test_sys/syscall.h"
#include "test_sys/types.h"

TEST_CASE(sys){
    // test for syscall
    RUN_SUB_TEST_CASE(syscall);
    // test for types
    RUN_SUB_TEST_CASE(unix_types);
}