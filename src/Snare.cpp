#include <Snare.h>

float WAVESHAPE_EXAMPLE[17] = {
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

void Snare::init()
{
  Serial.println(F("Snare init called"));
  (*drum).frequency(160);
  (*drum).pitchMod(0.5);
  (*drum).length(250);

  (*waveShaper).shape(WAVESHAPE_EXAMPLE, 17);
  (*noise).amplitude(0.19);
  (*filter).frequency(5000);
  (*env).attack(1);
  (*env).decay(80);
  (*env).sustain(0);
  (*env).release(80);
}

void Snare::noteOn()
{
  (*drum).noteOn();
  (*env).noteOn();
}

void Snare::noteOff()
{
  (*env).noteOff();
}

void Snare::setSkinLength(float length)
{
  (*drum).length(length);
}

void Snare::setEnvLength(float length)
{
  float newLength = length;
  (*env).decay(newLength);
  (*env).release(newLength);
}

void Snare::setNoiseAmp(float level)
{
  float newLevel = level * 0.01;
  (*noise).amplitude(newLevel);
}