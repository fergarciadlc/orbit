/*
  ==============================================================================

    ProcessingGUI.h
    Created: 31 May 2022 11:04:03pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "knob.h"


class ProcessingGUI : public juce::Component
{
public:

    ProcessingGUI(OrbitAudioProcessor&);
    ~ProcessingGUI() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:

    OrbitAudioProcessor& audioProcessor;

    juce::Slider roomSize;
    juce::Slider damping;
    juce::Slider width;
    juce::Slider feedback;

    juce::Slider panningFrequency;
    juce::Slider panningWidth;

    Knob_LookAndFeel lookAndFeel;

    juce::TextButton bypassButton;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> roomSizeAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dampingAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> widthAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> bypassAttach;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> panningFrequencyAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> panningWidthAttach;

    juce::Label roomSizeLabel;
    juce::Label dampingLabel;
    juce::Label widthLabel;
    juce::Label feedbackLabel;

    juce::Label panningFrequencyLabel;
    juce::Label panningWidthLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProcessingGUI)
};