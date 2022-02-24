/*
  BitDrumEncoder.h - Library for wrapping 
  encoders in the bit-drummer project, to
  help with testing. Created by David Thorpe 
  21st Feb 2022
*/
#ifndef BITDRUMENCODER_H
#define BITDRUMENCODER_H



class BitDrumEncoder
{
public:
    BitDrumEncoder();
    virtual void write(int value);
    virtual int read();
    int encoderValue;

};
#endif
