// Test IO Operation in unistd
#include <utest.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE_S       64
#define BUFFER_SIZE_M       128
#define BUFFER_SIZE_L       256
#define BUFFER_SIZE_1K      1024
#define BUFFER_SIZE_2K      2048

#if ((USING_QLIBC == 1) && (!defined(_QLIBC_UNISTD_H)))
#error "Expected <unistd.h> in qlibc"
#endif

// Test for read
SUB_TEST_CASE(unistd_read){
#if (TEST_INTERACTIVE == 1)
BEGIN_DECL
    char buffer[BUFFER_SIZE_S];
    ssize_t return_val = read(STDIN_FILENO, buffer, 4);
    EXPECT_EQ((size_t)return_val, 4);
END_DECL
#endif
}
// Test for write
SUB_TEST_CASE(unistd_write){
#if (TEST_INTERACTIVE == 1)
BEGIN_DECL
    const char buffer[] = "Hello QLibc System call !\n";
    ssize_t return_val =  write(STDOUT_FILENO, buffer, sizeof(buffer) - 1);
    EXPECT_EQ((size_t)return_val, sizeof(buffer) - 1);
END_DECL
#endif
}
// Test for close
SUB_TEST_CASE(unistd_close){
    EXPECT_EQ(close(INT32_MAX), -1);
    EXPECT_EQ(errno, EBADF);
}
// Test for lseek
SUB_TEST_CASE(unistd_lseek){
    EXPECT_EQ(lseek(INT32_MAX, 0, SEEK_CUR), -1);
    EXPECT_EQ(errno, EBADF);

BEGIN_DECL
    int fd = open("LICENSE", O_RDONLY);
    EXPECT_GE(fd, STDERR_FILENO);
    EXPECT_EQ(lseek(fd, 0, SEEK_CUR), 0);
    EXPECT_EQ(lseek(fd, 0, SEEK_SET), 0);
    EXPECT_EQ(lseek(fd, 10, SEEK_SET), 10);
    EXPECT_EQ(lseek(fd, 0, SEEK_CUR), 10);
END_DECL
}

