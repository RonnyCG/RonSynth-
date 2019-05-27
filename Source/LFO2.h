/*
  ==============================================================================

    LFO2.h
    Created: 12 Feb 2019 11:36:13am
    Author:  RonnyCG

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class LFO2    : public Component
{
public:
    LFO2(RonSynthAudioProcessor&);
    ~LFO2();

    void paint (Graphics&) override;
    void resized() override;

private:
	ComboBox lfo2WaveCB;
	ComboBox lfo2DestCB;
	Slider lfo2RateSL;
	Slider lfo2IntensitySL;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> lfo2WaveVal;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> lfo2DestVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfo2RateVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> lfo2IntensityVal;

	RonSynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LFO2)
};
