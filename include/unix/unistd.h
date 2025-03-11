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


// this header provide API for Unix POSIX System 
// in the current qlibc version the <unistd.h> only support the function that ISO C needs

#ifndef _QLIBC_UNISTD_H
#define _QLIBC_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

// file descriptor index
#define STDIN_FILENO        0
#define STDOUT_FILENO       1
#define STDERR_FILENO       2

// type define for general types
typedef signed long         ssize_t;
typedef long                off_t;
#include <stddef.h>

// File IO Functions
extern ssize_t write(int fd, const void *buf, size_t count);
extern ssize_t read(int fd, void *buf, size_t count);
extern int close(int fd);

#ifdef __cplusplus
}
#endif

#endif