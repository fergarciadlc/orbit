/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OrbitAudioProcessor::OrbitAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), apvts(*this, nullptr, "parameters", createParameters())
#endif
{
}

OrbitAudioProcessor::~OrbitAudioProcessor()
{
}

//==============================================================================
juce::AudioProcessorValueTreeState::ParameterLayout OrbitAudioProcessor::createParameters()
{
    juce::AudioProcessorValueTreeState::ParameterLayout parameters;

    parameters.add(std::make_unique<juce::AudioParameterFloat>(
        "rb_room_size",
        "rb_room_size",
        juce::NormalisableRange<float>(0.0f, 1.0f),
        0.6f
        ));
    parameters.add(std::make_unique<juce::AudioParameterFloat>(
        "rb_damping",
        "rb_damping",
        juce::NormalisableRange<float>(0.0f, 1.0f),
        0.5f
        ));

    return parameters;
}

//==============================================================================
const juce::String OrbitAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool OrbitAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool OrbitAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool OrbitAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double OrbitAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int OrbitAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int OrbitAudioProcessor::getCurrentProgram()
{
    return 0;
}

void OrbitAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String OrbitAudioProcessor::getProgramName (int index)
{
    return {};
}

void OrbitAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void OrbitAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::dsp::ProcessSpec spec{};
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumInputChannels();

    juceReverb.prepare(spec);
}

void OrbitAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool OrbitAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
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

void OrbitAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());


    juce::dsp::Reverb::Parameters reverbParameters = juceReverb.getReverbParamters(apvts.getRawParameterValue("rb_room_size")->load(),
                                                                                   apvts.getRawParameterValue("rb_damping")->load());
    juceReverb.process(buffer, reverbParameters);
}

//==============================================================================
bool OrbitAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* OrbitAudioProcessor::createEditor()
{
    return new OrbitAudioProcessorEditor (*this);
}

//==============================================================================
void OrbitAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void OrbitAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OrbitAudioProcessor();
}
