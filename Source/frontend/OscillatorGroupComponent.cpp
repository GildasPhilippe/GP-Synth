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
OscillatorGroupComponent::OscillatorGroupComponent(AudioProcessorValueTreeState& vts) : valueTreeState(vts)
{

    for(int i = 1; i<=3; ++i){
        OscillatorComponent* osc = new OscillatorComponent(i, vts);
        addAndMakeVisible(osc);
        oscillatorComponents.push_back(osc);
    }

}

OscillatorGroupComponent::~OscillatorGroupComponent()
{
    for(int i = 0; i<3; ++i){
        delete oscillatorComponents[i];
    }
}

void OscillatorGroupComponent::paint (Graphics& g)
{
}

void OscillatorGroupComponent::resized()
{
    auto area = getBounds();
    int oscillatorHeight = area.getHeight()/3;

    for(int i = 0; i<3; ++i){
        OscillatorComponent* osc = oscillatorComponents[i];
        osc->setBounds(area.removeFromTop(oscillatorHeight));
    }

}
