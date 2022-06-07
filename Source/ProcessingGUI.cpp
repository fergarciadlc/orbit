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
    //labels
    addAndMakeVisible(roomSizeLabel);
    addAndMakeVisible(dampingLabel);
    addAndMakeVisible(widthLabel);
    addAndMakeVisible(feedbackLabel);

    addAndMakeVisible(panningFrequencyLabel);
    addAndMakeVisible(panningWidthLabel);

    // sliders
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

    panningFrequencyAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "panning_frequency", panningFrequency);
    panningFrequency.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    panningFrequency.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(panningFrequency);

    panningWidthAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "panning_width", panningWidth);
    panningWidth.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    panningWidth.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible(panningWidth);

    bypassAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.apvts, "bypass", bypassButton);
    bypassButton.setButtonText("BYPASS");
    bypassButton.setClickingTogglesState(true);
    addAndMakeVisible(bypassButton);

    // Labels 
    //addAndMakeVisible(roomSizeLabel); 
    roomSizeLabel.setText("Room Size", juce::NotificationType::dontSendNotification);
    //roomSizeLabel.attachToComponent(&roomSize, false); 
    roomSizeLabel.setJustificationType(juce::Justification::centred);

    //addAndMakeVisible(dampingLabel); 
    dampingLabel.setText("Damping", juce::NotificationType::dontSendNotification);
    //dampingLabel.attachToComponent(&damping, false); 
    dampingLabel.setJustificationType(juce::Justification::centred);

    //addAndMakeVisible(widthLabel);
    widthLabel.setText("Width", juce::NotificationType::dontSendNotification);
    //widthLabel.attachToComponent(&width, false); 
    widthLabel.setJustificationType(juce::Justification::centred);

    //addAndMakeVisible(feedbackLabel); 
    feedbackLabel.setText("Feedback", juce::NotificationType::dontSendNotification);
    //feedbackLabel.attachToComponent(&feedback, false); 
    feedbackLabel.setJustificationType(juce::Justification::centred);

    panningFrequencyLabel.setText("Spin", juce::NotificationType::dontSendNotification);
    panningFrequencyLabel.setJustificationType(juce::Justification::centred);

    panningWidthLabel.setText("Orbit", juce::NotificationType::dontSendNotification);
    panningWidthLabel.setJustificationType(juce::Justification::centred);


}

ProcessingGUI::~ProcessingGUI() {}

void ProcessingGUI::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::transparentBlack);
}

void ProcessingGUI::resized()
{
    float bigDiameter = 0.5f;
    float smallDiameter = 0.25f;
    roomSize.setBoundsRelative(0.50f - bigDiameter   /2, 0.33f - bigDiameter   /2, bigDiameter,   bigDiameter);
    damping .setBoundsRelative(0.25f - smallDiameter /2, 0.66f - smallDiameter /2, smallDiameter, smallDiameter);
    width   .setBoundsRelative(0.50f - smallDiameter /2, 0.66f - smallDiameter /2, smallDiameter, smallDiameter); 
    feedback.setBoundsRelative(0.75f - smallDiameter /2, 0.66f - smallDiameter /2, smallDiameter, smallDiameter);

    bypassButton.setBoundsRelative(0.33f, 0.025f, 0.33f, 0.1f);

    float controlsOffset = 0.10f;
    roomSizeLabel.setBoundsRelative(0.50f - bigDiameter   /2, 0.33f - bigDiameter   /2, bigDiameter,   bigDiameter);
    dampingLabel .setBoundsRelative(0.25f - smallDiameter /2, 0.66f - smallDiameter /2 + controlsOffset, smallDiameter, smallDiameter);
    widthLabel   .setBoundsRelative(0.50f - smallDiameter /2, 0.66f - smallDiameter /2 + controlsOffset, smallDiameter, smallDiameter);
    feedbackLabel.setBoundsRelative(0.75f - smallDiameter /2, 0.66f - smallDiameter /2 + controlsOffset, smallDiameter, smallDiameter);

    panningFrequency     .setBoundsRelative(0.5f - 0.125f - smallDiameter / 2, 0.8f - smallDiameter / 2 + controlsOffset, smallDiameter, smallDiameter);
    panningFrequencyLabel.setBoundsRelative(0.5f - 0.125f - smallDiameter / 2, 0.8f - smallDiameter / 2 + controlsOffset, smallDiameter, smallDiameter);
    
    panningWidth     .setBoundsRelative(0.5f + 0.125f - smallDiameter / 2, 0.8f - smallDiameter / 2 + controlsOffset, smallDiameter, smallDiameter);
    panningWidthLabel.setBoundsRelative(0.5f + 0.125f - smallDiameter / 2, 0.8f - smallDiameter / 2 + controlsOffset, smallDiameter, smallDiameter);

}

