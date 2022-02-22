#include <unity.h>
#include "../tests/Pattern/test_pattern.cpp"
#include "../tests/EncoderHandler/test_EncoderHandler.cpp"

int main(int argc, char **argv) {
    UNITY_BEGIN();
    patternTests();
    encoderHandlerTests();
    UNITY_END();

    return 0;
}