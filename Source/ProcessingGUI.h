/*
  ==============================================================================

    ProcessingGUI.h
    Created: 31 May 2022 11:04:03pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class ProcessingGUI : public juce::Component
{
public:

    ProcessingGUI();
    ~ProcessingGUI() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:

    juce::Slider roomSize;
    juce::Slider damping;
    juce::Slider width;
    juce::Slider feedback;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProcessingGUI)
};