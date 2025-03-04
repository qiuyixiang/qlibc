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
#include <string.h>
// Implementation of C String library

// String manipulation

/**
 * Copies the null-terminated byte string pointed to by src, 
 * including the null terminator,
 * to the character array whose first element is pointed to by dest
 */
char* strcpy(char *restrict dest, const char *restrict src){
    return (char *)memcpy(dest, src, strlen(src) + 1);
}

/**
 * Copies at most count characters of the character array pointed to by src 
 * to character array pointed to by dest. 
 * - If count <= len(src) :  the resulting character array is not null-terminated.
 * - If count > len(src) : additional null characters are written to dest until 
 *      the total of count characters have been written.
 */


// String examination

/**
 * Most of the string examination function don't check whether
 * the pointer is NULL, if is NULL it will cause segment fault !
 */

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

// Finds the first occurrence of ch in the null-terminated byte string
char* strchr(const char* str, int ch){
    for (; *str ; ++str)
        if (*(unsigned char *)str == (unsigned char)ch)
            return (char *)str;
    return (ch == '\0') ? (char *)str : NULL;
}
// Finds the last occurrence of ch in the null-terminated byte string
char* strrchr(const char* str, int ch){
    const char * __last = NULL;
    for (; *str; ++str)
        if (*(unsigned char *)str == (unsigned char)ch)
            __last = str;
    return (ch == '\0') ? (char *)str : (char *)__last;
}
/**
 * Returns the length of the maximum initial segment in dest,
 * that consists of only the characters found in src. 
 * Implementation detail: Using a Hash Table to quick search whether
 * dest[i] exists in src[i]. O(len(dest) + len(src))
 */
size_t strspn(const char* dest, const char* src){
    char __hash[256] = {0};
    for (size_t __index = 0; src[__index]; ++__index)
        __hash[(size_t)src[__index]] = 1;
    size_t __count = 0;
    while (dest[__count] && __hash[(size_t)dest[__count]])
        ++__count;
    return __count;
}
// Similar to strspn but is complement (in dest but not in src)
size_t strcspn(const char *dest, const char *src){
    char __hash[256] = {0};
    for (size_t __index = 0; src[__index]; ++__index)
        __hash[(size_t)src[__index]] = 1;
    size_t __count = 0;
    while (dest[__count] && !__hash[(size_t)dest[__count]])
        ++__count;
    return __count;
}
/**
 * Scans the null-terminated byte string pointed to by dest for any character
 *  from the null-terminated byte string pointed to by breakset,
 *  and returns a pointer to that character.
 */
char *strpbrk(const char *dest, const char *breakset){
    dest += strcspn(dest, breakset);
    return *dest ? (char *)dest : NULL;
}
/**
 * Finds the first occurrence of the null-terminated byte string pointed 
 * to by substr in the null-terminated byte string pointed to by str. 
 * The terminating null characters are not compared.
 */
/// TODO: Optimize algorithm use KMP or BM
char* strstr(const char* str, const char* substr){
    if (*substr == '\0')
        return (char *)str;
    for (; *str; ++str){
        if (*str == *substr){
            const char * __accept = str;
            const char * __substr = substr;
            for (;*__substr && (*__substr == *__accept); ++__substr, ++__accept);
            if (*__substr == '\0')
                return (char *)str;
        }
    }
    return NULL;
}

// Character array manipulation

/**
 * Finds the first occurrence of ch in the initial count bytes
 * The behavior is undefined if access occurs beyond the end of the array searched.
 * The behavior is undefined if ptr is a null pointer.
 */
void* memchr(const void* ptr, int ch, size_t count){
    for (const unsigned char* __start = ptr;
        count; --count, ++__start)
        if (*__start == (unsigned char)ch)
            return (void*)__start;
    return NULL;
}
// Compares the first count bytes of the objects pointed to by lhs and rhs
int memcmp(const void* lhs, const void* rhs, size_t count){
    const unsigned char * __lhs = lhs;
    const unsigned char * __rhs = rhs; 
    for (; count && (*__lhs == *__rhs); --count, ++__lhs, ++__rhs);
    return count ? (*__lhs - *__rhs) : 0;
}
// Fill the value ch into each of the first count characters of the object pointed to by dest.
void* memset(void *dest, int ch, size_t count){
    unsigned char *__dest = dest;
    for (; count; --count, ++__dest)
        *__dest = (unsigned char)ch;
    return dest;
}
/**
 * Copies count characters from the object pointed to by src to the object pointed to by dest.
 * If the objects overlap (which is a violation of the restrict contract)
 * the behavior is undefined !
 */
void* memcpy(void *restrict dest, const void *restrict src, size_t count){
    unsigned char * __dest = dest;
    const unsigned char * __src = src;
    for (; count; ++__dest, ++__src, --count)
        *__dest = *__src;
    return (void*)dest;
}