/*
  ==============================================================================

    SynthVoice.cpp
    Created: 22 Jun 2019 7:30:31pm
    Author:  Gildas

  ==============================================================================
*/

#include "SynthVoice.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

SynthVoice::SynthVoice(AudioProcessorValueTreeState& vts) : parameters(vts)
{
    //oscWaveform1 = parameters.getRawParameterValue ("oscWaveform1");
    //oscOctave1 = parameters.getRawParameterValue ("oscOctave1");
    //oscSemis1 = parameters.getRawParameterValue ("oscSemis1");
    oscLevel1 = parameters.getRawParameterValue ("oscLevel1");

    //oscWaveform2 = parameters.getRawParameterValue ("oscWaveform2");
    //oscOctave2 = parameters.getRawParameterValue ("oscOctave2");
    //oscSemis2 = parameters.getRawParameterValue ("oscSemis2");
    oscLevel2 = parameters.getRawParameterValue ("oscLevel2");

    //oscWaveform3 = parameters.getRawParameterValue ("oscWaveform3");
    //oscOctave3 = parameters.getRawParameterValue ("oscOctave3");
    //oscSemis3 = parameters.getRawParameterValue ("oscSemis3");
    oscLevel3 = parameters.getRawParameterValue ("oscLevel3");

    freqLC = parameters.getRawParameterValue ("freqLC");
    qLC = parameters.getRawParameterValue ("qLC");
    freqHC = parameters.getRawParameterValue ("freqHC");
    qHC = parameters.getRawParameterValue ("qHC");

    attack = parameters.getRawParameterValue ("attack");
    decay = parameters.getRawParameterValue ("decay");
    sustain = parameters.getRawParameterValue ("sustain");
    release = parameters.getRawParameterValue ("release");

    lfoWaveform = parameters.getRawParameterValue ("lfoWaveform");
    lfoSpeed = parameters.getRawParameterValue ("lfoSpeed");
    lfoLevel = parameters.getRawParameterValue ("lfoLevel");


}

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

    envelope.setAttack(static_cast<double>(*attack));
    envelope.setDecay(static_cast<double>(*decay));
    envelope.setSustain(static_cast<double>(*sustain));
    envelope.setRelease(static_cast<double>(*release));


    for(int sample = 0; sample < numSamples; ++sample){

        double sound1 = oscillator.square(frequency);

        double sound = sound1;

        //sound = lowFilter.hires(sound, static_cast<double>(*freqLC), static_cast<double>(*qLC));
        // pops :
        //sound = highFilter.lores(sound, static_cast<double>(*freqHC), static_cast<double>(*qHC));

        double lfo = getLfo(*lfoLevel, *lfoSpeed, (int)std::round(*lfoWaveform));
        sound = envelope.adsr(sound, envelope.trigger) *lfo * level;

        //std::cout << (int)std::round(*lfoWaveform) <<endl;



        for(int channel = 0; channel < outputBuffer.getNumChannels(); ++channel){
            outputBuffer.addSample(channel, startSample, sound);
        }
        ++startSample;
    }
}

double SynthVoice::getLfo (float level, float speed, int waveform) {
    double wave;
    switch(waveform) {
        case Waveform::sine:
            wave = lfoOscillator.sinewave(speed);
            break;
        case Waveform::triangle:
            wave = lfoOscillator.triangle(speed);
            break;
        case Waveform::square:
            wave = lfoOscillator.square(speed);
            break;
        case Waveform::saw:
            wave = lfoOscillator.saw(speed);
            break;
        default:
            wave = 0;
            break;
    }
    return 1 + level * wave;
}