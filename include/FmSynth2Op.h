/*
  FmSynth.h - Library for creating an FM Synth.
  Created by David Thorpe 17th October 2021
*/
#ifndef FMSYNTH2OP_H
#define FMSYNTH2OP_H

#include <Arduino.h>
#include <Audio.h>

class FmSynth2Op
{
public:
  FmSynth2Op(
      AudioSynthWaveformModulated *iop1,
      AudioSynthWaveformModulated *iop2,
      AudioEffectEnvelope *iopEnv1,
      AudioEffectEnvelope *iopEnv2);

  void init();

  void noteOn();
  void noteOff();

  void setOp1Freq(int freq);
  void setOp2FreqRatio(int ratio);

  void setModAmount(int modAmount);

  void setOp1Env(int decay);

  void setOp2Env(int decay);


private:
  AudioSynthWaveformModulated *op1;
  AudioSynthWaveformModulated *op2;
  AudioEffectEnvelope *op1Env;
  AudioEffectEnvelope *op2Env;
  float op1Freq;
};

#endif
