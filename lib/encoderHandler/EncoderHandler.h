/*
  EncoderHandler.h - Library for handling 
  encoders in the bit-drummer project.
  Created by David Thorpe 21st Feb 2022
*/
#ifndef ENCODERHANDLER_H
#define ENCODERHANDLER_H

#include <BitDrumEncoder.h>

class EncoderHandler
{
public:
  BitDrumEncoder *physicalEncoder;
  int mode;
  int mode0LastValue;
  int mode1LastValue;

  EncoderHandler(BitDrumEncoder *encoderInstance, int mode, int mode0lv, int mode1lv);

  void ChangeMode();
};
#endif
