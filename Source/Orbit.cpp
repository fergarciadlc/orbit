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
    reverb.prepare(spec);
}


void Orbit::process(juce::AudioBuffer<float>& inBuffer,
                    float inGain,
                    juce::dsp::Reverb::Parameters reverbParameters,
                    float outGain,
                    bool isBypassed)
{
    if (isBypassed) { return; }
    //DBG("Wet:"); DBG(reverbParameters.wetLevel);
    //DBG("DRY 2x:"); DBG(reverbParameters.dryLevel*2.0f);
    gain.process(inBuffer, inGain);
    reverb.process(inBuffer, reverbParameters);
    gain.process(inBuffer, outGain);
}