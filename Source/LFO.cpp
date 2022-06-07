/*
  ==============================================================================

    LFO.cpp
    Created: 5 Jun 2022 2:02:49am
    Author:  Fernando

  ==============================================================================
*/

#include "LFO.h"

LFO::LFO() {}
LFO::~LFO() {}

void LFO::prepare(juce::dsp::ProcessSpec spec)
{
    sampleRate = static_cast<float>(spec.sampleRate);
}

void LFO::process(juce::AudioBuffer<float>& inBuffer, float inRate)
{
    if (inRate < 1.0f) { return; }
    for (int channel = 0; channel < inBuffer.getNumChannels(); channel++)
    {
        for (int i = 0; i < inBuffer.getNumSamples(); i++)
        {
            float sample = inBuffer.getSample(channel, i);

            inBuffer.setSample(channel, i, sample * sinf(2.0f * PI * fase[channel]));

            fase[channel] += inRate * (1.0f / sampleRate);

            if (fase[channel] >= 1.0f) fase[channel] -= 1.0f;
        }
    }
}
