/*
  BitDrumEncoderAbstract.h - Library for wrapping 
  encoders in the bit-drummer project, to
  help with testing. Created by David Thorpe 
  21st Feb 2022
*/
#ifndef BITDRUMENCODERABSTRACT_H
#define BITDRUMENCODERABSTRACT_H

class BitDrumEncoderAbstract 
{
  public:
    virtual void write(int value) = 0;
    virtual int read() = 0;
    virtual int buttonUpdate() = 0;
    virtual int buttonRead() = 0;
};

#endif
