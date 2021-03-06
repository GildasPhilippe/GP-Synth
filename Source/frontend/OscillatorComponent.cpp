/*
  ==============================================================================

    OscillatorComponent.cpp
    Created: 23 Jun 2019 3:55:16pm
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "OscillatorComponent.h"


//==============================================================================
OscillatorComponent::OscillatorComponent(int id, AudioProcessorValueTreeState& vts) : valueTreeState(vts),
                                                oscId(id),
                                                waveformSelector("waveform"+std::to_string(id)),
                                                octavePot("octave"+std::to_string(id)),
                                                semisPot("semis"+std::to_string(id)),
                                                levelPot("level"+std::to_string(id))
{
    // Waveform selector

    addAndMakeVisible(waveformSelector);
    waveformSelector.addItem("Sine", Waveform::sine);
    waveformSelector.addItem("Triangle", Waveform::triangle);
    waveformSelector.addItem("Square", Waveform::square);
    waveformSelector.addItem("Saw", Waveform::saw);
    waveformSelector.addItem("Noise", Waveform::noise);
    waveformSelector.setSelectedId(Waveform::sine);

    // Potentiometers

    addAndMakeVisible(octavePot);
    addAndMakeVisible(semisPot);
    addAndMakeVisible(levelPot);

    addAndMakeVisible(octaveLabel);
    addAndMakeVisible(semisLabel);
    addAndMakeVisible(levelLabel);

    // Potentiometer Labels

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


    // Attachements

    waveformAttachment.reset (new ComboBoxAttachment (valueTreeState, "oscWaveform"+std::to_string(id), waveformSelector));
    octaveAttachment.reset (new SliderAttachment (valueTreeState, "oscOctave"+std::to_string(id), octavePot));
    semisAttachment.reset (new SliderAttachment (valueTreeState, "oscSemis"+std::to_string(id), semisPot));
    levelAttachment.reset (new SliderAttachment (valueTreeState, "oscLevel"+std::to_string(id), levelPot));

}

OscillatorComponent::~OscillatorComponent()
{
}

void OscillatorComponent::paint (Graphics& g)
{
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
