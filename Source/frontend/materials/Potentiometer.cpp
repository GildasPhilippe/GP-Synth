/*
  ==============================================================================

    Potentiometer.cpp
    Created: 23 Jun 2019 5:34:54pm
    Author:  Gildas

  ==============================================================================
*/

#include "Potentiometer.h"

Potentiometer::Potentiometer(String name) : Slider(name)
{
    setSliderStyle(Slider::RotaryVerticalDrag);
    //setRotaryParameters();
    setMouseDragSensitivity(80);
    setTextBoxStyle(TextEntryBoxPosition::TextBoxBelow, true, 0, 0);
}


Potentiometer::~Potentiometer()
{
}
