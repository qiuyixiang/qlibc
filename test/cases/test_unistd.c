// These test headers are not part of ISO C
#include "test_unistd/io.h"
#include "test_unistd/sys.h"
#include "test_unistd/macros.h"

TEST_CASE(unistd){
    
    RUN_SUB_TEST_CASE(unistd_macros);
    // Test sys function in unistd
    RUN_SUB_TEST_CASE(unistd_syscall);
    // Test IO function in unistd
    RUN_SUB_TEST_CASE(unistd_write);
    RUN_SUB_TEST_CASE(unistd_read);
    RUN_SUB_TEST_CASE(unistd_close);
    RUN_SUB_TEST_CASE(unistd_lseek);
}