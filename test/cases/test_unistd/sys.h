#include <unistd.h>
#include <utest.h>
#include <sys/syscall.h>

#if (USING_QLIBC == 1)
// internal implementation not public interface
#include <sys/_syscall.h>

#define ANY_NR      0
SUB_TEST_CASE(unistd_syscall){
    EXPECT_EQ(__SYSCALL_NARGS(ANY_NR), 0);
    EXPECT_EQ(__SYSCALL_NARGS(ANY_NR, 1), 1);
    EXPECT_EQ(__SYSCALL_NARGS(ANY_NR, 1, 2), 2);
    EXPECT_EQ(__SYSCALL_NARGS(ANY_NR, 1, 2, 3), 3);
    EXPECT_EQ(__SYSCALL_NARGS(ANY_NR, 1, 2, 3, 4), 4);
    EXPECT_EQ(__SYSCALL_NARGS(ANY_NR, 1, 2, 3, 4, 5), 5);
    EXPECT_EQ(__SYSCALL_NARGS(ANY_NR, 1, 2, 3, 4, 5, 6), 6);
}
#else 
SUB_TEST_CASE(unistd_syscall) { }
#endif

#undef ANY_NR