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
    bool canPlaySound (SynthesiserSound * sound) override;
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchWheelPosition) override;
    void stopNote (float velocity, bool allowTailOff) override ;
    void pitchWheelMoved (int newPitchWheelValue) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    void renderNextBlock (AudioBuffer< float > &outputBuffer, int startSample, int numSamples) override;

private:
    double level;
    double frequency;

    int noteNumber;
    maxiOsc oscillator;
    maxiEnv envelope;

    float attackTime;
};