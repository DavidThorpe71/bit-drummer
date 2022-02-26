#include <EncoderHandler.h>
#include <iostream>

class PatternEncoderHandler: EncoderHandler {

public:
  int mode = 0;
  int mode0LastValue = 0;
  int mode1LastValue = 0;

  PatternEncoderHandler(
    BitDrumEncoderAbstract *encoderInstance, 
    Pattern pattern,
    int encoderMax,
    bool *update) 
  {
    physicalEncoder = encoderInstance;
    pattern = pattern;
    encoderMax = encoderMax;
    update = update;
  };

  void changeMode() {
    if (mode == 0)
    {
      mode = 1;
      physicalEncoder->write(mode1LastValue);
    }
    else
    {
      mode = 0;
      physicalEncoder->write(mode0LastValue);
    }
  };

  int getPattern() 
  {
    if (mode0LastValue == 0) {
      return 0;
    }
    return pattern.rightRotate(mode0LastValue, mode1LastValue);
  };

  void setUpdate(bool updateValue)
  {
    *update = updateValue;
  };

  void handleEncoderTurn()
  {
    int newEncoderValue = physicalEncoder->read();

    if (newEncoderValue > encoderMax)
    {
        newEncoderValue = encoderMax;
        physicalEncoder->write(newEncoderValue * 4);
    }

    if (newEncoderValue < 0)
    {
        newEncoderValue = 0;
        physicalEncoder->write(newEncoderValue);
    }

    if (mode == 0) {
      if (newEncoderValue != mode0LastValue)
      {
        mode0LastValue = newEncoderValue;
      }
    }

    if (mode == 1) {
      if (newEncoderValue != mode1LastValue)
      {
        mode1LastValue = newEncoderValue;
      }
    }
  };

  void handleButtonPress() {
    if (physicalEncoder->buttonUpdate())
    {
      setUpdate(true);
      if (physicalEncoder->buttonRead() == 1)
      {
        changeMode();
      }
    }
  };
};