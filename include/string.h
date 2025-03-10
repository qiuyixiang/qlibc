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

#ifndef _QLIBC_STRING_H
#define _QLIBC_STRING_H

// All features in string form ANSI/ISO C99 Should be implemented in 
// qlibc version 0.1

// Undefine all macros to avoid conflict
#undef strlen
#undef strcmp
#undef strncmp
#undef strchr
#undef strrchr
#undef strspn
#undef strcspn

#undef memchr
#undef memcmp
#undef memset
#undef memcpy
#undef memmove

// Type define for string.h
#ifndef __cplusplus
#define NULL ((void*)0)
#else
#define NULL nullptr
#endif

typedef unsigned long   size_t;

#ifdef __cplusplus
extern "C" { 
#endif

// String manipulation
char* strcpy(char *restrict dest, const char *restrict src);
char* strncpy(char *restrict dest, const char *restrict src, size_t count);
char *strcat(char *restrict dest, const char *restrict src);
char *strncat(char *restrict dest, const char *restrict src, size_t count);

#if (defined(QLIBC_WCHAR_SUPPORT)) && (QLIBC_WCHAR_SUPPORT == 1)
size_t strxfrm(char *restrict dest, const char *restrict src, size_t count);
#endif

// String examination
size_t strlen(const char* str);
int strcmp(const char* lhs, const char* rhs);
int strncmp(const char* lhs, const char* rhs, size_t count);

#if (defined(QLIBC_WCHAR_SUPPORT)) && (QLIBC_WCHAR_SUPPORT == 1)
int strcoll(const char* lhs, const char* rhs);
#endif

char* strchr(const char* str, int ch);
char* strrchr(const char* str, int ch);
size_t strspn(const char* dest, const char* src);
size_t strcspn(const char *dest, const char *src);
char* strpbrk(const char *dest, const char *breakset);
char* strstr(const char* str, const char* substr);
char* strtok(char* restrict str, const char* restrict delim);

// Character array manipulation
void* memchr(const void* ptr, int ch, size_t count);
int memcmp(const void* lhs, const void* rhs, size_t count);
void* memset(void *dest, int ch, size_t count);
void* memcpy(void *restrict dest, const void *restrict src, size_t count);
void* memmove(void* dest, const void* src, size_t count);

// Miscellaneous
#if (defined(QLIBC_POSIX_FINISH)) && (QLIBC_POSIX_FINISH == 1)
// Not implemented yet (need for Unix POSIX)
char* strerror(int errnum);
#endif

#ifdef __cplusplus
}
#endif

#endif