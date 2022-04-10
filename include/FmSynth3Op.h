/*
  FmSynth3Op.h - Library for creating a 3 operator FM Synth.
  Created by David Thorpe 17th October 2021
*/
#ifndef FMSYNTH3OP_H
#define FMSYNTH3OP_H

#include <Arduino.h>
#include <Audio.h>

class FmSynth3Op
{
public:
  FmSynth3Op(
      AudioSynthWaveformModulated *iop1,
      AudioSynthWaveformModulated *iop2,
      AudioSynthWaveformModulated *iop3,
      AudioEffectEnvelope *iopEnv1,
      AudioEffectEnvelope *iopEnv2,
      AudioEffectEnvelope *iopEnv3,
      AudioMixer4 *imodOpsMixer);

  void init();

  void noteOn();
  void noteOff();

  void setOp1Freq(int freq);
  void setOp2FreqRatio(float ratio);
  void setOp3FreqRatio(float ratio);

  void setModAmountOp2to1(float modAmount);
  void setModAmountOp3to1(float modAmount);

  void setOp1Env(int decay);
  void setOp2Env(int decay);
  void setOp3Env(int decay);

private:
  AudioSynthWaveformModulated *op1;
  AudioSynthWaveformModulated *op2;
  AudioSynthWaveformModulated *op3;
  AudioEffectEnvelope *op1Env;
  AudioEffectEnvelope *op2Env;
  AudioEffectEnvelope *op3Env;
  AudioMixer4 *modOpsMixer;
  float op1Freq;
};

#endif
