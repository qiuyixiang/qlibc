#include <string.h>

// Include all Sub-test cases (will be included only once)
// The category is divided according ANSI/ISO C Standard Reference
#include "test_string/manipulation.h"
#include "test_string/examination.h"
#include "test_string/character_array.h"

// Test for types in <string.h>
SUB_TEST_CASE(string_type){
    EXPECT_EQ(NULL, 0);
    EXPECT_TRUE(BITS(size_t) >= 16);
#if (TEST_WORD == BITS32)
    EXPECT_EQ(BITS(size_t), BITS32);
#elif (TEST_WORD == BITS64)
    EXPECT_EQ(BITS(size_t), BITS64);
#endif
}   
TEST_CASE(string){
    // Test String Types
    RUN_SUB_TEST_CASE(string_type);

    // Test String manipulation
    RUN_SUB_TEST_CASE(strcpy);
    RUN_SUB_TEST_CASE(strncpy);
    RUN_SUB_TEST_CASE(strcat);
    RUN_SUB_TEST_CASE(strncat);
#if (defined(QLIBC_WCHAR_SUPPORT)) && (QLIBC_WCHAR_SUPPORT == 1)
    RUN_SUB_TEST_CASE(strxfrm);
#endif

    // Test String examination
    RUN_SUB_TEST_CASE(strlen);
    RUN_SUB_TEST_CASE(strcmp);
    RUN_SUB_TEST_CASE(strncmp);
#if (defined(QLIBC_WCHAR_SUPPORT)) && (QLIBC_WCHAR_SUPPORT == 1)
    RUN_SUB_TEST_CASE(strcoll);
#endif
    RUN_SUB_TEST_CASE(strchr);
    RUN_SUB_TEST_CASE(strrchr);
    RUN_SUB_TEST_CASE(strspn);
    RUN_SUB_TEST_CASE(strcspn);
    RUN_SUB_TEST_CASE(strpbrk);
    RUN_SUB_TEST_CASE(strstr);
    RUN_SUB_TEST_CASE(strtok);

    // Test Character array manipulation
    RUN_SUB_TEST_CASE(memchr);
    RUN_SUB_TEST_CASE(memcmp);
    RUN_SUB_TEST_CASE(memset);
    RUN_SUB_TEST_CASE(memcpy);
    RUN_SUB_TEST_CASE(memmove);
}   