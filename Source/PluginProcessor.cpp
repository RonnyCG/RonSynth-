/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RonSynthAudioProcessor::RonSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
	tree(*this, nullptr)
#endif
{

	/*===================== Oscillators ======================*/
	NormalisableRange<float> oscsWaveParam(0, 4);
	tree.createAndAddParameter("osc1Wave", "Osc1Wave", "Osc1Wave", oscsWaveParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("osc2Wave", "Osc2Wave", "Osc2Wave", oscsWaveParam, 0, nullptr, nullptr);
	NormalisableRange<float> oscsSemitoneParam(0,12,1);
	tree.createAndAddParameter("osc1Semitone", "Osc1Semitone", "Osc1Semitone", oscsSemitoneParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("osc2Semitone", "Osc2Semitone", "Osc2Semitone", oscsSemitoneParam, 0, nullptr, nullptr);
	NormalisableRange<float> oscs2FineParam(0.0f, 10.0f, 0.01f);
	tree.createAndAddParameter("osc2Fine", "Osc2Fine", "Osc2Fine", oscs2FineParam, 0.0f, nullptr, nullptr);
	NormalisableRange<float> oscs2FMParam(0.00f, 10.00f, 0.01f);
	tree.createAndAddParameter("osc2FM", "Osc2FM", "Osc2FM", oscs2FMParam, 0, nullptr, nullptr);
	/*--------------------------------------------------------*/


	/*======================== Filter ========================*/
	NormalisableRange<float> filter1TypeParam(0, 2); 
	tree.createAndAddParameter("filter1Type", "Filter1Type", "Filter1Type", filter1TypeParam, 0, nullptr, nullptr);
	NormalisableRange<float> filter1CutoffParam(20.0f, 8000.0f, 1.0f); //Hz
	tree.createAndAddParameter("filter1Cutoff", "Filter1Cutoff", "Filter1Cutoff", filter1CutoffParam, 400.0f, nullptr, nullptr);
	NormalisableRange<float> filter1ResonanceParam(1.0f, 10.0f, 0.1f); 
	tree.createAndAddParameter("filter1Resonance", "Filter1Resonance", "Filter1Resonance", filter1ResonanceParam, 1.0f, nullptr, nullptr);
	/*--------------------------------------------------------*/


	/*====================== Envelopes =======================*/
	NormalisableRange<float> envsAttackParam(10.0f, 3000.0f, 1.0f); //miliseconds
	NormalisableRange<float> envsDecayParam(10.0f, 3000.0f, 1.0f);
	NormalisableRange<float> envsSustainParam(0.0f, 1.0f, 0.01f);
	NormalisableRange<float> envsReleaseParam(10.0f, 3000.0f, 1.0f);

	tree.createAndAddParameter("envelope1Attack", "Envelope1Attack", "Envelope1Attack", envsAttackParam, 10.0f, nullptr, nullptr); 
	tree.createAndAddParameter("envelope1Decay", "Envelope1Decay", "Envelope1Decay", envsDecayParam, 10.0f, nullptr, nullptr);
	tree.createAndAddParameter("envelope1Sustain", "Envelope1Sustain", "Envelope1Sustain", envsSustainParam, 1.0f, nullptr, nullptr);
	tree.createAndAddParameter("envelope1Release", "Envelope1Release", "Envelope1Release", envsReleaseParam, 10.0f, nullptr, nullptr);

	tree.createAndAddParameter("envelope2Attack", "Envelope2Attack", "Envelope2Attack", envsAttackParam, 10.0f, nullptr, nullptr); 
	tree.createAndAddParameter("envelope2Decay", "Envelope2Decay", "Envelope2Decay", envsDecayParam, 10.0f, nullptr, nullptr);
	tree.createAndAddParameter("envelope2Sustain", "Envelope2Sustain", "Envelope2Sustain", envsSustainParam, 1.0f, nullptr, nullptr);
	tree.createAndAddParameter("envelope2Release", "Envelope2Release", "Envelope2Release", envsReleaseParam, 10.0f, nullptr, nullptr);
	/*--------------------------------------------------------*/


	/*======================== Mixer =========================*/
	NormalisableRange<float> mixerOscsParam(0.0f, 10.0f, 0.1f);
	NormalisableRange<float> mixerMasterParam(0.0f, 10.0f, 0.1f);

	tree.createAndAddParameter("mixerOsc1", "MixerOsc1", "MixerOsc1", mixerOscsParam, 5.0f, nullptr, nullptr);
	tree.createAndAddParameter("mixerOsc2", "MixerOsc2", "MixerOsc2", mixerOscsParam, 5.0f, nullptr, nullptr);
	tree.createAndAddParameter("mixerSubOsc", "MixerSubOsc", "MixerSubOsc", mixerOscsParam, 0.0f, nullptr, nullptr);
	tree.createAndAddParameter("mixerNoise", "MixerNoise", "MixerNoise", mixerOscsParam, 0.0f, nullptr, nullptr);
	tree.createAndAddParameter("mixerMaster", "MixerMaster", "MixerMaster", mixerMasterParam, 7.0f, nullptr, nullptr);
	/*--------------------------------------------------------*/


	/*======================== LFOs ==========================*/
	NormalisableRange<float> lfosWaveParam(0, 3);
	tree.createAndAddParameter("lfo1Wave", "Lfo1Wave", "Lfo1Wave", lfosWaveParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("lfo2Wave", "Lfo2Wave", "Lfo2Wave", lfosWaveParam, 0, nullptr, nullptr);
	NormalisableRange<float> lfosDestParam(0, 6);
	tree.createAndAddParameter("lfo1Dest", "Lfo1Dest", "Lfo1Dest", lfosDestParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("lfo2Dest", "Lfo2Dest", "Lfo2Dest", lfosDestParam, 0, nullptr, nullptr);
	NormalisableRange<float> lfosRateParam(0.0f, 10.0f, 0.1f);
	tree.createAndAddParameter("lfo1Rate", "Lfo1Rate", "Lfo1Rate", lfosRateParam, 0.0f, nullptr, nullptr);
	tree.createAndAddParameter("lfo2Rate", "Lfo2Rate", "Lfo2Rate", lfosRateParam, 0.0f, nullptr, nullptr);
	NormalisableRange<float> lfosIntensityParam(0.0f, 10.0f, 0.1f);
	tree.createAndAddParameter("lfo1Intensity", "Lfo1Intensity", "Lfo1Intensity", lfosIntensityParam, 0.0f, nullptr, nullptr);
	tree.createAndAddParameter("lfo2Intensity", "Lfo2Intensity", "Lfo2Intensity", lfosIntensityParam, 0.0f, nullptr, nullptr);
	/*--------------------------------------------------------*/


	/*======================== Toolbar =========================*/
	NormalisableRange<float> toolbarCBParam(0,2);
	tree.createAndAddParameter("toolbarCBVal", "ToolbarCBVal", "ToolbarCBVal", toolbarCBParam, 0, nullptr, nullptr);
	/*--------------------------------------------------------*/
	
	tree.state = ValueTree("Foo");

	mySynth.clearVoices();

	for (int i = 0; i < 5; i++)
	{
		mySynth.addVoice(new SynthVoice());
	}

	mySynth.clearSounds();
	mySynth.addSound(new SynthSound());
}

RonSynthAudioProcessor::~RonSynthAudioProcessor()
{
}

//==============================================================================
const String RonSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool RonSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool RonSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool RonSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double RonSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int RonSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int RonSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void RonSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String RonSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void RonSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void RonSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

	ignoreUnused(samplesPerBlock); //ignora samples de la anterior tecla presionada, para q no quede basura
	lastSampleRate = sampleRate; //variable usada para q no haya problemas en varias tarjetas de sonido
	mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
	
}

void RonSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool RonSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif


void RonSynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	for (int i = 0; i < mySynth.getNumVoices(); i++)
	{
		if (myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i)))
		{
			/*Oscillators*/
			myVoice->getOsc1(tree.getRawParameterValue("osc1Wave"), 
							 tree.getRawParameterValue("osc1Semitone"));

			myVoice->getOsc2(tree.getRawParameterValue("osc2Wave"),
							 tree.getRawParameterValue("osc2Semitone"),
							 tree.getRawParameterValue("osc2Fine"),
							 tree.getRawParameterValue("osc2FM"));

			/*Filter*/
			myVoice->getFilter1(tree.getRawParameterValue("filter1Type"),
								tree.getRawParameterValue("filter1Cutoff"),
								tree.getRawParameterValue("filter1Resonance"));

			/*Envelopes*/
			myVoice->getAmpEnvelope(tree.getRawParameterValue("envelope1Attack"),
								  tree.getRawParameterValue("envelope1Decay"),
								  tree.getRawParameterValue("envelope1Sustain"),
								  tree.getRawParameterValue("envelope1Release"));

			myVoice->getCutEnvelope(tree.getRawParameterValue("envelope2Attack"),
								  tree.getRawParameterValue("envelope2Decay"),
								  tree.getRawParameterValue("envelope2Sustain"),
								  tree.getRawParameterValue("envelope1Release"));

			/*Mixer*/
			myVoice->getMixer(tree.getRawParameterValue("mixerOsc1"),
							  tree.getRawParameterValue("mixerOsc2"),
							  tree.getRawParameterValue("mixerSubOsc"),
							  tree.getRawParameterValue("mixerNoise"),
							  tree.getRawParameterValue("mixerMaster"));
		

			/*LFOs*/
			myVoice->getLFO1(tree.getRawParameterValue("lfo1Wave"),
							 tree.getRawParameterValue("lfo1Dest"),
							 tree.getRawParameterValue("lfo1Rate"),
							 tree.getRawParameterValue("lfo1Intensity"));
			
			myVoice->getLFO2(tree.getRawParameterValue("lfo2Wave"),
							 tree.getRawParameterValue("lfo2Dest"),
							 tree.getRawParameterValue("lfo2Rate"),
							 tree.getRawParameterValue("lfo2Intensity"));
		}
	}

	buffer.clear();
	mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
	
}

//==============================================================================
bool RonSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* RonSynthAudioProcessor::createEditor()
{
    return new RonSynthAudioProcessorEditor (*this);
}

//==============================================================================
void RonSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void RonSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}																																											

//============================================================================																																																																																																					==
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RonSynthAudioProcessor();
}
