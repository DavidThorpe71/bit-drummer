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
#include <Pattern.h>
#include <EncoderHandler.h>
#include <PatternEncoderHandler.cpp>
#include <TempoEncoderHandler.cpp>
#include <BitDrumEncoderAbstract.h>
#include <BitDrumEncoder.cpp>

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

Bounce bounce1 = Bounce(BUTTON1, 5);
Bounce bounce2 = Bounce(BUTTON2, 5);
Bounce bounce3 = Bounce(BUTTON3, 5);
Bounce bounce4 = Bounce(BUTTON4, 5);
Bounce bounce5 = Bounce(BUTTON5, 5);
Bounce bounce6 = Bounce(BUTTON6, 5);
Bounce bounce7 = Bounce(BUTTON7, 5);
Bounce bounce8 = Bounce(BUTTON8, 5);

boolean metroOn = false;

bool update = false;

BitDrumEncoderAbstract* encoder1 = new BitDrumEncoder(&knobOne, &bounce1);
PatternEncoderHandler* encoder1Handler = new PatternEncoderHandler(encoder1, pattern, 127, &update);

BitDrumEncoderAbstract* encoder2 = new BitDrumEncoder(&knobTwo, &bounce2);
PatternEncoderHandler* encoder2Handler = new PatternEncoderHandler(encoder2, pattern, 127, &update);

BitDrumEncoderAbstract* encoder3 = new BitDrumEncoder(&knobThree, &bounce3);
PatternEncoderHandler* encoder3Handler = new PatternEncoderHandler(encoder3, pattern, 127, &update);

BitDrumEncoderAbstract* encoder4 = new BitDrumEncoder(&knobFour, &bounce4);
PatternEncoderHandler* encoder4Handler = new PatternEncoderHandler(encoder4, pattern, 127, &update);

BitDrumEncoderAbstract* encoder5 = new BitDrumEncoder(&knobFive, &bounce5);
PatternEncoderHandler* encoder5Handler = new PatternEncoderHandler(encoder5, pattern, 127, &update);

BitDrumEncoderAbstract* encoder6 = new BitDrumEncoder(&knobSix, &bounce6);
PatternEncoderHandler* encoder6Handler = new PatternEncoderHandler(encoder6, pattern, 127, &update);

BitDrumEncoderAbstract* encoder7 = new BitDrumEncoder(&knobSeven, &bounce7);
PatternEncoderHandler* encoder7Handler = new PatternEncoderHandler(encoder7, pattern, 7, &update);

BitDrumEncoderAbstract* encoder8 = new BitDrumEncoder(&knobEight, &bounce8);
TempoEncoderHandler* encoder8Handler = new TempoEncoderHandler(encoder8, pattern, &metroOn, 1000, &update);

void HandleInputs();

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
  setupMixer();

  encoder8->write(250);
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
}

void setupMixer() 
{
  mixer1.gain(0, 1);
  mixer1.gain(1, 1);
  mixer1.gain(2, 1);
  mixer1.gain(3, 1);

  mixer2.gain(0, 1);
  mixer2.gain(1, 1);

  mixer3.gain(0, 1);
  mixer3.gain(1, 1);

  envelope1.decay(100);
}

int counter = 0;

int originalAudioMemUsage = 0;

Pattern pattern;

void loop()
{
  update = false;
  int audioMemUsage = AudioMemoryUsageMax();
  if (audioMemUsage > originalAudioMemUsage)
  {
    Serial.println(audioMemUsage);
    originalAudioMemUsage = audioMemUsage;
  }

  HandleInputs();

  // if a character is sent from the serial monitor
  if (Serial.available())
  {
    Serial.read();
    Serial.println("Pressed a key in the serial monitor");
  }
}

void HandleInputs()
{
  encoder1Handler->handleButtonPress();
  encoder2Handler->handleButtonPress();
  encoder3Handler->handleButtonPress();
  encoder4Handler->handleButtonPress();
  encoder5Handler->handleButtonPress();
  encoder6Handler->handleButtonPress();
  encoder7Handler->handleButtonPress();
  encoder8Handler->handleButtonPress();

  int tempoValue = encoder8Handler->getPattern();

  if (metroOn)
  {
    if (metro.hasPassed(tempoValue))
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

    if (metro.hasPassed(tempoValue * 0.7))
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
        encoder1Handler->mode,
        metroOn,
        enc1Value,
        enc2Value,
        enc3Value,
        enc4Value,
        enc5Value,
        enc6Value,
        enc7Value,
        enc8Value);
         
    Serial.print("knobOne: ");
    int myValue = encoder1Handler->getPattern();
    Serial.print(bitRead(myValue,0));
    Serial.print(bitRead(myValue,1));
    Serial.print(bitRead(myValue,2));
    Serial.print(bitRead(myValue,3));
    Serial.print(bitRead(myValue,4));
    Serial.print(bitRead(myValue,5));
    Serial.print(bitRead(myValue,6));
    Serial.print(bitRead(myValue,7));

    Serial.println();

    // Serial.print("1: ");
    // Serial.print(enc1Value);
    // Serial.print(", 2: ");
    // Serial.print(enc2Value);
    // Serial.print(", 3: ");
    // Serial.print(enc3Value);
    // Serial.print(", 4: ");
    // Serial.print(enc4Value);
    // Serial.print(", 5: ");
    // Serial.print(enc5Value);
    // Serial.print(", 6: ");
    // Serial.print(enc6Value);
    // Serial.print(", 7: ");
    // Serial.print(enc7Value);
    // Serial.print(", 8: ");
    // Serial.print(enc8Value);
    Serial.println();
  }
}

const char *filelist[6] = {"BD1.WAV", "SN1.WAV", "HH1.WAV", "FOUR.WAV", "FIVE.WAV", "SIX.WAV"};
// const char *filelist[6] = {"ONE.WAV", "TWO.WAV", "THREE.WAV", "FOUR.WAV", "FIVE.WAV", "SIX.WAV"};

void noteHandling()
{
  // BD1.WAV
  if (bitRead(encoder1Handler->getPattern(), counter) == 1)
  {
    envelope1.noteOn();
    playSdWav1.play(filelist[0]);
  }
  // SN1.WAV
  if (bitRead(encoder2Handler->getPattern(), counter) == 1)
  {
    envelope2.noteOn();
    playSdWav2.play(filelist[1]);
  }
  // // HH1.WAV
  if (bitRead(encoder3Handler->getPattern(), counter) == 1)
  {
    envelope3.noteOn();
    playSdWav3.play(filelist[2]);
  }

  // BD2.WAV
  if (bitRead(encoder4Handler->getPattern(), counter) == 1)
  {
    envelope1.noteOn();
    playSdWav1.play(filelist[3]);
  }

  // SNR2.WAV
  if (bitRead(encoder5Handler->getPattern(), counter) == 1)
  {
    envelope1.noteOn();
    playSdWav1.play(filelist[4]);
  }

  // HH2.WAV
  if (bitRead(encoder6Handler->getPattern(), counter) == 1)
  {
    envelope1.noteOn();
    playSdWav1.play(filelist[5]);
  }
}
