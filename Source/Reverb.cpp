/*
  ==============================================================================

    Reverb.cpp
    Created: 29 May 2022 9:17:59pm
    Author:  Fernando

  ==============================================================================
*/

#include "Reverb.h"

JuceReverb::JuceReverb() {}
JuceReverb::~JuceReverb() {}

void JuceReverb::prepare(double inSampleRate, 
                         int inSamplesPerBlock, 
                         int inNumChannels, 
                         float roomSize, 
                         float damping,
                         float wetLevel,
                         float dryLevel, 
                         float width, 
                         float freezeMode)
{
    juce::dsp::ProcessSpec spec{};
    spec.sampleRate = inSampleRate;
    spec.maximumBlockSize = inSamplesPerBlock;
    spec.numChannels = inNumChannels;

    reverbParameters.roomSize = roomSize;
    reverbParameters.damping = damping;
    reverbParameters.wetLevel = wetLevel;
    reverbParameters.width = width;
    reverbParameters.freezeMode = freezeMode;

    reverb.reset();
    updateReverb(roomSize, damping);
    reverb.prepare(spec);
    reverb.setParameters(reverbParameters);

}

void JuceReverb::updateReverb(float roomSize, float damping)
{
    reverbParameters.roomSize = roomSize;
    reverbParameters.damping = damping;
    reverb.setParameters(reverbParameters);
}

void JuceReverb::process(juce::AudioBuffer<float> inBuffer, bool isBypassed)
{
    if (isBypassed) { return; }
    juce::dsp::AudioBlock<float> block(inBuffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    reverb.process(context);
    
}
