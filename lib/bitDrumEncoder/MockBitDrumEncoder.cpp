#include <BitDrumEncoder.h>

class MockBitDrumEncoder: public BitDrumEncoderAbstract 
{
private:
    int encoderValue;
    int buttonValue;
public:
    MockBitDrumEncoder() {}
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