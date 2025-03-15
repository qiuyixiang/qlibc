#include <utest.h>
#include "test_string.h"

/**
 * Test String manipulation
 * Functions: strcpy, strncpy, strcat, strncat
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
// Test for strcat
SUB_TEST_CASE(strcat){
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Hello ";
    const char src[] = "World";
    EXPECT_EQ(strcat(buffer, src), buffer);
    EXPECT_EQ(strcmp(buffer, "Hello World"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR); 
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Hello";
    char *result = strcat(buffer, " World");
    EXPECT_TRUE(result == buffer);
    EXPECT_EQ(strcmp(buffer, "Hello World"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR); 
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Test";
    char *result = strcat(buffer, "");
    EXPECT_TRUE(result == buffer);
    EXPECT_EQ(strcmp(buffer, "Test"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR); 
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "";
    char *result = strcat(buffer, "Append");
    EXPECT_TRUE(result == buffer);
    EXPECT_EQ(strcmp(buffer, "Append"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR); 
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Start";
    strcat(buffer, " Middle");
    strcat(buffer, " End");
    EXPECT_EQ(strcmp(buffer, "Start Middle End"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR); 
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Safe";
    strcat(buffer, "!");
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR); 
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "A";
    strcat(buffer, " B");
    strcat(buffer, " C");
    strcat(buffer, " D");
    strcat(buffer, " E");
    EXPECT_EQ(strcmp(buffer, "A B C D E"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR); 
END_DECL
}
// Test for strncat
SUB_TEST_CASE(strncat){
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Hello";
    EXPECT_EQ(strncat(buffer, " WW world", 3), buffer);
    EXPECT_EQ(strcmp(buffer, "Hello WW"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Hello";
    char * result = strncat(buffer, " World", 10);
    EXPECT_EQ(result, buffer);
    EXPECT_EQ(strcmp(buffer, "Hello World"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Test";
    memset(&buffer[strlen(buffer) + 1], 0x44, 20);
    EXPECT_EQ(strcmp(buffer, "Test"), 0);
    EXPECT_EQ(buffer[4], NULL_TERMINATOR);
    EXPECT_EQ(buffer[5], 0x44);
    char * result = strncat(buffer, "123456", 3); 
    EXPECT_EQ(result, buffer);
    EXPECT_EQ(strcmp(buffer, "Test123"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "CS";
    char * result = strncat(buffer, "50", BUFFER_SIZE_S);
    EXPECT_EQ(result, buffer);
    EXPECT_EQ(strcmp(buffer, "CS50"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Keep";
    char * result = strncat(buffer, "", 5);
    EXPECT_EQ(result, buffer);
    EXPECT_EQ(strcmp(buffer, "Keep"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "";
    char * result = strncat(buffer, "Data", 10);
    EXPECT_EQ(result, buffer);
    EXPECT_EQ(strcmp(buffer, "Data"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Safe";
    strncat(buffer, "!", 1);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR); 
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "A";
    EXPECT_EQ(strncat(buffer, " B", 2), buffer);
    EXPECT_EQ(strncat(buffer, " C", 2), buffer);
    EXPECT_EQ(strncat(buffer, " D", 2), buffer);
    EXPECT_EQ(strncat(buffer, " E", 2), buffer);
    EXPECT_EQ(strcmp(buffer, "A B C D E"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR);
END_DECL
BEGIN_DECL
    char buffer[BUFFER_SIZE_S] = "Static";
    char * result = strncat(buffer, "Check", 0);
    EXPECT_EQ(result, buffer);
    EXPECT_EQ(strcmp(buffer, "Static"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR);
END_DECL
BEGIN_DECL
    // Special cases ensure that the appended string always ends with '\0'
    char buffer[BUFFER_SIZE_S];
    // Make sure the memory is disrupted
    memset(buffer, 0x44, BUFFER_SIZE_S);
    buffer[0] = 'A';
    buffer[1] = NULL_TERMINATOR;
    EXPECT_EQ(strcmp(buffer, "A"), 0);
    EXPECT_EQ(strncat(buffer, "1234567", 4), buffer);
    EXPECT_EQ(strcmp(buffer, "A1234"), 0);
    EXPECT_EQ(buffer[strlen(buffer)], NULL_TERMINATOR);
    EXPECT_EQ(buffer[strlen(buffer) + 1], 0x44);
    EXPECT_EQ(buffer[strlen(buffer) + 2], 0x44);
END_DECL
}
// Test for strxfrm
#if (defined(QLIBC_WCHAR_SUPPORT)) && (QLIBC_WCHAR_SUPPORT == 1)
SUB_TEST_CASE(strxfrm){
    static_assert(0, "Need Test cases for strxfrm !");
}
#endif