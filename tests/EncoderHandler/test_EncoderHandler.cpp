#include <unity.h>
#include <EncoderHandler.h>
#include <BitDrumEncoder.h>
#include <Pattern.h>
#include <../lib/bitDrumEncoder/MockBitDrumEncoder.cpp>

BitDrumEncoder* mockBitDrumEncoder = new MockBitDrumEncoder();
Pattern mockPattern;
EncoderHandler* myEnc = new EncoderHandler(mockBitDrumEncoder, mockPattern, 0, 0, 0);

void test_function_change_mode(void) {
    TEST_ASSERT_EQUAL(0, myEnc->mode);
    myEnc->ChangeMode();
    TEST_ASSERT_EQUAL(1,myEnc->mode);
    myEnc->ChangeMode();
    TEST_ASSERT_EQUAL(0,myEnc->mode);
}

void test_method_get_pattern(void) {
    TEST_ASSERT_EQUAL(0, myEnc->getPattern());
}

int encoderHandlerTests() {
    RUN_TEST(test_function_change_mode);
    RUN_TEST(test_method_get_pattern);

    return 0;
}