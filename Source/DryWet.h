/*
  ==============================================================================

    DryWet.h
    Created: 16 Jun 2022 12:45:29am
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class DryWet
{
public:
    
    DryWet();
    ~DryWet();
    
    void process(juce::AudioBuffer<float>& inBufferWet,
                 juce::AudioBuffer<float>& inBufferDry,
                 float inDryWet);
};
