#include <EncoderHandler.h>

EncoderHandler::EncoderHandler(BitDrumEncoder *encoderInstance, Pattern pattern, int m, int mode0lv, int mode1lv)
{
    physicalEncoder = encoderInstance;
    pattern = pattern;
    mode = m;
    mode0LastValue = mode0lv;
    mode1LastValue = mode1lv;

};

void EncoderHandler::ChangeMode()
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
}