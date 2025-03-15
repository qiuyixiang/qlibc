// This file test types and macros in unistd.h
#include <utest.h>
#include <unistd.h>


#define BITS(TYPE)  sizeof(TYPE) * 8

SUB_TEST_CASE(unistd_types){
    // Test file number
    EXPECT_EQ(STDIN_FILENO, 0);
    EXPECT_EQ(STDOUT_FILENO, 1);
    EXPECT_EQ(STDERR_FILENO, 2);
    // Test for ssize_t
#if (TEST_WORD == BITS32)
    EXPECT_EQ(BITS(ssize_t), 32);
    EXPECT_EQ(BITS(size_t), 32);
#elif (TEST_WORD == BITS64)
    EXPECT_EQ(BITS(ssize_t), 64);
    EXPECT_EQ(BITS(size_t), 64);
#endif
    // Test for off_t
#if (!defined(_QLIBC_UNISTD_H))
#if (TEST_WORD == 32)
    EXPECT_EQ(BITS(__off_t), 32);
#else
    EXPECT_EQ(BITS(__off_t), 64);
#endif
#else 
#if (TEST_WORD == 32)
    EXPECT_EQ(BITS(off_t), 32);
#else
    EXPECT_EQ(BITS(off_t), 64);
#endif
#endif
    // Test for offset of a file
    EXPECT_EQ(SEEK_SET, 0);
    EXPECT_EQ(SEEK_CUR, 1);
    EXPECT_EQ(SEEK_END, 2);
}