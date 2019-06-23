/*
  ==============================================================================

    ComboSelector.h
    Created: 23 Jun 2019 5:35:09pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

class ComboSelector    : public ComboBox
{
public:
    ComboSelector(String name, int width=100, int height=20);
    ~ComboSelector();

private:

    int comboHeight;
    int comboWidth;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboSelector)

};