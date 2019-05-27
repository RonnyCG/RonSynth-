/*
  ==============================================================================

    Oscillator2.cpp
    Created: 12 Feb 2019 11:33:25am
    Author:  RonnyCG

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator2.h"

//==============================================================================
Oscillator2::Oscillator2(RonSynthAudioProcessor& p) : processor{p}
{
 	setSize(220, 140);
	osc2WaveCB.addItem("Sine", 1);
	osc2WaveCB.addItem("Saw", 2);
	osc2WaveCB.addItem("Triangle", 3);
	osc2WaveCB.addItem("Square", 4);
	osc2WaveCB.addItem("Phasor", 5);
	osc2WaveCB.setJustificationType(Justification::centred);
	osc2WaveCB.setTooltip("Wave Type");
	addAndMakeVisible(&osc2WaveCB);
	osc2WaveVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "osc2Wave", osc2WaveCB);

	osc2SemitoneSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	osc2SemitoneSL.setRange(0, 12, 1);
	osc2SemitoneSL.setValue(0);
	osc2SemitoneSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	osc2SemitoneSL.setTooltip("Semitone");
	osc2SemitoneSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&osc2SemitoneSL);
	osc2SemitoneVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc2Semitone", osc2SemitoneSL);

	osc2FineSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	osc2FineSL.setRange(0.0f, 10.0f); 
	osc2FineSL.setValue(0.0f);
	osc2FineSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	osc2FineSL.setTooltip("Fine Tuning");
	osc2FineSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&osc2FineSL);
	osc2FineVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc2Fine", osc2FineSL);

	osc2FMSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	osc2FMSL.setRange(0.0f, 10.0f); 
	osc2FMSL.setValue(0.0f);
	osc2FMSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	osc2FMSL.setTooltip("FM");
	osc2FMSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&osc2FMSL);
	osc2FMVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc2FM", osc2FMSL);


}

Oscillator2::~Oscillator2()
{
}

void Oscillator2::paint (Graphics& g)
{
  	g.fillAll(Colours::black);
	juce::Rectangle<float> area(5, 10, getWidth()-15, getHeight()-10);
	juce::Rectangle<int> titleArea(0, 20, getWidth(), 20);
	g.setColour(Colour(204, 204, 204));
	g.setFont(Font(14, 1));
	g.drawText("OSCILLATOR 2  ", titleArea, Justification::centredTop);
	g.setColour(Colours::white);
	g.drawRoundedRectangle(area, 5.0f, 1.5f);
}

void Oscillator2::resized()
{
	osc2WaveCB.setBounds(30, 55, getWidth() / 3, 20);
	osc2SemitoneSL.setBounds(130, 35, getWidth() / 4, getWidth() / 4);
	osc2FineSL.setBounds(40, 80, getWidth() / 4, getWidth() / 4);
	osc2FMSL.setBounds(130, 80, getWidth() / 4, getWidth() / 4);
}
