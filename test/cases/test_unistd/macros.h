#include <utest.h>
#include <unistd.h>

#ifndef _QLIBC_UNISTD_H
#error "Expect <unistd.h> in qlibc"
#endif

SUB_TEST_CASE(unistd_macros){
    // macros for standard file descriptor
    EXPECT_EQ(STDIN_FILENO, 0);
    EXPECT_EQ(STDOUT_FILENO, 1);
    EXPECT_EQ(STDERR_FILENO, 2);

}