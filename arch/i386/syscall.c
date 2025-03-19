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
// implementation if system call for i386 architecture

// System call Instruction in i386 linux
#define __ASM__             __asm__ __volatile__
#define SYSTEMCALL_PREFIX  

typedef signed int             i32;
typedef unsigned int           u32;

#include <errno.h>
// Unified Error Checking
// This function will make sure that errno contain correct value
static inline i32 __syscall_ret(u32 _ret){
#ifdef _QLIBC_ERRNO_H
    if ((i32)_ret < 0){
        errno = -(i32)_ret;
        return -1;
    }
    return (i32)_ret;
#else
    return (i32)_ret;
#endif
}

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

// implementation of system call with different argument
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