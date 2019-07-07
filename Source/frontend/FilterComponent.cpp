/*
  ==============================================================================

    FilterComponent.cpp
    Created: 25 Jun 2019 10:06:16pm
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent(AudioProcessorValueTreeState& vts, String name) :
                                                            valueTreeState(vts),
                                                            filterName(name),
                                                            freqPot(name+"FreqPot"),
                                                            qPot(name+"QPot")
{
    addAndMakeVisible(freqPot);
    addAndMakeVisible(qPot);
    addAndMakeVisible(freqLabel);
    addAndMakeVisible(qLabel);

    Font labelFont(10.0f);

    freqLabel.setText ("freq", dontSendNotification);
    freqLabel.setFont(labelFont);
    freqLabel.setJustificationType(Justification::centred);

    qLabel.setText ("Q", dontSendNotification);
    qLabel.setFont(labelFont);
    qLabel.setJustificationType(Justification::centred);


    freqAttachment.reset (new SliderAttachment (valueTreeState, "freq"+name, freqPot));
    qAttachment.reset (new SliderAttachment (valueTreeState, "q"+name, qPot));
}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::paint (Graphics& g)
{
    g.setColour (Colours::white);
    g.setFont (16.0f);
    g.drawText (filterName, getLocalBounds(), Justification::centredTop, true);
}

void FilterComponent::resized()
{
    int textHeight(18);
    auto leftArea = getLocalBounds();
    leftArea.removeFromTop(textHeight);
    auto rightArea = leftArea.removeFromRight(leftArea.getWidth()/2);

    freqPot.setBounds(leftArea);
    freqLabel.setBounds(leftArea.removeFromBottom(10));
    qPot.setBounds(rightArea);
    qLabel.setBounds(rightArea.removeFromBottom(10));
}
