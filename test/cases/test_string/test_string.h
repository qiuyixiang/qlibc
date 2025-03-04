// Test Macros for String

#ifndef CASES_TEST_STRING_H
#define CASES_TEST_STRING_H

// The Macros below are needed for string test cases
#define EQU                 == 0
#define LESS                < 0
#define GREATER             > 0
#define NULL_TERMINATOR     0x00

#define BUFFER_SIZE_S       64
#define BUFFER_SIZE_M       128
#define BUFFER_SIZE_L       256
#define BUFFER_SIZE_1K      1024
#define BUFFER_SIZE_2K      2048

#define BITS(TYPE)          8 * sizeof(TYPE)

// This macro ensure that the variables will not conflict with
// outer variable space.
#define EXPECT_ALL_EQU(DEST, VALUE, SIZE)               \
BEGIN_DECL                                              \
    unsigned char * _buffer = (unsigned char *)DEST;    \
    size_t _count = (size_t)SIZE;                       \
    for ( ; _count; ++_buffer, --_count)                \
        EXPECT_EQ(*_buffer, (unsigned char)VALUE);      \
END_DECL                  

// The header will be included only once so it's ok to define these variables
static const char all_lower_cases[] = "abcdefghijklmnopqrstuvwxyz";
static const char all_upper_cases[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static const char long_str[] = "WIJDKALDIWNDLSMCJSHDUWHDGAGWJDIQWOWKD:DWJSIDJCALDJWGBCIWGDJSICBWVQUDNSKC\
                                    <SMDHSUABSKDIWNDWBUQIWPEPPDSJD CBASJD";

#endif