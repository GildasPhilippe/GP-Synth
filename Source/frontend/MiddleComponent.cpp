/*
  ==============================================================================

    MiddleComponent.cpp
    Created: 23 Jun 2019 11:33:20am
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "MiddleComponent.h"

//==============================================================================
MiddleComponent::MiddleComponent(AudioProcessorValueTreeState& vts) : valueTreeState(vts),
                                        lfoComponent(vts),
                                        envelopeComponent(vts)
{
    addAndMakeVisible(envelopeComponent);
    addAndMakeVisible(lfoComponent);
}

MiddleComponent::~MiddleComponent()
{
}

void MiddleComponent::paint (Graphics& g)
{
}

void MiddleComponent::resized()
{
    int middleSpace(13);
    auto area = getLocalBounds();
    envelopeComponent.setBounds(area.removeFromTop(area.getHeight()*0.52));
    lfoComponent.setBounds(area.removeFromBottom(area.getHeight()-middleSpace));
}
