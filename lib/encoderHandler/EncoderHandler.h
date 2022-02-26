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
  int mode;
  int mode0LastValue;
  int mode1LastValue;
  bool *update;
  int encoderMax;

  EncoderHandler(
    BitDrumEncoderAbstract *encoderInstance,
    Pattern pattern,
    int mode, 
    int mode0lv, 
    int mode1lv,
    bool *update,
    int encoderMax);

  void changeMode();
  int getPattern();
  void handleEncoderTurn();
  void handleButtonPress();
  void setUpdate(bool update);
};
#endif
