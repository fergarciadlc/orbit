/*
  ==============================================================================

    ProcessingGUI.cpp
    Created: 31 May 2022 11:04:03pm
    Author:  Fernando

  ==============================================================================
*/

#include "ProcessingGUI.h"


ProcessingGUI::ProcessingGUI(OrbitAudioProcessor& p) : audioProcessor(p)
{

    roomSizeAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "rb_room_size", roomSize);
    roomSize.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    roomSize.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(roomSize);

    dampingAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "rb_damping", damping);
    damping.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    damping.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(damping);

    widthAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "rb_width", width);
    width.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    width.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(width);

    feedbackAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "rb_freeze", feedback);
    feedback.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    feedback.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(feedback);

    bypassAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.apvts, "bypass", bypassButton);
    bypassButton.setButtonText("Bypass");
    addAndMakeVisible(bypassButton);
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
    roomSize.setBoundsRelative(0.50f - bigDiameter   /2, 0.33f - bigDiameter   /2, bigDiameter,   bigDiameter);
    damping .setBoundsRelative(0.25f - smallDiameter /2, 0.66f - smallDiameter /2, smallDiameter, smallDiameter);
    width   .setBoundsRelative(0.50f - smallDiameter /2, 0.66f - smallDiameter /2, smallDiameter, smallDiameter); 
    feedback.setBoundsRelative(0.75f - smallDiameter /2, 0.66f - smallDiameter /2, smallDiameter, smallDiameter);

    bypassButton.setBoundsRelative(0.25f, 0.85f, 0.5f, 0.1f);
}

