/*
  ==============================================================================

    SynthSound.h
    Created: 22 Jun 2019 7:30:09pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) override;
    bool appliesToChannel (int midiChannel) override;

private:

};