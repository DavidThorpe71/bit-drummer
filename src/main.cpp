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
#include <FmSynth2Op.h>
#include <BitDrumEncoderAbstract.h>
#include <EncoderHandler.h>
#include <MenuEncoderHandler.cpp>
#include <PatternEncoderHandler.cpp>
#include <TempoEncoderHandler.cpp>
#include <BitDrumPattern.h>
#include <BitDrumEncoder.cpp>

// GUItool: begin automatically generated code
AudioSynthWaveformModulated waveformMod2;   //xy=261.33331298828125,237.33331298828125
AudioSynthWaveformModulated waveformMod6; //xy=261.3332977294922,331
AudioSynthWaveformModulated waveformMod8; //xy=262.3332977294922,377
AudioSynthWaveformModulated waveformMod4; //xy=264.3332977294922,282
AudioSynthWaveformModulated waveformMod10; //xy=267.3332977294922,420
AudioSynthWaveformModulated waveformMod12; //xy=268.99998474121094,466
AudioSynthWaveformModulated waveformMod7; //xy=437.33331298828125,384
AudioSynthWaveformModulated waveformMod1;   //xy=441.33331298828125,246.33331298828125
AudioSynthWaveformModulated waveformMod3; //xy=442.33331298828125,296
AudioSynthWaveformModulated waveformMod5; //xy=443.33331298828125,338
AudioSynthWaveformModulated waveformMod9; //xy=443.33331298828125,430
AudioSynthWaveformModulated waveformMod11; //xy=445,476
AudioEffectEnvelope      envelope4;      //xy=603.888916015625,385.5556049346924
AudioEffectEnvelope      envelope2;      //xy=605.5555191040039,297.22220039367676
AudioEffectEnvelope      envelope1;      //xy=606.3333129882812,246.3333282470703
AudioEffectEnvelope      envelope3;      //xy=607.2222290039062,340.5555763244629
AudioEffectEnvelope      envelope5;      //xy=608.888916015625,430.5555486679077
AudioEffectEnvelope      envelope6;      //xy=610.5555419921875,475.55550956726074
AudioMixer4              mixer2;         //xy=810.5555648803711,362.22218322753906
AudioMixer4              mixer1;         //xy=812.2222696940103,285.5555076599121
AudioMixer4              mixer3;         //xy=960.5556945800781,315.55550765991217
AudioOutputI2S           i2s1;           //xy=1125.3334503173828,317.66662979125977
AudioConnection          patchCord1(waveformMod2, 0, waveformMod1, 0);
AudioConnection          patchCord2(waveformMod6, 0, waveformMod5, 0);
AudioConnection          patchCord3(waveformMod8, 0, waveformMod7, 0);
AudioConnection          patchCord4(waveformMod4, 0, waveformMod3, 0);
AudioConnection          patchCord5(waveformMod10, 0, waveformMod9, 0);
AudioConnection          patchCord6(waveformMod12, 0, waveformMod11, 0);
AudioConnection          patchCord7(waveformMod7, envelope4);
AudioConnection          patchCord8(waveformMod1, envelope1);
AudioConnection          patchCord9(waveformMod3, envelope2);
AudioConnection          patchCord10(waveformMod5, envelope3);
AudioConnection          patchCord11(waveformMod9, envelope5);
AudioConnection          patchCord12(waveformMod11, envelope6);
AudioConnection          patchCord13(envelope4, 0, mixer1, 3);
AudioConnection          patchCord14(envelope2, 0, mixer1, 1);
AudioConnection          patchCord15(envelope1, 0, mixer1, 0);
AudioConnection          patchCord16(envelope3, 0, mixer1, 2);
AudioConnection          patchCord17(envelope5, 0, mixer2, 0);
AudioConnection          patchCord18(envelope6, 0, mixer2, 1);
AudioConnection          patchCord19(mixer2, 0, mixer3, 1);
AudioConnection          patchCord20(mixer1, 0, mixer3, 0);
AudioConnection          patchCord21(mixer3, 0, i2s1, 0);
AudioConnection          patchCord22(mixer3, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=667.3333129882812,27.333335876464844
// GUItool: end automatically generated code


// PIN SETUP
Encoder knobOne(0, 1);
Encoder knobTwo(2, 3);
Encoder knobThree(4, 5);
Encoder knobFour(24, 25);
Encoder knobFive(26, 27);
Encoder knobSix(28, 29);
Encoder knobSeven(31, 30);
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
int mode = 0;
bool update = false;
BitDrumPattern pattern;

BitDrumEncoderAbstract* encoder1 = new BitDrumEncoder(&knobOne, &bounce1);
PatternEncoderHandler* encoder1Handler = new PatternEncoderHandler(encoder1, pattern, 127, &update, &mode);

BitDrumEncoderAbstract* encoder2 = new BitDrumEncoder(&knobTwo, &bounce2);
PatternEncoderHandler* encoder2Handler = new PatternEncoderHandler(encoder2, pattern, 127, &update, &mode);

BitDrumEncoderAbstract* encoder3 = new BitDrumEncoder(&knobThree, &bounce3);
PatternEncoderHandler* encoder3Handler = new PatternEncoderHandler(encoder3, pattern, 127, &update, &mode);

BitDrumEncoderAbstract* encoder4 = new BitDrumEncoder(&knobFour, &bounce4);
PatternEncoderHandler* encoder4Handler = new PatternEncoderHandler(encoder4, pattern, 127, &update, &mode);

BitDrumEncoderAbstract* encoder5 = new BitDrumEncoder(&knobFive, &bounce5);
PatternEncoderHandler* encoder5Handler = new PatternEncoderHandler(encoder5, pattern, 127, &update, &mode);

BitDrumEncoderAbstract* encoder6 = new BitDrumEncoder(&knobSix, &bounce6);
PatternEncoderHandler* encoder6Handler = new PatternEncoderHandler(encoder6, pattern, 127, &update, &mode);

BitDrumEncoderAbstract* encoder7 = new BitDrumEncoder(&knobSeven, &bounce7);
MenuEncoderHandler* encoder7Handler = new MenuEncoderHandler(encoder7, pattern, &mode, 9, &update);

BitDrumEncoderAbstract* encoder8 = new BitDrumEncoder(&knobEight, &bounce8);
TempoEncoderHandler* encoder8Handler = new TempoEncoderHandler(encoder8, pattern, &metroOn, 2000, &update);

FmSynth2Op* fmSynth1 = new FmSynth2Op(&waveformMod1, &waveformMod2, &envelope1);

void HandleInputs();

void initialiseEncoders();

void setupSdPlayer();

void setupMixer();

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
  initialiseEncoders();
}

void initialiseEncoders() {
  encoder8->write(250); 
  encoder8Handler->handleEncoderTurn();
  Serial.println("encoder 8 setup successfully");
  Serial.print("encode 8 value: ");
  Serial.println(encoder8->read());
  // encoder8Handler = new TempoEncoderHandler(encoder8, pattern, &metroOn, 1000, &update);
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
}

 int oldMode = 0;

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

  encoder1Handler->handleEncoderTurn();
  encoder2Handler->handleEncoderTurn();
  encoder3Handler->handleEncoderTurn();
  encoder4Handler->handleEncoderTurn();
  encoder5Handler->handleEncoderTurn();
  encoder6Handler->handleEncoderTurn();
  encoder7Handler->handleEncoderTurn();
  encoder8Handler->handleEncoderTurn();
  
 
  if (oldMode != mode) {
    encoder1Handler->changeMode();
    encoder2Handler->changeMode();
    encoder3Handler->changeMode();
    encoder4Handler->changeMode();
    encoder5Handler->changeMode();
    encoder6Handler->changeMode();

    oldMode = mode;
  }
  // encoder7Handler->changeMode();
  // encoder8Handler->handleEncoderTurn();

  int tempoValue = encoder8Handler->getPattern();

  if (metroOn)
  {
    if (metro.hasPassed(tempoValue))
    {
      metro.restart(); // Restart the chronometer.

      counter++;

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
        mode,
        metroOn,
        encoder1Handler->getEncoderModeValue(),
        encoder2Handler->getEncoderModeValue(),
        encoder3Handler->getEncoderModeValue(),
        encoder4Handler->getEncoderModeValue(),
        encoder5Handler->getEncoderModeValue(),
        encoder6Handler->getEncoderModeValue(),
        encoder7Handler->getPattern(),
        encoder8Handler->getPattern());
    // display.displayEncoders(0, false, 0, 0, 0, 0, 0, 0, 0, 0);
         
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
  if (bitRead(encoder1Handler->getPattern(), (counter % encoder1Handler->getLoopLength()) % 8) == 1)
  {
    envelope1.noteOn();
    playSdWav1.play(filelist[0]);
  }
  // SN1.WAV
  if (bitRead(encoder2Handler->getPattern(), (counter % encoder2Handler->getLoopLength()) % 8) == 1)
  {
    envelope2.noteOn();
    playSdWav2.play(filelist[1]);
  }
  // // HH1.WAV
  if (bitRead(encoder3Handler->getPattern(), (counter % encoder3Handler->getLoopLength()) % 8) == 1)
  {
    envelope3.noteOn();
    playSdWav3.play(filelist[2]);
  }

  // BD2.WAV
  if (bitRead(encoder4Handler->getPattern(), (counter % encoder4Handler->getLoopLength()) % 8) == 1)
  {
    envelope1.noteOn();
    playSdWav1.play(filelist[3]);
  }

  // SNR2.WAV
  if (bitRead(encoder5Handler->getPattern(), (counter % encoder5Handler->getLoopLength()) % 8) == 1)
  {
    envelope1.noteOn();
    playSdWav1.play(filelist[4]);
  }

  // HH2.WAV
  if (bitRead(encoder6Handler->getPattern(), (counter % encoder6Handler->getLoopLength()) % 8) == 1)
  {
    envelope1.noteOn();
    playSdWav1.play(filelist[5]);
  }
}
