/*
  MetalSynth.h - Library for creating a Metal Synth.
  Heavily inspired by https://tonejs.github.io/docs/14.7.77/MetalSynth
  Created by David Thorpe 17th October 2021
*/
#ifndef METALSYNTH_H
#define METALSYNTH_H

#include <Arduino.h>
#include <Audio.h>
#include <TwoOpFmSynth.h>

class MetalSynth
{
public:
  MetalSynth(
      TwoOpFmSynth *ifm1,
      TwoOpFmSynth *ifm2,
      TwoOpFmSynth *ifm3,
      TwoOpFmSynth *ifm4,
      TwoOpFmSynth *ifm5,
      AudioFilterStateVariable *ifilter,
      AudioEffectEnvelope *ifilterEnv,
      AudioEffectEnvelope *imainEnv,
      AudioSynthWaveformDc *idc)
  {
    fm1 = ifm1;
    fm2 = ifm2;
    fm3 = ifm4;
    fm4 = ifm4;
    fm5 = ifm5;
    filter = ifilter;
    filterEnv = ifilterEnv;
    mainEnv = imainEnv;
    dc = idc;
  };

  void init();

  void noteOn();
  void noteOff();

private:
  TwoOpFmSynth *fm1;
  TwoOpFmSynth *fm2;
  TwoOpFmSynth *fm3;
  TwoOpFmSynth *fm4;
  TwoOpFmSynth *fm5;
  AudioFilterStateVariable *filter;
  AudioEffectEnvelope *filterEnv;
  AudioEffectEnvelope *mainEnv;
  AudioSynthWaveformDc *dc;
};

#endif
