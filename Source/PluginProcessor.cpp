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
        {                                           // id, name, min, max, default
             std::make_unique<AudioParameterInt> ("oscWaveform1", "OscillatorWaveform1", 1, 5, 1),
             std::make_unique<AudioParameterInt> ("oscOctave1", "OscillatorOctave1", -3, 3, 0),
             std::make_unique<AudioParameterInt> ("oscSemis1", "OscillatorSemis1", -12, 12, 0),
             std::make_unique<AudioParameterFloat> ("oscLevel1", "OscillatorLevel1", 0.0f, 1.0f, 1.0f),

             std::make_unique<AudioParameterInt> ("oscWaveform2", "OscillatorWaveform2", 1, 5, 1),
             std::make_unique<AudioParameterInt> ("oscOctave2", "OscillatorOctave2", -3, 3, 0),
             std::make_unique<AudioParameterInt> ("oscSemis2", "OscillatorSemis2", -12, 12, 0),
             std::make_unique<AudioParameterFloat> ("oscLevel2", "OscillatorLevel2", 0.0f, 1.0f, 0.0f),

             std::make_unique<AudioParameterInt> ("oscWaveform3", "OscillatorWaveform3", 1, 5, 1),
             std::make_unique<AudioParameterInt> ("oscOctave3", "OscillatorOctave3", -3, 3, 0),
             std::make_unique<AudioParameterInt> ("oscSemis3", "OscillatorSemis3", -12, 12, 0),
             std::make_unique<AudioParameterFloat> ("oscLevel3", "OscillatorLevel3", 0.0f, 1.0f, 0.0f),

             std::make_unique<AudioParameterInt> ("freqLC", "LowCutFreq", 20, 20000, 100),
             std::make_unique<AudioParameterFloat> ("qLC", "LowCutQ", 0.0f, 3.0f, 0.0f),
             std::make_unique<AudioParameterInt> ("freqHC", "HighCutFreq", 20, 20000, 100),
             std::make_unique<AudioParameterFloat> ("qHC", "HighCutQ", 0.0f, 3.0f, 0.0f),

             std::make_unique<AudioParameterFloat> ("attack", "Attack", 0.0f, 2000.0f, 0.0f),
             std::make_unique<AudioParameterFloat> ("decay", "Decay", 0.0f, 2000.0f, 0.0f),
             std::make_unique<AudioParameterFloat> ("sustain", "Sustain", 0.0f, 1.0f, 1.0f),
             std::make_unique<AudioParameterFloat> ("release", "Release", 0.0f, 5000.0f, 0.0f),

             std::make_unique<AudioParameterInt> ("lfoWaveform", "LFOwaveform", 1, 4, 1),
             std::make_unique<AudioParameterFloat> ("lfoSpeed", "LFOspeed", 0.0f, 1.0f, 0.5f),
             std::make_unique<AudioParameterFloat> ("lfoLevel", "LFOlevel", 0.0f, 1.0f, 0.0f),

             std::make_unique<AudioParameterFloat> ("masterGain", "MasterGain", 0.0f, 1.0f, 0.8f),

        })
#endif
{


    masterGain = parameters.getRawParameterValue ("masterGain");

    synth.clearVoices();
    for (int i = 0; i < 5; i++)
    {
        synth.addVoice(new SynthVoice(parameters));
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
    buffer.applyGain (*masterGain);
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
