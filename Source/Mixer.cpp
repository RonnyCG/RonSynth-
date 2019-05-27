/*
  ==============================================================================

    Mixer.cpp
    Created: 12 Feb 2019 11:35:33am
    Author:  RonnyCG

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Mixer.h"

//==============================================================================
Mixer::Mixer(RonSynthAudioProcessor& p) : processor {p}
{
    setSize(440, 140);
	
	mixerOsc1SL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	mixerOsc1SL.setRange(0.0f, 10.0f);
	mixerOsc1SL.setValue(5.0f);
	mixerOsc1SL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	mixerOsc1SL.setTooltip("Oscillator 1");
	mixerOsc1SL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&mixerOsc1SL);
	mixerOsc1Val = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mixerOsc1", mixerOsc1SL);
	mixerOsc1SL.setSkewFactorFromMidPoint(5.0f);

	mixerOsc2SL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	mixerOsc2SL.setRange(0.0f, 10.0f);
	mixerOsc2SL.setValue(5.0f);
	mixerOsc2SL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	mixerOsc2SL.setTooltip("Oscillator 2");
	mixerOsc2SL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&mixerOsc2SL);
	mixerOsc2Val = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mixerOsc2", mixerOsc2SL);
	mixerOsc2SL.setSkewFactorFromMidPoint(5.0f);

	mixerSubOscSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	mixerSubOscSL.setRange(0.0f, 10.0f);
	mixerSubOscSL.setValue(5.0f);
	mixerSubOscSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	mixerSubOscSL.setTooltip("Sub-Oscillator");
	mixerSubOscSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&mixerSubOscSL);
	mixerSubOscVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mixerSubOsc", mixerSubOscSL);
	mixerSubOscSL.setSkewFactorFromMidPoint(5.0f);

	mixerNoiseSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	mixerNoiseSL.setRange(0.0f, 10.0f);
	mixerNoiseSL.setValue(5.0f);
	mixerNoiseSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	mixerNoiseSL.setTooltip("Noise");
	mixerNoiseSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&mixerNoiseSL);
	mixerNoiseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mixerNoise", mixerNoiseSL);
	mixerNoiseSL.setSkewFactorFromMidPoint(5.0f);

	mixerMasterSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	mixerMasterSL.setRange(0.0f, 10.0f);
	mixerMasterSL.setValue(5.0f);
	mixerMasterSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	mixerMasterSL.setTooltip("Master");
	mixerMasterSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&mixerMasterSL);
	mixerMasterVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "mixerMaster", mixerMasterSL);
	mixerMasterSL.setSkewFactorFromMidPoint(5.0f);
}

Mixer::~Mixer()
{
}

void Mixer::paint (Graphics& g)
{
	g.fillAll(Colours::black);
	juce::Rectangle<float> area(10, 10, getWidth() - 20, getHeight() - 20);
	juce::Rectangle<int> titleArea(0, 20, getWidth(), 20);
	g.setColour(Colour(204, 204, 204));
	g.setFont(Font(14, 1));
	g.drawText("MIXER", titleArea, Justification::centredTop);
	g.setColour(Colours::white);
	g.drawRoundedRectangle(area, 5.0f, 1.5f);
}

void Mixer::resized()
{
	juce::Rectangle<int> area(35, 45, 370, 60); //reduce el tama?o del rectangulo por el valor dado en relacion al setSize del constructor

	int sliderWidth = 74;
	int sliderHeight = 74;

	mixerOsc1SL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	mixerOsc2SL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	mixerSubOscSL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	mixerNoiseSL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	mixerMasterSL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
}
