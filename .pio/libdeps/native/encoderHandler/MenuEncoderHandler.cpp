#include <EncoderHandler.h>
#include <iostream>

class MenuEncoderHandler: EncoderHandler {

public:
  int *mode;

  MenuEncoderHandler(
    BitDrumEncoderAbstract *encoderInstance, 
    BitDrumPattern inPattern,
    int *inMode,
    int inEncoderMax,
    bool *inUpdate) 
  {
    physicalEncoder = encoderInstance;
    pattern = inPattern;
    mode = inMode;
    encoderMax = inEncoderMax;
    update = inUpdate;
  };

  int getPattern() 
  {
    return *mode;
  };

  void setUpdate(bool updateValue)
  {
    *update = updateValue;
  };

  void handleEncoderTurn()
  {
    int newEncoderValue = physicalEncoder->read();

    if (newEncoderValue > encoderMax - 1)
    {
      newEncoderValue = encoderMax;
      physicalEncoder->write(newEncoderValue * 4);
    }

    if (newEncoderValue < 0)
    {
      newEncoderValue = 0;
      physicalEncoder->write(newEncoderValue);
    }

    if (newEncoderValue != *mode)
    {
      setUpdate(true);
      *mode = newEncoderValue;
    }
  };

  void handleButtonPress() {
    if (physicalEncoder->buttonUpdate())
    {
      setUpdate(true);
      if (physicalEncoder->buttonRead() == 1)
      {
        
      }
    }
  };
};