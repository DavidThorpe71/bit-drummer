#include <Display.h>
#include <cmath>

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 32    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void testdrawchar();
void setModeText(int mode, String &modeText);
void setOnOffText(int metroOnOff, String &onOffText);
String createAlignedEncoder(int encoderValue);

void Display::init()
{
  Serial.println(F("is this called?"));

  if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
}

void Display::startup()
{
  init();

  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;
  String text = "Bit Drummer v0.1";
  oled.setTextSize(1);
  oled.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);

  oled.clearDisplay();

  oled.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);

  oled.setTextColor(SSD1306_WHITE); // Draw white text
  oled.println(text);
  oled.display();

  delay(2000);
}

int digits;

void Display::displayEncoders(
    int mode,
    bool metroOnOff,
    int encoderValue1,
    int encoderValue2,
    int encoderValue3,
    int encoderValue4,
    int encoderValue5,
    int encoderValue6,
    int encoderValue7,
    int encoderValue8)
{
  oled.clearDisplay();

  oled.setTextSize(1);              // Normal 1:1 pixel scale
  oled.setTextColor(SSD1306_WHITE); // Draw white text
  oled.setCursor(0, 0);

  String modeText;
  String onOffText;

  setModeText(mode, modeText);
  setOnOffText(metroOnOff, onOffText);

  oled.print(modeText);
  oled.setCursor(78, 0);
  oled.print(encoderValue8);
  oled.print("ms");
  oled.print("  ");
  oled.print(onOffText);

  oled.setCursor(2, 12);
  oled.print(encoderValue1);

  oled.setCursor(44, 12);
  oled.print(encoderValue2);

  oled.setCursor(86, 12);
  oled.println(encoderValue3);

  oled.setCursor(2, 24);
  oled.print(encoderValue4);

  oled.setCursor(44, 24);
  oled.print(encoderValue5);

  oled.setCursor(86, 24);
  oled.print(encoderValue6);
  oled.display();
}

void setModeText(int mode, String &modeText)
{
  if (mode == 0)
  {
    modeText = "SynthDrum";
  }
  else if (mode == 1)
  {
    modeText = "Strings";
  }
  else
  {
    modeText = "DrumSamps";
  }
}

void setOnOffText(int metroOnOff, String &onOffText)
{
  if (metroOnOff == 1)
  {
    oled.fillCircle(120, 3, 2, SSD1306_WHITE);
  }
}