#include <EncoderHandler.h>
#include <iostream>

class MenuEncoderHandler: EncoderHandler {

public:
  int *mode;

  MenuEncoderHandler(
    BitDrumEncoderAbstract *encoderInstance, 
    Pattern pattern,
    int *mode,
    int encoderMax,
    bool *update) 
  {
    physicalEncoder = encoderInstance;
    pattern = pattern;
    mode = mode;
    encoderMax = encoderMax;
    update = update;
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

    if (newEncoderValue != *mode)
    {
      *mode = newEncoderValue;
    }
  };

  void handleButtonPress() {
    if (physicalEncoder->buttonUpdate())
    {
      setUpdate(true);
      if (physicalEncoder->buttonRead() == 1)
      {
        std::cout << "nothing happens when you press this button\n";
      }
    }
  };
};