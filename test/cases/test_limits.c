#include <utest.h>
#include <limits.h>

#undef BITS8
#undef BITS16

#define BITS8   8
#define BITS16  16

#if ((USING_QLIBC == 1) && (!defined(_QLIBC_LIMITS_H)))
#error "Expected <limits.h> in qlibc !"
#endif

TEST_CASE(limits){
    EXPECT_EQ(CHAR_BIT, BITS8);
    EXPECT_TRUE(MB_LEN_MAX >= 4);

    EXPECT_TRUE(CHAR_MIN == -128 || CHAR_MIN == 0);
    EXPECT_TRUE(CHAR_MAX == 127 || CHAR_MAX == 255);

    EXPECT_EQ(SCHAR_MIN, -128);
    EXPECT_EQ(SCHAR_MAX, 127);

    EXPECT_EQ(SHRT_MIN, (short)0x8000);
    EXPECT_EQ(SHRT_MAX, (short)0x7fff);

    EXPECT_EQ(INT_MIN, (int)0x80000000);
    EXPECT_EQ(INT_MAX, (int)0x7fffffff);

#if (TEST_WORD == BITS32)
    EXPECT_EQ(LONG_MIN, (long)0x80000000);
    EXPECT_EQ(LONG_MAX, (long)0x7fffffff);
#elif (TEST_WORD == BITS64)
    EXPECT_EQ(LONG_MIN, (long)0x8000000000000000);
    EXPECT_EQ(LONG_MAX, (long)0x7fffffffffffffff);
#endif

    EXPECT_EQ(LLONG_MIN, (long long)0x8000000000000000);
    EXPECT_EQ(LLONG_MAX, (long long)0x7fffffffffffffff);

    EXPECT_EQ(UCHAR_MAX, 255);
    EXPECT_EQ(USHRT_MAX, (unsigned short)0xffff);
    EXPECT_EQ(UINT_MAX, (unsigned int)0xffffffff);
    
#if (TEST_WORD == BITS32)
    EXPECT_EQ(ULONG_MAX, (unsigned long)0xffffffff);
#elif (TEST_WORD == BITS64)
    EXPECT_EQ(ULONG_MAX, (unsigned long)0xffffffffffffffff);
#endif
    EXPECT_EQ(ULLONG_MAX, (unsigned long long)0xffffffffffffffff);
}