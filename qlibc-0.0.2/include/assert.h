#ifndef _QLIBC_ASSERT_H_
#define _QLIBC_ASSERT_H_ 1

// Diagnostic Library In qlibc
// Header File Declaration

// The Declaration Of Inner Implementation 
extern void __qlibc_assert(const char * __expr, 
        const char * __file, const char * __func, int __line);

#undef assert

#ifndef NDEBUG
    #define assert(_expr) (_expr ? ((void) 0) : \
            __qlibc_assert(""#_expr, __FILE__, __func__, __LINE__))
#else 
    #define assert(_expr) ((void) 0)
#endif

#endif