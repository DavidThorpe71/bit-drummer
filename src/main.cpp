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

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav playSdWav5;     // xy=378.8888804117838,458.88888041178376
AudioPlaySdWav playSdWav6;     // xy=380.5555191040039,510.555477142334
AudioPlaySdWav playSdWav4;     // xy=382.2222137451172,393.8888359069824
AudioPlaySdWav playSdWav2;     // xy=385.55554962158203,285.5555419921875
AudioPlaySdWav playSdWav3;     // xy=385.55555725097656,338.88886642456055
AudioPlaySdWav playSdWav1;     // xy=392.22221374511713,225.55554707845047
AudioEffectEnvelope envelope4; // xy=603.888916015625,385.5556049346924
AudioEffectEnvelope envelope2; // xy=605.5555191040039,297.22220039367676
AudioEffectEnvelope envelope1; // xy=606.3333129882812,246.3333282470703
AudioEffectEnvelope envelope3; // xy=607.2222290039062,340.5555763244629
AudioEffectEnvelope envelope5; // xy=608.888916015625,430.5555486679077
AudioEffectEnvelope envelope6; // xy=610.5555419921875,475.55550956726074
AudioMixer4 mixer2;            // xy=810.5555648803711,362.22218322753906
AudioMixer4 mixer1;            // xy=812.2222696940103,285.5555076599121
AudioMixer4 mixer3;            // xy=960.5556945800781,315.55550765991217
AudioOutputI2S i2s1;           // xy=1125.3334503173828,317.66662979125977
AudioConnection patchCord1(playSdWav5, 0, envelope5, 0);
AudioConnection patchCord2(playSdWav6, 0, envelope6, 0);
AudioConnection patchCord3(playSdWav4, 0, envelope4, 0);
AudioConnection patchCord4(playSdWav2, 0, envelope2, 0);
AudioConnection patchCord5(playSdWav3, 0, envelope3, 0);
AudioConnection patchCord6(playSdWav1, 0, envelope1, 0);
AudioConnection patchCord7(envelope4, 0, mixer1, 3);
AudioConnection patchCord8(envelope2, 0, mixer1, 1);
AudioConnection patchCord9(envelope1, 0, mixer1, 0);
AudioConnection patchCord10(envelope3, 0, mixer1, 2);
AudioConnection patchCord11(envelope5, 0, mixer2, 0);
AudioConnection patchCord12(envelope6, 0, mixer2, 1);
AudioConnection patchCord13(mixer2, 0, mixer3, 1);
AudioConnection patchCord14(mixer1, 0, mixer3, 0);
AudioConnection patchCord15(mixer3, 0, i2s1, 0);
AudioConnection patchCord16(mixer3, 0, i2s1, 1);
AudioControlSGTL5000 sgtl5000_1; // xy=667.3333129882812,27.333335876464844
// GUItool: end automatically generated code

// PIN SETUP
// TODO: correct these values
Encoder knobOne(0, 1);
Encoder knobTwo(2, 3);
Encoder knobThree(4, 5);
Encoder knobFour(24, 25);
Encoder knobFive(26, 27);
Encoder knobSix(28, 29);
Encoder knobSeven(30, 31);
Encoder knobEight(32, 33);
// TODO: need to check these values
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

void setupSdPlayer();

void noteHandling();

void setup()
{
  Serial.begin(9600);
  Serial.println("David bit drum machine - sampler version");

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

  setupSdPlayer();

  knobEight.write(600);
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

  mixer1.gain(0, 0.8);
  mixer1.gain(1, 0.8);
  mixer1.gain(2, 0.8);
  mixer1.gain(3, 0.8);

  mixer2.gain(0, 0.8);
  mixer2.gain(1, 0.8);

  mixer3.gain(0, 0.8);
  mixer3.gain(1, 0.8);
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
    Serial.println("button7 clicked");
  }

  if (bounce8.update())
  {
    update = true;
    if (bounce8.read() == HIGH)
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

  if (metroOn)
  {
    if (metro.hasPassed(enc8Value))
    {
      metro.restart(); // Restart the chronometer.

      if (counter == 8)
      {
        counter = 0;
      }
      else
      {
        counter++;
      }

      noteHandling();
    }
    if (metro.hasPassed(enc8Value * 0.7))
    {
      envelope1.noteOff();
      envelope2.noteOff();
      envelope3.noteOff();
      envelope4.noteOff();
      envelope5.noteOff();
      envelope6.noteOff();
    }
  }

  if (update)
  {
    display.displayEncoders(
        mode,
        metroOn,
        enc1Value,
        enc2Value,
        enc3Value,
        enc4Value,
        enc5Value,
        enc6Value,
        enc7Value,
        enc8Value);
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
  }
}

const char *filelist[6] = {"BD1.WAV", "SN1.WAV", "HH1.WAV", "BD2.WAV", "SNR2.WAV", "HH2.WAV"};

void noteHandling()
{
  // BD1.WAV
  if (bitRead(enc1Value, counter) == 1)
  {
    envelope1.noteOn();
    playSdWav1.play(filelist[0]);
  }
  // SN1.WAV
  if (bitRead(enc3Value, counter) == 1)
  {
    envelope2.noteOn();
    playSdWav2.play(filelist[1]);
  }
  // HH1.WAV
  if (bitRead(enc5Value, counter) == 1)
  {
    envelope3.noteOn();
    playSdWav3.play(filelist[2]);
  }

  // BD2.WAV
  if (bitRead(enc2Value, counter) == 1)
  {
    envelope4.noteOn();
    playSdWav4.play(filelist[3]);
  }

  // SNR2.WAV
  if (bitRead(enc4Value, counter) == 1)
  {
    envelope5.noteOn();
    playSdWav5.play(filelist[4]);
  }

  // HH2.WAV
  if (bitRead(enc6Value, counter) == 1)
  {
    envelope6.noteOn();
    playSdWav6.play(filelist[5]);
  }
}
