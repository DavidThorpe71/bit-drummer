/*
  FmSynth.h - Library for creating an FM Synth.
  Created by David Thorpe 17th October 2021
*/
#ifndef TWOOPFMSYNTH_H
#define TWOOPFMSYNTH_H

#include <Arduino.h>
#include <Audio.h>

class TwoOpFmSynth
{
public:
  TwoOpFmSynth(
      AudioSynthWaveformModulated *iop1,
      AudioSynthWaveform *iop2,
      AudioAmplifier *iModInAmp)
  {
    op1 = iop1;
    op2 = iop2;

    modInAmp = iModInAmp;
  };

  void init();

  void setWaveform(int waveform);
  void setModWaveform(int waveform);

  void setMainFreq(float freq);
  void setModFreqRatio(float ratio);

  void setModIndex(float level);

private:
  AudioSynthWaveformModulated *op1;
  AudioSynthWaveform *op2;
  AudioAmplifier *modInAmp;
  float mainFreq;
};

#endif
