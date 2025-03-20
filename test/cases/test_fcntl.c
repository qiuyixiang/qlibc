// test frame for unix fcntl

#include <utest.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define NON_EXIST_FILE      "non-exist.txt"

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
SUB_TEST_CASE(fcntl_open){
    EXPECT_EQ(open(NON_EXIST_FILE, O_RDONLY), -1);
    EXPECT_EQ(errno, ENOENT);
}
SUB_TEST_CASE(fcntl_openat){
    int dir_fd = open("../", O_RDONLY | O_DIRECTORY);
    EXPECT_GT(dir_fd, STDERR_FILENO);
    EXPECT_EQ(openat(dir_fd, NON_EXIST_FILE, O_RDONLY), -1);
    EXPECT_EQ(errno, ENOENT);
}
SUB_TEST_CASE(fcntl_create){

}

TEST_CASE(fcntl){
    RUN_SUB_TEST_CASE(fcntl_macros);
    RUN_SUB_TEST_CASE(fcntl_open);
    RUN_SUB_TEST_CASE(fcntl_openat);
    RUN_SUB_TEST_CASE(fcntl_create);
}