// test for unix/linux system call

#include <utest.h>
#include <sys/syscall.h>

SUB_TEST_CASE(syscall){
#if (TEST_ARCH == I386)
    EXPECT_EQ(SYS_restart_syscall, 0);
    EXPECT_EQ(SYS_exit, 1);
    EXPECT_EQ(SYS_fork, 2);
    EXPECT_EQ(SYS_read, 3);
    EXPECT_EQ(SYS_write, 4);
    EXPECT_EQ(SYS_open, 5);
    EXPECT_EQ(SYS_close, 6);
    EXPECT_EQ(SYS_waitpid, 7);
    EXPECT_EQ(SYS_creat, 8);
    EXPECT_EQ(SYS_link, 9);
    EXPECT_EQ(SYS_unlink, 10);
    EXPECT_EQ(SYS_execve, 11);
    EXPECT_EQ(SYS_chdir, 12);
    EXPECT_EQ(SYS_time, 13);
    EXPECT_EQ(SYS_mknod, 14);
    EXPECT_EQ(SYS_chmod, 15);
    EXPECT_EQ(SYS_lchown, 16);
    EXPECT_EQ(SYS_break, 17);
    EXPECT_EQ(SYS_oldstat, 18);
    EXPECT_EQ(SYS_lseek, 19);
    EXPECT_EQ(SYS_getpid, 20);
    EXPECT_EQ(SYS_mount, 21);
#endif
}