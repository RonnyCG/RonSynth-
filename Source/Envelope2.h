/*
  ==============================================================================

    Envelope2.h
    Created: 12 Feb 2019 11:35:04am
    Author:  RonnyCG

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Envelope2    : public Component
{
public:
    Envelope2(RonSynthAudioProcessor&);
    ~Envelope2();

    void paint (Graphics&) override;
    void resized() override;

private:
	Slider envelope2AttackSL;
	Slider envelope2DecaySL;
	Slider envelope2SustainSL;
	Slider envelope2ReleaseSL;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> envelope2AttackVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> envelope2DecayVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> envelope2SustainVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> envelope2ReleaseVal;

	RonSynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope2)
};
