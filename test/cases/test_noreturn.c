#include "../test.h"
#include <stdnoreturn.h>
#include <stdlib.h>

// Ensure the declaration is valid !
noreturn void noreturn_func() { exit(1); }
TEST_CASE(stdnoreturn){
    /// Nothing todo here just test that the define of the function
}