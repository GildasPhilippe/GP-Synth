/*
  ==============================================================================

    LeftComponent.cpp
    Created: 23 Jun 2019 11:33:01am
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "LeftComponent.h"

//==============================================================================
LeftComponent::LeftComponent()
{
    addAndMakeVisible(oscillatorGroupComponent);
    addAndMakeVisible(filterGroupComponent);
}

LeftComponent::~LeftComponent()
{
}

void LeftComponent::paint (Graphics& g)
{
    g.fillAll (Colours::darkred);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);
}

void LeftComponent::resized()
{
    auto area = getLocalBounds();

    int oscillatorGroupHeight(getHeight()*0.65);
    oscillatorGroupComponent.setBounds(area.removeFromTop(oscillatorGroupHeight));
    filterGroupComponent.setBounds((area));

}
