/*
  ==============================================================================

    LfoComponent.cpp
    Created: 26 Jun 2019 10:37:28pm
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "LfoComponent.h"


//==============================================================================
LfoComponent::LfoComponent(AudioProcessorValueTreeState& vts) : valueTreeState(vts),
                                                    waveformSelector("waveformLfo"),
                                                    speedPot("speedPot"),
                                                    levelPot("lfolevelPot")
{
    addAndMakeVisible(waveformSelector);
    waveformSelector.addItem("Sine", Waveform::sine);
    waveformSelector.addItem("Triangle", Waveform::triangle);
    waveformSelector.addItem("Square", Waveform::square);
    waveformSelector.addItem("Saw", Waveform::saw);
    waveformSelector.setSelectedId(Waveform::sine);

    addAndMakeVisible(speedPot);
    addAndMakeVisible(levelPot);

    addAndMakeVisible(speedLabel);
    addAndMakeVisible(levelLabel);

    Font labelFont(10.0f);

    speedLabel.setText ("Speed", dontSendNotification);
    speedLabel.setFont(labelFont);
    speedLabel.setJustificationType(Justification::centred);

    levelLabel.setText ("Level", dontSendNotification);
    levelLabel.setFont(labelFont);
    levelLabel.setJustificationType(Justification::centred);


    speedAttachment.reset (new SliderAttachment (valueTreeState, "lfoSpeed", speedPot));
    levelAttachment.reset (new SliderAttachment (valueTreeState, "lfoLevel", levelPot));
    waveformAttachment.reset (new ComboBoxAttachment (valueTreeState, "lfoWaveform", waveformSelector));
}

LfoComponent::~LfoComponent()
{
}

void LfoComponent::paint (Graphics& g)
{

    g.setColour (Colours::white);
    g.setFont (16.0f);
    g.drawText ("LFO", getLocalBounds(), Justification::centredTop, true);
}

void LfoComponent::resized()
{
    int textHeight(20), labelHeight(10), margin(10);
    int comboBoxWidth(100), comboBoxHeight(20);

    auto topArea = getLocalBounds();
    topArea.removeFromTop(textHeight);
    topArea.removeFromLeft(margin);
    topArea.removeFromRight(margin);
    auto botLeftArea = topArea.removeFromBottom(topArea.getHeight()*0.62);
    auto botRightArea = botLeftArea.removeFromRight(botLeftArea.getWidth()/2);

    int comboPaddingsTopBot((topArea.getHeight()-comboBoxHeight)/2);
    int comboPaddingsLeftRight((topArea.getWidth()-comboBoxWidth)/2);
    topArea.removeFromTop(comboPaddingsTopBot);
    topArea.removeFromBottom(comboPaddingsTopBot);
    topArea.removeFromLeft(comboPaddingsLeftRight);
    topArea.removeFromRight(comboPaddingsLeftRight);
    waveformSelector.setBounds(topArea);

    speedPot.setBounds(botLeftArea);
    levelPot.setBounds(botRightArea);

    speedLabel.setBounds(botLeftArea.removeFromBottom(labelHeight));
    levelLabel.setBounds(botRightArea.removeFromBottom(labelHeight));
}
