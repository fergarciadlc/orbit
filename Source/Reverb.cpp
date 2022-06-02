/*
  ==============================================================================

    Reverb.cpp
    Created: 29 May 2022 9:17:59pm
    Author:  Fernando

  ==============================================================================
*/

#include "Reverb.h"

Reverb::Reverb() {}
Reverb::~Reverb() {}

juce::dsp::Reverb::Parameters Reverb::getReverbParamters(float roomSize,
                                                         float damping,
                                                         float wetLevel,
                                                         float dryLevel,
                                                         float width,
                                                         float freezeMode)
{
    juce::dsp::Reverb::Parameters reverbParameters;
    reverbParameters.roomSize = roomSize;
    reverbParameters.damping = damping;
    reverbParameters.wetLevel = wetLevel;
    reverbParameters.dryLevel = dryLevel;
    reverbParameters.width = width;
    reverbParameters.freezeMode = freezeMode;

    return reverbParameters;
}

void Reverb::prepare(juce::dsp::ProcessSpec spec)
{
    reverb.reset();
    reverb.prepare(spec);
}


void Reverb::process(juce::AudioBuffer<float>& inBuffer, juce::dsp::Reverb::Parameters reverbParameters)
{
    reverb.setParameters(reverbParameters);
    juce::dsp::AudioBlock<float> block(inBuffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    reverb.process(context);

}
