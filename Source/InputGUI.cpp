/*
  ==============================================================================

    InputGUI.cpp
    Created: 31 May 2022 11:03:35pm
    Author:  Fernando

  ==============================================================================
*/


#include <JuceHeader.h>
#include "InputGUI.h"

InputGUI::InputGUI()
{
    inputSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    inputSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(inputSlider);
}

InputGUI::~InputGUI(){}

void InputGUI::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkcyan);
}

void InputGUI::resized()
{
    float diameter = 0.6f;
    inputSlider.setBoundsRelative(0.5f - diameter/2, 0.5f - diameter/2, diameter, diameter);
}
