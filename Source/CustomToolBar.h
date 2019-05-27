/*
  ==============================================================================

    CustomToolBar.h
    Created: 29 Apr 2019 10:48:19pm
    Author:  RonnyCG

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class CustomToolBar    : public Component
{
public:
    CustomToolBar(RonSynthAudioProcessor&);
    ~CustomToolBar();

    void paint (Graphics&) override;
    void resized() override;

private:

	ComboBox toolbarCB;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> toolbarCBValue;

	RonSynthAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomToolBar)
};
