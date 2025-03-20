#include <utest.h>
#include <errno.h>

#if (defined(USING_QLIBC) && (USING_QLIBC == 1))
#ifndef _QLIBC_ERRNO_H
#error "Expect <errno.h> in qlibc"
#endif
#endif

// Test for errno.h
TEST_CASE(error){
    EXPECT_EQ(errno, 0);
    errno = 10;
    EXPECT_EQ(errno, 10);
    errno = 0;
    EXPECT_EQ(errno, 0);
    
// These Macros test the consistency with x86 arch
// which may different on other arch such as aarch64 and arm
#if (defined(TEST_ARCH)) && ((TEST_ARCH == I386) || (TEST_ARCH == X86_64)) 
    EXPECT_EQ(EPERM, 1);
    EXPECT_EQ(ENOENT, 2);
    EXPECT_EQ(ESRCH, 3);
    EXPECT_EQ(EINTR, 4);
    EXPECT_EQ(EIO, 5);
    EXPECT_EQ(ENXIO, 6);
    EXPECT_EQ(E2BIG, 7);
    EXPECT_EQ(ENOEXEC, 8);
    EXPECT_EQ(EBADF, 9);
    EXPECT_EQ(ECHILD, 10);
    EXPECT_EQ(EAGAIN, 11);
    EXPECT_EQ(ENOMEM, 12);
    EXPECT_EQ(EACCES, 13);
    EXPECT_EQ(EFAULT, 14);
    EXPECT_EQ(ENOTBLK, 15);
    EXPECT_EQ(EBUSY, 16);
    EXPECT_EQ(EEXIST, 17);
    EXPECT_EQ(EXDEV, 18);
    EXPECT_EQ(ENODEV, 19);
    EXPECT_EQ(ENOTDIR, 20);
    EXPECT_EQ(EISDIR, 21);
    EXPECT_EQ(EINVAL, 22);
    EXPECT_EQ(ENFILE, 23);
    EXPECT_EQ(EMFILE, 24);
    EXPECT_EQ(ENOTTY, 25);
    EXPECT_EQ(ETXTBSY, 26);
    EXPECT_EQ(EFBIG, 27);
    EXPECT_EQ(ENOSPC, 28);
    EXPECT_EQ(ESPIPE, 29);
    EXPECT_EQ(EROFS, 30);
    EXPECT_EQ(EMLINK, 31);
    EXPECT_EQ(EPIPE, 32);
    EXPECT_EQ(EDOM, 33);
    EXPECT_EQ(ERANGE, 34);
#endif

#if (defined(TEST_ARCH)) && (TEST_ARCH == AARCH64)
/// Not Implement Yet !
#endif
}