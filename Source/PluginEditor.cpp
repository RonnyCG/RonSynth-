/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RonSynthAudioProcessorEditor::RonSynthAudioProcessorEditor (RonSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), osc1GUI(p), osc2GUI(p), filter1GUI(p), env1AmpGUI(p), 
												env2CutGUI(p), mixerGUI(p), lfo1GUI(p), lfo2GUI(p), toolbarGUI(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (720, 440);

	addAndMakeVisible(&osc1GUI);
	addAndMakeVisible(&osc2GUI);
	addAndMakeVisible(&filter1GUI);
	addAndMakeVisible(&env1AmpGUI); 
	addAndMakeVisible(&env2CutGUI);
	addAndMakeVisible(&mixerGUI);
	addAndMakeVisible(&lfo1GUI);
	addAndMakeVisible(&lfo2GUI);
	addAndMakeVisible(&toolbarGUI);

}

RonSynthAudioProcessorEditor::~RonSynthAudioProcessorEditor()
{
}

//==============================================================================
void RonSynthAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

}

void RonSynthAudioProcessorEditor::resized()
{
   	juce::Rectangle<int> toolbar(0, 0, getWidth(), 20);
	juce::Rectangle<int> area1(0, 20, getWidth(), getHeight()/3);
	juce::Rectangle<int> area2(0, 160, getWidth(), getHeight()/3);
	juce::Rectangle<int> area3(0, 300, getWidth(), getHeight()/3);

	const int componentWidth1 = 220;
	const int componentWidth2 = 280;
	const int componentHeigth = 140;

	toolbarGUI.setBounds(toolbar.removeFromLeft(710).removeFromTop(20));
	osc1GUI.setBounds(area1.removeFromLeft(componentWidth1).removeFromTop(componentHeigth));
	osc2GUI.setBounds(area1.removeFromLeft(componentWidth1).removeFromTop(componentHeigth));
	filter1GUI.setBounds(area1.removeFromLeft(componentWidth2).removeFromTop(componentHeigth));
	env1AmpGUI.setBounds(area2.removeFromLeft(componentWidth1*2).removeFromTop(componentHeigth));
	env2CutGUI.setBounds(area2.removeFromLeft(componentWidth2).removeFromTop(componentHeigth));
	mixerGUI.setBounds(area3.removeFromLeft(componentWidth1*2).removeFromTop(componentHeigth));
	lfo1GUI.setBounds(area3.removeFromLeft(componentWidth2/2).removeFromTop(componentHeigth));
	lfo2GUI.setBounds(area3.removeFromLeft(componentWidth2/2).removeFromTop(componentHeigth));
}
