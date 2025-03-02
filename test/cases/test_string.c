#include "../test.h"
#include <string.h>

SUB_TEST_CASE(strlen){
    const char buffer[] = "This is a formal test for strlen";
    EXPECT_EQ(strlen(buffer), sizeof(buffer) - 1);
    const char only_one[] = "S";
    const char __attribute__((unused)) next = '\0';
    EXPECT_EQ(strlen(only_one), 1);
}

TEST_CASE(string){
    RUN_SUB_CASE(strlen);
}