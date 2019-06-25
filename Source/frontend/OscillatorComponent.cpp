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
OscillatorComponent::OscillatorComponent(int id) : oscId(id),
                        waveformSelector("waveform"+std::to_string(id)),
                        octavePot("octave"+std::to_string(id)),
                        semisPot("semis"+std::to_string(id)),
                        levelPot("level"+std::to_string(id))
{
    // Waveform selector

    addAndMakeVisible(waveformSelector);
    waveformSelector.addItem("Sine", SINE_ID);
    waveformSelector.addItem("Triangle", TRIANGLE_ID);
    waveformSelector.addItem("Square", SQUARE_ID);
    waveformSelector.addItem("Saw", SAW_ID);
    waveformSelector.addItem("Noise", NOISE_ID);
    waveformSelector.setSelectedId(SINE_ID);

    // Potentiometers

    addAndMakeVisible(octavePot);
    addAndMakeVisible(semisPot);
    addAndMakeVisible(levelPot);

    addAndMakeVisible(octaveLabel);
    addAndMakeVisible(semisLabel);
    addAndMakeVisible(levelLabel);

    //Potentiometers Label

    Font labelFont(10.0f);

    octaveLabel.setText ("Octave", dontSendNotification);
    octaveLabel.setFont(labelFont);
    octaveLabel.setJustificationType(Justification::centred);

    semisLabel.setText ("Semis", dontSendNotification);
    semisLabel.setFont(labelFont);
    semisLabel.setJustificationType(Justification::centred);

    levelLabel.setText ("Level", dontSendNotification);
    levelLabel.setFont(labelFont);
    levelLabel.setJustificationType(Justification::centred);
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
    g.drawText ("Osc"+std::to_string(oscId+1), getLocalBounds(),
                Justification::centredLeft, true);
}

void OscillatorComponent::resized()
{
    int textLenght(50);
    int comboBoxLenght(100), comboBoxHeight(20);
    int marginTop(0), marginBot(0), spaceMiddle(20);

    auto area = getLocalBounds();
    area.removeFromLeft(textLenght);
    area.removeFromTop(marginTop);
    area.removeFromBottom(marginBot);

    auto comboBoxBounds = area.removeFromLeft(comboBoxLenght);
    int comboPaddings((comboBoxBounds.getHeight()-comboBoxHeight)/2);
    comboBoxBounds.removeFromTop(comboPaddings);
    comboBoxBounds.removeFromBottom(comboPaddings);
    waveformSelector.setBounds(comboBoxBounds);

    area.removeFromLeft(spaceMiddle);
    int sliderSpace(area.getWidth()/3);


    auto potArea = area.removeFromLeft(sliderSpace);
    octavePot.setBounds(potArea);
    octaveLabel.setBounds(potArea.removeFromBottom(10));

    potArea = area.removeFromLeft(sliderSpace);
    semisPot.setBounds(potArea);
    semisLabel.setBounds(potArea.removeFromBottom(10));

    potArea = area.removeFromLeft(sliderSpace);
    levelPot.setBounds(potArea);
    levelLabel.setBounds(potArea.removeFromBottom(10));
}
