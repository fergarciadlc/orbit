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

    juce::TextButton bypassButton;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> roomSizeAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dampingAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> widthAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> bypassAttach;

    juce::Label roomSizeLabel;
    juce::Label dampingLabel;
    juce::Label widthLabel;
    juce::Label feedbackLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProcessingGUI)
};