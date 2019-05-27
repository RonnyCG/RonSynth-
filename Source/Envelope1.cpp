/*
  ==============================================================================

    Envelope1.cpp
    Created: 12 Feb 2019 11:34:50am
    Author:  RonnyCG

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope1.h"

//==============================================================================
Envelope1::Envelope1(RonSynthAudioProcessor& p) : processor{p}
{
	setSize(440, 140);

	envelope1AttackSL.setSliderStyle(Slider::SliderStyle::LinearVertical);
	envelope1AttackSL.setRange(0.1f, 10000.0f);
	envelope1AttackSL.setValue(0.1f);
	envelope1AttackSL.setTextBoxStyle(Slider::NoTextBox, true, 20.0, 10.0);
	envelope1AttackSL.setTooltip("Attack");
	envelope1AttackSL.setPopupDisplayEnabled(true, false, this);
	envelope1AttackSL.setTextValueSuffix(" ms");
	addAndMakeVisible(&envelope1AttackSL);
	envelope1AttackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "envelope1Attack", envelope1AttackSL);

	envelope1DecaySL.setSliderStyle(Slider::SliderStyle::LinearVertical);
	envelope1DecaySL.setRange(0.1f, 10000.0f);
	envelope1DecaySL.setValue(0.1f);
	envelope1DecaySL.setTextBoxStyle(Slider::NoTextBox, true, 20.0, 10.0);
	envelope1DecaySL.setTooltip("Decay");
	envelope1DecaySL.setPopupDisplayEnabled(true, false, this);
	envelope1DecaySL.setTextValueSuffix(" ms");
	addAndMakeVisible(&envelope1DecaySL);
	envelope1DecayVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "envelope1Decay", envelope1DecaySL);
	
	envelope1SustainSL.setSliderStyle(Slider::SliderStyle::LinearVertical);
	envelope1SustainSL.setRange(0.1f, 1.0f);
	envelope1SustainSL.setValue(0.1f);
	envelope1SustainSL.setTextBoxStyle(Slider::NoTextBox, true, 20.0, 10.0);
	envelope1SustainSL.setTooltip("Sustain");
	envelope1SustainSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&envelope1SustainSL);
	envelope1SustainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "envelope1Sustain", envelope1SustainSL);

	envelope1ReleaseSL.setSliderStyle(Slider::SliderStyle::LinearVertical);
	envelope1ReleaseSL.setRange(0.1f, 10000.0f);
	envelope1ReleaseSL.setValue(0.1f);
	envelope1ReleaseSL.setTextBoxStyle(Slider::NoTextBox, true, 20.0, 10.0);
	envelope1ReleaseSL.setTooltip("Release");
	envelope1ReleaseSL.setPopupDisplayEnabled(true, false, this);
	envelope1ReleaseSL.setTextValueSuffix(" ms");
	addAndMakeVisible(&envelope1ReleaseSL);
	envelope1ReleaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "envelope1Release", envelope1ReleaseSL);
}

Envelope1::~Envelope1()
{
}

void Envelope1::paint (Graphics& g)
{
	g.fillAll(Colours::black);
	juce::Rectangle<float> area(10, 7, getWidth() - 20, getHeight() - 17);
	juce::Rectangle<int> titleArea(0, 20, getWidth(), 20);
	g.setColour(Colour(204, 204, 204));
	g.setFont(Font(14, 1));
	g.drawText("AMP ENVELOPE", titleArea, Justification::centredTop);
	g.setColour(Colours::white);
	g.drawRoundedRectangle(area, 5.0f, 1.5f);
}

void Envelope1::resized()
{
    juce::Rectangle<int> area(60,45, 320, 60);
	int sliderWidth = 80;
	int sliderHeight = 60;

	envelope1AttackSL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	envelope1DecaySL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	envelope1SustainSL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
	envelope1ReleaseSL.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight));
}
