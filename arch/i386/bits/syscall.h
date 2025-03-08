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

// This file Implement System call on i386 linux system
#ifndef _QLIBC_I386_SYSCALL_H
#define _QLIBC_I386_SYSCALL_H

#undef EAX
#undef EBX
#undef ECX
#undef EDX

#define EAX             "a"
#define EBX             "b"
#define ECX             "c"
#define EDX             "d"
#define ESI             "S"
#define EDI             "D"
#define ANY_REGISTER    "r"
#define SYSCALL         "int $0x80"
#define MEMORY          "memory"


#define I386_SYSTEM_CALL    1

// System call Instruction in i386 linux
#define __ASM__             __asm__ __volatile__
#define SYSTEMCALL_PREFIX   static inline

typedef signed long             i32;
typedef unsigned long           u32;


// System call Procedure Number
#define __NR_restart_syscall        0
#define __NR_exit		            1
#define __NR_fork		            2
#define __NR_read		            3
#define __NR_write		            4
#define __NR_open		            5
#define __NR_close		            6
#define __NR_waitpid		        7
#define __NR_creat		            8
#define __NR_link		            9
#define __NR_unlink		            10
#define __NR_execve		            11
#define __NR_chdir		            12
#define __NR_time		            13
#define __NR_mknod		            14
#define __NR_chmod		            15
#define __NR_lchown		            16
#define __NR_break		            17
#define __NR_oldstat		        18
#define __NR_lseek		            19
#define __NR_getpid		            20

// Unified Error Checking
// This function will make sure that errno contain correct value
SYSTEMCALL_PREFIX i32 __syscall_ret(u32 _ret){
#ifdef _QLIBC_ERRNO_H

#else
    return (i32)_ret;
#endif
}

// Implementation of System Call With Different Argument
SYSTEMCALL_PREFIX i32 __syscall0(u32 _NR){
    u32 ret;
    __ASM__(SYSCALL : "=a"(ret) 
            : EAX(_NR) 
            : MEMORY);
    return __syscall_ret(ret);
}
SYSTEMCALL_PREFIX i32 __syscall1(u32 _NR, u32 _arg1){
    u32 ret;
    __ASM__(SYSCALL : "=a"(ret) 
            : EAX(_NR), EBX(_arg1) 
            : MEMORY);
    return __syscall_ret(ret);
}
SYSTEMCALL_PREFIX i32 __syscall2(u32 _NR, u32 _arg1, u32 _arg2){
    u32 ret;
    __ASM__(SYSCALL : "=a"(ret) 
            : EAX(_NR), EBX(_arg1), ECX(_arg2) 
            : MEMORY);
    return __syscall_ret(ret);
}
SYSTEMCALL_PREFIX i32 __syscall3(u32 _NR, u32 _arg1, u32 _arg2, u32 _arg3){
    u32 ret;
    __ASM__(SYSCALL : "=a"(ret) 
            : EAX(_NR), EBX(_arg1), ECX(_arg2), EDX(_arg3) 
            : MEMORY);
    return __syscall_ret(ret);
}
SYSTEMCALL_PREFIX i32 __syscall4(u32 _NR, u32 _arg1, u32 _arg2, u32 _arg3, u32 _arg4){
    u32 ret;
    __ASM__(SYSCALL : "=a"(ret) 
            : EAX(_NR), EBX(_arg1), ECX(_arg2), EDX(_arg3), ESI(_arg4)
            : MEMORY);
    return __syscall_ret(ret);
}
SYSTEMCALL_PREFIX i32 __syscall5(u32 _NR, u32 _arg1, u32 _arg2, u32 _arg3, u32 _arg4, u32 _arg5){
    u32 ret;
    __ASM__(SYSCALL : "=a"(ret) 
            : EAX(_NR), EBX(_arg1), ECX(_arg2), EDX(_arg3), ESI(_arg4), EDI(_arg5)
            : MEMORY);
    return __syscall_ret(ret);
}
SYSTEMCALL_PREFIX i32 __syscall6(u32 _NR, u32 _arg1, u32 _arg2, u32 _arg3, u32 _arg4, u32 _arg5, u32 _arg6){
    u32 ret;
    __ASM__("pushl %%ebp            \n\t"
            "movl %1, %%ebp         \n\t"
            "xchgl %%ebp, %%eax     \n\t"
            SYSCALL                 "\n\t"
            "popl %%ebp"
            : "=a"(ret) 
            : "g"(_NR), EBX(_arg1), ECX(_arg2), EDX(_arg3), ESI(_arg4), EDI(_arg5), EAX(_arg6)
            : MEMORY);
    return __syscall_ret(ret);
}

#endif