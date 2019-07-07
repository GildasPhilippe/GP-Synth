/*
  ==============================================================================

    LfoComponent.h
    Created: 26 Jun 2019 10:37:28pm
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
class LfoComponent : public Component {
public:
    LfoComponent(AudioProcessorValueTreeState&);
    ~LfoComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    ComboSelector waveformSelector;
    Potentiometer speedPot;
    Potentiometer levelPot;

    Label speedLabel;
    Label levelLabel;

    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
    AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<SliderAttachment> speedAttachment;
    std::unique_ptr<SliderAttachment> levelAttachment;
    std::unique_ptr<ComboBoxAttachment> waveformAttachment;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LfoComponent)
};
