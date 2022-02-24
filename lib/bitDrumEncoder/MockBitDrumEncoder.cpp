#include <BitDrumEncoder.h>

class MockBitDrumEncoder: public BitDrumEncoderAbstract 
{
private:
    int encoderValue;
public:
    MockBitDrumEncoder() {}
    void write(int value) {
        encoderValue = value;
    };
    int read() {
        return encoderValue;
    };
};