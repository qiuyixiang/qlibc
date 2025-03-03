#include "../test.h"
#include <string.h>

#define EQU                 == 0
#define LESS                < 0
#define GREATER             > 0
#define NULL_TERMINATOR     0x00

static const char all_lower_cases[] = "abcdefghijklmnopqrstuvwxyz";
static const char all_upper_cases[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static const char long_str[] = "WIJDKALDIWNDLSMCJSHDUWHDGAGWJDIQWOWKD:DWJSIDJCALDJWGBCIWGDJSICBWVQUDNSKC\
                                    <SMDHSUABSKDIWNDWBUQIWPEPPDSJD CBASJD";

SUB_TEST_CASE(strlen){
    const char buffer[] = "This is a formal test for strlen";
    EXPECT_EQ(strlen(buffer), sizeof(buffer) - 1);
    const char only_one[] = "S";
    const char __attribute__((unused)) next = '\0';
    EXPECT_EQ(strlen(only_one), 1);

    EXPECT_EQ(strlen(long_str), sizeof(long_str) - 1);
    EXPECT_EQ(strlen(all_lower_cases), sizeof(all_lower_cases) - 1);
    EXPECT_EQ(strlen(all_upper_cases), sizeof(all_upper_cases) - 1);
}

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

    EXPECT_TRUE(strcmp(long_str, long_str) EQU);
}

SUB_TEST_CASE(strncmp){
    EXPECT_TRUE(strncmp("AB", "AC", 1) EQU);
    EXPECT_TRUE(strncmp("L", "G", 0) EQU);
    EXPECT_TRUE(strncmp("ABCD", "ABC", 3) EQU);

    EXPECT_TRUE(strncmp("ABCD", "ABCO", 4) LESS);
    EXPECT_TRUE(strncmp("ABCO", "ABCD", 4) GREATER);
    EXPECT_TRUE(strncmp("ABC", "UVW", 0) EQU);

    EXPECT_TRUE(strncmp(long_str, long_str, 0) EQU);
    EXPECT_TRUE(strncmp(long_str, long_str, 12) EQU);
    EXPECT_TRUE(strncmp(long_str, long_str, 20) EQU);
    EXPECT_TRUE(strncmp("WIJD", long_str, 4) EQU);
    EXPECT_TRUE(strncmp("WIJD", long_str, 5) LESS);

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

    EXPECT_EQ(*strchr(long_str, ':'), ':');
    EXPECT_EQ(*strchr(long_str, '<'), '<');

    const char only_two[] = "A";
    EXPECT_EQ(*strchr(only_two, NULL_TERMINATOR), NULL_TERMINATOR);
}
SUB_TEST_CASE(strrchr){
    EXPECT_EQ(*strrchr("ABCDE", 'E'), 'E');
    EXPECT_EQ(*strrchr("ABCDE", 'A'), 'A');
    EXPECT_EQ(*strrchr("ABCDE", NULL_TERMINATOR), NULL_TERMINATOR);
    EXPECT_EQ(strrchr("ABCDE", 'F'), NULL);
    EXPECT_EQ(strrchr("ABCDE", 'W'), NULL);

    const char buffer[] = "ABCDEABCDEABCDE";
    EXPECT_EQ(strrchr(buffer, 'A'), &buffer[10]);
    EXPECT_EQ(strrchr(buffer, 'B'), &buffer[11]);
    EXPECT_EQ(strrchr(buffer, 'C'), &buffer[12]);
    EXPECT_EQ(strrchr(buffer, 'D'), &buffer[13]);
    EXPECT_EQ(strrchr(buffer, 'E'), &buffer[14]);
    EXPECT_EQ(*strrchr(buffer, NULL_TERMINATOR), buffer[15]);
    EXPECT_EQ(strrchr(buffer, NULL_TERMINATOR), &buffer[15]);

    EXPECT_EQ(*strrchr(long_str, ':'), ':');
    EXPECT_EQ(*strrchr(long_str, '<'), '<');

    EXPECT_EQ(strrchr(long_str, 'D'), &long_str[strlen(long_str) - 1]);
    EXPECT_EQ(strrchr(long_str, 'J'), &long_str[strlen(long_str) - 2]);
    EXPECT_EQ(strrchr(long_str, 'S'), &long_str[strlen(long_str) - 3]);
    EXPECT_EQ(strrchr(long_str, 'A'), &long_str[strlen(long_str) - 4]);
    EXPECT_EQ(strrchr(long_str, 'B'), &long_str[strlen(long_str) - 5]);
    EXPECT_EQ(strrchr(long_str, NULL_TERMINATOR), &long_str[strlen(long_str)]);
}

SUB_TEST_CASE(strspn){
BEGIN_DECL
    const char* analysis = "abcde312$#@";
    const char* source = "qwertyuiopasdfghjklzxcvbnm";
    size_t analysis_result = strspn(analysis, source);
    EXPECT_EQ(analysis_result, 5);
    EXPECT_TRUE(strcmp(analysis + analysis_result, "312$#@") EQU);
END_DECL
BEGIN_DECL
    const char* analysis = "abcde312$#@";
    const char* source = "312";
    size_t analysis_result = strspn(analysis, source);
    EXPECT_EQ(analysis_result, 0);
    EXPECT_TRUE(analysis + analysis_result == analysis);
END_DECL
BEGIN_DECL
    const char* analysis = "abcd";
    size_t analysis_result = strspn(analysis, all_lower_cases);
    EXPECT_EQ(analysis_result, 4);
    EXPECT_TRUE(*(analysis + analysis_result) == NULL_TERMINATOR);
END_DECL
BEGIN_DECL
    const char* analysis = "abcd";
    size_t analysis_result = strspn(analysis, all_upper_cases);
    EXPECT_EQ(analysis_result, 0);
    EXPECT_TRUE(*(analysis + analysis_result) == 'a');
END_DECL
BEGIN_DECL
    const char* analysis = "aiskwjdoalcpsodhqbcdhwo";
    size_t analysis_result = strspn(analysis, all_lower_cases);
    EXPECT_EQ(analysis_result, strlen(analysis));
    EXPECT_TRUE(*(analysis + analysis_result) == NULL_TERMINATOR);
END_DECL
}   

SUB_TEST_CASE(strcspn){
BEGIN_DECL
    const char* analysis = "abcde312$#@";
    const char* invalid = "qwertyuiopasdfghjklzxcvbnm";
    size_t analysis_result = strcspn(analysis, invalid);
    EXPECT_EQ(analysis_result, 0);
END_DECL
BEGIN_DECL
    const char* analysis = "abcde312$#@";
    const char* invalid = "wzz";
    size_t analysis_result = strcspn(analysis, invalid);
    EXPECT_EQ(analysis_result, strlen(analysis));
END_DECL
BEGIN_DECL
    const char* analysis = "abcde312$#@";
    const char* invalid = "@";
    size_t analysis_result = strcspn(analysis, invalid);
    EXPECT_EQ(analysis_result, strlen(analysis) - 1);
END_DECL
BEGIN_DECL
    const char* analysis = "abcde312$#@";
    const char* invalid = "312$#@";
    size_t analysis_result = strcspn(analysis, invalid);
    EXPECT_EQ(analysis_result, 5);
END_DECL
BEGIN_DECL
    const char* analysis = "abcdefghijk";
    size_t analysis_result = strcspn(analysis, all_lower_cases);
    EXPECT_EQ(analysis_result, 0);
END_DECL
BEGIN_DECL
    const char* analysis = "abcdefghijk";
    size_t analysis_result = strcspn(analysis, all_upper_cases);
    EXPECT_EQ(analysis_result, strlen(analysis));
END_DECL
BEGIN_DECL
    const char* analysis = "abcdefABCDEFgh";
    size_t analysis_result = strcspn(analysis, all_upper_cases);
    EXPECT_EQ(analysis_result, 6);
END_DECL
}
TEST_CASE(string){
    RUN_SUB_CASE(strlen);
    RUN_SUB_CASE(strcmp);
    RUN_SUB_CASE(strncmp);
#if (defined(QLIBC_WCHAR_SUPPORT)) && (QLIBC_WCHAR_SUPPORT == 1)
    RUN_SUB_CASE(strcoll);
#endif
    RUN_SUB_CASE(strchr);
    RUN_SUB_CASE(strrchr);
    RUN_SUB_CASE(strspn);
    RUN_SUB_CASE(strcspn);
}   