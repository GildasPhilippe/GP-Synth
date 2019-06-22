/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GpsynthAudioProcessorEditor::GpsynthAudioProcessorEditor (GpsynthAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState(vts)
{
    setSize (600, 400);
    addAndMakeVisible (gainSlider);
    gainAttachment.reset (new SliderAttachment (valueTreeState, "gain", gainSlider));
}

GpsynthAudioProcessorEditor::~GpsynthAudioProcessorEditor()
{
}

//==============================================================================
void GpsynthAudioProcessorEditor::paint (Graphics& g)
{

    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    /*
    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
     */
}

void GpsynthAudioProcessorEditor::resized() {

    auto r = getLocalBounds();
    auto gainRect = r.removeFromTop (50);
    gainLabel .setBounds (gainRect.removeFromLeft (50));
    gainSlider.setBounds (gainRect);

}
