/*
  ==============================================================================

    LFO1.cpp
    Created: 12 Feb 2019 11:36:03am
    Author:  RonnyCG

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LFO1.h"

//==============================================================================
LFO1::LFO1(RonSynthAudioProcessor& p) : processor{p}
{
	setSize(140, 140);

	lfo1WaveCB.addItem("Sine", 1);
	lfo1WaveCB.addItem("Saw", 2);
	lfo1WaveCB.addItem("Square", 3);
	lfo1WaveCB.addItem("Triangle", 4);
	lfo1WaveCB.setJustificationType(Justification::centred);
	lfo1WaveCB.setTooltip("Wave Type");
	addAndMakeVisible(&lfo1WaveCB);
	lfo1WaveVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "lfo1Wave", lfo1WaveCB);
	
	lfo1DestCB.addItem("Osc1", 1);
	lfo1DestCB.addItem("Osc2", 2);
	lfo1DestCB.addItem("Osc1 Freq", 3);
	lfo1DestCB.addItem("Osc2 Freq", 4);
	lfo1DestCB.addItem("SubOsc", 5);
	lfo1DestCB.addItem("Cutoff", 6);
	lfo1DestCB.addItem("Master", 7);
	lfo1DestCB.setJustificationType(Justification::centred);
	lfo1DestCB.setTooltip("Destination");
	addAndMakeVisible(&lfo1DestCB);
	lfo1DestVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "lfo1Dest", lfo1DestCB);
	
	lfo1RateSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	lfo1RateSL.setRange(0.0f, 15.0f); //Hz
	lfo1RateSL.setValue(0.0f); //Hz
	lfo1RateSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	lfo1RateSL.setTooltip("Rate");
	lfo1RateSL.setPopupDisplayEnabled(true, false, this);
	lfo1RateSL.setTextValueSuffix(" Hz");
	addAndMakeVisible(&lfo1RateSL);
	lfo1RateVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "lfo1Rate", lfo1RateSL);
	lfo1RateSL.setSkewFactorFromMidPoint(3.0f);
	
	lfo1IntensitySL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	lfo1IntensitySL.setRange(0.0f, 10.0f); 
	lfo1IntensitySL.setValue(0.0f); 
	lfo1IntensitySL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	lfo1IntensitySL.setTooltip("Intensity");
	lfo1IntensitySL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&lfo1IntensitySL);
	lfo1IntensityVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "lfo1Intensity", lfo1IntensitySL);
}

LFO1::~LFO1()
{
}

void LFO1::paint (Graphics& g)
{
	g.fillAll(Colours::black);
	juce::Rectangle<float> area(10, 10, getWidth() - 15, getHeight() - 20);
	juce::Rectangle<int> titleArea(0, 20, getWidth() + 5 , 20);
	g.setColour(Colour(204, 204, 204));
	g.setFont(Font(14, 1));
	g.drawText("LFO 1", titleArea, Justification::centredTop);
	g.setColour(Colours::white);
	g.drawRoundedRectangle(area, 5.0f, 1.5f);
}

void LFO1::resized()
{
	lfo1WaveCB.setBounds(22, 48, getWidth() / 2.2, 17);
	lfo1DestCB.setBounds(22, 87, getWidth() / 2.2, 17);
	lfo1RateSL.setBounds(88, 35, getWidth() / 3, getWidth() / 3);
	lfo1IntensitySL.setBounds(88, 75, getWidth() / 3, getWidth() / 3);
}
