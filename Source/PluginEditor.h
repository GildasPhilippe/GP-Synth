/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "./frontend/MainComponent.h"

//==============================================================================
/**
*/
class GpsynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    GpsynthAudioProcessorEditor (GpsynthAudioProcessor&, AudioProcessorValueTreeState&);
    ~GpsynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GpsynthAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;

    MidiKeyboardState keyboardState;
    MidiKeyboardComponent keyboardComponent;

    MainComponent mainComponent;





    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

    Label gainLabel;
    Slider gainSlider;
    std::unique_ptr<SliderAttachment> gainAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GpsynthAudioProcessorEditor)
};