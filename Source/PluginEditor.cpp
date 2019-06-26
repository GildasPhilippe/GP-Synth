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
    : AudioProcessorEditor (&p), processor (p), valueTreeState(vts),
      keyboardComponent (keyboardState, MidiKeyboardComponent::horizontalKeyboard)
{
    setSize (600, 370);
    /*
    addAndMakeVisible (gainSlider);
    gainAttachment.reset (new SliderAttachment (valueTreeState, "gain", gainSlider));
    */
    addAndMakeVisible (keyboardComponent);

    addAndMakeVisible(mainComponent);
}

GpsynthAudioProcessorEditor::~GpsynthAudioProcessorEditor()
{
}

//==============================================================================
void GpsynthAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void GpsynthAudioProcessorEditor::resized() {

    auto area = getLocalBounds();
    int keyboardComponentHeight(getHeight()*0.25);
    mainComponent.setBounds(area.removeFromTop(area.getHeight()-keyboardComponentHeight));
    area.removeFromTop(15);
    keyboardComponent.setBounds(area);

    /*
    auto r = getLocalBounds();
    auto gainRect = r.removeFromTop (50);
    gainLabel .setBounds (gainRect.removeFromLeft (50));
    gainSlider.setBounds (gainRect);
     */

}
