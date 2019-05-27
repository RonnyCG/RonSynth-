/*
  ==============================================================================

    Filter1.h
    Created: 12 Feb 2019 11:34:17am
    Author:  RonnyCG

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Filter1    : public Component
{
public:
    Filter1(RonSynthAudioProcessor&);
    ~Filter1();

    void paint (Graphics&) override;
    void resized() override;

private:
	ComboBox filter1TypeCB;
	Slider filter1CutoffSL;
	Slider filter1ResonanceSL;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> filter1TypeVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filter1CutoffVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filter1ResonanceVal;

	RonSynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter1)
};
