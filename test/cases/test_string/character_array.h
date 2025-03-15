#include <utest.h>
#include "test_string.h"

/**
 * Test Character array manipulation.
 * Functions: memchr, memcmp, memset, memcpy, memmove
 */

// Test for memchr
SUB_TEST_CASE(memchr){
BEGIN_DECL
    unsigned char buffer[] = "ABCDEFGHI";
    EXPECT_EQ(*(unsigned char*)memchr(buffer, 'D', sizeof(buffer)), 'D');
    EXPECT_EQ(*(unsigned char*)memchr(buffer, 'A', sizeof(buffer)), 'A');
    EXPECT_EQ(*(unsigned char*)memchr(buffer, 'E', sizeof(buffer)), 'E');
    EXPECT_EQ(*(unsigned char*)memchr(buffer, 'I', sizeof(buffer)), 'I');
    EXPECT_EQ(*(unsigned char*)memchr(buffer, NULL_TERMINATOR, sizeof(buffer)), NULL_TERMINATOR);
    EXPECT_EQ(memchr(buffer, 'Q', sizeof(buffer)), NULL);
    EXPECT_EQ(memchr(buffer, 'Z', sizeof(buffer)), NULL);
    EXPECT_EQ(memchr(buffer, 'a', sizeof(buffer)), NULL);
END_DECL
}
// Test for memcmp
SUB_TEST_CASE(memcmp){
    EXPECT_EQ(memcmp("ABCD", "ABCD", 4), strcmp("ABCD", "ABCD"));
    EXPECT_EQ(memcmp("AB", "A", 2), strcmp("AB", "A"));
    EXPECT_EQ(memcmp("A", "AB", 2), strcmp("A", "AB"));
    EXPECT_TRUE(memcmp("ABCD", "ABC", 5) GREATER);
    EXPECT_TRUE(memcmp("ABC", "ABCD", 5) LESS);
    EXPECT_TRUE(memcmp("ABCD", "ABC", 10) GREATER);
    EXPECT_TRUE(memcmp("ABC", "ABCD", 10) LESS);
    EXPECT_TRUE(memcmp(all_lower_cases, all_lower_cases, sizeof(all_lower_cases)) EQU);
    EXPECT_TRUE(memcmp(all_lower_cases, all_lower_cases, 10) EQU);
    EXPECT_TRUE(memcmp("a", "A", 1) GREATER);
    EXPECT_TRUE(memcmp("", "", 1) EQU);
}
// Test for memset
SUB_TEST_CASE(memset){
BEGIN_DECL
    unsigned char dest[BUFFER_SIZE_S];
    EXPECT_EQ(memset(dest, 'A', 20), &dest[0]);
    EXPECT_ALL_EQU(dest, 'A', 20);
END_DECL
BEGIN_DECL
    unsigned char dest[BUFFER_SIZE_S];
    EXPECT_EQ(memset(dest, 0x55, 8), &dest[0]);
    EXPECT_ALL_EQU(dest, 0x55, 8);
    EXPECT_EQ(memset(dest, 0xaa, 8), &dest[0]);
    EXPECT_ALL_EQU(dest, 0xaa, 8);
END_DECL
BEGIN_DECL
    unsigned char dest[BUFFER_SIZE_L];
    EXPECT_EQ(memset(dest, 0xbb, BUFFER_SIZE_L), &dest[0]);
    EXPECT_ALL_EQU(dest, 0xbb, BUFFER_SIZE_L);
END_DECL
}
// Test for memcpy
SUB_TEST_CASE(memcpy){
BEGIN_DECL
    unsigned char buffer[] = "ABCDEFG";
    unsigned char dest[BUFFER_SIZE_S];
    EXPECT_EQ(memcpy(dest, buffer, sizeof(buffer)), &dest[0]);
    EXPECT_FALSE(memcmp(dest, buffer, sizeof(buffer)));
END_DECL
BEGIN_DECL
    unsigned char dest[BUFFER_SIZE_S];
    EXPECT_EQ(memcpy(dest, all_lower_cases, sizeof(all_lower_cases)), &dest[0]);
    EXPECT_FALSE(memcmp(dest, all_lower_cases, sizeof(all_lower_cases)));
END_DECL
BEGIN_DECL
    unsigned char dest[BUFFER_SIZE_S];
    EXPECT_EQ(memcpy(dest, all_upper_cases, sizeof(all_upper_cases)), &dest[0]);
    EXPECT_FALSE(memcmp(dest, all_upper_cases, sizeof(all_upper_cases)));
END_DECL
BEGIN_DECL
    unsigned char dest[BUFFER_SIZE_S];
    EXPECT_EQ(memcpy(dest, all_upper_cases, 10), &dest[0]);
    EXPECT_FALSE(memcmp(dest, all_upper_cases, 10));
END_DECL
BEGIN_DECL
    // Without overlap
    unsigned char dest[BUFFER_SIZE_S];
    memset(dest, 0, BUFFER_SIZE_S);
    EXPECT_EQ(memset(dest, 0x55, 10), &dest[0]);
    EXPECT_ALL_EQU(dest, 0x55, 10);
    EXPECT_EQ(memcpy(&dest[10], dest, 10), &dest[10]);
    EXPECT_ALL_EQU(dest, 0x55, 20);
END_DECL
BEGIN_DECL
    unsigned char dest[BUFFER_SIZE_S];
    memset(dest, 0, BUFFER_SIZE_S);
    EXPECT_EQ(memcpy(dest, all_lower_cases, sizeof(all_lower_cases) - 1), &dest[0]);
    EXPECT_FALSE(memcmp(dest, all_lower_cases, sizeof(all_lower_cases) - 1));
    EXPECT_EQ(dest[sizeof(all_lower_cases)], 0);
END_DECL
}
// Test for memmove
SUB_TEST_CASE(memmove){
BEGIN_DECL
    char buffer[BUFFER_SIZE_S];

    memset(buffer, 0, sizeof(buffer));
    EXPECT_EQ(strcpy(buffer, "HelloWorld"), buffer);
    EXPECT_EQ(memmove(buffer + 5, buffer, 5), buffer + 5); 
    EXPECT_TRUE(strcmp(buffer, "HelloHello") EQU);

    memset(buffer, 0, sizeof(buffer));
    EXPECT_EQ(strcpy(buffer, "123456789"), buffer);
    EXPECT_EQ(memmove(buffer + 2, buffer, 5), buffer + 2); 
    EXPECT_TRUE(strcmp(buffer, "121234589") EQU);

    memset(buffer, 0, sizeof(buffer));
    EXPECT_EQ(strcpy(buffer, "abcdef"), buffer);
    EXPECT_EQ(memmove(buffer, buffer + 2, 4), buffer);
    EXPECT_TRUE(strncmp(buffer, "cdef", 4) EQU);  

    memset(buffer, 0, sizeof(buffer));
    EXPECT_EQ(strcpy(buffer, "overlap"), buffer);
    EXPECT_EQ(memmove(buffer, buffer, 7), buffer); 
    EXPECT_TRUE(strcmp(buffer, "overlap") EQU);

    memset(buffer, 0xaa, sizeof(buffer));
    EXPECT_EQ(memmove(buffer, "data", 0), buffer); 
    EXPECT_EQ(buffer[0], (char)0xaa); 
    EXPECT_ALL_EQU(buffer, 0xaa, BUFFER_SIZE_S)

    memset(buffer, 0x55, sizeof(buffer));
    EXPECT_EQ(memmove(buffer, "", 1), buffer);  
    EXPECT_EQ(buffer[0], NULL_TERMINATOR);
    EXPECT_EQ(buffer[1], (char)0x55);
    EXPECT_ALL_EQU(&buffer[1], 0x55, 32);

    memset(buffer, 0, sizeof(buffer));
    EXPECT_EQ(strcpy(buffer, "abcdefgh"), buffer);
    EXPECT_EQ(memmove(buffer + 2, buffer, 3), buffer + 2);  
    EXPECT_TRUE(strncmp(buffer, "abab", 4) EQU);
    EXPECT_TRUE(strcmp(buffer, "ababcfgh") EQU);
END_DECL
BEGIN_DECL
    char largeSrc[BUFFER_SIZE_1K];
    char largeDest[BUFFER_SIZE_1K];
    memset(largeSrc, 'X', BUFFER_SIZE_1K - 1);
    largeSrc[BUFFER_SIZE_1K - 1] = '\0';
    EXPECT_EQ(memmove(largeDest, largeSrc, BUFFER_SIZE_1K), largeDest);
    EXPECT_TRUE(strcmp(largeDest, largeSrc) EQU);
END_DECL
}