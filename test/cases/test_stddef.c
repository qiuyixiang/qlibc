#include "../test.h"
#include <stddef.h>
#include <stdalign.h>

#define BITS(TYPE) (sizeof(TYPE) * 8)

typedef struct unpacked{
    char _CHAR;
    double _DOUBLE;
}unpacked;

typedef struct __attribute__((packed)) packed{
    char _CHAR1;
    short _SHORT;
    char _CHAR2;
    unsigned _UNSIGNED;
}packed;

typedef struct unpacked1{
    char _CHAR1;
    short _SHORT;
    char _CHAR2;
    unsigned _UNSIGNED;
}unpacked1;

#define PADDING1        1
#define PADDING2        2

TEST_CASE(stddef){
    EXPECT_TRUE(BITS(ptrdiff_t) >= 16);
    EXPECT_TRUE(BITS(ptrdiff_t) >= 17);
    EXPECT_EQ(NULL, 0);
    EXPECT_TRUE(sizeof(max_align_t) >= sizeof(long double));
#if (defined(TEST_WORD)) && (TEST_WORD == BITS64)
    // maximum alignment in x86_64 should return 16 bytes
    EXPECT_EQ(sizeof(max_align_t), 16);
#endif
    EXPECT_TRUE(BITS(size_t) >= 16);

    EXPECT_EQ(offsetof(unpacked, _CHAR), 0);
    EXPECT_EQ(offsetof(unpacked, _DOUBLE), alignof(double));

    EXPECT_EQ(offsetof(packed, _CHAR1), 0);
    EXPECT_EQ(offsetof(packed, _SHORT), sizeof(char));
    EXPECT_EQ(offsetof(packed, _CHAR2), sizeof(char) + sizeof(short));
    EXPECT_EQ(offsetof(packed, _UNSIGNED), 2 * sizeof(char) + sizeof(short));

    EXPECT_EQ(offsetof(unpacked1, _CHAR1), 0);
    EXPECT_EQ(offsetof(unpacked1, _SHORT), alignof(short));
    EXPECT_EQ(offsetof(unpacked1, _CHAR2), PADDING1 + sizeof(char) + sizeof(short));
    EXPECT_EQ(offsetof(unpacked1, _UNSIGNED), 2 * sizeof(unsigned));
}