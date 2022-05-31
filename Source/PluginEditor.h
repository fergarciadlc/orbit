/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class OrbitAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    OrbitAudioProcessorEditor (OrbitAudioProcessor&);
    ~OrbitAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that roomSizeDialcreated it.
    juce::Slider roomSizeDial;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> roomSizeDialAttach;

    OrbitAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OrbitAudioProcessorEditor)
};
