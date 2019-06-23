/*
  ==============================================================================

    OscillatorComponent.h
    Created: 23 Jun 2019 3:55:16pm
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
class OscillatorComponent    : public Component
{
public:
    OscillatorComponent(int id);
    ~OscillatorComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    int oscId;

    ComboSelector waveformSelector;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};
