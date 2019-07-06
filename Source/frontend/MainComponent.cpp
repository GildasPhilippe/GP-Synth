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
MainComponent::MainComponent(AudioProcessorValueTreeState& vts) : valueTreeState(vts),
                                    //leftComponent(vts),
                                    //middleComponent(vts),
                                    rightComponent(vts)
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
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    int marginTop(20), marginBot(10), marginLeft(5), marginRight(20);
    area.removeFromTop(marginTop);
    area.removeFromBottom(marginBot);
    area.removeFromLeft(marginLeft);
    area.removeFromRight(marginRight);

    int leftWidth(area.getWidth()*0.6);
    int rightWidth((area.getWidth()-leftWidth)*0.4);

    leftComponent.setBounds(area.removeFromLeft(leftWidth));
    rightComponent.setBounds(area.removeFromRight(rightWidth));
    middleComponent.setBounds(area);

}
