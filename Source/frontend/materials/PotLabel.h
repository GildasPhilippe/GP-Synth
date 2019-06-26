/*
  ==============================================================================

    PotLabel.h
    Created: 26 Jun 2019 10:54:17pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class PotLabel    : public Label
{
public:
    PotLabel(String text);
    ~PotLabel();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PotLabel)
};
