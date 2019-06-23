/*
  ==============================================================================

    OscillatorComponent.cpp
    Created: 23 Jun 2019 3:55:16pm
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "OscillatorComponent.h"

#define SINE_ID 1
#define TRIANGLE_ID 2
#define SQUARE_ID 3
#define SAW_ID 4
#define NOISE_ID 5

//==============================================================================
OscillatorComponent::OscillatorComponent(int id) : oscId(id), waveformSelector("waveformSelector"+std::to_string(id))
{
    waveformSelector.addItem("Sine", SINE_ID);
    waveformSelector.addItem("Triangle", TRIANGLE_ID);
    waveformSelector.addItem("Square", SQUARE_ID);
    waveformSelector.addItem("Saw", SAW_ID);
    waveformSelector.addItem("Noise", NOISE_ID);
    waveformSelector.setSelectedId(SINE_ID);
    addAndMakeVisible(waveformSelector);
}

OscillatorComponent::~OscillatorComponent()
{
}

void OscillatorComponent::paint (Graphics& g)
{

    g.fillAll (Colours::chocolate);
    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);

    g.setColour (Colours::white);
    g.setFont (16.0f);
    g.drawText ("Osc"+std::to_string(oscId), getLocalBounds(),
                Justification::centredLeft, true);
}

void OscillatorComponent::resized()
{
    int textLenght(50);
    int comboBoxLenght(100), comboBoxHeight(20);
    int marginTop(10), marginBot(10), spaceMiddle(20);

    auto area = getBounds();
    area.removeFromLeft(textLenght);
    area.removeFromTop(marginTop);
    area.removeFromBottom(marginBot);

    auto comboBoxBounds = area.removeFromLeft(comboBoxLenght);
    int comboPaddings((comboBoxBounds.getHeight()-comboBoxHeight)/2);
    comboBoxBounds.removeFromTop(comboPaddings);
    comboBoxBounds.removeFromBottom(comboPaddings);
    waveformSelector.setBounds(comboBoxBounds);

    area.removeFromLeft(spaceMiddle);

    //int sliderSpace(area.getWidth()/3);

}
