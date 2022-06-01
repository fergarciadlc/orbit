/*
  ==============================================================================

    OutputGUI.h
    Created: 31 May 2022 11:03:46pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

//==============================================================================
/*
*/
class OutputGUI : public juce::Component
{
public:
    OutputGUI();
    ~OutputGUI() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:

    juce::Slider mixSlider;
    juce::Slider outputSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutputGUI)
};
