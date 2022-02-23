#include <BitDrumEncoder.h>

BitDrumEncoder::BitDrumEncoder(Encoder physicalEncoder) {
    physicalEncoder = physicalEncoder
}

int BitDrumEncoder::read() {
    return physicalEncoder->read();
}

void BitDrumEncoder::write(int encoderValue) {
    physicalEncoder->write(encoderValue);
}