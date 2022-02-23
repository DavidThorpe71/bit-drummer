/*
  BitDrumEncoder.h - Library for wrapping 
  encoders in the bit-drummer project, to
  help with testing. Created by David Thorpe 
  21st Feb 2022
*/
#ifndef BITDRUMENCODER_H
#define BITDRUMENCODER_H

#include <Encoder.h>

class BitDrumEncoder 
{
private:
  Encoder physicalEncoder;
public:
    BitDrumEncoder(Encoder physicalEncoder);
    void write(int value);
    int read();
    int encoderValue;

};
#endif
