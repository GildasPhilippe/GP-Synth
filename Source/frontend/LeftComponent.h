/*
  ==============================================================================

    LeftComponent.h
    Created: 23 Jun 2019 11:33:01am
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "OscillatorGroupComponent.h"
#include "FilterGroupComponent.h"

//==============================================================================
/*
*/
class LeftComponent    : public Component
{
public:
    LeftComponent(AudioProcessorValueTreeState&);
    ~LeftComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    OscillatorGroupComponent oscillatorGroupComponent;
    FilterGroupComponent filterGroupComponent;

    AudioProcessorValueTreeState& valueTreeState;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LeftComponent)
};
