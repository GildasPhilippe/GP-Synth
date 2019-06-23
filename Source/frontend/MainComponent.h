/*
  ==============================================================================

    MainComponent.h
    Created: 23 Jun 2019 10:59:51am
    Author:  Gildas

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "LeftComponent.h"
#include "MiddleComponent.h"
#include "RightComponent.h"

//==============================================================================
/*
*/
class MainComponent    : public Component
{
public:
    MainComponent();
    ~MainComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    LeftComponent leftComponent;
    MiddleComponent middleComponent;
    RightComponent rightComponent;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
