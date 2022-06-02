/*
  ==============================================================================

    Gain.cpp
    Created: 30 May 2022 11:25:15pm
    Author:  Fernando

  ==============================================================================
*/

#include "Gain.h"

Gain::Gain() {}
Gain::~Gain() {}

void Gain::process(juce::AudioBuffer<float>& inBuffer, float inGain)
{
    for (int channel = 0; channel < inBuffer.getNumChannels(); ++channel)
    {
        for (int n = 0; n < inBuffer.getNumSamples(); ++n)
        {
            auto sample = inBuffer.getSample(channel, n);
            auto outSample = inGain * sample;
            inBuffer.setSample(channel, n, outSample);
        }
    }
}
