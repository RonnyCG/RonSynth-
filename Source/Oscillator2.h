/*
  ==============================================================================

    Oscillator2.h
    Created: 12 Feb 2019 11:33:25am
    Author:  RonnyCG

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Oscillator2 : public Component
{
public:
	Oscillator2(RonSynthAudioProcessor&);
	~Oscillator2();

	void paint(Graphics&) override;
	void resized() override;

private:
	ComboBox osc2WaveCB;
	Slider osc2SemitoneSL;
	Slider osc2FineSL;
	Slider osc2FMSL;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> osc2WaveVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc2SemitoneVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc2FineVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc2FMVal;

	RonSynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator2)
};
