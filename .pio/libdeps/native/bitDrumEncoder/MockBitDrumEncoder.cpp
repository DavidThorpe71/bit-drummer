#include <BitDrumEncoderAbstract.h>

class MockBitDrumEncoder: public BitDrumEncoderAbstract 
{
private:
    int encoderValue;
    int buttonValue;
public:
    MockBitDrumEncoder() {
        encoderValue = 0;
        buttonValue = 0;
    }
    void write(int value) {
        encoderValue = value;
    };
    int read() {
        return encoderValue;
    };
    int buttonUpdate() {
        buttonValue = 1;
        return 1;
    }
    int buttonRead() {
        return buttonValue;
    }
};