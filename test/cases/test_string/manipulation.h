#include "../../test.h"
#include "test_string.h"

/**
 * Test String manipulation
 * Functions: strcpy, strncpy
 */

// Test for strcpy
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
// Test for strncpy
SUB_TEST_CASE(strncpy){
BEGIN_DECL
    char dest[BUFFER_SIZE_S];
    const char * const fix_start = &dest[0];

    memset(dest, 0, sizeof(dest));
    EXPECT_EQ(strncpy(dest, "hello", 6), fix_start);
    EXPECT_TRUE(strcmp(dest, "hello") EQU);

    memset(dest, 0, sizeof(dest));
    EXPECT_EQ(strncpy(dest, "world", strlen("world") + 1), fix_start);
    EXPECT_TRUE(strcmp(dest, "world") EQU);

    memset(dest, 0x55, sizeof(dest));
    EXPECT_EQ(strncpy(dest, "longstring", 4), fix_start);
    EXPECT_TRUE(strncmp(dest, "long", 4) EQU);
    EXPECT_EQ(dest[4], 0x55);

    memset(dest, 'X', sizeof(dest));
    EXPECT_EQ(strncpy(dest, "hi", 10), fix_start);
    EXPECT_TRUE(strcmp(dest, "hi") EQU);  
    EXPECT_EQ(dest[3], NULL_TERMINATOR);
    EXPECT_EQ(dest[9], NULL_TERMINATOR);
    EXPECT_EQ(dest[10], 'X');

    memset(dest, 'X', sizeof(dest));
    EXPECT_EQ(strncpy(dest, "", 5), fix_start);
    EXPECT_EQ(dest[0], NULL_TERMINATOR);
    EXPECT_ALL_EQU(dest, NULL_TERMINATOR, 5);
    EXPECT_EQ(dest[5], 'X');
    EXPECT_ALL_EQU(&dest[5], 'X', 10);

    memset(dest, 0xaa, sizeof(dest));
    EXPECT_EQ(strncpy(dest, "test", 0), fix_start);
    EXPECT_EQ(dest[0], (char)0xaa);
    EXPECT_ALL_EQU(dest, 0xaa, BUFFER_SIZE_S);

    memset(dest, 'X', sizeof(dest));
    EXPECT_EQ(strncpy(dest, "test", 3), fix_start);
    EXPECT_TRUE(strncmp(dest, "tes", 3) EQU);
    EXPECT_TRUE(dest[3] != NULL_TERMINATOR); 
    EXPECT_TRUE(dest[3] == 'X');

    memset(dest, 'X', sizeof(dest));
    EXPECT_EQ(strncpy(dest, "12345", 10), fix_start);
    EXPECT_TRUE(strcmp(dest, "12345") EQU);
    EXPECT_EQ(dest[6], NULL_TERMINATOR);
    EXPECT_EQ(dest[8], NULL_TERMINATOR);
    EXPECT_EQ(dest[10], 'X');
END_DECL
}