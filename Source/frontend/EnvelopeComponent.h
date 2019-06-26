/*
  ==============================================================================

    EnvelopeComponent.h
    Created: 26 Jun 2019 10:37:06pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "materials/Potentiometer.h"
#include "materials/PotLabel.h"

//==============================================================================
/*
*/
class EnvelopeComponent    : public Component
{
public:
    EnvelopeComponent();
    ~EnvelopeComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    Potentiometer attackPot;
    Potentiometer decayPot;
    Potentiometer sustainPot;
    Potentiometer releasePot;

    Label attackLabel;
    Label decayLabel;
    Label sustainLabel;
    Label releaseLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeComponent)
};
