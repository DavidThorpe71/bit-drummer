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
#include <FmSynth.h>

// GUItool: begin automatically generated code
AudioSynthSimpleDrum drum1;               // xy=83,556
AudioSynthNoiseWhite noise1;              // xy=83,595
AudioMixer4 mixer2;                       // xy=99,366
AudioSynthWaveformSineModulated sine_fm6; // xy=99,504
AudioMixer4 mixer1;                       // xy=101,119
AudioSynthWaveformSineModulated sine_fm3; // xy=101,257
AudioSynthWaveformSineModulated sine_fm5; // xy=103,421
AudioSynthWaveformSineModulated sine_fm2; // xy=105,174
AudioSynthWaveformSineModulated sine_fm4; // xy=105,312
AudioSynthWaveformSineModulated sine_fm1; // xy=107,65
AudioFilterStateVariable filter1;         // xy=200,602
AudioAmplifier amp7;                      // xy=239,464
AudioAmplifier amp4;                      // xy=241,217
AudioEffectEnvelope envelope4;            // xy=248,312
AudioEffectEnvelope envelope5;            // xy=250,422
AudioEffectEnvelope envelope2;            // xy=252,175
AudioEffectEnvelope envelope6;            // xy=252,504
AudioEffectEnvelope envelope3;            // xy=254,257
AudioEffectEnvelope envelope1;            // xy=258,67
AudioMixer4 mixer3;                       // xy=330,575
AudioMixer4 mixer6;                       // xy=428,330
AudioMixer4 mixer5;                       // xy=444,83
AudioEffectWaveshaper waveshape1;         // xy=469,575
AudioSynthSimpleDrum drum2;               // xy=471,503
AudioEffectBitcrusher bitcrusher1;        // xy=607,503
AudioSynthSimpleDrum drum4;               // xy=616,744
AudioEffectEnvelope envelope7;            // xy=617,575
AudioSynthSimpleDrum drum3;               // xy=624,691
AudioMixer4 mixer7;                       // xy=858,237
AudioMixer4 mixer8;                       // xy=862,343
AudioMixer4 mixer9;                       // xy=1026,300
AudioOutputI2S i2s1;                      // xy=1203,300
AudioConnection patchCord1(drum1, 0, mixer3, 0);
AudioConnection patchCord2(noise1, 0, filter1, 0);
AudioConnection patchCord3(mixer2, sine_fm4);
AudioConnection patchCord4(sine_fm6, envelope6);
AudioConnection patchCord5(mixer1, sine_fm1);
AudioConnection patchCord6(sine_fm3, envelope3);
AudioConnection patchCord7(sine_fm5, envelope5);
AudioConnection patchCord8(sine_fm2, envelope2);
AudioConnection patchCord9(sine_fm4, envelope4);
AudioConnection patchCord10(sine_fm1, envelope1);
AudioConnection patchCord11(filter1, 1, mixer3, 1);
AudioConnection patchCord12(amp7, sine_fm5);
AudioConnection patchCord13(amp4, sine_fm2);
AudioConnection patchCord14(envelope4, 0, mixer6, 0);
AudioConnection patchCord15(envelope5, 0, mixer2, 0);
AudioConnection patchCord16(envelope5, 0, mixer6, 1);
AudioConnection patchCord17(envelope2, 0, mixer1, 0);
AudioConnection patchCord18(envelope2, 0, mixer5, 1);
AudioConnection patchCord19(envelope6, 0, mixer2, 1);
AudioConnection patchCord20(envelope6, amp7);
AudioConnection patchCord21(envelope6, 0, mixer6, 2);
AudioConnection patchCord22(envelope3, 0, mixer1, 1);
AudioConnection patchCord23(envelope3, amp4);
AudioConnection patchCord24(envelope3, 0, mixer5, 2);
AudioConnection patchCord25(envelope1, 0, mixer5, 0);
AudioConnection patchCord26(mixer3, waveshape1);
AudioConnection patchCord27(mixer6, 0, mixer7, 1);
AudioConnection patchCord28(mixer5, 0, mixer7, 0);
AudioConnection patchCord29(waveshape1, envelope7);
AudioConnection patchCord30(drum2, bitcrusher1);
AudioConnection patchCord31(bitcrusher1, 0, mixer7, 2);
AudioConnection patchCord32(drum4, 0, mixer8, 1);
AudioConnection patchCord33(envelope7, 0, mixer7, 3);
AudioConnection patchCord34(drum3, 0, mixer8, 0);
AudioConnection patchCord35(mixer7, 0, mixer9, 0);
AudioConnection patchCord36(mixer8, 0, mixer9, 1);
AudioConnection patchCord37(mixer9, 0, i2s1, 0);
AudioConnection patchCord38(mixer9, 0, i2s1, 1);
AudioControlSGTL5000 sgtl5000_1; // xy=1087,852
// GUItool: end automatically generated code

// PIN SETUP
Encoder knobOne(0, 1);
Encoder knobTwo(2, 3);
Encoder knobThree(4, 5);
Encoder knobFour(28, 29);
Encoder knobFive(30, 31);
Encoder knobSix(32, 33);
Encoder knobSeven(4, 5);
Encoder knobEight(34, 35);

#define BUTTON1 24
#define BUTTON2 25
#define BUTTON3 36
#define BUTTON4 37
#define BUTTON5 38
#define BUTTON6 39
#define BUTTON7 26
#define BUTTON8 40

#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11
#define SDCARD_SCK_PIN 12

Display display;

Chrono metro;

FmSynth fmSynth1(
    &sine_fm1,
    &sine_fm2,
    &sine_fm3,
    &envelope1,
    &envelope2,
    &envelope3,
    &mixer5,
    &mixer1,
    &amp4);

// // TODO: FIX ISSUE HERE
// Encoder physicalEncoderArray[3] = {knobOne, knobTwo, knobSeven};

Bounce bounce1 = Bounce(BUTTON1, 5);
Bounce bounce2 = Bounce(BUTTON2, 5);
Bounce bounce3 = Bounce(BUTTON3, 5);
Bounce bounce4 = Bounce(BUTTON4, 5);
Bounce bounce5 = Bounce(BUTTON5, 5);
Bounce bounce6 = Bounce(BUTTON6, 5);
Bounce bounce7 = Bounce(BUTTON7, 5);
Bounce bounce8 = Bounce(BUTTON8, 5);

boolean metroOn = false;

void HandleInputs(
    int &enc1Value,
    int &enc2Value,
    int &enc3Value,
    int &enc4Value,
    int &enc5Value,
    int &enc6Value,
    int &enc7Value,
    int &enc8Value);

void setupFMSynth1();
void setupFMSynth2();
void setupWavefolderSynth1();
void setupWavefolderSynth2();
void setupDrumSynth1();
void setupDrumSynth2();

void noteHandling();

#define NOTE_F2 87.31
#define NOTE_A2 110.00
#define NOTE_C3 130.81
#define NOTE_F3 174.61
#define NOTE_A3 220.00
#define NOTE_C4 261.63

float WAVESHAPE_EXAMPLE_1[17] = {
    -0.588,
    -0.579,
    -0.549,
    -0.488,
    -0.396,
    -0.320,
    -0.228,
    -0.122,
    0,
    0.122,
    0.228,
    0.320,
    0.396,
    0.488,
    0.549,
    0.579,
    0.588};

float WAVESHAPE_EXAMPLE_2[2] = {
    -0.488,
    0.549};

void setup()
{
  Serial.begin(9600);
  Serial.println("David bit drum machine");

  display.startup();

  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(BUTTON5, INPUT);
  pinMode(BUTTON6, INPUT);
  pinMode(BUTTON7, INPUT);
  pinMode(BUTTON8, INPUT);

  AudioMemory(20);

  // turn on the output
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);

  fmSynth1.init();
  // sine_fm1.frequency(220);
  // sine_fm1.amplitude(0.7);

  // delay(1000);

  // setupWavefolderSynth1();
  // setupWavefolderSynth2();
  // setupDrumSynth1();
  // setupDrumSynth2();

  knobSeven.write(600);
}

int positionOne = -999;
int positionTwo = -999;
int positionThree = -999;
int positionFour = -999;
int positionFive = -999;
int positionSix = -999;
int positionSeven = -999;
int positionEight = -999;

int oldEncoderValuesArray[8] = {
    positionOne,
    positionTwo,
    positionThree,
    positionFour,
    positionFive,
    positionSix,
    positionSeven,
    positionEight};

int counter = 0;

int enc1Value;
int enc2Value;
int enc3Value;
int enc4Value;
int enc5Value;
int enc6Value;
int enc7Value;
int enc8Value;

int encoderValuesArray[8] = {
    enc1Value,
    enc2Value,
    enc3Value,
    enc4Value,
    enc5Value,
    enc6Value,
    enc7Value,
    enc8Value};

int mode = 0;
int originalAudioMemUsage = 0;

void loop()
{

  int audioMemUsage = AudioMemoryUsageMax();
  if (audioMemUsage > originalAudioMemUsage)
  {
    Serial.println(audioMemUsage);
    originalAudioMemUsage = audioMemUsage;
  }

  HandleInputs(enc1Value, enc2Value, enc3Value, enc4Value, enc5Value, enc6Value, enc7Value, enc8Value);
  // fmSynth1.op1.frequency(450);
  // fmSynth1.op1Env.noteOn();
  // delay(1000);
  // fmSynth1.op1Env.noteOff();
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available())
  {
    Serial.read();
    Serial.println("Reset all knobs to zero");
    knobOne.write(0);
    knobTwo.write(0);
    knobThree.write(0);
    knobFour.write(0);
    knobFive.write(0);
    knobSix.write(0);
    knobSeven.write(0);
    knobEight.write(0);
  }
}

void HandleEncoder(Encoder physicalEncoder, int &oldEncoderValue, int &encoderValue, bool &update)
{
  int newEncoderValue = physicalEncoder.read();

  if (newEncoderValue >= 1020)
  {
    physicalEncoder.write(1020);
  }

  if (newEncoderValue <= 0)
  {
    physicalEncoder.write(0);
  }

  if (newEncoderValue != oldEncoderValue)
  {
    encoderValue = newEncoderValue / 4;
    update = true;

    oldEncoderValue = newEncoderValue;
  }
}

void HandleInputs(
    int &enc1Value,
    int &enc2Value,
    int &enc3Value,
    int &enc4Value,
    int &enc5Value,
    int &enc6Value,
    int &enc7Value,
    int &enc8Value)
{
  bool update = false;

  HandleEncoder(knobOne, oldEncoderValuesArray[0], enc1Value, update);
  HandleEncoder(knobTwo, oldEncoderValuesArray[1], enc2Value, update);
  HandleEncoder(knobThree, oldEncoderValuesArray[2], enc3Value, update);
  HandleEncoder(knobFour, oldEncoderValuesArray[3], enc4Value, update);
  HandleEncoder(knobFive, oldEncoderValuesArray[4], enc5Value, update);
  HandleEncoder(knobSix, oldEncoderValuesArray[5], enc6Value, update);
  HandleEncoder(knobSeven, oldEncoderValuesArray[6], enc7Value, update);
  HandleEncoder(knobEight, oldEncoderValuesArray[7], enc8Value, update);

  if (bounce1.update())
  {
    update = true;
    if (bounce1.read() == HIGH)
    {
      Serial.println("button1 clicked");
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

  if (bounce2.update())
  {
    Serial.println("button2 clicked");
  }

  if (bounce3.update())
  {
    Serial.println("button3 clicked");
  }

  if (bounce4.update())
  {
    Serial.println("button4 clicked");
  }

  if (bounce5.update())
  {
    Serial.println("button5 clicked");
  }

  if (bounce6.update())
  {
    Serial.println("button6 clicked");
  }

  if (bounce7.update())
  {
    update = true;
    if (bounce7.read() == HIGH)
    {
      Serial.println("button7 clicked");
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

  if (bounce8.update())
  {
    Serial.println("button8 clicked");
  }

  if (metroOn)
  {
    if (metro.hasPassed(enc7Value))
    {
      metro.restart(); // Restart the chronometer.

      if (counter == 15)
      {
        counter = 0;
      }
      else
      {
        counter++;
      }

      noteHandling();
    }
    if (metro.hasPassed(enc7Value * 0.7))
    {
      fmSynth1.noteOff();
      // fmSynth1.op2Env.noteOff();
      // fmSynth1.op3Env.noteOff();
      // fmSynth2.op1Env.noteOff();
      // fmSynth2.op2Env.noteOff();
      // fmSynth2.op3Env.noteOff();
    }
  }

  if (update)
  {
    display.displayEncoders(mode, metroOn, enc1Value, enc2Value, enc7Value);
    // Serial.print("1: ");
    // Serial.print(enc1Value);
    // Serial.print(", 2: ");
    // Serial.print(enc2Value);
    // Serial.print(", 3: ");
    // Serial.print(enc3Value);
    // Serial.print(", 4: ");
    // Serial.print(enc4Value);
    // Serial.print(", 7: ");
    // Serial.print(enc7Value);
    // Serial.println();
  }
}

void noteHandling()
{
  // Steps 0 - 7
  if (counter < 8)
  {
    // FM Synth 1
    if (bitRead(enc1Value, counter) == 1)
    {
      // Serial.println(fmSynth1.getOp1Freq());

      fmSynth1.noteOn();
      // fmSynth1.op2Env.noteOn();
      // fmSynth1.op2Env.noteOn();
    }
    // FM Synth 2
    if (bitRead(enc3Value, counter) == 1)
    {
      // fmSynth2.op1Env.noteOn();
      // fmSynth2.op2Env.noteOn();
      // fmSynth2.op2Env.noteOn();
    }
    // Wavefolder Synth 1
    if (bitRead(0, counter) == 1)
    {
      // envelope8.noteOn();
    }

    // Wavefolder Synth 2
    if (bitRead(0, counter) == 1)
    {
      // envelope7.noteOn();
    }

    // Drum Synth 2
    if (bitRead(0, counter) == 1)
    {
      // drum1.noteOn();
    }

    // Drum Synth 2
    if (bitRead(0, counter) == 1)
    {
      // drum2.noteOn();
    }
  }
  else if (counter > 7)
  {
    int newCounter = counter - 8;
    // FM Synth 1
    if (bitRead(enc2Value, newCounter) == 1)
    {
      fmSynth1.noteOn();
    }
    // FM Synth 2
    // if (bitRead(enc4Value, newCounter) == 1)
    // {
    //   // fmSynth2.op1Env.noteOn();
    //   // fmSynth2.op2Env.noteOn();
    //   // fmSynth2.op2Env.noteOn();
    // }
    // Wavefolder Synth 1
    if (bitRead(0, newCounter) == 1)
    {
      // envelope8.noteOn();
      // if (metro.hasPassed(enc7Value * 0.7))
      // {
      //   envelope8.noteOff();
      // }
    }

    // Wavefolder Synth 2
    if (bitRead(0, newCounter) == 1)
    {
      // envelope7.noteOn();
    }

    // Drum Synth 2
    if (bitRead(0, newCounter) == 1)
    {
      // drum1.noteOn();
    }

    // Drum Synth 2
    if (bitRead(0, newCounter) == 1)
    {
      // drum2.noteOn();
    }
  }
}
