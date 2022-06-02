/*
  ==============================================================================

    Gain.h
    Created: 30 May 2022 11:25:15pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Gain
{
public:
    Gain();
    ~Gain();
    void process(juce::AudioBuffer<float>& inBuffer, float inGain);
};
