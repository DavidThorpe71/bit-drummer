/*
  Snare.h - Library for creating a Snare Synth.
  Created by David Thorpe 17th October 2021
*/
#ifndef SNARE_H
#define SNARE_H

#include <Arduino.h>
#include <Audio.h>

class Snare
{
public:
  Snare(
      AudioSynthSimpleDrum *idrum,
      AudioSynthNoiseWhite *inoise,
      AudioFilterStateVariable *ifilter,
      AudioMixer4 *imixer,
      AudioEffectWaveshaper *iwaveShaper,
      AudioEffectEnvelope *ienv)
  {
    drum = idrum;
    noise = inoise;
    filter = ifilter;
    mixer = imixer;
    waveShaper = iwaveShaper;
    env = ienv;
  };

  void init();

  void noteOn();
  void noteOff();

  void setSkinLength(float length);
  void setEnvLength(float length);
  void setNoiseAmp(float level);

private:
  AudioSynthSimpleDrum *drum;
  AudioSynthNoiseWhite *noise;
  AudioFilterStateVariable *filter;
  AudioMixer4 *mixer;
  AudioEffectWaveshaper *waveShaper;
  AudioEffectEnvelope *env;
};

#endif
