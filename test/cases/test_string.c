#include "../test.h"
#include <string.h>

SUB_TEST_CASE(strlen){
    const char buffer[] = "This is a formal test for strlen";
    EXPECT_EQ(strlen(buffer), sizeof(buffer) - 1);
    const char only_one[] = "S";
    const char __attribute__((unused)) next = '\0';
    EXPECT_EQ(strlen(only_one), 1);
}

#define EQU                 == 0
#define LESS                < 0
#define GREATER             > 0
#define NULL_TERMINATOR     0x00

static unsigned char long_str[] = "WIJDKALDIWNDLSMCJSHDUWHDGAGWJDIQWOWKD:DWJSIDJCALDJWGBCIWGDJSICBWVQUDNSKC\
                                    <SMDHSUABSKDIWNDWBUQIWPEPPDSJD CBASJD";
SUB_TEST_CASE(strcmp){
    EXPECT_TRUE(strcmp("A", "A") EQU);
    EXPECT_TRUE(strcmp("B", "D") LESS);
    EXPECT_TRUE(strcmp("E", "F") LESS);
    EXPECT_TRUE(strcmp("P", "C") GREATER);

    EXPECT_TRUE(strcmp("AB", "A") GREATER);
    EXPECT_TRUE(strcmp("ABC", "ABC") EQU);
    EXPECT_TRUE(strcmp("ABCD", "ABCDEF") LESS);

    EXPECT_TRUE(strcmp("A", "a") LESS);
    EXPECT_TRUE(strcmp("E", "e") LESS);
    EXPECT_TRUE(strcmp("d", "D") GREATER);
    EXPECT_TRUE(strcmp("abC", "abc") LESS);

    unsigned char fix_buffer[2];
    fix_buffer[0] = 0x01;
    fix_buffer[1] = NULL_TERMINATOR;

    unsigned char cmp_buffer[2];
    cmp_buffer[1] = NULL_TERMINATOR;
    for (unsigned char var = 0x02; var != 0x7f; ++var){
        cmp_buffer[0] = var;
        EXPECT_TRUE(strcmp((const char *)fix_buffer, (const char *)cmp_buffer) LESS);
        EXPECT_TRUE(strcmp((const char *)cmp_buffer, (const char *)fix_buffer) GREATER);
    }

    EXPECT_TRUE(strcmp((const char*)long_str, (const char *)long_str) EQU);
}

SUB_TEST_CASE(strncmp){
    EXPECT_TRUE(strncmp("AB", "AC", 1) EQU);
    EXPECT_TRUE(strncmp("L", "G", 0) EQU);
    EXPECT_TRUE(strncmp("ABCD", "ABC", 3) EQU);

    EXPECT_TRUE(strncmp("ABCD", "ABCO", 4) LESS);
    EXPECT_TRUE(strncmp("ABCO", "ABCD", 4) GREATER);
    EXPECT_TRUE(strncmp("ABC", "UVW", 0) EQU);

    EXPECT_TRUE(strncmp((const char*)long_str, (const char *)long_str, 0) EQU);
    EXPECT_TRUE(strncmp((const char*)long_str, (const char *)long_str, 12) EQU);
    EXPECT_TRUE(strncmp((const char*)long_str, (const char *)long_str, 20) EQU);
    EXPECT_TRUE(strncmp("WIJD", (const char *)long_str, 4) EQU);
    EXPECT_TRUE(strncmp("WIJD", (const char *)long_str, 5) LESS);

    EXPECT_TRUE(strncmp("ABCDEF", "ABCDE", 5) EQU);
    EXPECT_TRUE(strncmp("ABCDEF", "ABCDE", 6) GREATER);
    EXPECT_TRUE(strncmp("ABCDE", "ABCDEF", 6) LESS);
}
#if (defined(QLIBC_WCHAR_SUPPORT)) && (QLIBC_WCHAR_SUPPORT == 1)
SUB_TEST_CASE(strcoll){ }
#endif

SUB_TEST_CASE(strchr){
    EXPECT_EQ(*strchr("ABCDE", 'C'), 'C');
    EXPECT_EQ(*strchr("ABCDE", 'A'), 'A');
    EXPECT_EQ(*strchr("ABCDE", NULL_TERMINATOR), NULL_TERMINATOR);
    EXPECT_EQ(strchr("ABCDE", 'F'), NULL);
    EXPECT_EQ(strchr("ABCDE", 'W'), NULL);

    const char buffer[] = "ABCDEABCDEABCDE";
    EXPECT_EQ(strchr(buffer, 'A'), buffer);
    EXPECT_EQ(strchr(buffer, 'B'), buffer + 1);
    EXPECT_EQ(strchr(buffer, 'C'), buffer + 2);
    EXPECT_EQ(strchr(buffer, 'D'), buffer + 3);
    EXPECT_EQ(strchr(buffer, 'E'), buffer + 4);

    EXPECT_EQ(*strchr((const char *)long_str, ':'), ':');
    EXPECT_EQ(*strchr((const char *)long_str, '<'), '<');

    const char only_two[] = "A";
    EXPECT_EQ(*strchr(only_two, NULL_TERMINATOR), NULL_TERMINATOR);
}

TEST_CASE(string){
    RUN_SUB_CASE(strlen);
    RUN_SUB_CASE(strcmp);
    RUN_SUB_CASE(strncmp);
#if (defined(QLIBC_WCHAR_SUPPORT)) && (QLIBC_WCHAR_SUPPORT == 1)
    RUN_SUB_CASE(strcoll);
#endif
    RUN_SUB_CASE(strchr);

}