/*
  ==============================================================================

    Panning.cpp
    Created: 5 Jun 2022 1:11:02am
    Author:  Fernando

  ==============================================================================
*/

#include "Panning.h"

Panning::Panning() {}
Panning::~Panning() {}

//void Panning::process(juce::AudioBuffer<float>& inBuffer, float inPan)
//{
//    for (int channel = 0; channel < inBuffer.getNumChannels(); channel++)
//    {
//        for (int i=0; i < inBuffer.getNumSamples(); i++)
//        {
//            float sample = inBuffer.getSample(channel, i);
//            if (channel == 0) // left
//            {
//                sample *= sqrtf(((PI / 2.0f) - inPan) * (2.0f / PI) * cosf(inPan));
//                inBuffer.setSample(channel, i, sample);
//            }
//            else
//            {
//                sample *= sqrtf(inPan * (2.0f / PI) * sinf(inPan));
//                inBuffer.setSample(channel, i, sample);
//            }
//        }
//    }
//}

void Panning::prepare(juce::dsp::ProcessSpec spec)
{
    jucePanner.reset();

    jucePanner.setRule(juce::dsp::Panner<float>::Rule::squareRoot4p5dB);
    jucePanner.prepare(spec);
}

void Panning::process(juce::AudioBuffer<float>& inBuffer, float inPan)
{
    jucePanner.setPan(inPan);
    juce::dsp::AudioBlock<float> block(inBuffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    jucePanner.process(context);
}
