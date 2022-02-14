#include <Kick.h>

void Kick::init()
{
  Serial.println(F("Kick init called"));
  (*drum).frequency(100);
  (*drum).pitchMod(0.7);
  (*drum).length(85);

  (*dc).amplitude(0.25);
}

void Kick::noteOn()
{
  (*drum).noteOn();
}

void Kick::setDrumFreq(float frequency)
{
  (*drum).frequency(frequency);
}

void Kick::setEnvLength(float length)
{
  (*drum).length(length);
}

void Kick::setWavefolderAmount(float modAmount)
{
  float newMod = modAmount * 0.01;
  (*dc).amplitude(newMod);
}
