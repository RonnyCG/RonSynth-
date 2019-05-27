/*
  ==============================================================================

    Mixer.h
    Created: 12 Feb 2019 11:35:33am
    Author:  RonnyCG

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Mixer    : public Component
{
public:
    Mixer(RonSynthAudioProcessor&);
    ~Mixer();

    void paint (Graphics&) override;
    void resized() override;

private:
	Slider mixerOsc1SL;
	Slider mixerOsc2SL;
	Slider mixerSubOscSL;
	Slider mixerNoiseSL;
	Slider mixerMasterSL;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mixerOsc1Val;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mixerOsc2Val;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mixerSubOscVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mixerNoiseVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mixerMasterVal;

	RonSynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Mixer)
};
