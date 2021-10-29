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

void HandleInputs(int &enc1Value, int &enc2Value, int &enc3Value, int &enc4Value, int &enc7Value);

void setupFMSynth1();
void setupFMSynth2();
void setupWavefolderSynth1();
void setupWavefolderSynth2();
void setupDrumSynth1();
void setupDrumSynth2();

void noteHandling();

Display display;

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

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoisePink pink1;                // xy=92,842
AudioAmplifier amp4;                      // xy=99,108
AudioSynthWaveform waveform1;             // xy=97,708
AudioAmplifier amp6;                      // xy=101,149
AudioAmplifier amp12;                     // xy=100,429
AudioAmplifier amp11;                     // xy=102,470
AudioSynthWaveform waveform2;             // xy=102,803
AudioAmplifier amp5;                      // xy=105,266
AudioSynthWaveformSineModulated sine_fm1; // xy=107,65
AudioAmplifier amp10;                     // xy=106,587
AudioSynthWaveformSineModulated sine_fm4; // xy=108,386
AudioSynthWaveformSineModulated sine_fm2; // xy=109,220
AudioSynthWaveformSineModulated sine_fm3; // xy=109,310
AudioSynthWaveformSineModulated sine_fm5; // xy=110,541
AudioSynthWaveformSineModulated sine_fm6; // xy=110,631
AudioMixer4 mixer6;                       // xy=243,127
AudioMixer4 mixer11;                      // xy=244,448
AudioEffectEnvelope envelope1;            // xy=250,65
AudioEffectEnvelope envelope4;            // xy=251,386
AudioEffectEnvelope envelope2;            // xy=256,221
AudioEffectEnvelope envelope5;            // xy=257,542
AudioEffectEnvelope envelope3;            // xy=259,310
AudioMixer4 mixer1;                       // xy=259,819
AudioEffectEnvelope envelope6;            // xy=260,631
AudioSynthWaveformDc dc1;                 // xy=266,749
AudioEffectWaveshaper waveshape1;         // xy=281,707
AudioEffectWaveshaper waveshape2;         // xy=413,818
AudioFilterStateVariable filter1;         // xy=424,713
AudioSynthWaveformDc dc2;                 // xy=427,862
AudioAmplifier amp1;                      // xy=454,66
AudioAmplifier amp2;                      // xy=455,108
AudioAmplifier amp7;                      // xy=455,387
AudioAmplifier amp3;                      // xy=456,154
AudioAmplifier amp8;                      // xy=456,429
AudioAmplifier amp9;                      // xy=457,475
AudioFilterStateVariable filter2;         // xy=557,826
AudioEffectEnvelope envelope8;            // xy=568,700
AudioMixer4 mixer5;                       // xy=622,84
AudioMixer4 mixer10;                      // xy=623,405
AudioEffectEnvelope envelope7;            // xy=694,825
AudioSynthSimpleDrum drum1;               // xy=710,887
AudioSynthSimpleDrum drum2;               // xy=712,941
AudioMixer4 mixer7;                       // xy=858,237
AudioMixer4 mixer8;                       // xy=862,343
AudioMixer4 mixer9;                       // xy=1026,300
AudioOutputI2S i2s1;                      // xy=1217,298
AudioConnection patchCord1(pink1, 0, mixer1, 1);
AudioConnection patchCord2(amp4, 0, mixer6, 0);
AudioConnection patchCord3(waveform1, waveshape1);
AudioConnection patchCord4(amp6, 0, mixer6, 1);
AudioConnection patchCord5(amp12, 0, mixer11, 0);
AudioConnection patchCord6(amp11, 0, mixer11, 1);
AudioConnection patchCord7(waveform2, 0, mixer1, 0);
AudioConnection patchCord8(amp5, sine_fm2);
AudioConnection patchCord9(sine_fm1, envelope1);
AudioConnection patchCord10(amp10, sine_fm5);
AudioConnection patchCord11(sine_fm4, envelope4);
AudioConnection patchCord12(sine_fm2, envelope2);
AudioConnection patchCord13(sine_fm3, envelope3);
AudioConnection patchCord14(sine_fm5, envelope5);
AudioConnection patchCord15(sine_fm6, envelope6);
AudioConnection patchCord16(mixer6, sine_fm1);
AudioConnection patchCord17(mixer11, sine_fm4);
AudioConnection patchCord18(envelope1, amp1);
AudioConnection patchCord19(envelope4, amp7);
AudioConnection patchCord20(envelope2, amp2);
AudioConnection patchCord21(envelope2, amp4);
AudioConnection patchCord22(envelope5, amp8);
AudioConnection patchCord23(envelope5, amp12);
AudioConnection patchCord24(envelope3, amp3);
AudioConnection patchCord25(envelope3, amp5);
AudioConnection patchCord26(envelope3, amp6);
AudioConnection patchCord27(mixer1, waveshape2);
AudioConnection patchCord28(envelope6, amp9);
AudioConnection patchCord29(envelope6, amp10);
AudioConnection patchCord30(envelope6, amp11);
AudioConnection patchCord31(dc1, 0, filter1, 1);
AudioConnection patchCord32(waveshape1, 0, filter1, 0);
AudioConnection patchCord33(waveshape2, 0, filter2, 0);
AudioConnection patchCord34(filter1, 0, envelope8, 0);
AudioConnection patchCord35(dc2, 0, filter2, 1);
AudioConnection patchCord36(amp1, 0, mixer5, 0);
AudioConnection patchCord37(amp2, 0, mixer5, 1);
AudioConnection patchCord38(amp7, 0, mixer10, 0);
AudioConnection patchCord39(amp3, 0, mixer5, 2);
AudioConnection patchCord40(amp8, 0, mixer10, 1);
AudioConnection patchCord41(amp9, 0, mixer10, 2);
AudioConnection patchCord42(filter2, 1, envelope7, 0);
AudioConnection patchCord43(envelope8, 0, mixer7, 2);
AudioConnection patchCord44(mixer5, 0, mixer7, 0);
AudioConnection patchCord45(mixer10, 0, mixer7, 1);
AudioConnection patchCord46(envelope7, 0, mixer7, 3);
AudioConnection patchCord47(drum1, 0, mixer8, 0);
AudioConnection patchCord48(drum2, 0, mixer8, 1);
AudioConnection patchCord49(mixer7, 0, mixer9, 0);
AudioConnection patchCord50(mixer8, 0, mixer9, 1);
AudioConnection patchCord51(mixer9, 0, i2s1, 0);
AudioConnection patchCord52(mixer9, 0, i2s1, 1);

AudioControlSGTL5000 audioShield; // xy=1026,670
// GUItool: end automatically generated code

// Encoders pin setup
Encoder knobOne(0, 1);
Encoder knobTwo(2, 3);
Encoder knobThree(4, 5);
Encoder knobFour(24, 25);
// Encoder knobFive(?, ?);
// Encoder knobSix(?, ?);
Encoder knobSeven(26, 27);

// TODO: FIX ISSUE HERE
Encoder physicalEncoderArray[5] = {knobOne, knobTwo, knobThree, knobFour, knobSeven};

#define BUTTON1 28
#define BUTTON2 29
#define BUTTON3 30
#define BUTTON4 31
//#define BUTTON5 ?
//#define BUTTON6 ?
#define BUTTON7 32

Bounce bounce1 = Bounce(BUTTON1, 5);
Bounce bounce2 = Bounce(BUTTON2, 5);
Bounce bounce3 = Bounce(BUTTON3, 5);
Bounce bounce4 = Bounce(BUTTON4, 5);
// Bounce bounce5 = Bounce(BUTTON5, 5);
// Bounce bounce6 = Bounce( BUTTON6, 5 );
Bounce bounce7 = Bounce(BUTTON7, 5);

#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11
#define SDCARD_SCK_PIN 12

boolean metroOn = false;

Chrono metro;

// #define SDCARD_CS_PIN BUILTIN_SDCARD

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
  pinMode(BUTTON7, INPUT);

  AudioMemory(12);

  // turn on the output
  audioShield.enable();
  audioShield.volume(0.5);

  setupFMSynth1();
  setupFMSynth2();
  setupWavefolderSynth1();
  setupWavefolderSynth2();
  setupDrumSynth1();
  setupDrumSynth2();

  knobSeven.write(600);
}

struct fmPreset
{
  float frequency;
  float c1ratio;
  float c2ratio;
  float c3ratio;
  float fm2to1;
  float fm3to1;
  float fm3to2;
  float c1release;
  float c2release;
  float c3release;
  float op1gain;
  float op2gain;
  float op3gain;
};

fmPreset preset1{
    50,
    1,
    651.727357609711,
    3,
    36387.8884887288,
    4908.63011871415,
    28358.0098706149,
    5,
    5,
    5,
    1,
    0,
    0};

fmPreset preset2{
    50,
    9,
    32,
    60,
    36387.8884887288,
    4908.63011871415,
    28358.0098706149,
    5,
    5,
    5,
    1,
    0,
    0};

fmPreset preset3{
    50,
    4,
    4,
    15,
    1000,
    4500,
    2500,
    3.63786832648871,
    2.25588424024641,
    3.1229863963039,
    1,
    1,
    1};

void setupFMSynth1()
{
  fmPreset activePreset = preset3;
  int baseFreq = activePreset.frequency;

  // OP1 setup
  sine_fm1.amplitude(0.4);
  sine_fm1.frequency(baseFreq * activePreset.c1ratio);

  // OP1 setup
  sine_fm2.amplitude(0.4);
  sine_fm2.frequency(baseFreq * activePreset.c2ratio);

  // OP3 setup
  sine_fm3.amplitude(0.4);
  sine_fm3.frequency(baseFreq * activePreset.c3ratio);

  // OP2 to OP1
  mixer6.gain(0, 0.5);
  amp4.gain(activePreset.fm2to1);

  // OP3 to OP1
  mixer6.gain(1, 0.5);
  amp6.gain(activePreset.fm3to1);

  // OP3 to OP2
  amp5.gain(activePreset.fm3to2);

  // direct OP outs
  mixer5.gain(0, activePreset.op1gain * 0.5);
  mixer5.gain(1, activePreset.op2gain * 0.5);
  mixer5.gain(2, activePreset.op2gain * 0.5);

  // OP1 env
  envelope1.attack(1);
  envelope1.release(activePreset.c1release * 10);

  // OP2 env
  envelope2.attack(1);
  envelope2.release(activePreset.c2release * 10);

  // OP3 env
  envelope3.attack(1);
  envelope3.release(activePreset.c3release * 10);
}

void setupFMSynth2()
{
  fmPreset activePreset = preset2;
  int baseFreq = activePreset.frequency;

  // OP1 setup
  sine_fm4.amplitude(0.4);
  sine_fm4.frequency(baseFreq * activePreset.c1ratio);

  // OP1 setup
  sine_fm5.amplitude(0.4);
  sine_fm5.frequency(baseFreq * activePreset.c2ratio);

  // OP3 setup
  sine_fm6.amplitude(0.4);
  sine_fm6.frequency(baseFreq * activePreset.c3ratio);

  // OP2 to OP1
  mixer11.gain(0, 0.5);
  amp12.gain(activePreset.fm2to1);

  // OP3 to OP1
  mixer11.gain(1, 0.5);
  amp11.gain(activePreset.fm3to1);

  // OP3 to OP2
  amp10.gain(activePreset.fm3to2);

  // direct OP outs
  mixer10.gain(0, activePreset.op1gain * 0.5);
  mixer10.gain(1, activePreset.op2gain * 0.5);
  mixer10.gain(2, activePreset.op2gain * 0.5);

  // OP1 env
  envelope4.attack(1);
  envelope4.release(activePreset.c1release * 10);

  // OP2 env
  envelope5.attack(1);
  envelope5.release(activePreset.c2release * 10);

  // OP3 env
  envelope6.attack(1);
  envelope6.release(activePreset.c3release * 10);
}

void setupWavefolderSynth1()
{
  waveform1.begin(0.4, NOTE_A2, WAVEFORM_SAWTOOTH);
  waveshape1.shape(WAVESHAPE_EXAMPLE_1, 17);
  filter1.frequency(1500);
  filter1.resonance(2.5);

  envelope8.attack(1);
  envelope8.decay(746);
  envelope8.sustain(1);
  envelope8.release(791);

  mixer8.gain(0, 0.4);
}

void setupWavefolderSynth2()
{
  waveform2.begin(0.4, NOTE_C3, WAVEFORM_PULSE);
  waveshape2.shape(WAVESHAPE_EXAMPLE_2, 2);
  pink1.amplitude(0.4);

  dc2.amplitude(0.7);
  filter2.frequency(700);
  filter2.resonance(1.5);

  envelope7.attack(1);
  envelope7.decay(1884);
  envelope7.sustain(1);
  envelope7.release(161);

  mixer7.gain(2, 0.4);
}

void setupDrumSynth1()
{
  drum1.frequency(150);
  drum1.length(150);
  drum1.pitchMod(0.55);

  mixer7.gain(2, 0.5);
}

void setupDrumSynth2()
{
  drum2.frequency(330);
  drum2.length(75);
  drum2.pitchMod(0.3);

  mixer8.gain(1, 0.4);
}

int positionOne = -999;
int positionTwo = -999;
int positionThree = -999;
int positionFour = -999;
// int positionFive = -999;
// int positionSix = -999;
int positionSeven = -999;

int oldEncoderValuesArray[5] = {positionOne, positionTwo, positionThree, positionFour, positionSeven};

int counter = 0;

int enc1Value;
int enc2Value;
int enc3Value;
int enc4Value;
// int enc5Value = 0;
// int enc6Value = 0;
int enc7Value;

int encoderValuesArray[5] = {enc1Value, enc2Value, enc3Value, enc4Value, enc7Value};

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

  HandleInputs(enc1Value, enc2Value, enc3Value, enc4Value, enc7Value);

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
    // knobFive.write(0);
    // knobSix.write(0);
    knobSeven.write(0);
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

void HandleInputs(int &enc1Value, int &enc2Value, int &enc3Value, int &enc4Value, int &enc7Value)
{
  bool update = false;

  HandleEncoder(knobOne, oldEncoderValuesArray[0], enc1Value, update);
  HandleEncoder(knobTwo, oldEncoderValuesArray[1], enc2Value, update);
  HandleEncoder(knobThree, oldEncoderValuesArray[2], enc3Value, update);
  HandleEncoder(knobFour, oldEncoderValuesArray[3], enc4Value, update);
  HandleEncoder(knobSeven, oldEncoderValuesArray[4], enc7Value, update);

  // if (update)
  // {
  //   Serial.print("1: ");
  //   Serial.print(enc1Value);
  //   Serial.print(", 2: ");
  //   Serial.print(enc2Value);
  //   Serial.print(", 3: ");
  //   Serial.print(enc3Value);
  //   Serial.print(", 4: ");
  //   Serial.print(enc4Value);
  //   Serial.print(", 7: ");
  //   Serial.print(enc7Value);
  //   Serial.println();
  // }

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
    if (metro.hasPassed(enc7Value * 0.1))
    {
      envelope1.noteOff();
      envelope2.noteOff();
      envelope3.noteOff();
      envelope4.noteOff();
      envelope5.noteOff();
      envelope6.noteOff();
      envelope7.noteOff();
      envelope8.noteOff();
    }
  }

  if (update)
  {
    display.displayEncoders(mode, metroOn, enc1Value, enc2Value, enc3Value, enc4Value, enc7Value);
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
      envelope1.noteOn();
      envelope2.noteOn();
      envelope3.noteOn();
    }
    // FM Synth 2
    if (bitRead(enc3Value, counter) == 1)
    {
      envelope4.noteOn();
      envelope5.noteOn();
      envelope6.noteOn();
    }
    // Wavefolder Synth 1
    if (bitRead(0, counter) == 1)
    {
      envelope8.noteOn();
    }

    // Wavefolder Synth 2
    if (bitRead(0, counter) == 1)
    {
      envelope7.noteOn();
    }

    // Drum Synth 2
    if (bitRead(0, counter) == 1)
    {
      drum1.noteOn();
    }

    // Drum Synth 2
    if (bitRead(0, counter) == 1)
    {
      drum2.noteOn();
    }
  }
  else if (counter > 7)
  {
    int newCounter = counter - 8;
    // FM Synth 1
    if (bitRead(enc2Value, newCounter) == 1)
    {
      envelope1.noteOn();
      envelope2.noteOn();
      envelope3.noteOn();
    }
    // FM Synth 2
    if (bitRead(enc4Value, newCounter) == 1)
    {
      envelope4.noteOn();
      envelope5.noteOn();
      envelope6.noteOn();
    }
    // Wavefolder Synth 1
    if (bitRead(0, newCounter) == 1)
    {
      envelope8.noteOn();
      if (metro.hasPassed(enc7Value * 0.7))
      {
        envelope8.noteOff();
      }
    }

    // Wavefolder Synth 2
    if (bitRead(0, newCounter) == 1)
    {
      envelope7.noteOn();
    }

    // Drum Synth 2
    if (bitRead(0, newCounter) == 1)
    {
      drum1.noteOn();
    }

    // Drum Synth 2
    if (bitRead(0, newCounter) == 1)
    {
      drum2.noteOn();
    }
  }
}
