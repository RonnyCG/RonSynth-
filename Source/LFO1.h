/*
  ==============================================================================

    LFO1.h
    Created: 12 Feb 2019 11:36:03am
    Author:  RonnyCG

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class LFO1    : public Component
{
public:
    LFO1(RonSynthAudioProcessor&);
    ~LFO1();

    void paint (Graphics&) override;
    void resized() override;

private:
	ComboBox lfo1WaveCB;
	ComboBox lfo1DestCB;
	Slider lfo1RateSL;
	Slider lfo1IntensitySL;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> lfo1WaveVal;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> lfo1DestVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfo1RateVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfo1IntensityVal;

	RonSynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LFO1)
};
