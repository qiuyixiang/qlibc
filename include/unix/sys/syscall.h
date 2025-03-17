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

// implement macros for system call number
// start with SYS_ 

#ifndef _QLIBC_SYS_SYSCALL_H
#define _QLIBC_SYS_SYSCALL_H   

// this header file will included system call number depends on architecture
#include <bits/syscall.h>

#ifdef _QLIBC_I386_SYSCALL_H
#define SYS_restart_syscall     __NR_restart_syscall
#endif

#define SYS_exit                __NR_exit
#define SYS_fork                __NR_fork
#define SYS_read                __NR_read 
#define SYS_write               __NR_write
#define SYS_open                __NR_open
#define SYS_close               __NR_close
#define SYS_waitpid             __NR_waitpid
#define SYS_creat               __NR_creat
#define SYS_link                __NR_link
#define SYS_unlink              __NR_unlink
#define SYS_execve              __NR_execve
#define SYS_chdir               __NR_chdir
#define SYS_time                __NR_time
#define SYS_mknod               __NR_mknod
#define SYS_chmod               __NR_chmod
#define SYS_lchown              __NR_lchown
#define SYS_break               __NR_break
#define SYS_oldstat             __NR_oldstat
#define SYS_lseek               __NR_lseek
#define SYS_getpid              __NR_getpid
#define SYS_mount               __NR_mount

#define SYS_openat              __NR_openat

#endif