#include "../test.h"
#include <stddef.h>

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

TEST_CASE(stddef){
    EXPECT_TRUE(BITS(ptrdiff_t) >= 16);
    EXPECT_TRUE(BITS(ptrdiff_t) >= 17);
    EXPECT_EQ(NULL, 0);
    EXPECT_TRUE(sizeof(max_align_t) >= sizeof(long double));
    EXPECT_TRUE(BITS(size_t) >= 16);

    EXPECT_EQ(offsetof(unpacked, _CHAR), 0);
    EXPECT_EQ(offsetof(unpacked, _DOUBLE), sizeof(double));

    EXPECT_EQ(offsetof(packed, _CHAR1), 0);
    EXPECT_EQ(offsetof(packed, _SHORT), sizeof(char));
    EXPECT_EQ(offsetof(packed, _CHAR2), sizeof(char) + sizeof(short));
    EXPECT_EQ(offsetof(packed, _UNSIGNED), 2 * sizeof(char) + sizeof(short));
}