// This file test types and macros in unistd.h
#include "../../test.h"
#include <unistd.h>

SUB_TEST_CASE(unistd_types){
    // Test file number
    EXPECT_EQ(STDIN_FILENO, 0);
    EXPECT_EQ(STDOUT_FILENO, 1);
    EXPECT_EQ(STDERR_FILENO, 2);
}