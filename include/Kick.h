/*
  Kick.h - Library for creating a Kick Synth.
  Created by David Thorpe 17th October 2021
*/
#ifndef KICK_H
#define KICK_H

#include <Arduino.h>
#include <Audio.h>

class Kick
{
public:
  Kick(
      AudioSynthSimpleDrum *idrum,
      AudioEffectWaveFolder *iwavefolder,
      AudioSynthWaveformDc *idc)
  {
    drum = idrum;
    wavefolder = iwavefolder;
    dc = idc;
  };

  void init();

  void noteOn();
  void noteOff();

  void setDrumFreq(float frequency);
  void setEnvLength(float length);
  void setWavefolderAmount(float modAmount);

private:
  AudioSynthSimpleDrum *drum;
  AudioEffectWaveFolder *wavefolder;
  AudioSynthWaveformDc *dc;
};

#endif
