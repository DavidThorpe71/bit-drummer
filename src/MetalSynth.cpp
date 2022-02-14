#include <MetalSynth.h>

void MetalSynth::init()
{
  Serial.println("initialising metal synth");

  (*dc).amplitude(1);

  (*filterEnv).attack(1);
  (*filterEnv).decay(150);
  (*filterEnv).sustain(0);
  (*filterEnv).release(200);

  (*mainEnv).attack(1);
  (*mainEnv).decay(150);
  (*mainEnv).sustain(0);
  (*mainEnv).release(200);

  (*fm1).setWaveform(1);
  (*fm1).setModWaveform(1);
  (*fm1).setMainFreq(28);
  (*fm1).setModFreqRatio(1.483);
  (*fm1).setModIndex(32);

  (*fm2).setWaveform(1);
  (*fm2).setModWaveform(1);
  (*fm2).setMainFreq(28);
  (*fm2).setModFreqRatio(1.932);
  (*fm2).setModIndex(32);

  (*fm3).setWaveform(1);
  (*fm3).setModWaveform(1);
  (*fm3).setMainFreq(28);
  (*fm3).setModFreqRatio(2.546);
  (*fm3).setModIndex(32);

  (*fm4).setWaveform(1);
  (*fm4).setModWaveform(1);
  (*fm4).setMainFreq(28);
  (*fm4).setModFreqRatio(2.630);
  (*fm4).setModIndex(32);

  (*fm5).setWaveform(1);
  (*fm5).setModWaveform(1);
  (*fm5).setMainFreq(28);
  (*fm5).setModFreqRatio(3.897);
  (*fm5).setModIndex(32);
}

void MetalSynth::noteOn()
{
  // (*fm1).noteOn();
  // (*fm2).noteOn();
  // (*fm3).noteOn();
  // (*fm4).noteOn();
  // (*fm5).noteOn();
  (*filterEnv).noteOn();
  (*mainEnv).noteOn();
}

void MetalSynth::noteOff()
{
  // (*fm1).noteOff();
  // (*fm2).noteOff();
  // (*fm3).noteOff();
  // (*fm4).noteOff();
  // (*fm5).noteOff();
  (*filterEnv).noteOff();
  (*mainEnv).noteOff();
}