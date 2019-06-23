/*
  ==============================================================================

    MainComponent.cpp
    Created: 23 Jun 2019 10:59:51am
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{


}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{


    g.fillAll (Colours::darkred);

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);
}

void MainComponent::resized()
{

}
