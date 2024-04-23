#ifndef _QLIBC_ASSERT_H
#define _QLIBC_ASSERT_H 1

// This File Is A Header For C Diagnostic Library !

extern void __qlibc_assert(const char * __assert_msg, const char * __func, 
        const char * __file, int __line);

#undef assert

#ifndef NDEBUG
// Enable Assert Error Message
#define assert(_expr) (_expr ? ((void)0) : \
                    __qlibc_assert(""#_expr, __func__, __FILE__, __LINE__))
#else
// Disable Assert Error Message
#define assert(_expr) ((void)0)

#endif

#endif