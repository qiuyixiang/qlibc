#ifndef _QLIBC_STDDEF_H_
#define _QLIBC_STDDEF_H_ 1

#ifndef _QLIBC_QSTDDEF_H_
#include <extension/qstddef.h>
#endif 

// Define Some General Data Type For C
// Conform For ISO/ANSI C

// You Can Use Macro __X86__ To Choose 32-bits Data Type

#define size_t      _SIZE_T
#define ptrdiff_t   _PTR_DIFF_T
#define NULL        _NULL_TYPE
#define wchar_t     _W_CHAR_TYPE

// Define For Offsetof
#define offsetof(TYPE, MEMBER) _QLIBC_OFFSET_OF(TYPE, MEMBER)

#endif