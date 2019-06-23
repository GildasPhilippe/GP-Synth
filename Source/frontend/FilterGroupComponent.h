/*
  ==============================================================================

    FilterGroupComponent.h
    Created: 23 Jun 2019 12:26:29pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class FilterGroupComponent    : public Component
{
public:
    FilterGroupComponent();
    ~FilterGroupComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterGroupComponent)
};
