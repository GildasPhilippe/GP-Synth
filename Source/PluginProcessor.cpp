/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GpsynthAudioProcessor::GpsynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
       parameters (*this, nullptr, Identifier ("APVTSTutorial"),
                   {
                        std::make_unique<AudioParameterFloat> ("gain",    // parameter ID
                                                                  "Gain",    // parameter name
                                                                  0.0f,      // minimum value
                                                                  1.0f,      // maximum value
                                                                  0.5f),     // default value
                   })
#endif
{
    gainParameter = parameters.getRawParameterValue ("gain");

    synth.clearVoices();
    for (int i = 0; i < 5; i++)
    {
        synth.addVoice(new SynthVoice());
    }
    synth.clearSounds();
    synth.addSound(new SynthSound());
}

GpsynthAudioProcessor::~GpsynthAudioProcessor()
{
}

//==============================================================================
const String GpsynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool GpsynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool GpsynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool GpsynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double GpsynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int GpsynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int GpsynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void GpsynthAudioProcessor::setCurrentProgram (int index)
{
}

const String GpsynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void GpsynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void GpsynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    synth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void GpsynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GpsynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void GpsynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    /*auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();


    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());


    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
    }*/

    buffer.clear();


    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
    buffer.applyGain (*gainParameter);
}

//==============================================================================
bool GpsynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* GpsynthAudioProcessor::createEditor()
{
    return new GpsynthAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void GpsynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void GpsynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GpsynthAudioProcessor();
}
