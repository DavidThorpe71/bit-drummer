#include <BitDrumEncoder.h>

class MockBitDrumEncoder: public BitDrumEncoder 
{
public:
    MockBitDrumEncoder() {}
    void write(int value) {
        encoderValue = value;
    };
    int read() {
        return encoderValue;
    };
};