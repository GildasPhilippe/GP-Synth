/*
  ==============================================================================

    PotLabel.cpp
    Created: 26 Jun 2019 10:54:17pm
    Author:  Gildas

  ==============================================================================
*/

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "PotLabel.h"

//==============================================================================
PotLabel::PotLabel(String text) : Label()
{
    Font labelFont(10.0f);
    setText (text, dontSendNotification);
    setFont(labelFont);
    setJustificationType(Justification::centred);
}

PotLabel::~PotLabel()
{
}

void PotLabel::paint (Graphics& g)
{
}

void PotLabel::resized()
{
}
