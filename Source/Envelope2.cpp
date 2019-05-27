/*
  ==============================================================================

    Envelope2.cpp
    Created: 12 Feb 2019 11:35:04am
    Author:  RonnyCG

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope2.h"

//==============================================================================
Envelope2::Envelope2(RonSynthAudioProcessor& p) : processor{p}
{
    setSize(280, 140);

	envelope2AttackSL.setSliderStyle(Slider::SliderStyle::LinearVertical);
	envelope2AttackSL.setRange(0.1f, 5000.0f);
	envelope2AttackSL.setValue(0.1f);
	envelope2AttackSL.setTextBoxStyle(Slider::NoTextBox, true, 20.0, 10.0);
	envelope2AttackSL.setTooltip("Attack");
	envelope2AttackSL.setPopupDisplayEnabled(true, false, this);
	envelope2AttackSL.setTextValueSuffix(" ms");
	addAndMakeVisible(&envelope2AttackSL);
	envelope2AttackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "envelope2Attack", envelope2AttackSL);

	envelope2DecaySL.setSliderStyle(Slider::SliderStyle::LinearVertical);
	envelope2DecaySL.setRange(0.1f, 5000.0f);
	envelope2DecaySL.setValue(0.1f);
	envelope2DecaySL.setTextBoxStyle(Slider::NoTextBox, true, 20.0, 10.0);
	envelope2DecaySL.setTooltip("Decay");
	envelope2DecaySL.setPopupDisplayEnabled(true, false, this);
	envelope2DecaySL.setTextValueSuffix(" ms");
	addAndMakeVisible(&envelope2DecaySL);
	envelope2DecayVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "envelope2Decay", envelope2DecaySL);

	envelope2SustainSL.setSliderStyle(Slider::SliderStyle::LinearVertical);
	envelope2SustainSL.setRange(0.1f, 5000.0f);
	envelope2SustainSL.setValue(0.1f);
	envelope2SustainSL.setTextBoxStyle(Slider::NoTextBox, true, 20.0, 10.0);
	envelope2SustainSL.setTooltip("Sustain");
	envelope2SustainSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&envelope2SustainSL);
	envelope2SustainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "envelope2Sustain", envelope2SustainSL);

	envelope2ReleaseSL.setSliderStyle(Slider::SliderStyle::LinearVertical);
	envelope2ReleaseSL.setRange(0.1f, 5000.0f);
	envelope2ReleaseSL.setValue(0.1f);
	envelope2ReleaseSL.setTextBoxStyle(Slider::NoTextBox, true, 20.0, 10.0);
	envelope2ReleaseSL.setTooltip("Release");
	envelope2ReleaseSL.setPopupDisplayEnabled(true, false, this);
	envelope2ReleaseSL.setTextValueSuffix(" ms");
	addAndMakeVisible(&envelope2ReleaseSL);
	envelope2ReleaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "envelope2Release", envelope2ReleaseSL);
}

Envelope2::~Envelope2()
{
}

void Envelope2::paint (Graphics& g)
{
	g.fillAll(Colours::black);
	juce::Rectangle<float> area(10, 7, getWidth() - 20, getHeight() - 17);
	juce::Rectangle<int> titleArea(0, 20, getWidth(), 20);
	g.setColour(Colour(204, 204, 204));
	g.setFont(Font(14, 1));
	g.drawText("CUT ENVELOPE", titleArea, Justification::centredTop);
	g.setColour(Colours::white);
	g.drawRoundedRectangle(area, 5.0f, 1.5f);
}

void Envelope2::resized()
{
	juce::Rectangle<int> area(40, 45, 200, 60);
	int sliderWidth = 50;
	int sliderHeight = 60;

	envelope2AttackSL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	envelope2DecaySL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	envelope2SustainSL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	envelope2ReleaseSL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
}
