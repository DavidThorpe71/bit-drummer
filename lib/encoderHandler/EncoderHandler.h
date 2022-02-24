/*
  EncoderHandler.h - Library for handling 
  encoders in the bit-drummer project.
  Created by David Thorpe 21st Feb 2022
*/
#ifndef ENCODERHANDLER_H
#define ENCODERHANDLER_H

#include <BitDrumEncoder.h>
#include <Pattern.h>

class EncoderHandler
{
public:
  BitDrumEncoder *physicalEncoder;
  Pattern pattern;
  int mode;
  int mode0LastValue;
  int mode1LastValue;

  EncoderHandler(
    BitDrumEncoder *encoderInstance,
    Pattern pattern,
    int mode, 
    int mode0lv, 
    int mode1lv);

  void ChangeMode();
  int getPattern();
  void handleChange();
};
#endif
