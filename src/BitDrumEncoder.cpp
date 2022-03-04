#include <../lib/bitDrumEncoder/BitDrumEncoderAbstract.h>
#include <Encoder.h>
#include <Bounce.h>

class BitDrumEncoder: public BitDrumEncoderAbstract
{
private:
    Encoder *encoder;
    Bounce *button;
public:
    BitDrumEncoder(Encoder *inEncoder, Bounce *inButton) {
        encoder = inEncoder;
        button = inButton;
    }

    int read() {
        return encoder->read() / 4;
    }

    void write(int value) {
        encoder->write(value * 4);
    }

    int buttonUpdate() {
       return button->update();
    }

    int buttonRead() {
        return button->read();
    }
};
