/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "InputGUI.h"
#include "ProcessingGUI.h"
#include "OutputGUI.h"
//#include "Background.h"

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
    //juce::Slider roomSizeDial;
    //std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> roomSizeDialAttach;

    OrbitAudioProcessor& audioProcessor;

    InputGUI input { audioProcessor };
    ProcessingGUI processing { audioProcessor };
    OutputGUI output { audioProcessor };

    //Background::BGComponent Background;
    juce::Image background;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OrbitAudioProcessorEditor)
};
