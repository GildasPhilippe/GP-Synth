/*
  ==============================================================================

    LfoComponent.h
    Created: 26 Jun 2019 10:37:28pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "materials/Potentiometer.h"
#include "materials/ComboSelector.h"

//==============================================================================
/*
*/
class LfoComponent    : public Component
{
public:
    LfoComponent();
    ~LfoComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    ComboSelector waveformSelector;
    Potentiometer speedPot;
    Potentiometer levelPot;

    Label speedLabel;
    Label levelLabel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LfoComponent)
};
