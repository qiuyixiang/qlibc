#include <utest.h>
#include <stdarg.h>

#if ((USING_QLIBC == 1) && (!defined(_QLIBC_STDARG_H)))
#error "Expect header <stdarg.h> in qlibc"
#endif

// (int, int, int)
void arg_check1(int count, ...){
    va_list args;
    va_start(args, count);
    if (count <= 1)
        EXPECT_EQ(va_arg(args, int), 10);
    else if (count <= 2){
        EXPECT_EQ(va_arg(args, int), 10);
        EXPECT_EQ(va_arg(args, int), 20);
    }else{
        EXPECT_EQ(va_arg(args, int), 10);
        EXPECT_EQ(va_arg(args, int), 20);
        EXPECT_EQ(va_arg(args, int), 30);
    }
    va_end(args);
}

// (char, double, float, long, void *)
// And there will be type promotions 
void arg_check2(int count, int fix, ...){
    va_list args;
    va_start(args, fix);
    EXPECT_EQ(fix, 0xbb);
    EXPECT_EQ(sizeof(fix), sizeof(int));
    if (count <= 1)
        EXPECT_EQ(va_arg(args, int), 'A');
    else if (count <= 2){
        EXPECT_EQ(va_arg(args, int), 'A');
        EXPECT_EQ(va_arg(args, double), (double)0.3815);
    }else if (count <= 3){
        EXPECT_EQ(va_arg(args, int), 'A');
        EXPECT_EQ(va_arg(args, double), (double)0.3815);
        EXPECT_EQ(va_arg(args, double), (double)3.1415926);
    }else if (count <= 4){
        EXPECT_EQ(va_arg(args, int), 'A');
        EXPECT_EQ(va_arg(args, double), (double)0.3815);
        EXPECT_EQ(va_arg(args, double), (double)3.1415926);
        EXPECT_EQ(va_arg(args, long), 0x7c9b0000);
    }else{
        EXPECT_EQ(va_arg(args, int), 'A');
        EXPECT_EQ(va_arg(args, double), (double)0.3815);
        EXPECT_EQ(va_arg(args, double), (double)3.1415926);
        EXPECT_EQ(va_arg(args, long), 0x7c9b0000);
        EXPECT_EQ(va_arg(args, void*), NULL);
    }
    va_end(args);
}

SUB_TEST_CASE(stdarg_fix_type){
    // check arguments with fixed type
    arg_check1(1, 10);
    arg_check1(2, 10, 20);
    arg_check1(3, 10, 20, 30);
}
SUB_TEST_CASE(stdarg_diff_type){
    // check arguments with different type
    arg_check2(1, 0xbb, 'A');
    arg_check2(2, 0xbb, 'A', 0.3815);
    arg_check2(3, 0xbb, 'A', 0.3815, 3.1415926);
    arg_check2(4, 0xbb, 'A', 0.3815, 3.1415926, 0x7c9b0000);
    arg_check2(5, 0xbb, 'A', 0.3815, 3.1415926, 0x7c9b0000, NULL);
}
TEST_CASE(stdarg){    
#if (TEST_ARCH == I386)
    EXPECT_EQ(sizeof(va_list), sizeof(char *));
#endif
    RUN_TEST_FLAG(stdarg_fix_type, FLAG_PURE_FUNC);
    RUN_TEST_FLAG(stdarg_diff_type, FLAG_PURE_FUNC);
}