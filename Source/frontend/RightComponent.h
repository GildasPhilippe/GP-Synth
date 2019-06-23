/*
  ==============================================================================

    RightComponent.h
    Created: 23 Jun 2019 11:33:38am
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class RightComponent    : public Component
{
public:
    RightComponent();
    ~RightComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RightComponent)
};
