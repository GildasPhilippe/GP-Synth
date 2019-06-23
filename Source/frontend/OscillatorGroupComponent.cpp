/*
  ==============================================================================

    OscillatorGroupComponent.cpp
    Created: 23 Jun 2019 12:25:48pm
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "OscillatorGroupComponent.h"

//==============================================================================
OscillatorGroupComponent::OscillatorGroupComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

OscillatorGroupComponent::~OscillatorGroupComponent()
{
}

void OscillatorGroupComponent::paint (Graphics& g)
{
    g.fillAll(Colours::lightsalmon);
    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);
}

void OscillatorGroupComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
