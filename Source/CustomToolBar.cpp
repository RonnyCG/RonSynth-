/*
  ==============================================================================

    CustomToolBar.cpp
    Created: 29 Apr 2019 10:48:19pm
    Author:  RonnyCG

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "CustomToolBar.h"

//==============================================================================
CustomToolBar::CustomToolBar(RonSynthAudioProcessor& p) : processor{ p }
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
	setSize(720, 20);
	
	toolbarCB.addItem("80's Bass", 1);
	toolbarCB.addItem("Classic Bass", 2);
	toolbarCB.addItem("Distorted Bass", 3);
	toolbarCB.addItem("Clear Piano", 4);
	toolbarCB.addItem("Soft Piano", 5);
	toolbarCB.addItem("Magic Xylophone", 6);
	toolbarCB.addItem("Synth Choir", 7);
	toolbarCB.addItem("Synth Lead", 8); 
	toolbarCB.addItem("Bird Sing", 9);
	toolbarCB.addItem("Smooth Shaker", 10);
	toolbarCB.addItem("Note Kick", 11);
	toolbarCB.addItem("Noise Effect", 12);
	toolbarCB.addItem("Ghost", 13);
	toolbarCB.addItem("Space Ambient", 14);

	toolbarCB.setJustificationType(Justification::centred);
	toolbarCB.setTooltip("Presets");
	addAndMakeVisible(&toolbarCB);
	toolbarCBValue = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "toolbarCBVal", toolbarCB);



}

CustomToolBar::~CustomToolBar()
{
}

void CustomToolBar::paint (Graphics& g)
{
   
	juce::Rectangle<float> area(10, 0, getWidth() - 10, getHeight());
	g.setColour(Colours::white);
	//g.drawRoundedRectangle(area, 5.0f, 1.5f);
}

void CustomToolBar::resized()
{
	toolbarCB.setBounds(10,0, 150, 20);

}
