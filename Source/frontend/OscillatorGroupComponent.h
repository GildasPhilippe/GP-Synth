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
    OscillatorGroupComponent();
    ~OscillatorGroupComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    std::vector<OscillatorComponent*> oscillatorComponents;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorGroupComponent)
};
