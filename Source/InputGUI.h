/*
  ==============================================================================

    InputGUI.h
    Created: 31 May 2022 11:03:35pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "knob.h"

class InputGUI  : public juce::Component
{
public:
    
    InputGUI(OrbitAudioProcessor&);
    ~InputGUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;


private:
    
    OrbitAudioProcessor& audioProcessor;

    juce::Slider inputSlider;
    juce::TextButton bypassButton;

    Knob_LookAndFeel lookAndFeel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> bypassAttach;

    juce::Label inputLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputGUI)
};

