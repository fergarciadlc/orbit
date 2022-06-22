/*
  ==============================================================================

    LFOPanner.h
    Created: 5 Jun 2022 2:05:49am
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class lfoPanning
{
public:
    lfoPanning();
    ~lfoPanning();

    void prepare(juce::dsp::ProcessSpec spec);
    void process(juce::AudioBuffer<float>& inBuffer, 
                 float lfoFrequency, 
                 float panningAmplitude = 1.0f);

private:
    float sampleRate{ 0.0f };
    float PI = juce::MathConstants<float>::pi;
    float fase[2]{ 0.0f };
};