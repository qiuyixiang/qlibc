#include <utest.h>
#include <ctype.h>

#define TRUE    1
#define FALSE   0
#define CHECK_CHAR_RANGE(START, END, FUNC, COND)            \
        for (unsigned CHAR = START; CHAR <= END; ++CHAR){   \
            if (COND)                                       \
                EXPECT_TRUE(FUNC(CHAR));                    \
            else                                            \
                EXPECT_FALSE(FUNC(CHAR));                   \
        }
           
SUB_TEST_CASE(iscntrl){
    CHECK_CHAR_RANGE(0x00, 0x1f, iscntrl, TRUE);
    CHECK_CHAR_RANGE(0x20, 0x7e, iscntrl, FALSE);
    EXPECT_TRUE(iscntrl(0x7f));
}
SUB_TEST_CASE(isprint){
    CHECK_CHAR_RANGE(0x00, 0x1f, isprint, FALSE);
    CHECK_CHAR_RANGE(0x20, 0x7e, isprint, TRUE);
    EXPECT_FALSE(isprint(0x7f));
}
SUB_TEST_CASE(isspace){
    CHECK_CHAR_RANGE(0x00, 0x08, isspace, FALSE);
    CHECK_CHAR_RANGE(0x09, 0x0d, isspace, TRUE);
    CHECK_CHAR_RANGE(0x0e, 0x1f, isspace, FALSE);
    EXPECT_TRUE(isspace(0x20));
    CHECK_CHAR_RANGE(0x21, 0x7f, isspace, FALSE);
}
SUB_TEST_CASE(isblank){
    CHECK_CHAR_RANGE(0x00, 0x08, isblank, FALSE);
    EXPECT_TRUE(isblank(0x09));
    CHECK_CHAR_RANGE(0x0a, 0x1f, isblank, FALSE);
    EXPECT_TRUE(isblank(0x20));
    CHECK_CHAR_RANGE(0x21, 0x7f, isblank, FALSE);
}
SUB_TEST_CASE(isgraph){
    CHECK_CHAR_RANGE(0x00, 0x20, isgraph, FALSE);
    CHECK_CHAR_RANGE(0x21, 0x7e, isgraph, TRUE);
    EXPECT_FALSE(isgraph(0x7f));
}
SUB_TEST_CASE(ispunct){
    CHECK_CHAR_RANGE(0x00, 0x20, ispunct, FALSE);
    CHECK_CHAR_RANGE(0x21, 0x2f, ispunct, TRUE);
    CHECK_CHAR_RANGE(0x3a, 0x40, ispunct, TRUE);
    CHECK_CHAR_RANGE(0x5b, 0x60, ispunct, TRUE);
    CHECK_CHAR_RANGE(0x61, 0x7a, ispunct, FALSE);
}
SUB_TEST_CASE(isalnum){
    CHECK_CHAR_RANGE(0x00, 0x2f, isalnum, FALSE);
    CHECK_CHAR_RANGE(0x30, 0x39, isalnum, TRUE);
    CHECK_CHAR_RANGE(0x41, 0x5a, isalnum, TRUE);
    CHECK_CHAR_RANGE(0x5b, 0x60, isalnum, FALSE);
    CHECK_CHAR_RANGE(0x61, 0x7a, isalnum, TRUE);
}
SUB_TEST_CASE(isalpha){
    CHECK_CHAR_RANGE(0x00, 0x40, isalpha, FALSE);
    CHECK_CHAR_RANGE(0x41, 0x5a, isalpha, TRUE);
    CHECK_CHAR_RANGE(0x5b, 0x60, isalpha, FALSE);
    CHECK_CHAR_RANGE(0x61, 0x7a, isalpha, TRUE);
    CHECK_CHAR_RANGE(0x7b, 0x7f, isalpha, FALSE);
}
SUB_TEST_CASE(isupper){
    CHECK_CHAR_RANGE(0x00, 0x40, isupper, FALSE);
    CHECK_CHAR_RANGE(0x41, 0x5a, isupper, TRUE);
    CHECK_CHAR_RANGE(0x5b, 0x7f, isupper, FALSE);
}
SUB_TEST_CASE(islower){
    CHECK_CHAR_RANGE(0x00, 0x60, islower, FALSE);
    CHECK_CHAR_RANGE(0x61, 0x7a, islower, TRUE);
    CHECK_CHAR_RANGE(0x7b, 0x7f, islower, FALSE);
}
SUB_TEST_CASE(isdigit){
    CHECK_CHAR_RANGE(0x00, 0x2f, isdigit, FALSE);
    CHECK_CHAR_RANGE(0x30, 0x39, isdigit, TRUE);
    CHECK_CHAR_RANGE(0x3a, 0x7f, isdigit, FALSE);
}
SUB_TEST_CASE(isxdigit){
    CHECK_CHAR_RANGE(0x00, 0x2f, isxdigit, FALSE);
    CHECK_CHAR_RANGE(0x30, 0x39, isxdigit, TRUE);
    CHECK_CHAR_RANGE(0x3a, 0x40, isxdigit, FALSE);
    CHECK_CHAR_RANGE(0x41, 0x46, isxdigit, TRUE);
    CHECK_CHAR_RANGE(0x47, 0x60, isxdigit, FALSE);
    CHECK_CHAR_RANGE(0x61, 0x66, isxdigit, TRUE);
    CHECK_CHAR_RANGE(0x67, 0x7f, isxdigit, FALSE);
}
SUB_TEST_CASE(toupper){
    for (int CHAR = 0x00; CHAR <= 0x7f; ++CHAR){
        if (islower(CHAR))
            EXPECT_EQ(toupper(CHAR), CHAR - 0x20);
        else
            EXPECT_EQ(toupper(CHAR), CHAR);
    }   
}
SUB_TEST_CASE(tolower){
    for (int CHAR = 0x00; CHAR <= 0x7f; ++CHAR){
        if (isupper(CHAR))
            EXPECT_EQ(tolower(CHAR), CHAR + 0x20);
        else
            EXPECT_EQ(tolower(CHAR), CHAR);
    }   
}
TEST_CASE(ctype){
    RUN_SUB_TEST_CASE(iscntrl);
    RUN_SUB_TEST_CASE(isprint);
    RUN_SUB_TEST_CASE(isspace);
    RUN_SUB_TEST_CASE(isblank);
    RUN_SUB_TEST_CASE(isgraph);
    RUN_SUB_TEST_CASE(ispunct);
    RUN_SUB_TEST_CASE(isalnum);
    RUN_SUB_TEST_CASE(isalpha);
    RUN_SUB_TEST_CASE(isupper);
    RUN_SUB_TEST_CASE(islower);
    RUN_SUB_TEST_CASE(isdigit);
    RUN_SUB_TEST_CASE(isxdigit);
    RUN_SUB_TEST_CASE(toupper);
    RUN_SUB_TEST_CASE(tolower);
}