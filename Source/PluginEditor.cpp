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
    setSize(600, 320);

    addAndMakeVisible(roomSizeDial);
    

    
}

OrbitAudioProcessorEditor::~OrbitAudioProcessorEditor()
{
}

//==============================================================================
void OrbitAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("oRBit", getLocalBounds(), juce::Justification::centred, 1);
}

void OrbitAudioProcessorEditor::resized()
{
    auto bounds       = getLocalBounds().toFloat()
                                        .removeFromBottom (getHeight() * 0.9f)
                                        .reduced (getWidth() * 0.06f, getHeight() * 0.25f);
    auto dialWidth    = bounds.getWidth() * 0.25f;
    auto dialHeight   = dialWidth;

    roomSizeDial.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    roomSizeDial.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);

    //roomSizeDial.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 45, 20);
    //roomSizeDial.setNumDecimalPlacesToDisplay(0);
    //roomSizeDial.setTextBoxIsEditable(true);
    //roomSizeDial.setRange(1, 100, 1);

    roomSizeDial.setBounds((getWidth() / 2) - dialWidth/2, getHeight() / 2 - dialHeight/2, dialWidth, dialHeight);
    //auto buttonWidth  = bounds.getWidth() * 0.18f;
    //auto buttonHeight = buttonWidth * 0.8f;
    //auto compArea     = bounds.getWidth() / .0f;
    //
    //auto sizeMasterDialArea = bounds.removeFromLeft(compArea);

    //roomSizeDial.setBounds(sizeMasterDialArea.withSizeKeepingCentre(dialWidth, dialHeight).toNearestInt());


}
