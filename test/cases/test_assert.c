#include <utest.h>

#include <assert.h>

TEST_CASE(assert){
    assert(10 == 10);
    assert(20 == 20);
    assert((10 + 30) == (30 + 10));
    static_assert(sizeof(int) == 4, "check int size");
#define NDEBUG
#include <assert.h>
// The error here should be ignored
    assert(30 == 40);
    assert(0.8 == 0.99);
#undef NDEBUG
}