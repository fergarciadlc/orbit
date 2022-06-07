/*
  ==============================================================================

    Panning.h
    Created: 5 Jun 2022 1:11:02am
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
class Panning
{
public:
    Panning();
    ~Panning();

    //void process(juce::AudioBuffer<float>& inBuffer, float inPan);

    void prepare(juce::dsp::ProcessSpec spec);
    void process(juce::AudioBuffer<float>& inBuffer, float inPan);
private:
    //float PI = juce::MathConstants<float>::pi;
    juce::dsp::Panner<float> jucePanner;
};
