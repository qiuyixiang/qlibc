#include "../test.h"
#include <string.h>

#define EQU                 == 0
#define LESS                < 0
#define GREATER             > 0
#define NULL_TERMINATOR     0x00

#define BUFFER_SIZE_S       64
#define BUFFER_SIZE_M       128
#define BUFFER_SIZE_L       256
#define BUFFER_SIZE_1K      1024
#define BUFFER_SIZE_2K      2048

// This macro ensure that the variables will not conflict with
// outer variable space.
#define EXPECT_ALL_EQU(DEST, VALUE, SIZE)               \
BEGIN_DECL                                              \
    unsigned char * _buffer = (unsigned char *)DEST;    \
    size_t _count = (size_t)SIZE;                       \
    for ( ; _count; ++_buffer, --_count)                \
        EXPECT_EQ(*_buffer, (unsigned char)VALUE);      \
END_DECL                  

static const char all_lower_cases[] = "abcdefghijklmnopqrstuvwxyz";
static const char all_upper_cases[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static const char long_str[] = "WIJDKALDIWNDLSMCJSHDUWHDGAGWJDIQWOWKD:DWJSIDJCALDJWGBCIWGDJSICBWVQUDNSKC\
                                    <SMDHSUABSKDIWNDWBUQIWPEPPDSJD CBASJD";

// Test String examination                                   
SUB_TEST_CASE(strlen){
BEGIN_DECL
    const char buffer[] = "This is a formal test for strlen";
    EXPECT_EQ(strlen(buffer), sizeof(buffer) - 1);
    const char only_one[] = "S";
    const char __attribute__((unused)) next = '\0';
    EXPECT_EQ(strlen(only_one), 1);
END_DECL

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

BEGIN_DECL
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
END_DECL

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

BEGIN_DECL
    const char buffer[] = "ABCDEABCDEABCDE";
    EXPECT_EQ(strchr(buffer, 'A'), buffer);
    EXPECT_EQ(strchr(buffer, 'B'), buffer + 1);
    EXPECT_EQ(strchr(buffer, 'C'), buffer + 2);
    EXPECT_EQ(strchr(buffer, 'D'), buffer + 3);
    EXPECT_EQ(strchr(buffer, 'E'), buffer + 4);
END_DECL

    EXPECT_EQ(*strchr(long_str, ':'), ':');
    EXPECT_EQ(*strchr(long_str, '<'), '<');

BEGIN_DECL
    const char only_two[] = "A";
    EXPECT_EQ(*strchr(only_two, NULL_TERMINATOR), NULL_TERMINATOR);
END_DECL
}
SUB_TEST_CASE(strrchr){
    EXPECT_EQ(*strrchr("ABCDE", 'E'), 'E');
    EXPECT_EQ(*strrchr("ABCDE", 'A'), 'A');
    EXPECT_EQ(*strrchr("ABCDE", NULL_TERMINATOR), NULL_TERMINATOR);
    EXPECT_EQ(strrchr("ABCDE", 'F'), NULL);
    EXPECT_EQ(strrchr("ABCDE", 'W'), NULL);

BEGIN_DECL
    const char buffer[] = "ABCDEABCDEABCDE";
    EXPECT_EQ(strrchr(buffer, 'A'), &buffer[10]);
    EXPECT_EQ(strrchr(buffer, 'B'), &buffer[11]);
    EXPECT_EQ(strrchr(buffer, 'C'), &buffer[12]);
    EXPECT_EQ(strrchr(buffer, 'D'), &buffer[13]);
    EXPECT_EQ(strrchr(buffer, 'E'), &buffer[14]);
    EXPECT_EQ(*strrchr(buffer, NULL_TERMINATOR), buffer[15]);
    EXPECT_EQ(strrchr(buffer, NULL_TERMINATOR), &buffer[15]);
END_DECL

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

SUB_TEST_CASE(strpbrk){
    EXPECT_EQ(*strpbrk("abcdef", "cde"), 'c');
    EXPECT_EQ(*strpbrk("abcdef", "f"), 'f');
    EXPECT_EQ(*strpbrk("ab?cdef", "?"), '?');
    EXPECT_EQ(strpbrk("abcdef", "g"), NULL);
    EXPECT_EQ(strpbrk("abcdef", "z"), NULL);
    EXPECT_EQ(*strpbrk(all_lower_cases, "f"), 'f');

BEGIN_DECL
    const char buffer[] = "abcdabcdabcd";
    EXPECT_EQ(strpbrk(buffer, "a"), &buffer[0]);
    EXPECT_EQ(strpbrk(buffer, "b"), &buffer[1]);
    EXPECT_EQ(strpbrk(buffer, "c"), &buffer[2]);
    EXPECT_EQ(strpbrk(buffer, "d"), &buffer[3]);
    EXPECT_EQ(strpbrk(buffer, "abcd"), &buffer[0]);
END_DECL
    EXPECT_TRUE(strcmp(strpbrk("hello world", "o"), "o world") EQU);
    EXPECT_TRUE(strcmp(strpbrk("abcdef", "cd"), "cdef") EQU);
    EXPECT_TRUE(strcmp(strpbrk("abcdef", "a"), "abcdef") EQU);

    EXPECT_TRUE(strcmp(strpbrk("hello world", "oe"), "ello world") EQU);
    EXPECT_TRUE(strcmp(strpbrk("abcdef", "dcba"), "abcdef") EQU);

    EXPECT_EQ(strpbrk("hello", "xyz"), NULL);
    EXPECT_EQ(strpbrk("", "xyz"), NULL);
    EXPECT_EQ(strpbrk("hello", ""), NULL);
    EXPECT_EQ(strpbrk("", "aeiou"), NULL);
    EXPECT_EQ(strpbrk("abcdef", "z"), NULL);

    EXPECT_TRUE(strcmp(strpbrk("hello", "o"), "o") EQU);
    EXPECT_TRUE(strcmp(strpbrk("abcdef", "f"), "f") EQU);
    EXPECT_TRUE(strcmp(strpbrk("hello\nworld", "\n"), "\nworld") EQU);
    EXPECT_TRUE(strcmp(strpbrk("12345", "5"), "5") EQU);
    EXPECT_TRUE(strcmp(strpbrk("abc123", "0123456789"), "123") EQU);
    EXPECT_TRUE(strcmp(strpbrk("hello world", " "), " world") EQU);
}

SUB_TEST_CASE(strstr){
    EXPECT_EQ(sizeof(""), 1);
    EXPECT_TRUE(strcmp(strstr("abc", ""), "abc") EQU);
    EXPECT_TRUE(strcmp(strstr("", ""), "") EQU);
    EXPECT_TRUE(strcmp(strstr(all_lower_cases, ""), all_lower_cases) EQU);
    EXPECT_TRUE(strcmp(strstr(all_upper_cases, ""), all_upper_cases) EQU);
    EXPECT_TRUE(strcmp(strstr(long_str, ""), long_str) EQU);

    EXPECT_EQ(*strstr("abcd", "ab"), 'a');
    EXPECT_EQ(*strstr("abcd", "abc"), 'a');
    EXPECT_EQ(*strstr("abcd", "abcd"), 'a');
BEGIN_DECL
    const char buffer[] = "abcdabcdabcd";
    EXPECT_EQ(strstr(buffer, "abc"), &buffer[0]);
    EXPECT_EQ(strstr(buffer, "abcd"), &buffer[0]);
    EXPECT_EQ(strstr(buffer, "abcda"), &buffer[0]);
    EXPECT_EQ(strstr(buffer, "da"), &buffer[3]);
    EXPECT_EQ(strstr(buffer, "cd"), &buffer[2]);
    EXPECT_EQ(strstr(buffer, "dab"), &buffer[3]);
END_DECL
    EXPECT_EQ(strstr("abcd", "efg"), NULL);
    EXPECT_EQ(strstr("abcdefg", "ll"), NULL);
    EXPECT_EQ(strstr("abcdefg", "a?"), NULL);
    EXPECT_EQ(strstr("abcdefg", "ab?"), NULL);
    EXPECT_EQ(strstr("abcdefg", "abc/"), NULL);
    EXPECT_EQ(strstr("abcdefg", "abcdefgh"), NULL);

    EXPECT_TRUE(strcmp(strstr("hello world", "world"), "world") EQU);
    EXPECT_TRUE(strcmp(strstr("abcdef", "cd"), "cdef") EQU);
    EXPECT_TRUE(strcmp(strstr("abcdef", "a"), "abcdef") EQU);
    EXPECT_TRUE(strcmp(strstr("hello", "hello"), "hello") EQU);
    
    EXPECT_TRUE(strcmp(strstr("hello", "hell"), "hello") EQU);
    EXPECT_TRUE(strcmp(strstr("hello", "ell"), "ello") EQU);
    EXPECT_TRUE(strcmp(strstr("hello", ""), "hello") EQU);
    EXPECT_TRUE(strcmp(strstr("", ""), "") EQU);
    
    EXPECT_TRUE(strcmp(strstr("aaaaa", "aa"), "aaaaa") EQU);
    EXPECT_TRUE(strcmp(strstr("aaaaa", "aaa"), "aaaaa") EQU);
    EXPECT_TRUE(strcmp(strstr("hello", "o"), "o") EQU);
    EXPECT_TRUE(strcmp(strstr("abcdef", "f"), "f") EQU);

    EXPECT_EQ(strstr("hello", "xyz"), NULL);
    EXPECT_EQ(strstr("", "xyz"), NULL);
    EXPECT_EQ(strstr("abcdef", "z"), NULL);
    EXPECT_EQ(strstr("abc", "abcdef"), NULL);
}

// Test Character array manipulation
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
TEST_CASE(string){
    // Test String examination
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
    RUN_SUB_CASE(strpbrk);
    RUN_SUB_CASE(strstr);

    // Test Character array manipulation
    RUN_SUB_CASE(memchr);
    RUN_SUB_CASE(memcmp);
    RUN_SUB_CASE(memset);
    RUN_SUB_CASE(memcpy);
}   