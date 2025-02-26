#include "../test.h"
#include <stdalign.h>

#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ < _STDC_C23))
#ifndef alignof 
#error "Integrity for alignof check failed"
#endif
#endif

TEST_CASE(stdalign){
    EXPECT_TRUE(alignof(char) == sizeof(char));
    EXPECT_TRUE(alignof(short) == sizeof(short));
    EXPECT_TRUE(alignof(int) == sizeof(int));
    EXPECT_TRUE(alignof(long) == sizeof(long));
    EXPECT_TRUE(alignof(double) == sizeof(double));

#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ < _STDC_C23))
#ifndef alignas 
#error "Integrity for alignas check failed"
#endif
#endif
}