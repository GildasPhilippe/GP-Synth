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
FilterGroupComponent::FilterGroupComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

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
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
