/*
  ThreeOpFmSynth.h - Library for creating an FM Synth.
  Created by David Thorpe 17th October 2021
*/
#ifndef THREEOPFMSYNTH_H
#define THREEOPFMSYNTH_H

#include <Arduino.h>
#include <Audio.h>

class ThreeOpFmSynth
{
public:
  ThreeOpFmSynth(
      AudioSynthWaveformModulated *iop1,
      AudioSynthWaveformModulated *iop2,
      AudioSynthWaveform *iop3,
      AudioEffectEnvelope *iopEnv1,
      AudioEffectEnvelope *iopEnv2,
      AudioEffectEnvelope *iopEnv3,
      AudioMixer4 *ioperatorOutMixer,
      AudioMixer4 *iop1FmInMixer,
      AudioAmplifier *iop2FmInAmp)
  {
    op1 = iop1;
    op2 = iop2;
    op3 = iop3;
    op1Env = iopEnv1;
    op2Env = iopEnv2;
    op3Env = iopEnv3;
    outputAmp = ioperatorOutMixer;
    op1FmInMixer = iop1FmInMixer;
    op2FmInAmp = iop2FmInAmp;
  };

  void init();

  void noteOn();
  void noteOff();

  void setOp1Freq(float freq);
  void setOp2FreqRatio(float ratio);
  void setOp3FreqRatio(float ratio);

  void setOp2ToOp1(float modAmount);
  void setOp3ToOp1(float modAmount);
  void setOp3ToOp2(float modAmount);

  void setOP1Env(float a, float d, float r);
  void setOP2Env(float a, float d, float r);
  void setOP3Env(float a, float d, float r);

  void setOP1Amp(float level);
  void setOP2Amp(float level);
  void setOP3Amp(float level);

private:
  AudioSynthWaveformModulated *op1;
  AudioSynthWaveformModulated *op2;
  AudioSynthWaveform *op3;
  AudioEffectEnvelope *op1Env;
  AudioEffectEnvelope *op2Env;
  AudioEffectEnvelope *op3Env;
  AudioMixer4 *outputAmp;
  AudioMixer4 *op1FmInMixer;
  AudioAmplifier *op2FmInAmp;
  float op1Freq;
};

#endif
