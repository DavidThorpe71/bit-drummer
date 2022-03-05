#include <FmSynth2Op.h>

FmSynth2Op::FmSynth2Op(
      AudioSynthWaveformModulated *iop1,
      AudioSynthWaveformModulated *iop2,
      AudioEffectEnvelope *iopEnv1)
  {
    op1 = iop1;
    op2 = iop2;
    op1Env = iopEnv1;
  };

void FmSynth2Op::init() {
    Serial.println(F("FmSynth init called"));

    setOp1Freq(220);
    setOp2FreqRatio(2);

    setOp2FreqRatio(0.6);

    setOp1Env(1, 35, 200);
}

void FmSynth2Op::noteOn() {
    op1Env->noteOn();
}

void FmSynth2Op::noteOff() {
    op1Env->noteOff();
}

void FmSynth2Op::setOp1Freq(float freq) {
    op1Freq = freq;
    op1->frequency(freq);
}

void FmSynth2Op::setOp2FreqRatio(float ratio) {
    op2->frequency(op1Freq * ratio);
}

void FmSynth2Op::setModAmount(int modAmount) {
    int scaledModAmount = 720 / 127;
    op1->phaseModulation(modAmount * scaledModAmount);
}

void FmSynth2Op::setOp1Env(float a, float d, float r) {
    op1Env->attack(a);
    op1Env->decay(d);
    op1Env->sustain(1);
    op1Env->release(r);
}