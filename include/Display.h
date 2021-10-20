/*
  Display.h - Library for handling OLED
  display in the bit-drummer projrvy.
  Created by David Thorpe 17th October 2021
*/
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Display
{
private:
  void init();

public:
  Display()
  {
    init();
  }
  void startup();
  void displayEncoders(
      int mode,
      bool metroOnOff,
      int metroEncoder,
      int encoder1Value,
      int encoder2Value,
      int encoder3Value,
      int encoder4Value,
      int encoder5Value,
      int encoder6Value);
};
#endif
