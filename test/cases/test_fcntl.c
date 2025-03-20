// test frame for unix fcntl

#include <utest.h>
#include <fcntl.h>

SUB_TEST_CASE(fcntl_macros){
    EXPECT_EQ(O_RDONLY, 0);
    EXPECT_EQ(O_WRONLY, 1);
    EXPECT_EQ(O_RDWR, 2);
    
#if (TEST_ARCH == I386)
    EXPECT_EQ(O_APPEND, 02000);
#ifdef _QLIBC_FCNTL_H
    EXPECT_EQ(O_CLOEXEC, 02000000);
#endif
    EXPECT_EQ(O_CREAT, 0100);
#ifdef _QLIBC_FCNTL_H
    EXPECT_EQ(O_DIRECTORY, 00200000);
#endif
    EXPECT_EQ(O_EXCL, 0200);
    EXPECT_EQ(O_NOCTTY, 0400);
#ifdef _QLIBC_FCNTL_H
    EXPECT_EQ(O_NOFOLLOW, 00400000);
#endif
    EXPECT_EQ(O_NONBLOCK, 04000);
    EXPECT_EQ(O_SYNC, 04010000);
    EXPECT_EQ(O_TRUNC, 01000);
    
#endif
}

TEST_CASE(fcntl){
    RUN_SUB_TEST_CASE(fcntl_macros);
}