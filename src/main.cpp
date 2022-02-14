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
#include <Kick.h>
#include <Snare.h>
#include <TwoOpFmSynth.h>
#include <ThreeOpFmSynth.h>
#include <MetalSynth.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioMixer4 mixer11;                      // xy=115,361
AudioSynthSimpleDrum drum1;               // xy=123,952
AudioSynthNoiseWhite noise1;              // xy=124,992
AudioMixer4 mixer1;                       // xy=141,113
AudioSynthWaveformModulated waveformMod7; // xy=141,418
AudioSynthWaveformModulated waveformMod6; // xy=145,306
AudioSynthWaveformModulated waveformMod9; // xy=156,168
AudioSynthWaveformModulated waveformMod8; // xy=161,58
AudioSynthWaveform waveform6;             // xy=164,504
AudioSynthWaveform waveform7;             // xy=195,255
AudioSynthWaveform waveform4;             // xy=233,757
AudioSynthWaveform waveform3;             // xy=235,708
AudioSynthWaveform waveform5;             // xy=236,808
AudioSynthWaveform waveform2;             // xy=238,659
AudioSynthWaveform waveform1;             // xy=239,612
AudioFilterStateVariable filter1;         // xy=241,999
AudioAmplifier amp7;                      // xy=299,459
AudioEffectEnvelope envelope12;           // xy=307,306
AudioEffectEnvelope envelope13;           // xy=310,417
AudioEffectEnvelope envelope14;           // xy=310,503
AudioAmplifier amp4;                      // xy=325,211
AudioEffectEnvelope envelope1;            // xy=333,58
AudioEffectEnvelope envelope2;            // xy=336,169
AudioEffectEnvelope envelope3;            // xy=336,255
AudioMixer4 mixer3;                       // xy=371,972
AudioAmplifier amp5;                      // xy=386,757
AudioAmplifier amp3;                      // xy=388,708
AudioAmplifier amp1;                      // xy=389,614
AudioAmplifier amp6;                      // xy=389,808
AudioAmplifier amp2;                      // xy=391,659
AudioSynthWaveformDc dc2;                 // xy=508,1013
AudioEffectWaveshaper waveshape1;         // xy=510,972
AudioMixer4 mixer10;                      // xy=513,326
AudioSynthSimpleDrum drum3;               // xy=520,1057
AudioMixer4 mixer5;                       // xy=539,78
AudioSynthWaveformModulated waveformMod4; // xy=542,762
AudioSynthWaveformModulated waveformMod3; // xy=544,713
AudioSynthWaveformModulated waveformMod5; // xy=545,813
AudioSynthWaveformModulated waveformMod2; // xy=547,664
AudioSynthWaveformModulated waveformMod1; // xy=548,617
AudioEffectWaveFolder wavefolder1;        // xy=659,1034
AudioEffectEnvelope envelope7;            // xy=662,973
AudioSynthSimpleDrum drum4;               // xy=662,1095
AudioSynthWaveformDc dc1;                 // xy=674,524
AudioMixer4 mixer2;                       // xy=723,661
AudioMixer4 mixer6;                       // xy=725,739
AudioEffectEnvelope envelope5;            // xy=814,523
AudioMixer4 mixer4;                       // xy=870,671
AudioFilterStateVariable filter2;         // xy=976,516
AudioEffectEnvelope envelope4;            // xy=1119,523
AudioMixer4 mixer7;                       // xy=1299,519
AudioMixer4 mixer8;                       // xy=1303,625
AudioMixer4 mixer9;                       // xy=1467,582
AudioOutputI2S i2s1;                      // xy=1644,582
AudioConnection patchCord1(mixer11, 0, waveformMod6, 0);
AudioConnection patchCord2(drum1, 0, mixer3, 0);
AudioConnection patchCord3(noise1, 0, filter1, 0);
AudioConnection patchCord4(mixer1, 0, waveformMod8, 0);
AudioConnection patchCord5(waveformMod7, envelope13);
AudioConnection patchCord6(waveformMod6, envelope12);
AudioConnection patchCord7(waveformMod9, envelope2);
AudioConnection patchCord8(waveformMod8, envelope1);
AudioConnection patchCord9(waveform6, envelope14);
AudioConnection patchCord10(waveform7, envelope3);
AudioConnection patchCord11(waveform4, amp5);
AudioConnection patchCord12(waveform3, amp3);
AudioConnection patchCord13(waveform5, amp6);
AudioConnection patchCord14(waveform2, amp2);
AudioConnection patchCord15(waveform1, amp1);
AudioConnection patchCord16(filter1, 1, mixer3, 1);
AudioConnection patchCord17(amp7, 0, waveformMod7, 0);
AudioConnection patchCord18(envelope12, 0, mixer10, 0);
AudioConnection patchCord19(envelope13, 0, mixer11, 0);
AudioConnection patchCord20(envelope13, 0, mixer10, 1);
AudioConnection patchCord21(envelope14, 0, mixer11, 1);
AudioConnection patchCord22(envelope14, amp7);
AudioConnection patchCord23(envelope14, 0, mixer10, 2);
AudioConnection patchCord24(amp4, 0, waveformMod9, 0);
AudioConnection patchCord25(envelope1, 0, mixer5, 0);
AudioConnection patchCord26(envelope2, 0, mixer1, 0);
AudioConnection patchCord27(envelope2, 0, mixer5, 1);
AudioConnection patchCord28(envelope3, 0, mixer1, 1);
AudioConnection patchCord29(envelope3, amp4);
AudioConnection patchCord30(envelope3, 0, mixer5, 2);
AudioConnection patchCord31(mixer3, waveshape1);
AudioConnection patchCord32(amp5, 0, waveformMod4, 0);
AudioConnection patchCord33(amp3, 0, waveformMod3, 0);
AudioConnection patchCord34(amp1, 0, waveformMod1, 0);
AudioConnection patchCord35(amp6, 0, waveformMod5, 0);
AudioConnection patchCord36(amp2, 0, waveformMod2, 0);
AudioConnection patchCord37(dc2, 0, wavefolder1, 0);
AudioConnection patchCord38(waveshape1, envelope7);
AudioConnection patchCord39(mixer10, 0, mixer7, 1);
AudioConnection patchCord40(drum3, 0, wavefolder1, 1);
AudioConnection patchCord41(mixer5, 0, mixer7, 0);
AudioConnection patchCord42(waveformMod4, 0, mixer2, 3);
AudioConnection patchCord43(waveformMod3, 0, mixer2, 2);
AudioConnection patchCord44(waveformMod5, 0, mixer6, 0);
AudioConnection patchCord45(waveformMod2, 0, mixer2, 1);
AudioConnection patchCord46(waveformMod1, 0, mixer2, 0);
AudioConnection patchCord47(wavefolder1, 0, mixer8, 0);
AudioConnection patchCord48(envelope7, 0, mixer7, 3);
AudioConnection patchCord49(drum4, 0, mixer8, 1);
AudioConnection patchCord50(dc1, envelope5);
AudioConnection patchCord51(mixer2, 0, mixer4, 0);
AudioConnection patchCord52(mixer6, 0, mixer4, 1);
AudioConnection patchCord53(envelope5, 0, filter2, 1);
AudioConnection patchCord54(mixer4, 0, filter2, 0);
AudioConnection patchCord55(filter2, 2, envelope4, 0);
AudioConnection patchCord56(envelope4, 0, mixer7, 2);
AudioConnection patchCord57(mixer7, 0, mixer9, 0);
AudioConnection patchCord58(mixer8, 0, mixer9, 1);
AudioConnection patchCord59(mixer9, 0, i2s1, 0);
AudioConnection patchCord60(mixer9, 0, i2s1, 1);
AudioControlSGTL5000 sgtl5000_1; // xy=1087,852
// GUItool: end automatically generated code

// PIN SETUP
Encoder knobOne(0, 1);
Encoder knobTwo(2, 3);
Encoder knobThree(4, 5);
Encoder knobFour(24, 25);
Encoder knobFive(26, 27);
Encoder knobSix(28, 29);
Encoder knobSeven(30, 31);
Encoder knobEight(32, 33);

#define BUTTON1 34
#define BUTTON2 37
#define BUTTON3 35
#define BUTTON4 38
#define BUTTON5 36
#define BUTTON6 39
#define BUTTON7 41
#define BUTTON8 40

#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11
#define SDCARD_SCK_PIN 12

Display display;

Chrono metro;

TwoOpFmSynth fmSynth1(
    &waveformMod1,
    &waveform1,
    &amp1);

TwoOpFmSynth fmSynth2(
    &waveformMod2,
    &waveform2,
    &amp2);

TwoOpFmSynth fmSynth3(
    &waveformMod3,
    &waveform3,
    &amp3);

TwoOpFmSynth fmSynth4(
    &waveformMod4,
    &waveform4,
    &amp4);

TwoOpFmSynth fmSynth5(
    &waveformMod5,
    &waveform5,
    &amp5);

Snare snare(
    &drum1,
    &noise1,
    &filter1,
    &mixer3,
    &waveshape1,
    &envelope7);

Kick kick(
    &drum3,
    &wavefolder1,
    &dc2);

MetalSynth metalSynth(
    &fmSynth1,
    &fmSynth2,
    &fmSynth3,
    &fmSynth4,
    &fmSynth5,
    &filter2,
    &envelope5,
    &envelope4,
    &dc1);

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

void HandleEncoder(Encoder physicalEncoder, int &oldEncoderValue, int &encoderValue, bool &update);

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

  // fmSynth1.init();
  snare.init();
  kick.init();
  metalSynth.init();
  mixer7.gain(3, 1.2);
  mixer7.gain(2, 0.5);
  mixer8.gain(0, 0.4);
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
int counterMax = 16;

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

void HandleEncoder(Encoder *physicalEncoder, int &oldEncoderValue, int &encoderValue, bool &update)
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

  HandleEncoder(*knobOne, oldEncoderValuesArray[0], enc1Value, update);
  HandleEncoder(*knobTwo, oldEncoderValuesArray[1], enc2Value, update);
  HandleEncoder(*knobThree, oldEncoderValuesArray[2], enc3Value, update);
  HandleEncoder(*knobFour, oldEncoderValuesArray[3], enc4Value, update);
  HandleEncoder(*knobFive, oldEncoderValuesArray[4], enc5Value, update);
  HandleEncoder(*knobSix, oldEncoderValuesArray[5], enc6Value, update);
  HandleEncoder(*knobSeven, oldEncoderValuesArray[6], enc7Value, update);
  HandleEncoder(*knobEight, oldEncoderValuesArray[7], enc8Value, update);

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

  counterMax = enc8Value;
  if (metroOn)
  {
    if (metro.hasPassed(enc7Value))
    {
      metro.restart(); // Restart the chronometer.

      if (counter >= counterMax)
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
      // fmSynth1.noteOff();
      snare.noteOff();
      // fmSynth1.op3Env.noteOff();
      // fmSynth2.op1Env.noteOff();
      // fmSynth2.op2Env.noteOff();
      // fmSynth2.op3Env.noteOff();
    }
  }

  if (update)
  {
    display.displayEncoders(mode, metroOn, enc1Value, enc2Value, enc7Value);
    Serial.print("1: ");
    Serial.print(enc1Value);
    Serial.print(", 2: ");
    Serial.print(enc2Value);
    Serial.print(", 3: ");
    Serial.print(enc3Value);
    Serial.print(", 4: ");
    Serial.print(enc4Value);
    Serial.print(", 5: ");
    Serial.print(enc5Value);
    Serial.print(", 6: ");
    Serial.print(enc6Value);
    Serial.print(", 7: ");
    Serial.print(enc7Value);
    Serial.print(", 8: ");
    Serial.print(enc8Value);
    Serial.println();

    // kick.setDrumFreq(enc2Value);
    // kick.setEnvLength(enc3Value);
    // kick.setWavefolderAmount(enc4Value);
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

      // fmSynth1.noteOn();
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
    if (bitRead(enc5Value, counter) == 1)
    {
      metalSynth.noteOn();
    }

    // Snare
    if (bitRead(enc3Value, counter) == 1)
    {
      snare.noteOn();
    }

    // Kick
    if (bitRead(enc1Value, counter) == 1)
    {
      kick.noteOn();
    }
  }
  else if (counter > 7)
  {
    int newCounter = counter - 8;
    // FM Synth 1
    if (bitRead(enc2Value, newCounter) == 1)
    {
      // fmSynth1.noteOn();
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

    // Metal Synth
    if (bitRead(enc6Value, newCounter) == 1)
    {
      metalSynth.noteOn();
    }

    // Snare
    if (bitRead(enc4Value, newCounter) == 1)
    {
      snare.noteOn();
    }

    // Drum Synth 2
    if (bitRead(enc2Value, newCounter) == 1)
    {
      kick.noteOn();
    }
  }
}
