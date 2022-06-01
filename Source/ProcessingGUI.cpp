/*
  ==============================================================================

    ProcessingGUI.cpp
    Created: 31 May 2022 11:04:03pm
    Author:  Fernando

  ==============================================================================
*/

#include "ProcessingGUI.h"


ProcessingGUI::ProcessingGUI()
{
    roomSize.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    roomSize.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(roomSize);

    damping.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    damping.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(damping);

    roomSize.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    roomSize.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(roomSize);

    width.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    width.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(width);

    feedback.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    feedback.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(feedback);
}

ProcessingGUI::~ProcessingGUI() {}

void ProcessingGUI::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkturquoise);
}

void ProcessingGUI::resized()
{
    float bigDiameter = 0.5f;
    float smallDiameter = 0.25f;
    roomSize.setBoundsRelative(0.50f - bigDiameter   /2, 0.33f - bigDiameter   /2, bigDiameter, bigDiameter);
    width   .setBoundsRelative(0.50f - smallDiameter /2, 0.66f - smallDiameter /2, smallDiameter, smallDiameter);
    damping .setBoundsRelative(0.25f - smallDiameter /2, 0.66f - smallDiameter /2, smallDiameter, smallDiameter);
    feedback.setBoundsRelative(0.75f - smallDiameter /2, 0.66f - smallDiameter /2, smallDiameter, smallDiameter);
}

