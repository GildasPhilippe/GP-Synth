/*
  ==============================================================================

    EnvelopeComponent.cpp
    Created: 26 Jun 2019 10:37:06pm
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "EnvelopeComponent.h"

//==============================================================================
EnvelopeComponent::EnvelopeComponent() : attackPot("attackPot"),
                                        decayPot("decayPot"),
                                        sustainPot("sustainPot"),
                                        releasePot("releasePot")
{
    addAndMakeVisible(attackPot);
    addAndMakeVisible(decayPot);
    addAndMakeVisible(sustainPot);
    addAndMakeVisible(releasePot);

    addAndMakeVisible(attackLabel);
    addAndMakeVisible(decayLabel);
    addAndMakeVisible(sustainLabel);
    addAndMakeVisible(releaseLabel);

    Font labelFont(10.0f);

    attackLabel.setText ("Attack", dontSendNotification);
    attackLabel.setFont(labelFont);
    attackLabel.setJustificationType(Justification::centred);

    decayLabel.setText ("Decay", dontSendNotification);
    decayLabel.setFont(labelFont);
    decayLabel.setJustificationType(Justification::centred);

    sustainLabel.setText ("Sustain", dontSendNotification);
    sustainLabel.setFont(labelFont);
    sustainLabel.setJustificationType(Justification::centred);

    releaseLabel.setText ("Release", dontSendNotification);
    releaseLabel.setFont(labelFont);
    releaseLabel.setJustificationType(Justification::centred);
}

EnvelopeComponent::~EnvelopeComponent()
{
}

void EnvelopeComponent::paint (Graphics& g)
{
    g.setColour (Colours::white);
    g.setFont (16.0f);
    g.drawText ("Envelope", getLocalBounds(), Justification::centredTop, true);
}

void EnvelopeComponent::resized()
{
    int textHeight(12), labelHeight(10), margin(12);
    auto topLeftArea = getLocalBounds();
    topLeftArea.removeFromTop(textHeight);
    topLeftArea.removeFromLeft(margin);
    topLeftArea.removeFromRight(margin);
    topLeftArea.removeFromBottom(margin);
    auto botLeftArea = topLeftArea.removeFromBottom(topLeftArea.getHeight()/2);
    auto topRightArea = topLeftArea.removeFromRight(topLeftArea.getWidth()/2);
    auto botRightArea = botLeftArea.removeFromRight(botLeftArea.getWidth()/2);

    attackPot.setBounds(topLeftArea);
    decayPot.setBounds(topRightArea);
    sustainPot.setBounds(botLeftArea);
    releasePot.setBounds(botRightArea);

    attackLabel.setBounds(topLeftArea.removeFromBottom(labelHeight));
    decayLabel.setBounds((topRightArea.removeFromBottom(labelHeight)));
    sustainLabel.setBounds(botLeftArea.removeFromBottom(labelHeight));
    releaseLabel.setBounds(botRightArea.removeFromBottom(labelHeight));

}
