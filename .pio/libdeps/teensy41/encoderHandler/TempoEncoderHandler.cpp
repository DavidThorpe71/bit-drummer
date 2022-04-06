#include <EncoderHandler.h>
#include <iostream>

class TempoEncoderHandler: EncoderHandler {

public:
  bool *metro;
  int encoderLastValue = 0;

  TempoEncoderHandler(
    BitDrumEncoderAbstract *encoderInstance, 
    BitDrumPattern inPattern, 
    bool *inMetro,
    int inEncoderMax,
    bool *inUpdate)
  {
    physicalEncoder = encoderInstance;
    pattern = inPattern;
    metro = inMetro;
    encoderMax = inEncoderMax;
    update = inUpdate;
  };

  void toggleMetroOnOff()
  {
    *metro = !*metro;
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
      setUpdate(true);
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