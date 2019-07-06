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
    RightComponent(AudioProcessorValueTreeState&);
    ~RightComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    Slider masterSlider;
    Label masterLabel;

    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<SliderAttachment> gainAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RightComponent)
};
