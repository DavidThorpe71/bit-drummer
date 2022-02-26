#include <EncoderHandler.h>
#include <iostream>

class TempoEncoderHandler: EncoderHandler {

public:
  bool *metro;
  int encoderLastValue = 0;

  TempoEncoderHandler(
    BitDrumEncoderAbstract *encoderInstance, 
    Pattern pattern, 
    bool *metro,
    int encoderMax,
    bool *update)
  {
    physicalEncoder = encoderInstance;
    pattern = pattern;
    metro = metro;
    encoderMax = encoderMax;
    update = update;
  };

  void toggleMetroOnOff()
  {
    *metro = !metro;
  };

  int getPattern() 
  {
    return encoderLastValue;
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

    if (newEncoderValue != encoderLastValue)
    {
      encoderLastValue = newEncoderValue;
    }
  };

  void handleButtonPress() {
    if (physicalEncoder->buttonUpdate())
    {
      setUpdate(true);
      if (physicalEncoder->buttonRead() == 1)
      {
        toggleMetroOnOff();
      }
    }
  };
};