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

juce::dsp::Reverb::Parameters JuceReverb::getReverbParamters(float roomSize,
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
    reverbParameters.width = width;
    reverbParameters.freezeMode = freezeMode;

    return reverbParameters;
}

void JuceReverb::prepare(juce::dsp::ProcessSpec spec)
{
    reverb.reset();
    reverb.prepare(spec);
}

//void JuceReverb::updateReverb(float roomSize, float damping)
//{
//    reverbParameters.roomSize = roomSize;
//    reverbParameters.damping = damping;
//    reverb.setParameters(reverbParameters);
//}

void JuceReverb::process(juce::AudioBuffer<float> inBuffer, juce::dsp::Reverb::Parameters reverbParameters, bool isBypassed)
{
    if (isBypassed) { return; }
    reverb.setParameters(reverbParameters);
    juce::dsp::AudioBlock<float> block(inBuffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    reverb.process(context);

}
