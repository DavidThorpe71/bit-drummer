#include <TwoOpFmSynth.h>

void TwoOpFmSynth::init()
{
  Serial.println(F("TwoOpFmSynth init called"));

  // setMainEnv(1, 35, 200);
  // setModEnv(1, 25, 300);
  (*op1).phaseModulation(180);
  (*op1).begin(1, 110, WAVEFORM_SINE);
  setMainFreq(110);
  (*op2).begin(1, 110, WAVEFORM_SINE);

  (*op2).phase(45);
  setModFreqRatio(2);
  // setModIndex(0.6);
}

void TwoOpFmSynth::setWaveform(int waveform)
{
  if (waveform == 1)
  {
    (*op1).begin(1, 110, WAVEFORM_SQUARE);
  }
  else
  {
    (*op1).begin(1, 110, WAVEFORM_SINE);
  }
}

void TwoOpFmSynth::setModWaveform(int waveform)
{
  if (waveform == 1)
  {
    (*op2).begin(1, 110, WAVEFORM_SQUARE);
  }
  else
  {
    (*op2).begin(1, 110, WAVEFORM_SINE);
  }
}

void TwoOpFmSynth::setMainFreq(float freq)
{
  // this->op1Freq = freq;
  this->mainFreq = freq;
  (*op1).frequency(freq);
}

void TwoOpFmSynth::setModFreqRatio(float ratio)
{
  float newFreq = this->mainFreq * ratio;
  Serial.print("New freq: ");
  Serial.println(newFreq);
  (*op2).frequency(newFreq);
}

void TwoOpFmSynth::setModIndex(float level)
{
  Serial.print("modIndex");
  Serial.println(level);
  (*modInAmp).gain(level);
}
