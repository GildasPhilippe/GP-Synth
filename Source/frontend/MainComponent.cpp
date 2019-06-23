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
    addAndMakeVisible(leftComponent);
    addAndMakeVisible(middleComponent);
    addAndMakeVisible(rightComponent);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{


    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);
}

void MainComponent::resized()
{
    int leftWidth(getWidth()*0.6);
    int rightWidth((getWidth()-leftWidth)*0.4);
    auto area = getLocalBounds();

    leftComponent.setBounds(area.removeFromLeft(leftWidth));
    rightComponent.setBounds(area.removeFromRight(rightWidth));
    middleComponent.setBounds(area);

}
