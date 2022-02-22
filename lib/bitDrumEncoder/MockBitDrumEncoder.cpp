#include <BitDrumEncoder.h>

class MockBitDrumEncoder: public BitDrumEncoder 
{
    void write(int value) {
        encoderValue = value;
    };
    int read() {
        return encoderValue;
    };
};