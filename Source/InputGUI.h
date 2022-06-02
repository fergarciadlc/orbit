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
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;

    juce::Label inputLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputGUI)
};

