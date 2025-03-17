#include <utest.h>
#include <sys/types.h>

#define BITS(TYPE)  sizeof(TYPE) * 8

SUB_TEST_CASE(unix_types){
    
#if (TEST_WORD == BITS32)
    EXPECT_EQ(BITS(void*), BITS32);
#elif (TEST_WORD == BITS64)
    EXPECT_EQ(BITS(void*), BITS64);
#endif

    EXPECT_EQ(BITS(mode_t), BITS(unsigned int));

#if (TEST_WORD == BITS32)
    EXPECT_EQ(BITS(ssize_t), 32);
#else
    EXPECT_EQ(BITS(ssize_t), 64);
#endif

#if (TEST_WORD == BITS32)
    EXPECT_EQ(BITS(off_t), 32);
#else
    EXPECT_EQ(BITS(off_t), 64);
#endif

}