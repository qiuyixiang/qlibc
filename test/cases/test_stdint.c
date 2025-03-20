#include <utest.h>
#include <stdint.h>

#if ((USING_QLIBC == 1) && (!defined(_QLIBC_STDINT_H)))
#error "Expected <stdint.h> in qlibc !"
#endif

#define BITS(TYPE)  8 * sizeof(TYPE)
#define BITS_8      8
#define BITS_16     16
#define BITS_32     32
#define BITS_64     64

#define CHECK_TYPE_BITS(PREFIX)                          \
    EXPECT_EQ(BITS(CONCAT3(PREFIX, 8, _t)), BITS_8);     \
    EXPECT_EQ(BITS(CONCAT3(PREFIX, 16, _t)), BITS_16);   \
    EXPECT_EQ(BITS(CONCAT3(PREFIX, 32, _t)), BITS_32);   \
    EXPECT_EQ(BITS(CONCAT3(PREFIX, 64, _t)), BITS_64)  

#define CHECK_TYPE_VALUE_EQ(PREFIX1, PREFIX2, POSTFIX)                              \
    EXPECT_EQ(CONCAT4(PREFIX1, 8, _, POSTFIX), CONCAT4(PREFIX2, 8, _, POSTFIX));    \
    EXPECT_EQ(CONCAT4(PREFIX1, 16, _, POSTFIX), CONCAT4(PREFIX2, 16, _, POSTFIX));  \
    EXPECT_EQ(CONCAT4(PREFIX1, 32, _, POSTFIX), CONCAT4(PREFIX2, 32, _, POSTFIX));  \
    EXPECT_EQ(CONCAT4(PREFIX1, 64, _, POSTFIX), CONCAT4(PREFIX2, 64, _, POSTFIX))

#define CHECK_TYPE_SIZE(PREFIX1, PREFIX2)                                               \
    EXPECT_EQ(sizeof((CONCAT3(PREFIX2, 8, _t))CONCAT3(PREFIX1, 8, _C)(0)),              \
            sizeof(CONCAT3(PREFIX2, 8, _t)));                                           \
    EXPECT_EQ(sizeof((CONCAT3(PREFIX2, 16, _t))CONCAT3(PREFIX1, 16, _C)(0)),            \
            sizeof(CONCAT3(PREFIX2, 16, _t)));                                          \
    EXPECT_EQ(sizeof(CONCAT3(PREFIX1, 32, _C)(0)), sizeof(CONCAT3(PREFIX2, 32, _t)));   \
    EXPECT_EQ(sizeof(CONCAT3(PREFIX1, 64, _C)(0)), sizeof(CONCAT3(PREFIX2, 64, _t))); 
    
/**
 * Note: some of these test cases below depends on the 
 * machine architecture, if your test machine differs from
 * your target architecture, some of these tests may fail to
 * run.
 */
TEST_CASE(stdint){
    // Test for fixed-width integer types
    CHECK_TYPE_BITS(int);

#if (USING_QLIBC == 1)
    CHECK_TYPE_BITS(int_fast);
#else
    EXPECT_EQ(BITS(int_fast8_t), 8);
#if (TEST_WORD == BITS32)
    EXPECT_EQ(BITS(int_fast16_t), BITS32);
    EXPECT_EQ(BITS(int_fast32_t), BITS32);
#endif
    EXPECT_EQ(BITS(int_fast64_t), 64);
#endif

    CHECK_TYPE_BITS(int_least);

    EXPECT_EQ(BITS(intmax_t), BITS_64);

#if (TEST_WORD == BITS64)
    EXPECT_EQ(sizeof(void *), 8);
#elif (TEST_WORD == BITS32)
    EXPECT_EQ(sizeof(void *), 4);
#endif

#if (TEST_WORD == BITS64)
    EXPECT_EQ(BITS(intptr_t), BITS_64);
#elif (TEST_WORD == BITS32)
    EXPECT_EQ(BITS(intptr_t), BITS_32);
#endif

    CHECK_TYPE_BITS(uint);

#if (USING_QLIBC == 1)
    CHECK_TYPE_BITS(uint_fast);
#else
    EXPECT_EQ(BITS(uint_fast8_t), 8);
#if (TEST_WORD == BITS32)
    EXPECT_EQ(BITS(uint_fast16_t), BITS32);
    EXPECT_EQ(BITS(uint_fast32_t), BITS32);
#endif
    EXPECT_EQ(BITS(uint_fast64_t), 64);
#endif

    CHECK_TYPE_BITS(uint_least);

    EXPECT_EQ(BITS(uintmax_t), BITS_64);

#if (TEST_WORD == BITS64)
    EXPECT_EQ(BITS(uintptr_t), BITS_64);
#elif (TEST_WORD == BITS32)
    EXPECT_EQ(BITS(uintptr_t), BITS_32);
#endif

    EXPECT_TRUE((uint8_t)0x80 > (uint8_t)0x7f);
    EXPECT_TRUE((int8_t)0x80 < (int8_t)0x7f);

    // Check Min and Max Value
    EXPECT_EQ(INT8_MIN, (int8_t)0x80);
    EXPECT_EQ(INT16_MIN, (int16_t)0x8000);
    EXPECT_EQ(INT32_MIN, (int32_t)0x80000000);
    EXPECT_EQ(INT64_MIN, (int64_t)0x8000000000000000);

    EXPECT_EQ(INT8_MAX, (int8_t)0x7f);
    EXPECT_EQ(INT16_MAX, (int16_t)0x7fff);
    EXPECT_EQ(INT32_MAX, (int32_t)0x7fffffff);
    EXPECT_EQ(INT64_MAX, (int64_t)0x7fffffffffffffff);

    EXPECT_EQ(UINT8_MAX, (uint8_t)0xff);
    EXPECT_EQ(UINT16_MAX, (uint16_t)0xffff);
    EXPECT_EQ(UINT32_MAX, (uint32_t)0xffffffff);
    EXPECT_EQ(UINT64_MAX, (uint64_t)0xffffffffffffffff);

    CHECK_TYPE_VALUE_EQ(INT_FAST, INT, MIN);
    CHECK_TYPE_VALUE_EQ(INT_FAST, INT, MAX);
    CHECK_TYPE_VALUE_EQ(UINT_FAST, UINT, MAX);

    CHECK_TYPE_VALUE_EQ(INT_LEAST, INT, MIN);
    CHECK_TYPE_VALUE_EQ(INT_LEAST, INT, MAX);
    CHECK_TYPE_VALUE_EQ(UINT_LEAST, UINT, MAX);

    EXPECT_EQ(INTMAX_MIN, INT64_MIN);
    EXPECT_EQ(INTMAX_MAX, INT64_MAX);
    EXPECT_EQ(UINTMAX_MAX, UINT64_MAX);

#if (TEST_WORD == BITS64)
    EXPECT_EQ(INTPTR_MIN, INT64_MIN);
    EXPECT_EQ(INTPTR_MAX, INT64_MAX);
    EXPECT_EQ(UINTPTR_MAX, UINT64_MAX);
#elif (TEST_WORD == BITS32)
    EXPECT_EQ(INTPTR_MIN, INT32_MIN);
    EXPECT_EQ(INTPTR_MAX, INT32_MAX);
    EXPECT_EQ(UINTPTR_MAX, UINT32_MAX);
#endif

#if (TEST_WORD == BITS64)
    EXPECT_EQ(PTRDIFF_MIN, INT64_MIN);
    EXPECT_EQ(PTRDIFF_MAX, INT64_MAX);
    EXPECT_EQ(SIZE_MAX, UINT64_MAX);
#elif (TEST_WORD == BITS32)
    EXPECT_EQ(PTRDIFF_MIN, INT32_MIN);
    EXPECT_EQ(PTRDIFF_MAX, INT32_MAX);
    EXPECT_EQ(SIZE_MAX, UINT32_MAX);
#endif

    EXPECT_EQ(SIG_ATOMIC_MIN, INT32_MIN);
    EXPECT_EQ(SIG_ATOMIC_MAX, INT32_MAX);

    EXPECT_TRUE(WCHAR_MIN == 0 || WCHAR_MIN == INT32_MIN);
    EXPECT_TRUE(WCHAR_MAX == UINT32_MAX || WCHAR_MAX == INT32_MAX);

    EXPECT_TRUE(WINT_MIN == 0 || WINT_MIN == INT32_MIN);
    EXPECT_TRUE(WINT_MAX == UINT32_MAX || WINT_MAX == INT32_MAX);

    // Test for Integer Literal Constant Value
    CHECK_TYPE_SIZE(INT, int);
    CHECK_TYPE_SIZE(UINT, uint);

    EXPECT_EQ(sizeof(INTMAX_C(0)), sizeof(intmax_t));
    EXPECT_EQ(sizeof(UINTMAX_C(0)), sizeof(uintmax_t));

    EXPECT_EQ(INT32_C(123), 123);
    EXPECT_EQ(UINT32_C(123), 123U);
    EXPECT_EQ(INTMAX_C(1234567890123456789), (intmax_t)1234567890123456789);
    EXPECT_EQ(UINTMAX_C(1234567890123456789), (uintmax_t)1234567890123456789);
}