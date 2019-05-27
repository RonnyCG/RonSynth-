/*
  ==============================================================================

    Filter1.cpp
    Created: 12 Feb 2019 11:34:17am
    Author:  RonnyCG

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter1.h"

//==============================================================================
Filter1::Filter1(RonSynthAudioProcessor& p) : processor{p}
{
   	setSize(280, 140);
	
	filter1TypeCB.addItem("Low Pass", 1);
	filter1TypeCB.addItem("High pass", 2);
	filter1TypeCB.addItem("Band Pass", 3);
	filter1TypeCB.setJustificationType(Justification::centred);
	filter1TypeCB.setTooltip("Filter Type");
	addAndMakeVisible(&filter1TypeCB);
	filter1TypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filter1Type", filter1TypeCB);

	filter1CutoffSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	filter1CutoffSL.setRange(20.0f, 9000.0f); //Hz
	filter1CutoffSL.setValue(400.0f); //Hz
	filter1CutoffSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	filter1CutoffSL.setTooltip("CutOff");
	filter1CutoffSL.setPopupDisplayEnabled(true, false, this);
	filter1CutoffSL.setTextValueSuffix(" Hz");
	addAndMakeVisible(&filter1CutoffSL);
	filter1CutoffVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filter1Cutoff", filter1CutoffSL);
	filter1CutoffSL.setSkewFactorFromMidPoint(1500.0f);

	filter1ResonanceSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	filter1ResonanceSL.setRange(1, 10); 
	filter1ResonanceSL.setValue(1);
	filter1ResonanceSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	filter1ResonanceSL.setTooltip("Resonance");
	filter1ResonanceSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&filter1ResonanceSL);
	filter1ResonanceVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filter1Resonance", filter1ResonanceSL);
}

Filter1::~Filter1()
{
}

void Filter1::paint (Graphics& g)

{
	g.fillAll(Colours::black);
	juce::Rectangle<float> area(10, 10, getWidth() - 20, getHeight() - 10);
	juce::Rectangle<int> titleArea(0, 20, getWidth(), 20);
	g.setColour(Colour(204, 204, 204));
	g.setFont(Font(14, 1));
	g.drawText("FILTER", titleArea, Justification::centredTop);
	g.setColour(Colours::white);
	g.drawRoundedRectangle(area, 5.0f, 1.5f);
}


void Filter1::resized()
{
	filter1TypeCB.setBounds(30, 65, getWidth() / 3, 20);
	filter1CutoffSL.setBounds(130, 45, getWidth() / 4, getWidth() / 4);
	filter1ResonanceSL.setBounds(195, 45, getWidth() / 4, getWidth() / 4);
}
