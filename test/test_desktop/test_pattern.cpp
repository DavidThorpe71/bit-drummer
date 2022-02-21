#include <unity.h>
#include <Pattern.h>

Pattern pattern;

int getBit(int byte, int position) {
   return (byte >> position) & 0x1;
}

void test_function_calculator_addition(void) {
    TEST_ASSERT_EQUAL(32, pattern.add(25, 7));
}

void test_pattern_no_rotate(void) {
    int rotatedPattern = pattern.get(4, 0);
    TEST_ASSERT_EQUAL(1, getBit(rotatedPattern, 0));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 1));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 2));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 3));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 4));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 5));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 6));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 7));
}
void test_pattern_one_rotate(void) {
    int rotatedPattern = pattern.get(4, 4);
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 0));
    TEST_ASSERT_EQUAL(1, getBit(rotatedPattern, 1));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 2));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 3));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 4));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 5));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 6));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 7));
}

void test_pattern_eight_rotate(void) {
    int rotatedPattern = pattern.get(4, 32);
    TEST_ASSERT_EQUAL(1, getBit(rotatedPattern, 0));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 1));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 2));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 3));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 4));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 5));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 6));
    TEST_ASSERT_EQUAL(0, getBit(rotatedPattern, 7));
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_function_calculator_addition);
    RUN_TEST(test_pattern_no_rotate);
    RUN_TEST(test_pattern_one_rotate);
    RUN_TEST(test_pattern_eight_rotate);
    UNITY_END();

    return 0;
}