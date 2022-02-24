#include <../lib/bitDrumEncoder/BitDrumEncoderAbstract.h>
#include <Encoder.h>

class BitDrumEncoder: public BitDrumEncoderAbstract
{
private:
    Encoder *encoder;
public:
    BitDrumEncoder(Encoder *encoder) {
        encoder = encoder;
    }

    int read() {
        return encoder->read() / 4;
    }

    void write(int value) {
        encoder->write(value * 4);
    }
};
