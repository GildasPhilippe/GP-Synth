/*
  ==============================================================================

    OscillatorGroupComponent.h
    Created: 23 Jun 2019 12:25:48pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorGroupComponent)
};
