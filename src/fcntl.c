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

// implement fcntl utility functions 
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/syscall.h>

int open(const char *filename, int flag, ...){
    mode_t mode = 0;

    if (flag & O_CREAT){
        va_list __args;
        va_start(__args, flag);
        mode = va_arg(__args, mode_t);
        va_end(__args);
    }
    return syscall(SYS_open, filename, flag, mode);
}
int openat(int fd, const char *filename, int flag, ...){
    mode_t mode = 0;

    if (flag & O_CREAT){
        va_list __args;
        va_start(__args, flag);
        mode = va_arg(__args, mode_t);
        va_end(__args);
    }
    return syscall(SYS_openat, fd, filename, flag, mode);
}
int creat(const char * filename, mode_t mode){
    return open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
}