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
#include "Waveforms.h"

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

    double getLfoWave (float level, float speed, int waveform);
    double getOscWave (int waveform, int octave, float semis, float level, maxiOsc& oscillator, double freq);

private:
    AudioProcessorValueTreeState& parameters;

    double level;
    double frequency;

    int noteNumber;
    maxiOsc osc1;
    maxiOsc osc2;
    maxiOsc osc3;
    maxiOsc lfoOscillator;
    maxiEnv envelope;
    maxiFilter lowFilter;
    maxiFilter highFilter;

    float* oscWaveform1 = nullptr; float* oscOctave1 = nullptr; float* oscSemis1 = nullptr; float* oscLevel1 = nullptr;
    float* oscWaveform2 = nullptr; float* oscOctave2 = nullptr; float* oscSemis2 = nullptr; float* oscLevel2 = nullptr;
    float* oscWaveform3 = nullptr; float* oscOctave3 = nullptr; float* oscSemis3 = nullptr; float* oscLevel3  = nullptr;
    float* freqLC = nullptr; float* freqHC = nullptr; float* qLC = nullptr; float* qHC = nullptr;
    float* attack = nullptr; float* decay = nullptr; float* sustain = nullptr; float* release = nullptr;
    float* lfoWaveform = nullptr; float* lfoSpeed = nullptr; float* lfoLevel = nullptr;
};