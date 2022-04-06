#include <EncoderHandler.h>
#include <iostream>
#include <cstdlib>

class PatternEncoderHandler: EncoderHandler {

public:
  int *mode;
  int encoderMax;
  int valueArraySize;
  int valueArray[9];
  int loopLength;

  PatternEncoderHandler(
    BitDrumEncoderAbstract *encoderInstance, 
    BitDrumPattern patternPkg,
    int maxValue,
    bool *shouldUpdate,
    int *inputMode) 
  {
    physicalEncoder = encoderInstance;
    pattern = patternPkg;
    encoderMax = maxValue;
    update = shouldUpdate;
    loopLength = 8;
    mode = inputMode;
    valueArraySize = sizeof(valueArray)/sizeof(valueArray[0]);
   
    initialiseEncoderValues();

  };

  void initialiseEncoderValues() {
    // pattern 0 - 127
    valueArray[0] = 0;

    // pattern rotation 0 - 8
    valueArray[1] = 0;
    
    // pattern length 1 - 127
    valueArray[2] = 8;
    
    // instrument 1 setting 1 - 127
    valueArray[3] = 0;

    // instrument 2 setting 1 - 127
    valueArray[4] = 0;

    // instrument 3 setting 1 - 127
    valueArray[5] = 0;

    // instrument 4 setting 1 - 127
    valueArray[6] = 0;

    // instrument 5 setting 1 - 127
    valueArray[7] = 0;

    // instrument 6 setting 1 - 127
    valueArray[7] = 0;
  }

  void changeMode() {
    physicalEncoder->write(valueArray[*mode]);
  };

  int getPattern() 
  {
    return pattern.rightRotate(valueArray[0], valueArray[1]);
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

    if (newEncoderValue != valueArray[*mode])
    {
      setUpdate(true);
      valueArray[*mode] = newEncoderValue;
    }
  };

  void handleButtonPress() {
    if (physicalEncoder->buttonUpdate())
    {
      setUpdate(true);
      if (physicalEncoder->buttonRead() == 1)
      {
        valueArray[0] = rand() % 127;
        if (*mode == 0) {
          physicalEncoder->write(valueArray[0]);
          // handleEncoderTurn();
        }
      }
    }
  };

  int getLoopLength() {
    return valueArray[2];
  }

  int getEncoderModeValue() {
    return valueArray[*mode];
  }
};