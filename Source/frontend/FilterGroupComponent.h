/*
  ==============================================================================

    FilterGroupComponent.h
    Created: 23 Jun 2019 12:26:29pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "FilterComponent.h"

//==============================================================================
/*
*/
class FilterGroupComponent    : public Component
{
public:
    FilterGroupComponent(AudioProcessorValueTreeState&);
    ~FilterGroupComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    FilterComponent lowCutComponent;
    FilterComponent highCutComponent;

    AudioProcessorValueTreeState& valueTreeState;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterGroupComponent)
};
