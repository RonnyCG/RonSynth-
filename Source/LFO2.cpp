/*
  ==============================================================================

    LFO2.cpp
    Created: 12 Feb 2019 11:36:13am
    Author:  RonnyCG

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LFO2.h"

//==============================================================================
LFO2::LFO2(RonSynthAudioProcessor& p) : processor{p}
{
	setSize(140, 140);

	lfo2WaveCB.addItem("Sine", 1);
	lfo2WaveCB.addItem("Saw", 2);
	lfo2WaveCB.addItem("Square", 3);
	lfo2WaveCB.addItem("Triangle", 4);
	lfo2WaveCB.setJustificationType(Justification::centred);
	lfo2WaveCB.setTooltip("Wave Type");
	addAndMakeVisible(&lfo2WaveCB);
	lfo2WaveVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "lfo2Wave", lfo2WaveCB);

	lfo2DestCB.addItem("Osc1", 1);
	lfo2DestCB.addItem("Osc2", 2);
	lfo2DestCB.addItem("Osc1 Freq", 3);
	lfo2DestCB.addItem("Osc2 Freq", 4);
	lfo2DestCB.addItem("SubOsc", 5);
	lfo2DestCB.addItem("Cutoff", 6);
	lfo2DestCB.addItem("Master", 7);
	lfo2DestCB.setJustificationType(Justification::centred);
	lfo2DestCB.setTooltip("Destination");
	addAndMakeVisible(&lfo2DestCB);
	lfo2DestVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "lfo2Dest", lfo2DestCB);

	lfo2RateSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	lfo2RateSL.setRange(0.0f, 15.0f); //Hz
	lfo2RateSL.setValue(0.0f); //Hz
	lfo2RateSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	lfo2RateSL.setTooltip("Rate");
	lfo2RateSL.setPopupDisplayEnabled(true, false, this);
	lfo2RateSL.setTextValueSuffix(" Hz");
	addAndMakeVisible(&lfo2RateSL);
	lfo2RateVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "lfo2Rate", lfo2RateSL);
	lfo2RateSL.setSkewFactorFromMidPoint(3.0f);

	lfo2IntensitySL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	lfo2IntensitySL.setRange(0.0f, 10.0f);
	lfo2IntensitySL.setValue(0.0f);
	lfo2IntensitySL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	lfo2IntensitySL.setTooltip("Intensity");
	lfo2IntensitySL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&lfo2IntensitySL);
	lfo2IntensityVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "lfo2Intensity", lfo2IntensitySL);
}

LFO2::~LFO2()
{
}

void LFO2::paint (Graphics& g)
{
	g.fillAll(Colours::black);
	juce::Rectangle<float> area(5, 10, getWidth() - 15, getHeight() - 20);
	juce::Rectangle<int> titleArea(0, 20, getWidth()-5, 20);
	g.setColour(Colour(204, 204, 204));
	g.setFont(Font(14, 1));
	g.drawText("LFO 2", titleArea, Justification::centredTop);
	g.setColour(Colours::white);
	g.drawRoundedRectangle(area, 5.0f, 1.5f);
}

void LFO2::resized()
{
	lfo2WaveCB.setBounds(17, 48, getWidth() / 2.2, 17);
	lfo2DestCB.setBounds(17, 87, getWidth() / 2.2, 17);
	lfo2RateSL.setBounds(83, 35, getWidth() / 3, getWidth() / 3);
	lfo2IntensitySL.setBounds(83, 75, getWidth() / 3, getWidth() / 3);
}
