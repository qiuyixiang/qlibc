/**
 *  MIT License
 *
 *  Copyright (c) 2025 QIU YIXIANG
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */
#include <stddef.h>
// Implementation of C String library


// String examination
// Most of the string examination function don't check whether
// the pointer is NULL, if is NULL it will cause segment fault !

/**
 * Implementation of strlen: current version 0.1 without optimization. 
 * In the future version it will be optimized for better memory block access.
 * TODO: Optimize for memory block access read for one word per time
 */

// returns the length of a given string
size_t strlen(const char* str){
    const char * __p = str;
    for (; *__p; ++__p);
    return __p - str;
}
// compares two strings
int strcmp(const char* lhs, const char* rhs){
    for (; *lhs && (*lhs == *rhs); ++lhs, ++rhs);
    return *(unsigned char*)lhs - *(unsigned char*)rhs;
}
// compares a certain amount of characters of two strings
int strncmp(const char* lhs, const char* rhs, size_t count){
    if (count == 0)
        return 0;
    --count;
    for (; *lhs && *rhs && count && (*lhs == *rhs); ++lhs, ++rhs, --count);
    return *(unsigned char*)lhs - *(unsigned char*)rhs;
}

#if (defined(QLIBC_WCHAR_SUPPORT)) && (QLIBC_WCHAR_SUPPORT == 1)
#error "Not implement strcoll for local yet !"
int strcoll(const char* lhs, const char* rhs) { }
#endif

// Finds the first occurrence of ch  in the null-terminated byte string
char* strchr(const char* str, int ch){
    for (; *str ; ++str)
        if (*(unsigned char *)str == (unsigned char)ch)
            return (char *)str;
    return (ch == '\0') ? (char *)str : NULL;
}
