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
    return reverb.getReverbParamters(roomSize, damping, wetLevel, dryLevel, width, freezeMode);
}

void Orbit::prepare(juce::dsp::ProcessSpec spec)
{
    reverb.prepare(spec);
}


void Orbit::process(juce::AudioBuffer<float> inBuffer, juce::dsp::Reverb::Parameters reverbParameters, bool isBypassed)
{
    if (isBypassed) { return; }
    reverb.process(inBuffer, reverbParameters);
}