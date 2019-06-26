/*
  ==============================================================================

    MiddleComponent.h
    Created: 23 Jun 2019 11:33:20am
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "EnvelopeComponent.h"
#include "LfoComponent.h"

//==============================================================================
/*
*/
class MiddleComponent    : public Component
{
public:
    MiddleComponent();
    ~MiddleComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    EnvelopeComponent envelopeComponent;
    LfoComponent lfoComponent;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MiddleComponent)
};
