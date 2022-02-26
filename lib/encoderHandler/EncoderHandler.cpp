#include <EncoderHandler.h>
#include <iostream>

EncoderHandler::EncoderHandler(
  BitDrumEncoderAbstract *encoderInstance, 
  Pattern pattern, 
  int m,
  int mode0lv,
  int mode1lv,
  bool *update,
  int encoderMax)
{
    physicalEncoder = encoderInstance;
    pattern = pattern;
    mode = m;
    mode0LastValue = mode0lv;
    mode1LastValue = mode1lv;
    update = update;
    encoderMax = encoderMax;
};

void EncoderHandler::changeMode()
{
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

int EncoderHandler::getPattern() 
{
  if (mode0LastValue == 0) {
    return 0;
  }
  return pattern.rightRotate(mode0LastValue, mode1LastValue);
};

void EncoderHandler::setUpdate(bool updateValue)
{
  update = updateValue;
};

void EncoderHandler::handleEncoderTurn()
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

void EncoderHandler::handleButtonPress() {
  if (physicalEncoder->buttonUpdate())
  {
    setUpdate(true);
    if (physicalEncoder->buttonRead() == 1)
    {
      changeMode();
    }
  }
}