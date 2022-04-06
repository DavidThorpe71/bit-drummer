#include <EncoderHandler.h>
#include <iostream>
#include <cstdlib>

class PatternEncoderHandler: EncoderHandler {

public:
  int *mode;
  int encoderMax;
  int valueArraySize;
  int *valueArray;
  int loopLength;

  PatternEncoderHandler(
    BitDrumEncoderAbstract *encoderInstance, 
    BitDrumPattern patternPkg,
    int maxValue,
    bool *shouldUpdate,
    int *inputMode,
    int inputValueArray[9]) 
  {
    physicalEncoder = encoderInstance;
    pattern = patternPkg;
    encoderMax = maxValue;
    update = shouldUpdate;
    loopLength = 8;
    mode = inputMode;
    valueArray = inputValueArray;
    valueArraySize = sizeof(valueArray)/sizeof(valueArray[0]);
  };

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

  int getModeValue(int mode) {
    return valueArray[mode];
  }

  void setModeValue(int mode, int value) {
    valueArray[mode] = value;
  }

  int getEncoderModeValue() {
    return valueArray[*mode];
  }
};