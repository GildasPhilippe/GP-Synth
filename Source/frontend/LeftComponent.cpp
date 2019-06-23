/*
  ==============================================================================

    LeftComponent.cpp
    Created: 23 Jun 2019 11:33:01am
    Author:  Gildas

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "LeftComponent.h"

//==============================================================================
LeftComponent::LeftComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

LeftComponent::~LeftComponent()
{
}

void LeftComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::darkred);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);
}

void LeftComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
