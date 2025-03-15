#include <utest.h>
#include <stdbool.h>

TEST_CASE(stdbool){
    EXPECT_EQ(sizeof(bool), sizeof(_Bool));
    EXPECT_EQ(true, 1);
    EXPECT_EQ(false, 0);
    EXPECT_NE(true, false);
}