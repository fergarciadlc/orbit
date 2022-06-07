/*
  ==============================================================================

    LFOPanner.h
    Created: 5 Jun 2022 2:05:49am
    Author:  Fernando

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
//#include "Panning.h"
//#include "LFO.h"
//
//class LFOPanner
//{
//public:
//    LFOPanner();
//    ~LFOPanner();
//
//    void prepare(juce::dsp::ProcessSpec spec);
//    void process(juce::AudioBuffer<float>& inBuffer, 
//                 float inPan,
//                 float LFOFreq);
//
//    void processLFOPanner(juce::AudioBuffer<float>& inBuffer, 
//                          float inPan,
//                          float LFOFreq);
//private:
//    float sampleRate;
//    float fase[2]{ 0.0f };
//    float PI = juce::MathConstants<float>::pi;
//    LFO lfo;
//    Panning panner;
//};
//
//class cppPanning
//{
//public:
//    cppPanning() {};
//    ~cppPanning() {};
//
//    void process(juce::AudioBuffer<float>& inBuffer, float inPan)
//    {
//        //inPan = juce::jmap<float>(inPan, 0.0f, PI / 2.0f, 1.0f, -1.0f);
//        for (int channel = 0; channel < inBuffer.getNumChannels(); channel++)
//        {
//            for (int i=0; i < inBuffer.getNumSamples(); i++)
//            {
//                float sample = inBuffer.getSample(channel, i);
//                if (channel == 0) // left
//                {
//                    sample *= sqrtf(((PI / 2.0f) - inPan) * (2.0f / PI) * cosf(inPan));
//                    inBuffer.setSample(channel, i, sample);
//                }
//                else
//                {
//                    sample *= sqrtf(inPan * (2.0f / PI) * sinf(inPan));
//                    inBuffer.setSample(channel, i, sample);
//                }
//            }
//        }
//    }
//
//    //void prepare(juce::dsp::ProcessSpec spec);
//    //void process(juce::AudioBuffer<float>& inBuffer, float inPan);
//private:
//    float PI = juce::MathConstants<float>::pi;
//    //juce::dsp::Panner<float> jucePanner;
//};


class lfoPanning
{
public:
    lfoPanning() {};
    ~lfoPanning() {};

    void prepare(juce::dsp::ProcessSpec spec)
    {
        sampleRate = static_cast<float>(spec.sampleRate);
    }

    void process(juce::AudioBuffer<float>& inBuffer, float lfoFrequency, float panningAmplitude = 1.0f)
    {
        if (lfoFrequency < 1) { return; }
        float inPan;
        //float panningAmplitude = 1;
        for (int channel = 0; channel < inBuffer.getNumChannels(); channel++)
        {
            for (int i = 0; i < inBuffer.getNumSamples(); i++)
            {
                inPan = PI/4 + (panningAmplitude * PI/4 * sinf(2.0f * PI * fase[channel]) );
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

    //void prepare(juce::dsp::ProcessSpec spec);
    //void process(juce::AudioBuffer<float>& inBuffer, float inPan);
private:
    //float PI = juce::MathConstants<float>::pi;
    //juce::dsp::Panner<float> jucePanner;
    float sampleRate{ 0.0f };
    float PI = juce::MathConstants<float>::pi;
    float fase[2]{ 0.0f };
};