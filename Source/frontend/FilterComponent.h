/*
  ==============================================================================

    FilterComponent.h
    Created: 25 Jun 2019 10:06:15pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "materials/Potentiometer.h"

//==============================================================================
/*
*/
class FilterComponent    : public Component
{
public:
    FilterComponent(String name);
    ~FilterComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    String filterName;

    Potentiometer freqPot;
    Potentiometer qPot;

    Label freqLabel;
    Label qLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
