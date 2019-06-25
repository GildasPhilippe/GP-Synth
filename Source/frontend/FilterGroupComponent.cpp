/*
  ==============================================================================

    FilterGroupComponent.cpp
    Created: 23 Jun 2019 12:26:29pm
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "FilterGroupComponent.h"

//==============================================================================
FilterGroupComponent::FilterGroupComponent() : lowCutComponent("LowCut"), highCutComponent("HighCut")
{
    addAndMakeVisible(lowCutComponent);
    addAndMakeVisible(highCutComponent);
}

FilterGroupComponent::~FilterGroupComponent()
{
}

void FilterGroupComponent::paint (Graphics& g)
{
    g.fillAll(Colours::lightblue);
    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);
}

void FilterGroupComponent::resized()
{
    int marginSide(30), marginTop(12);
    auto areaLeft = getLocalBounds();
    areaLeft.removeFromTop(marginTop);
    auto areaRight = areaLeft.removeFromRight(areaLeft.getWidth()/2);

    areaLeft.removeFromLeft(marginSide);
    areaLeft.removeFromRight(marginSide);
    areaRight.removeFromLeft(marginSide);
    areaRight.removeFromRight(marginSide);

    lowCutComponent.setBounds(areaLeft);
    highCutComponent.setBounds(areaRight);
}
