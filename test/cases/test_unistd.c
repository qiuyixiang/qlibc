// This file is the test framwork for unistd
#include <unistd.h>

// These test headers are not part of ISO C
#include "test_unistd/types.h"

TEST_CASE(unistd){
    // Test Macros in unistd
    RUN_SUB_CASE(unistd_types);
}