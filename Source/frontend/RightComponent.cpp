/*
  ==============================================================================

    RightComponent.cpp
    Created: 23 Jun 2019 11:33:38am
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "RightComponent.h"

//==============================================================================
RightComponent::RightComponent()
{
    addAndMakeVisible(masterSlider);
    masterSlider.setSliderStyle(Slider::LinearVertical);
    masterSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);

    addAndMakeVisible(masterLabel);
    Font labelFont(16.0f);
    masterLabel.setText ("Master", dontSendNotification);
    masterLabel.setFont(labelFont);
    masterLabel.setJustificationType(Justification::centred);
}

RightComponent::~RightComponent()
{
}

void RightComponent::paint (Graphics& g)
{
}

void RightComponent::resized()
{
    int marginTop(10), marginBot(30);
    auto area = getLocalBounds();
    area.removeFromTop(marginTop);
    masterSlider.setBounds(area.removeFromTop(area.getHeight()-marginBot));
    masterLabel.setBounds(area);
}
