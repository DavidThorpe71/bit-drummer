#include <unity.h>
#include <EncoderHandler.h>
#include <BitDrumEncoder.h>
#include <../lib/bitDrumEncoder/MockBitDrumEncoder.cpp>

BitDrumEncoder* mockBitDrumEncoder = new MockBitDrumEncoder();

EncoderHandler* myEnc = new EncoderHandler(mockBitDrumEncoder, 0, 0, 0);

void test_function_change_mode(void) {
    TEST_ASSERT_EQUAL(0, myEnc->mode);
    myEnc->ChangeMode();
    TEST_ASSERT_EQUAL(1,myEnc->mode);
    myEnc->ChangeMode();
    TEST_ASSERT_EQUAL(0,myEnc->mode);
}

int encoderHandlerTests() {
    RUN_TEST(test_function_change_mode);

    return 0;
}