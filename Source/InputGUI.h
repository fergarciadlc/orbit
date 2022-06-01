/*
  ==============================================================================

    InputGUI.h
    Created: 31 May 2022 11:03:35pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class InputGUI  : public juce::Component
{
public:
    
    InputGUI();
    ~InputGUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::Slider inputSlider;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputGUI)
};

