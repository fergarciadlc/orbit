/*
  ==============================================================================

    Orbit.h
    Created: 29 May 2022 11:23:29pm
    Author:  Fernando

  ==============================================================================
*/

#pragma once

#include<JuceHeader.h>
#include "Reverb.h"
#include "Gain.h"
#include "LFOPanner.h"

class Orbit
{
public:
    Orbit();
    ~Orbit();

    juce::dsp::Reverb::Parameters getReverbParamters(float roomSize = 0.5f,
                                                     float damping = 0.5f,
                                                     float wetLevel = 0.33f,
                                                     float dryLevel = 0.4f,
                                                     float width = 1.0f,
                                                     float freezeMode = 0.0f);

    void prepare(juce::dsp::ProcessSpec spec);

    void process(juce::AudioBuffer<float>& inBuffer,
                 float inGain,
                 juce::dsp::Reverb::Parameters reverbParameters,
                 float panningFrequency,
                 float panningWidth,
                 float outGain,
                 bool isBypassed = false);

private:
    
    Gain gain;
    Reverb reverb;
    lfoPanning lfoPanning;

};
