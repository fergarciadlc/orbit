/*
  ==============================================================================

    Reverb.h
    Created: 29 May 2022 9:17:59pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class JuceReverb
{
public:
    
    JuceReverb();
    ~JuceReverb();

    juce::dsp::Reverb::Parameters getReverbParamters(float roomSize = 0.5f,
                                                     float damping = 0.5f,
                                                     float wetLevel = 0.33f,
                                                     float dryLevel = 0.4f,
                                                     float width = 1.0f,
                                                     float freezeMode = 0.0f);
    
    void prepare(juce::dsp::ProcessSpec spec);

    //void updateReverb(float roomSize, float damping);

    void process(juce::AudioBuffer<float> inBuffer, juce::dsp::Reverb::Parameters reverbParameters, bool isBypassed = false);

private:
    juce::dsp::Reverb reverb;
    //juce::dsp::Reverb::Parameters reverbParameters;
};