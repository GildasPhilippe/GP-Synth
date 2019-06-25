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
FilterComponent::FilterComponent(String name) : filterName(name), freqPot(name+"FreqPot"), qPot(name+"QPot")
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
}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::paint (Graphics& g)
{

    g.fillAll (Colours::darkkhaki);

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);

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
