/*
  ==============================================================================

    OutputGUI.cpp
    Created: 31 May 2022 11:03:46pm
    Author:  Fernando

  ==============================================================================
*/

#include "OutputGUI.h"


OutputGUI::OutputGUI(OrbitAudioProcessor& p) : audioProcessor(p)
{

    //Labels
    addAndMakeVisible(outputLabel);
    addAndMakeVisible(mixtLabel);

    mixAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "rb_wet", mixSlider);
    mixSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mixSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    mixSlider.setLookAndFeel(&lookAndFeel);
    addAndMakeVisible(mixSlider);

    outputAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "output_gain", outputSlider);
    outputSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    outputSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    outputSlider.setLookAndFeel(&lookAndFeel);
    addAndMakeVisible(outputSlider);

    // Labels
    //addAndMakeVisible(mixtLabel);
    mixtLabel.setText("MIX", juce::NotificationType::dontSendNotification);
    //mixtLabel.attachToComponent(&mixSlider, false);
    mixtLabel.setJustificationType(juce::Justification::centred);

    //addAndMakeVisible(outputLabel);
    outputLabel.setText("Output", juce::NotificationType::dontSendNotification);
    //outputLabel.attachToComponent(&outputSlider, false);
    outputLabel.setJustificationType(juce::Justification::centred);
}

OutputGUI::~OutputGUI() 
{
    mixSlider.setLookAndFeel(nullptr);
    outputSlider.setLookAndFeel(nullptr);
}

void OutputGUI::paint(juce::Graphics& g)
{
    g.fillAll(juce::PixelARGB(64, 24,34,58));
    //g.fillAll(juce::Colours::darkcyan);
}

void OutputGUI::resized()
{
    float diameter = 0.6f;
    mixSlider   .setBoundsRelative(0.5f - diameter/2, 0.33f - diameter/2, diameter, diameter);
    outputSlider.setBoundsRelative(0.5f - diameter/2, 0.66f - diameter/2, diameter, diameter);

    mixtLabel  .setBoundsRelative(0.5f - diameter / 2, 0.33f - 0.15f - diameter / 2, diameter, diameter);
    outputLabel.setBoundsRelative(0.5f - diameter / 2, 0.66f - 0.15f - diameter / 2, diameter, diameter);
}

