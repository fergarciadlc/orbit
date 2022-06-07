/*
  ==============================================================================

    LFOPanner.cpp
    Created: 5 Jun 2022 2:05:49am
    Author:  Fernando

  ==============================================================================
*/

#include "LFOPanner.h"

//LFOPanner::LFOPanner() {}
//LFOPanner::~LFOPanner() {}
//
//
//void LFOPanner::prepare(juce::dsp::ProcessSpec spec)
//{
//    lfo.prepare(spec);
//    panner.prepare(spec);
//    sampleRate = spec.sampleRate;
//}
//
//void LFOPanner::process(juce::AudioBuffer<float>& inBuffer,
//                        float inPan,
//                        float LFOFreq)
//{
//    lfo.process(inBuffer, LFOFreq);
//    panner.process(inBuffer, inPan);
//}
//
//void LFOPanner::processLFOPanner(juce::AudioBuffer<float>& inBuffer,
//                                 float inPan,
//                                 float LFOFreq)
//{
//    if (LFOFreq < 1.0f) { return; }
//    for (int channel = 0; channel < inBuffer.getNumChannels(); channel++)
//    {
//        for (int i = 0; i < inBuffer.getNumSamples(); i++)
//        {
//            float inGain = sinf(2.0f * PI * fase[channel]);
//
//            panner.process(inBuffer, inGain);
//
//            fase[channel] += LFOFreq * (1.0f / sampleRate);
//            if (fase[channel] >= 1.0f) fase[channel] -= 1.0f;
//        }
//    }
//    //panner.process(inBuffer, inPan);
//}
