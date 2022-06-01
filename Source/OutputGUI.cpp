/*
  ==============================================================================

    OutputGUI.cpp
    Created: 31 May 2022 11:03:46pm
    Author:  Fernando

  ==============================================================================
*/

#include "OutputGUI.h"


OutputGUI::OutputGUI()
{
    mixSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mixSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(mixSlider);

    outputSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    outputSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(outputSlider);
}

OutputGUI::~OutputGUI() {}

void OutputGUI::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::blue);
}

void OutputGUI::resized()
{
    float diameter = 0.6f;
    mixSlider   .setBoundsRelative(0.5f - diameter/2, 0.33f - diameter/2, diameter, diameter);
    outputSlider.setBoundsRelative(0.5f - diameter/2, 0.66f - diameter/2, diameter, diameter);
}

