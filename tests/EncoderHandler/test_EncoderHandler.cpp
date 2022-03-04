#include <unity.h>
#include <EncoderHandler.h>
#include <PatternEncoderHandler.cpp>
#include <BitDrumEncoderAbstract.h>
#include <BitDrumPattern.h>
#include <../lib/bitDrumEncoder/MockBitDrumEncoder.cpp>

BitDrumEncoderAbstract* mockBitDrumEncoder = new MockBitDrumEncoder();
BitDrumPattern mockPattern;
bool update = false;
int mode = 0;
PatternEncoderHandler* sut = new PatternEncoderHandler(mockBitDrumEncoder, mockPattern, 127, &update, &mode);

void test_function_change_mode(void) {
    TEST_ASSERT_EQUAL(0, sut->mode);
    sut->changeMode();
    TEST_ASSERT_EQUAL(1,sut->mode);
    sut->changeMode();
    TEST_ASSERT_EQUAL(2,sut->mode);
    sut->changeMode();
    TEST_ASSERT_EQUAL(0,sut->mode);
}

void test_method_set_update(void) {
    TEST_ASSERT_EQUAL(false, update);
    sut->setUpdate(true);
    TEST_ASSERT_EQUAL(true, update);
    sut->setUpdate(false);
    TEST_ASSERT_EQUAL(false, update);
}

void test_method_get_pattern(void) {
    TEST_ASSERT_EQUAL(0, sut->getPattern());
}

void test_method_handle_encoder_change(void) {
    mode = 0;
    mockBitDrumEncoder->write(0);
    TEST_ASSERT_EQUAL(0, sut->getPattern());
    mockBitDrumEncoder->write(1);
    sut->handleEncoderTurn();
    TEST_ASSERT_EQUAL(1, sut->getPattern());
}

void test_method_handle_button_press(void) {
    TEST_ASSERT_EQUAL(0, sut->mode);
    TEST_ASSERT_EQUAL(false, update);
    TEST_ASSERT_EQUAL(0, mockBitDrumEncoder->buttonRead());
    sut->handleButtonPress();
    TEST_ASSERT_EQUAL(true, update);
    TEST_ASSERT_EQUAL(1, mockBitDrumEncoder->buttonRead());
    TEST_ASSERT_EQUAL(1, sut->mode);
}

void test_mode_change(void) {
    mode = 0;
    mockBitDrumEncoder->write(0);
    sut->handleEncoderTurn();
    TEST_ASSERT_EQUAL(0, sut->getPattern());
    mockBitDrumEncoder->write(5);
    sut->handleEncoderTurn();
    TEST_ASSERT_EQUAL(17, sut->getPattern());
    TEST_ASSERT_EQUAL(5, sut->getEncoderModeValue());
    mode = 3;
    mockBitDrumEncoder->write(16);
    sut->handleEncoderTurn();
    TEST_ASSERT_EQUAL(17, sut->getPattern());
    TEST_ASSERT_EQUAL(16, sut->getEncoderModeValue());
}

int encoderHandlerTests() {
    // RUN_TEST(test_function_change_mode);
    RUN_TEST(test_method_get_pattern);
    RUN_TEST(test_method_set_update);
    RUN_TEST(test_method_handle_encoder_change);
    // RUN_TEST(test_method_handle_button_press);
    RUN_TEST(test_mode_change);

    return 0;
}