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

/**
 * Implementation of strlen: current version 0.1 without optimization. 
 * In the future version it will be optimized for better memory block access.
 * TODO: Optimize for memory block access read for one word per time
 */

size_t strlen(const char* str){
    const char * __p = str;
    for (; *__p; ++__p);
    return __p - str;
}
int strcmp(const char* lhs, const char* rhs){
    for (; *lhs && (*lhs == *rhs); ++lhs, ++rhs);
    return *(unsigned char*)lhs - *(unsigned char*)rhs;
}
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

char* strchr(const char* str, int ch){
    for (; *str ; ++str)
        if (*(unsigned char *)str == (unsigned char)ch)
            return (char *)str;
    return (ch == '\0') ? (char *)str : NULL;
}
