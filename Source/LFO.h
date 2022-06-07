/*
  ==============================================================================

    LFO.h
    Created: 5 Jun 2022 2:02:49am
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class LFO
{
public:
    LFO();
    ~LFO();
    
    void prepare(juce::dsp::ProcessSpec spec);
    void process(juce::AudioBuffer<float>& inBuffer, float inRate);
private:
    float sampleRate{ 0.0f };
    float PI = juce::MathConstants<float>::pi;
    float fase[2]{ 0.0f };
};
