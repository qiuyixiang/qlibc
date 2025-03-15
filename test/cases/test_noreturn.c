#include <utest.h>
#include <stdnoreturn.h>
#include <stdlib.h>

// Ensure the declaration is valid !
noreturn void noreturn_func() { exit(1); }
TEST_CASE(stdnoreturn){
    /// Nothing to do here just test that the define of the function
}