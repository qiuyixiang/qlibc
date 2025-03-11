// This file is the test framwork for unistd
#include <unistd.h>

// These test headers are not part of ISO C
#include "test_unistd/types.h"
#include "test_unistd/io.h"

TEST_CASE(unistd){
    // Test Macros in unistd
    RUN_SUB_CASE(unistd_types);
    // Test IO function in unistd
    RUN_SUB_CASE(unistd_write);
    RUN_SUB_CASE(unistd_read);
    RUN_SUB_CASE(unistd_close);
    RUN_SUB_CASE(unistd_lseek);
}