// Test IO Operation in unistd
#include "../../test.h"
#include <unistd.h>

#define BUFFER_SIZE_S       64
#define BUFFER_SIZE_M       128
#define BUFFER_SIZE_L       256
#define BUFFER_SIZE_1K      1024
#define BUFFER_SIZE_2K      2048

SUB_TEST_CASE(unistd_write){
#if (TEST_INTERACTIVE == 1)
BEGIN_DECL
    const char buffer[] = "Hello QLibc System call !\n";
    ssize_t return_val =  write(STDOUT_FILENO, buffer, sizeof(buffer) - 1);
    EXPECT_EQ((size_t)return_val, sizeof(buffer) - 1);
END_DECL
#endif
}
SUB_TEST_CASE(unistd_read){
#if (TEST_INTERACTIVE == 1)
BEGIN_DECL
    char buffer[BUFFER_SIZE_S];
    ssize_t return_val = read(STDIN_FILENO, buffer, 4);
    EXPECT_EQ((size_t)return_val, 4);
END_DECL
#endif
}