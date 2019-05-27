/*
  ==============================================================================

    Oscillator1.h
    Created: 12 Feb 2019 11:32:54am
    Author:  RonnyCG

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Oscillator1    : public Component
{
public:
    Oscillator1(RonSynthAudioProcessor&);
    ~Oscillator1();

    void paint (Graphics&) override;
    void resized() override;

private:
	ComboBox osc1WaveCB;
	Slider osc1SemitoneSL;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> osc1WaveVal;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1SemitoneVal;
	
	
	RonSynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator1)
};
