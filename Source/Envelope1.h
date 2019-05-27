/*
  ==============================================================================

    Envelope1.h
    Created: 12 Feb 2019 11:34:50am
    Author:  RonnyCG

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Envelope1    : public Component
{
public:
    Envelope1(RonSynthAudioProcessor&);
    ~Envelope1();

    void paint (Graphics&) override;
    void resized() override;

private:
	Slider envelope1AttackSL;
	Slider envelope1DecaySL;
	Slider envelope1SustainSL;
	Slider envelope1ReleaseSL;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> envelope1AttackVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> envelope1DecayVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> envelope1SustainVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> envelope1ReleaseVal;

	RonSynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope1)
};
