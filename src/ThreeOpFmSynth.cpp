#include <ThreeOpFmSynth.h>

void ThreeOpFmSynth::init()
{
  Serial.println(F("FmSynth init called"));

  setOp1Freq(220);
  setOp2FreqRatio(2);
  setOp3FreqRatio(8);

  setOp2ToOp1(0.6);
  setOp3ToOp1(4);
  setOp3ToOp2(200);

  setOP1Env(1, 35, 200);
  setOP2Env(1, 25, 25);
  setOP3Env(1, 50, 350);

  setOP1Amp(1);
  setOP2Amp(0);
  setOP3Amp(0);
}

void ThreeOpFmSynth::noteOn()
{
  (*op1Env).noteOn();
  (*op2Env).noteOn();
  (*op3Env).noteOn();
}

void ThreeOpFmSynth::noteOff()
{
  (*op1Env).noteOff();
  (*op2Env).noteOff();
  (*op3Env).noteOff();
}

void ThreeOpFmSynth::setOp1Freq(float freq)
{
  // this->op1Freq = freq;
  (*op1).frequency(freq);
}

void ThreeOpFmSynth::setOp2FreqRatio(float ratio)
{
  (*op2).frequency(250);
}

void ThreeOpFmSynth::setOp3FreqRatio(float ratio)
{
  (*op3).frequency(800);
}

void ThreeOpFmSynth::setOp2ToOp1(float modAmount)
{
  (*op1FmInMixer).gain(0, modAmount);
}

void ThreeOpFmSynth::setOp3ToOp1(float modAmount)
{
  (*op1FmInMixer).gain(1, modAmount);
}

void ThreeOpFmSynth::setOp3ToOp2(float modAmount)
{
  (*op2FmInAmp).gain(modAmount);
}

void ThreeOpFmSynth::setOP1Env(float a, float d, float r)
{
  (*op1Env).attack(a);
  (*op1Env).decay(d);
  (*op1Env).sustain(1);
  (*op1Env).release(r);
}

void ThreeOpFmSynth::setOP2Env(float a, float d, float r)
{
  (*op2Env).attack(a);
  (*op2Env).decay(d);
  (*op2Env).sustain(1);
  (*op2Env).release(r);
}

void ThreeOpFmSynth::setOP3Env(float a, float d, float r)
{
  (*op3Env).attack(a);
  (*op3Env).decay(d);
  (*op3Env).sustain(1);
  (*op3Env).release(r);
}

void ThreeOpFmSynth::setOP1Amp(float level)
{
  (*outputAmp).gain(0, level);
}

void ThreeOpFmSynth::setOP2Amp(float level)
{
  (*outputAmp).gain(1, level);
}

void ThreeOpFmSynth::setOP3Amp(float level)
{
  (*outputAmp).gain(2, level);
}

struct fmPreset
{
  float frequency;
  float c1ratio;
  float c2ratio;
  float c3ratio;
  float fm2to1;
  float fm3to1;
  float fm3to2;
  float c1release;
  float c2release;
  float c3release;
  float op1gain;
  float op2gain;
  float op3gain;
};

fmPreset preset1{
    50,
    1,
    651.727357609711,
    3,
    36387.8884887288,
    4908.63011871415,
    28358.0098706149,
    5,
    5,
    5,
    1,
    0,
    0};

fmPreset preset2{
    50,
    9,
    32,
    60,
    36387.8884887288,
    4908.63011871415,
    28358.0098706149,
    5,
    5,
    5,
    1,
    0,
    0};

fmPreset preset3{
    50,
    4,
    4,
    15,
    1000,
    4500,
    2500,
    3.63786832648871,
    2.25588424024641,
    3.1229863963039,
    1,
    1,
    1};
