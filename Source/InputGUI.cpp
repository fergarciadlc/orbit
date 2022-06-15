/*
  ==============================================================================

    InputGUI.cpp
    Created: 31 May 2022 11:03:35pm
    Author:  Fernando

  ==============================================================================
*/


#include <JuceHeader.h>
#include "InputGUI.h"

InputGUI::InputGUI(OrbitAudioProcessor& p): audioProcessor(p)
{
    sliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "input_gain", inputSlider);
    addAndMakeVisible(inputLabel);
    inputSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    inputSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 0, 0);
    inputSlider.setLookAndFeel(&lookAndFeel);
    addAndMakeVisible(inputSlider);

    // Labels
    inputLabel.setText("Input", juce::NotificationType::dontSendNotification);
    //inputLabel.attachToComponent(&inputSlider, false);
    inputLabel.setJustificationType(juce::Justification::centred);

    bypassAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.apvts, "bypass", bypassButton);
    bypassButton.setButtonText("BYPASS");
    bypassButton.setClickingTogglesState(true);
    addAndMakeVisible(bypassButton);
}

InputGUI::~InputGUI()
{
    inputSlider.setLookAndFeel(nullptr);
}

void InputGUI::paint (juce::Graphics& g)
{
    //g.fillAll(juce::Colours::darkcyan);
    //g.fillAll(juce::Colours::darkcyan);
    g.fillAll(juce::PixelARGB(64, 24, 34, 58));
}

void InputGUI::resized()
{
    float diameter = 0.6f;
    inputSlider.setBoundsRelative(0.5f - diameter / 2, 0.5f - diameter / 2, diameter, diameter);
    inputLabel .setBoundsRelative(0.5f - diameter / 2, 0.325f - diameter / 2, diameter, diameter);

    bypassButton.setBoundsRelative(0.25f, 0.8f, 0.5f, 0.1f);
}
