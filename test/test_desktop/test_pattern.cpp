#include <unity.h>
#include <Pattern.h>

Pattern pattern;

void test_function_calculator_addition(void) {
    TEST_ASSERT_EQUAL(32, pattern.add(25, 7));
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_function_calculator_addition);
    UNITY_END();

    return 0;
}