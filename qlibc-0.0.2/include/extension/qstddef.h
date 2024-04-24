#ifndef _QLIBC_QSTDDEF_H_
#define _QLIBC_QSTDDEF_H_ 1

/*
    Definition For Internal Type Define
    Create on 2024-04-24
*/

#if defined(__X86__)
#define Q_X86_FLAG 1
#endif

// This Macro Just Using As Test
#ifdef _DEBUGGER_Q
#define _USING_QLIBC_STDDEF 1
#endif

#if defined(Q_X86_FLAG) || defined(__X86__)
// 32-bits Program
#define _SIZE_T         unsigned int
#define _PTR_DIFF_T     signed int
#define _W_CHAR_TYPE    unsigned short

#else
// 64-bits Program
#define _SIZE_T         unsigned long
#define _PTR_DIFF_T     signed long
#define _W_CHAR_TYPE    unsigned int

#endif

// Define Arch Dependent Variables
#define _NULL_TYPE (void *)0  
#define _QLIBC_OFFSET_OF(_TYPE, _MEMBER) ((_SIZE_T) &(((_TYPE *)0)->_MEMBER))

#endif