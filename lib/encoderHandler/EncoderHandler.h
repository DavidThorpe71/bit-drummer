/*
  EncoderHandler.h - Library for handling 
  encoders in the bit-drummer project.
  Created by David Thorpe 21st Feb 2022
*/
#ifndef ENCODERHANDLER_H
#define ENCODERHANDLER_H

#include <BitDrumEncoderAbstract.h>
#include <Pattern.h>

class EncoderHandler
{
public:
  BitDrumEncoderAbstract *physicalEncoder;
  Pattern pattern;
  bool *update;
  int encoderMax;

  virtual int getPattern() = 0;
  virtual void handleEncoderTurn() = 0;
  virtual void handleButtonPress() = 0;
  virtual void setUpdate(bool update) = 0;
};
#endif
