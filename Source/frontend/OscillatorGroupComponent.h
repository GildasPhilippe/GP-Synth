/*
  ==============================================================================

    OscillatorGroupComponent.h
    Created: 23 Jun 2019 12:25:48pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "OscillatorComponent.h"
#include <vector>

//==============================================================================
/*
*/
class OscillatorGroupComponent    : public Component
{
public:
    OscillatorGroupComponent(AudioProcessorValueTreeState&);
    ~OscillatorGroupComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    std::vector<OscillatorComponent*> oscillatorComponents;

    AudioProcessorValueTreeState& valueTreeState;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorGroupComponent)
};
