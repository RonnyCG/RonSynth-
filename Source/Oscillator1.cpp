/*
  ==============================================================================

    Oscillator1.cpp
    Created: 12 Feb 2019 11:32:54am
    Author:  RonnyCG

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator1.h"
#include <string>
//==============================================================================
Oscillator1::Oscillator1(RonSynthAudioProcessor& p) : processor{p}
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
	setSize(220, 140);

	osc1WaveCB.addItem("Sine", 1);
	osc1WaveCB.addItem("Saw", 2);
	osc1WaveCB.addItem("Triangle", 3);
	osc1WaveCB.addItem("Square", 4);
	osc1WaveCB.addItem("Phasor", 5);
	osc1WaveCB.setJustificationType(Justification::centred);
	osc1WaveCB.setTooltip("Wave Type");
	addAndMakeVisible(&osc1WaveCB);
	osc1WaveVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "osc1Wave", osc1WaveCB);

	osc1SemitoneSL.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	osc1SemitoneSL.setRange(0, 12, 1);
	osc1SemitoneSL.setValue(0);
	osc1SemitoneSL.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	osc1SemitoneSL.setTooltip("Semitone");
	osc1SemitoneSL.setPopupDisplayEnabled(true, false, this);
	addAndMakeVisible(&osc1SemitoneSL);
	osc1SemitoneVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "osc1Semitone", osc1SemitoneSL);
}

Oscillator1::~Oscillator1()
{
}

void Oscillator1::paint (Graphics& g)
{
    
   /* g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("Oscillator1", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text*/

	
	g.fillAll(Colours::black);
	juce::Rectangle<float> area(10, 10, getWidth() - 15, getHeight() - 10);
	juce::Rectangle<int> titleArea(0, 20, getWidth() + 5, 20);
	g.setColour(Colour(204, 204, 204));
	g.setFont(Font(14, 1));
	g.drawText("OSCILLATOR 1", titleArea, Justification::centredTop);
	g.setColour(Colours::white);
	g.drawRoundedRectangle(area, 5.0f, 1.5f);

}

void Oscillator1::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
	osc1WaveCB.setBounds(30, 65, getWidth()/3, 20);
	osc1SemitoneSL.setBounds(130, 40, getWidth()/3, getWidth()/3);
}
