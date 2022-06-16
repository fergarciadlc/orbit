/*
  ==============================================================================

    Orbit.cpp
    Created: 29 May 2022 11:23:29pm
    Author:  Fernando

  ==============================================================================
*/

#include "Orbit.h"

Orbit::Orbit() {}
Orbit::~Orbit() {}

juce::dsp::Reverb::Parameters Orbit::getReverbParamters(float roomSize,
                                                        float damping,
                                                        float wetLevel,
                                                        float dryLevel,
                                                        float width,
                                                        float freezeMode)
{
    return reverb.getReverbParamters(roomSize, damping, wetLevel, 0.5f * dryLevel, width, freezeMode);
}

void Orbit::prepare(juce::dsp::ProcessSpec spec)
{
    dryBuffer.setSize(spec.numChannels, spec.maximumBlockSize);
    dryBuffer.clear();

    reverb.prepare(spec);
    lfoPanning.prepare(spec);
}


void Orbit::process(juce::AudioBuffer<float>& inBuffer,
                    float inGain,
                    juce::dsp::Reverb::Parameters reverbParameters,
                    float panningFrequency,
                    float panningWidth,
                    float outGain,
                    float mixLevel,
                    bool isBypassed)
{
    if (isBypassed) { return; }
    //DBG("Wet:"); DBG(reverbParameters.wetLevel);
    //DBG("DRY 2x:"); DBG(reverbParameters.dryLevel*2.0f);

    dryBuffer.makeCopyOf(inBuffer);

    gain.process(inBuffer, inGain);
    lfoPanning.process(dryBuffer, panningFrequency, panningWidth);
    reverb.process(inBuffer, reverbParameters);
    //lfoPanning.process(inBuffer, panningFrequency, panningWidth);
    gain.process(inBuffer, outGain);
    dryWet.process(inBuffer, dryBuffer, mixLevel);
}