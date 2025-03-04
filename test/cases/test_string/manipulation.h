#include "../../test.h"
#include "test_string.h"

/**
 * Test String manipulation
 * Functions: strcpy
 */
SUB_TEST_CASE(strcpy){
BEGIN_DECL
    char buffer[BUFFER_SIZE_S];
    memset(buffer, 0, BUFFER_SIZE_S);
    EXPECT_EQ(strcpy(buffer, "abcdefgh"), buffer);
    EXPECT_TRUE(strcmp(buffer, "abcdefgh") EQU);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S];
    memset(buffer, 0x55, BUFFER_SIZE_S);
    EXPECT_EQ(strcpy(buffer, ""), buffer);
    EXPECT_TRUE(strcmp(buffer, "") EQU);
    EXPECT_EQ(buffer[1], 0x55);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S];
    memset(buffer, 0, BUFFER_SIZE_S);
    EXPECT_EQ(strcpy(buffer, all_lower_cases), buffer);
    EXPECT_TRUE(strcmp(buffer, all_lower_cases) EQU);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S];
    memset(buffer, 0, BUFFER_SIZE_S);
    EXPECT_EQ(strcpy(buffer, all_upper_cases), buffer);
    EXPECT_TRUE(strcmp(buffer, all_upper_cases) EQU);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_L];
    memset(buffer, 0, BUFFER_SIZE_L);
    EXPECT_EQ(strcpy(buffer, long_str), buffer);
    EXPECT_TRUE(strcmp(buffer, long_str) EQU);
END_DECL
}      