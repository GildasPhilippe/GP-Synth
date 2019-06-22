/*
  ==============================================================================

    SynthVoice.cpp
    Created: 22 Jun 2019 7:30:31pm
    Author:  Gildas

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(SynthesiserSound * sound) {
    return dynamic_cast <SynthSound*>(sound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchWheelPosition) {
    frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    level = velocity;
    envelope.trigger = 1;
}

void SynthVoice::stopNote(float velocity, bool allowTailOff) {
    envelope.trigger = 0;
    allowTailOff = true;
    if (velocity == 0)
        clearCurrentNote();
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue) {

}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue) {

}

void SynthVoice::renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples) {

    envelope.setAttack(attackTime);
    envelope.setDecay(500);
    envelope.setSustain(0.5);
    envelope.setRelease(2000);

    for(int sample = 0; sample < numSamples; ++sample){

        double wave = oscillator.sinewave(frequency) * level;
        double sound = envelope.adsr(wave, envelope.trigger) * level;

        for(int channel = 0; channel < outputBuffer.getNumChannels(); ++channel){
            outputBuffer.addSample(channel, startSample, sound);
        }
        ++startSample;
    }
}