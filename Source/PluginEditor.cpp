/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OrbitAudioProcessorEditor::OrbitAudioProcessorEditor (OrbitAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    //setSize(600, 320);
    //addAndMakeVisible(roomSizeDial);

    //addAndMakeVisible(background);
    background = juce::ImageCache::getFromMemory(BinaryData::bg_jpg, BinaryData::bg_jpgSize);
    
    addAndMakeVisible(input);
    addAndMakeVisible(processing);
    addAndMakeVisible(output);
    setSize(640, 380);
    
}

OrbitAudioProcessorEditor::~OrbitAudioProcessorEditor()
{
    //input.~InputGUI(); // not working
    input.setLookAndFeel(nullptr);
    processing.setLookAndFeel(nullptr);
    output.setLookAndFeel(nullptr);
}

//==============================================================================
void OrbitAudioProcessorEditor::paint (juce::Graphics& g)
{
    //// (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.drawImage(background, getLocalBounds().toFloat());

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("oRBit", getLocalBounds(), juce::Justification::centred, 1);
}

void OrbitAudioProcessorEditor::resized()
{
    
    input     .setBoundsRelative(0.00f, 0.0f, 0.25f, 1.0f);
    processing.setBoundsRelative(0.25f, 0.0f, 0.50f, 1.0f);
    output    .setBoundsRelative(0.75f, 0.0f, 0.25f, 1.0f);

}
