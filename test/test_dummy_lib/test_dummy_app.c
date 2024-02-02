#include <unity.h>

#include "dummy_lib.h"



void test_add_dummy_values(void) {
    TEST_ASSERT_EQUAL_UINT8(40, add(40, 0));
    TEST_ASSERT_EQUAL_UINT8(40, add(0, 40));
    TEST_ASSERT_EQUAL_UINT8(40, add(20, 20));
}


void test_add_overflow_values(void) {
    TEST_ASSERT_EQUAL_UINT8(0, add(128, 128));
    TEST_ASSERT_EQUAL_UINT8(0, add(255, 1));
    TEST_ASSERT_EQUAL_UINT8(9, add(255, 10));
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add_dummy_values);
    RUN_TEST(test_add_overflow_values);

    return UNITY_END();
}
