#include <Arduino.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Encoder.h>
#include <Chrono.h>
#include <Bounce.h>
#include <Display.h>

void HandleInputs(int &enc1, int &enc2);

void setupDrumSynth();
void setupStringSynth();
void setupSdPlayer();

void drumSynthHandling();
void stringSynthHandling();
void sdPlayerHandling();

Display display;

// GUItool: begin automatically generated code
AudioSynthKarplusStrong string2; // xy=79,676
AudioSynthKarplusStrong string1; // xy=80,633
AudioSynthKarplusStrong string3; // xy=81,721
AudioSynthKarplusStrong string4; // xy=82,768
AudioSynthKarplusStrong string5; // xy=82,811
AudioSynthSimpleDrum drum1;      // xy=86,333
AudioSynthKarplusStrong string6; // xy=84,859
AudioSynthSimpleDrum drum2;      // xy=86,380
AudioSynthSimpleDrum drum4;      // xy=87,474
AudioSynthSimpleDrum drum5;      // xy=87,521
AudioSynthSimpleDrum drum3;      // xy=88,425
AudioSynthSimpleDrum drum6;      // xy=89,566
AudioPlaySdWav playSdWav1;       // xy=99,60
AudioPlaySdWav playSdWav2;       // xy=99,101
AudioPlaySdWav playSdWav3;       // xy=101,145
AudioPlaySdWav playSdWav4;       // xy=101,191
AudioPlaySdWav playSdWav5;       // xy=101,232
AudioPlaySdWav playSdWav6;       // xy=103,276
AudioMixer4 mixer7;              // xy=248,655
AudioMixer4 mixer8;              // xy=249,796
AudioMixer4 mixer4;              // xy=255,369
AudioMixer4 mixer5;              // xy=256,510
AudioMixer4 mixer2;              // xy=265,261
AudioMixer4 mixer1;              // xy=266,72
AudioMixer4 mixer9;              // xy=384,719
AudioMixer4 mixer3;              // xy=406,155
AudioMixer4 mixer6;              // xy=410,435
AudioMixer4 mixer10;             // xy=586,432
AudioOutputI2S i2s1;             // xy=766,439
AudioConnection patchCord1(string2, 0, mixer7, 1);
AudioConnection patchCord2(string1, 0, mixer7, 0);
AudioConnection patchCord3(string3, 0, mixer7, 2);
AudioConnection patchCord4(string4, 0, mixer8, 0);
AudioConnection patchCord5(string5, 0, mixer8, 1);
AudioConnection patchCord6(drum1, 0, mixer4, 0);
AudioConnection patchCord7(string6, 0, mixer8, 2);
AudioConnection patchCord8(drum2, 0, mixer4, 1);
AudioConnection patchCord9(drum4, 0, mixer5, 0);
AudioConnection patchCord10(drum5, 0, mixer5, 1);
AudioConnection patchCord11(drum3, 0, mixer4, 2);
AudioConnection patchCord12(drum6, 0, mixer5, 2);
AudioConnection patchCord13(playSdWav1, 0, mixer1, 0);
AudioConnection patchCord14(playSdWav2, 0, mixer1, 1);
AudioConnection patchCord15(playSdWav3, 0, mixer1, 2);
AudioConnection patchCord16(playSdWav4, 0, mixer2, 0);
AudioConnection patchCord17(playSdWav5, 0, mixer2, 1);
AudioConnection patchCord18(playSdWav6, 0, mixer2, 2);
AudioConnection patchCord19(mixer7, 0, mixer9, 0);
AudioConnection patchCord20(mixer7, 0, mixer9, 1);
AudioConnection patchCord21(mixer8, 0, mixer9, 2);
AudioConnection patchCord22(mixer8, 0, mixer9, 3);
AudioConnection patchCord23(mixer4, 0, mixer6, 0);
AudioConnection patchCord24(mixer4, 0, mixer6, 1);
AudioConnection patchCord25(mixer5, 0, mixer6, 2);
AudioConnection patchCord26(mixer5, 0, mixer6, 3);
AudioConnection patchCord27(mixer2, 0, mixer3, 2);
AudioConnection patchCord28(mixer2, 0, mixer3, 3);
AudioConnection patchCord29(mixer1, 0, mixer3, 0);
AudioConnection patchCord30(mixer1, 0, mixer3, 1);
AudioConnection patchCord31(mixer9, 0, mixer10, 2);
AudioConnection patchCord32(mixer3, 0, mixer10, 0);
AudioConnection patchCord33(mixer6, 0, mixer10, 1);
AudioConnection patchCord34(mixer10, 0, i2s1, 0);
AudioConnection patchCord35(mixer10, 0, i2s1, 1);
AudioControlSGTL5000 audioShield; // xy=643,178
// GUItool: end automatically generated code

// Encoders pin setup
Encoder knobOne(0, 1);
Encoder knobTwo(2, 3);
// Encoder enc3(5, 6);
// Encoder enc4(7, 8);
// Encoder enc5(9, 10);
// Encoder enc6(11, 12);

#define BUTTON1 4
#define BUTTON2 5
//#define BUTTON3 14
//#define BUTTON4 15
//#define BUTTON5 16
//#define BUTTON6 17

Bounce bounce1 = Bounce(BUTTON1, 5);
Bounce bounce2 = Bounce(BUTTON2, 5);
// Bounce bounce3 = Bounce( BUTTON3, 5 );
// Bounce bounce4 = Bounce( BUTTON4, 5 );
// Bounce bounce5 = Bounce( BUTTON5, 5 );
// Bounce bounce6 = Bounce( BUTTON6, 5 );

#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 7
#define SDCARD_SCK_PIN 14

boolean metroOn = false;

Chrono metro;

// #define SDCARD_CS_PIN BUILTIN_SDCARD

#define NOTE_F2 87.31
#define NOTE_A2 110.00
#define NOTE_C3 130.81
#define NOTE_F3 174.61
#define NOTE_A3 220.00
#define NOTE_C4 261.63

void setup()
{
  Serial.begin(9600);
  Serial.println("David bit drum machine");

  display.startup();

  pinMode(BUTTON1, INPUT);

  AudioMemory(12);

  // turn on the output
  audioShield.enable();
  audioShield.volume(0.5);

  setupDrumSynth();
  setupStringSynth();
  setupSdPlayer();

  knobTwo.write(600);
}

int positionOne = -999;
int positionTwo = -999;
// int initialEncVal3 = -999;
// int initialEncVal4 = -999;
// int initialEncVal5 = -999;
// int initialEncVal6 = -999;

int counter = 0;

// int mockBd = 199;
int mockSn = 65;
int mockHh = 200;
int mockBdFill = 10;
int mockSnFill = 4;
int mockHhFill = 67;

int enc1Value;
int enc2Value;
// int hhEncValue;
// int bdFillEncValue;
// int snFillEncValue;
// int hhFillEncValue;

int mode = 0;
int origTest = 0;

void loop()
{

  int test = AudioMemoryUsageMax();
  if (test > origTest)
  {
    Serial.println(test);
    origTest = test;
  }

  HandleInputs(enc1Value, enc2Value);

  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available())
  {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    knobOne.write(0);
    knobTwo.write(0);
  }
}

void HandleInputs(int &enc1, int &enc2)
{
  bool update = false;
  int newOne, newTwo;
  //  int newOne, newTwo, newThree, newFour, newFive, newSix;

  newOne = knobOne.read();
  newTwo = knobTwo.read();
  //  newThree = enc3.read();
  //  newFour = enc4.read();
  //  newFive = enc5.read();
  //  newSix = enc6.read();

  if (newOne >= 1020)
  {
    knobOne.write(1020);
  }

  if (newOne <= 0)
  {
    knobOne.write(0);
  }

  if (newOne != positionOne || newTwo != positionTwo)
  {
    enc1 = newOne / 4;
    enc2 = newTwo / 4;

    update = true;
    Serial.print("1: ");
    Serial.print(enc1);
    Serial.print(", 2: ");
    Serial.print(enc2);
    Serial.println();

    positionOne = newOne;
    positionTwo = newTwo;
  }

  if (bounce1.update())
  {
    update = true;
    if (bounce1.read() == HIGH)
    {
      if (!metroOn)
      {
        metroOn = true;
      }
      else
      {
        metroOn = false;
      }
    }
  }

  if (bounce2.update())
  {
    update = true;
    if (bounce2.read() == HIGH)
    {
      if (mode < 2)
      {
        mode++;
      }
      else
      {
        mode = 0;
      }
    }
  }

  if (metroOn)
  {
    if (metro.hasPassed(enc2Value))
    {
      metro.restart(); // Restart the chronometer.

      if (counter == 7)
      {
        counter = 0;
      }
      else
      {
        counter++;
      }

      if (mode == 0)
      {
        drumSynthHandling();
      }

      if (mode == 1)
      {
        stringSynthHandling();
      }

      if (mode == 2)
      {
        sdPlayerHandling();
      }
    }
  }

  if (update)
  {
    display.displayEncoders(mode, metroOn, enc2, enc1, 127, 201, 165, 255, 187);
  }
}

void setupDrumSynth()
{
  drum1.frequency(150);
  drum1.length(150);

  drum4.frequency(150);
  drum4.length(150);

  drum2.frequency(330);
  drum2.length(75);
  drum2.pitchMod(0.55);

  drum5.frequency(330);
  drum5.length(75);
  drum5.pitchMod(0.55);

  drum3.frequency(600);
  drum3.length(100);

  drum6.frequency(600);
  drum6.length(100);

  mixer9.gain(3, 0.4);
  mixer9.gain(4, 0.4);
}

void drumSynthHandling()
{
  //  int bdFill = bdFillEncValue ^ (enc1Value & bdFillEncValue);
  //  int snFill = snFillEncValue ^ (enc2Value & snFillEncValue);
  //  int hhFill = hhFillEncValue ^ (hhEncValue & hhFillEncValue);

  int bdFill = mockBdFill ^ (enc1Value & mockBdFill);
  int snFill = mockSnFill ^ (mockSn & mockSnFill);
  int hhFill = mockHhFill ^ (mockHh & mockHhFill);

  // Bass drums
  if (bitRead(enc1Value, counter) == 1)
  {
    drum1.noteOn();
  }

  if (bitRead(bdFill, counter) == 1)
  {
    drum4.noteOn();
  }

  // Snares
  if (bitRead(mockSn, counter) == 1)
  {
    drum2.noteOn();
  }

  if (bitRead(snFill, counter) == 1)
  {
    drum5.noteOn();
  }

  // HiHats
  if (bitRead(mockHh, counter) == 1)
  {
    drum3.noteOn();
  }

  if (bitRead(hhFill, counter) == 1)
  {
    drum6.noteOn();
  }
}

void setupStringSynth()
{
}

void stringSynthHandling()
{
  //  int bdFill = bdFillEncValue ^ (enc1Value & bdFillEncValue);
  //  int snFill = snFillEncValue ^ (enc2Value & snFillEncValue);
  //  int hhFill = hhFillEncValue ^ (hhEncValue & hhFillEncValue);

  int bdFill = mockBdFill ^ (enc1Value & mockBdFill);
  int snFill = mockSnFill ^ (mockSn & mockSnFill);
  int hhFill = mockHhFill ^ (mockHh & mockHhFill);

  // Bass drums
  if (bitRead(enc1Value, counter) == 1)
  {
    string1.noteOn(NOTE_F2, 0.65);
  }

  if (bitRead(bdFill, counter) == 1)
  {
    string4.noteOn(NOTE_F3, 0.2);
  }

  // Snares
  if (bitRead(mockSn, counter) == 1)
  {
    string1.noteOn(NOTE_A2, 0.65);
  }

  if (bitRead(snFill, counter) == 1)
  {
    string1.noteOn(NOTE_A3, 0.3);
  }

  // HiHats
  if (bitRead(mockHh, counter) == 1)
  {
    string1.noteOn(NOTE_C3, 0.65);
  }

  if (bitRead(hhFill, counter) == 1)
  {
    string1.noteOn(NOTE_C4, 0.3);
  }
}

void setupSdPlayer()
{

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN)))
  {
    while (1)
    {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  mixer1.gain(0, 0.6);
  mixer1.gain(1, 0.6);
  mixer1.gain(2, 0.6);
  mixer1.gain(3, 0.6);

  mixer2.gain(0, 0.6);
  mixer2.gain(1, 0.6);
  mixer2.gain(2, 0.6);
  mixer2.gain(3, 0.6);

  mixer3.gain(2, 0.6);
  mixer3.gain(3, 0.4);
}

const char *filelist[6] = {"BD1.WAV", "SN1.WAV", "HH1.WAV", "BD2.WAV", "SNR2.WAV", "HH2.WAV"};

void sdPlayerHandling()
{

  //  int bdFill = bdFillEncValue ^ (enc1Value & bdFillEncValue);
  //  int snFill = snFillEncValue ^ (enc2Value & snFillEncValue);
  //  int hhFill = hhFillEncValue ^ (hhEncValue & hhFillEncValue);

  int bdFill = mockBdFill ^ (enc1Value & mockBdFill);
  int snFill = mockSnFill ^ (mockSn & mockSnFill);
  int hhFill = mockHhFill ^ (mockHh & mockHhFill);

  // Bass drums
  if (bitRead(enc1Value, counter) == 1)
  {
    playSdWav1.play(filelist[0]);
  }

  // if (bitRead(bdFill, counter) == 1)
  // {
  //   playSdWav4.play(filelist[3]);
  // }

  // Snares
  if (bitRead(mockSn, counter) == 1)
  {
    playSdWav2.play(filelist[1]);
  }

  // if (bitRead(snFill, counter) == 1)
  // {
  //   playSdWav5.play(filelist[4]);
  // }

  // HiHats
  if (bitRead(mockHh, counter) == 1)
  {
    playSdWav3.play(filelist[2]);
  }

  // if (bitRead(hhFill, counter) == 1)
  // {
  //   playSdWav6.play(filelist[5]);
  // }
}
