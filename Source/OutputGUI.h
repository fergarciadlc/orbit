/*
  ==============================================================================

    OutputGUI.h
    Created: 31 May 2022 11:03:46pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class OutputGUI : public juce::Component
{
public:
    OutputGUI(OrbitAudioProcessor&);
    ~OutputGUI() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:

    OrbitAudioProcessor& audioProcessor;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> outputAttach;

    juce::Slider mixSlider;
    juce::Slider outputSlider;

    juce::Label mixtLabel;
    juce::Label outputLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutputGUI)
};
