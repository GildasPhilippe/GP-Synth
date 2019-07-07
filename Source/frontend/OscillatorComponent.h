/*
  ==============================================================================

    OscillatorComponent.h
    Created: 23 Jun 2019 3:55:16pm
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "materials/Potentiometer.h"
#include "materials/ComboSelector.h"
#include "../backend/Waveforms.h"

//==============================================================================
/*
*/
class OscillatorComponent    : public Component
{
public:
    OscillatorComponent(int, AudioProcessorValueTreeState&);
    ~OscillatorComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    int oscId;

    ComboSelector waveformSelector;
    Potentiometer octavePot;
    Potentiometer semisPot;
    Potentiometer levelPot;

    Label octaveLabel;
    Label semisLabel;
    Label levelLabel;

    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
    AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<ComboBoxAttachment> waveformAttachment;
    std::unique_ptr<SliderAttachment> octaveAttachment;
    std::unique_ptr<SliderAttachment> semisAttachment;
    std::unique_ptr<SliderAttachment> levelAttachment;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};
