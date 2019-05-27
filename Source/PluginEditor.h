/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator1.h"
#include "Oscillator2.h"
#include "Filter1.h"
#include "Envelope1.h"
#include "Envelope2.h"
#include "Mixer.h"
#include "LFO1.h"
#include "LFO2.h"
#include "CustomToolBar.h"
//==============================================================================
/**
*/
class RonSynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    RonSynthAudioProcessorEditor (RonSynthAudioProcessor&);
    ~RonSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    RonSynthAudioProcessor& processor;

	Oscillator1 osc1GUI;
	Oscillator2 osc2GUI;
	Filter1 filter1GUI;
	Envelope1 env1AmpGUI;
	Envelope2 env2CutGUI;
	Mixer mixerGUI;
	LFO1 lfo1GUI;
	LFO2 lfo2GUI;
	CustomToolBar toolbarGUI;
	

	TooltipWindow tooltipWindow;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RonSynthAudioProcessorEditor)
};
