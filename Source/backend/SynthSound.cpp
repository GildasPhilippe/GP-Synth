/*
  ==============================================================================

    SynthSound.cpp
    Created: 22 Jun 2019 7:30:09pm
    Author:  Gildas

  ==============================================================================
*/

#include "SynthSound.h"


bool SynthSound::appliesToNote(int midiNoteNumber) {
    return true;
}

bool SynthSound::appliesToChannel(int midiChannel) {
    return true;
}