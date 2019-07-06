/*
  ==============================================================================

    SynthVoice.h
    Created: 22 Jun 2019 7:30:31pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "Maximilian/maximilian.h"
#include "SynthSound.h"

class SynthVoice : public SynthesiserVoice
{
public:
    SynthVoice (AudioProcessorValueTreeState&);
    bool canPlaySound (SynthesiserSound * sound) override;
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchWheelPosition) override;
    void stopNote (float velocity, bool allowTailOff) override ;
    void pitchWheelMoved (int newPitchWheelValue) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    void renderNextBlock (AudioBuffer< float > &outputBuffer, int startSample, int numSamples) override;

private:
    AudioProcessorValueTreeState& parameters;

    double level;
    double frequency;

    int noteNumber;
    maxiOsc oscillator;
    maxiEnv envelope;

    int* oscWaveform1 = nullptr; int* oscOctave1 = nullptr; int* oscSemis1 = nullptr; float* oscLevel1 = nullptr;
    int* oscWaveform2 = nullptr; int* oscOctave2 = nullptr; int* oscSemis2 = nullptr; float* oscLevel2 = nullptr;
    int* oscWaveform3 = nullptr; int* oscOctave3 = nullptr; int* oscSemis3 = nullptr; float* oscLevel3  = nullptr;
    int* freqLC = nullptr; int* freqHC = nullptr; float* qLC = nullptr; float* qHC = nullptr;
    float* attack = nullptr; float* decay = nullptr; float* sustain = nullptr; float* release = nullptr;
    int* lfoWaveform = nullptr; float* lfoSpeed = nullptr; float* lfoLevel = nullptr;
};