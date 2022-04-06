#include <FmSynth2Op.h>

float notesArray[101] = {
  16.35, 17.32, 18.35, 19.45, 20.60,
  21.83, 23.12, 24.50, 25.96, 27.50,
  29.14, 30.87, 32.70, 34.65, 36.71,
  38.89, 41.20, 43.65, 46.25, 49.00,
  51.91, 55.00, 58.27, 61.74, 65.41,
  69.30, 73.42, 77.78, 82.41, 87.31,
  92.50, 98.00, 103.83, 110.00, 116.54,
  123.47, 130.81, 138.59, 146.83, 155.56,
  164.81, 174.61, 185.00, 196.00, 207.65,
  220.00, 233.08, 246.94, 261.63, 277.18,
  293.66, 311.13, 329.63, 349.23, 369.99,
  392.00, 415.30, 440.00, 466.16, 493.88,
  523.25, 554.37, 587.33, 622.25, 659.26,
  698.46, 739.99, 783.99, 830.61, 880.00,
  932.33, 987.77, 1046.50, 1108.73, 1174.66,
  1244.51, 1318.51, 1396.91, 1479.98, 1567.98,
  1661.22, 1760.00, 1864.66, 1975.53, 2093.00,
  2217.46, 2349.32, 2489.02, 2637.02, 2793.83,
  2959.96, 3135.96, 3322.44, 3520.00, 3729.31,
  3951.07, 4186.01, 4434.92, 4434.92, 4698.64,
  4978.03
};

FmSynth2Op::FmSynth2Op(
      AudioSynthWaveformModulated *iop1,
      AudioSynthWaveformModulated *iop2,
      AudioEffectEnvelope *iopEnv1,
      AudioEffectEnvelope *iopEnv2)
  {
    Serial.println("FMSynth2Op initialised");
    op1 = iop1;
    op2 = iop2;
    op1Env = iopEnv1;
    op2Env = iopEnv2;
  };

void FmSynth2Op::init() {
    op1->begin(WAVEFORM_SINE);
    op2->begin(WAVEFORM_SINE);
    op1->amplitude(1);
    op2->amplitude(1);
}

void FmSynth2Op::noteOn() {
    Serial.println("FMSynth2Op noteOn");
    op2Env->noteOn();
    op1Env->noteOn();
}

void FmSynth2Op::noteOff() {
    op2Env->noteOff();
    op1Env->noteOff();
}

void FmSynth2Op::setOp1Freq(int freq) {
    op1Freq = notesArray[freq];
    Serial.print("FMSynth2Op op1Freq: ");
    Serial.println(op1Freq);
    op1->frequency(notesArray[freq]);
}

void FmSynth2Op::setOp2FreqRatio(int ratio) {
    float scaledValue = ratio / 10;
    Serial.print("FMSynth2Op op2Freq: ");
    Serial.println(op1Freq * scaledValue);
    op2->frequency(op1Freq * scaledValue);
}

void FmSynth2Op::setModAmount(int modAmount) {
    int scaledModAmount = 720 / 127;
    Serial.print("FMSynth2Op modAmount: ");
    Serial.println(modAmount * scaledModAmount);
    op1->phaseModulation(modAmount * scaledModAmount);
}

void FmSynth2Op::setOp1Env(int decay) {
    int scaledValue = 500 / 127;
    Serial.print("FMSynth2Op decay: ");
    Serial.print(scaledValue * decay + 1);

    op1Env->attack(1);
    op1Env->decay(scaledValue * decay + 1);
    op1Env->sustain(0);
    op1Env->release(scaledValue * decay + 1);
}

void FmSynth2Op::setOp2Env(int decay) {
    int scaledValue = 500 / 127;
    Serial.print("FMSynth2Op Mod decay: ");
    Serial.print(scaledValue * decay + 1);

    op2Env->attack(1);
    op2Env->decay(scaledValue * decay + 1);
    op2Env->sustain(0);
    op2Env->release(scaledValue * decay + 1);
}