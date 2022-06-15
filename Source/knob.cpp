/*
  ==============================================================================

    knob.cpp
    Created: 14 Jun 2022 11:14:03pm
    Author:  Fernando

  ==============================================================================
*/

#include "knob.h"
#include "Knob.h"

Knob_LookAndFeel::Knob_LookAndFeel()
{
    knobImage = juce::ImageCache::getFromMemory(BinaryData::white_knob_png, BinaryData::white_knob_pngSize);
}

Knob_LookAndFeel::~Knob_LookAndFeel(){
}

void Knob_LookAndFeel::drawRotarySlider(juce::Graphics& g,
                            int x, int y,
                            int width, int height,
                            float sliderPosProportional,
                            float rotaryStartAngle,
                            float rotaryEndAngle,
                            juce::Slider& slider)
{
    // FILM STRIP--------------------------------------------
    const int numFrames = knobImage.getHeight() / knobImage.getWidth();
    const int frameIndex = (int)std::ceil(sliderPosProportional * (numFrames - 1));
    
    const float radius = fmin(width*0.5, height*0.5);
    const float centreX = x + width * 0.5f;
    const float centreY = y + height * 0.5f;
    const float rx = centreX - radius;
    const float ry = centreY - radius;
    
    g.drawImage(knobImage,
                rx,
                ry,
                2 * radius,
                2 * radius,
                0,
                frameIndex * knobImage.getWidth(),
                knobImage.getWidth(),
                knobImage.getWidth());
}
