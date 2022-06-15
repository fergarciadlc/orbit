/*
  ==============================================================================

    knob.h
    Created: 14 Jun 2022 11:14:03pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Knob_LookAndFeel : public juce::LookAndFeel_V4
{
public:
    
    Knob_LookAndFeel();
    ~Knob_LookAndFeel();
    
    void drawRotarySlider(juce::Graphics& g,
                          int x, int y,
                          int width, int height,
                          float sliderPosProportional,
                          float rotaryStartAngle,
                          float rotaryEndAngle,
                          juce::Slider& slider) override;

private:
    
    juce::Image knobImage;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Knob_LookAndFeel)
};
