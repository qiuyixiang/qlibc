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

// file descriptor index
#define STDIN_FILENO        0
#define STDOUT_FILENO       1
#define STDERR_FILENO       2

// current file offset mode
#define SEEK_SET            0
#define SEEK_CUR            1
#define SEEK_END            2

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

long syscall(long number, ...);

/// file IO functions
extern ssize_t write(int fd, const void *buf, size_t count);
extern ssize_t read(int fd, void *buf, size_t count);
extern int close(int fd);

// the default offset in a file is 0
extern off_t lseek(int fd, off_t offset, int whence);

#ifdef __cplusplus
}
#endif

#include <sys/_syscall.h>

#endif