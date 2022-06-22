/*
  ==============================================================================

    LFOPanner.cpp
    Created: 5 Jun 2022 2:05:49am
    Author:  Fernando

  ==============================================================================
*/

#include "LFOPanner.h"

lfoPanning::lfoPanning() {}
lfoPanning::~lfoPanning() {}

void lfoPanning::prepare(juce::dsp::ProcessSpec spec)
{
    sampleRate = static_cast<float>(spec.sampleRate);
}

void lfoPanning::process(juce::AudioBuffer<float>& inBuffer, float lfoFrequency, float panningAmplitude)
{
    if (lfoFrequency < 1) { return; }
    float inPan;
    //float panningAmplitude = 1;
    for (int channel = 0; channel < inBuffer.getNumChannels(); channel++)
    {
        for (int i = 0; i < inBuffer.getNumSamples(); i++)
        {
            inPan = PI / 4 + (panningAmplitude * PI / 4 * sinf(2.0f * PI * fase[channel]));
            float sample = inBuffer.getSample(channel, i);

            if (channel == 0) // left
            {
                sample *= sqrtf(((PI / 2.0f) - inPan) * (2.0f / PI) * cosf(inPan));
                inBuffer.setSample(channel, i, sample);
            }
            else
            {
                sample *= sqrtf(inPan * (2.0f / PI) * sinf(inPan));
                inBuffer.setSample(channel, i, sample);
            }
            fase[channel] += lfoFrequency * (1.0f / sampleRate);

            if (fase[channel] >= 1.0f) fase[channel] -= 1.0f;
        }
    }
}
