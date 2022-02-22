#include <EncoderHandler.h>

EncoderHandler::EncoderHandler(BitDrumEncoder *encoderInstance, int m, int mode0lv, int mode1lv)
{
    physicalEncoder = encoderInstance;
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
