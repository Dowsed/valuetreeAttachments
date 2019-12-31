/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ValuetreeAttachmentsAudioProcessor::ValuetreeAttachmentsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), parameters(*this, nullptr, "Parameters", createParameters())
#endif
{
}

ValuetreeAttachmentsAudioProcessor::~ValuetreeAttachmentsAudioProcessor()
{
}

//==============================================================================
const String ValuetreeAttachmentsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ValuetreeAttachmentsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ValuetreeAttachmentsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ValuetreeAttachmentsAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ValuetreeAttachmentsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ValuetreeAttachmentsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ValuetreeAttachmentsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ValuetreeAttachmentsAudioProcessor::setCurrentProgram (int index)
{
}

const String ValuetreeAttachmentsAudioProcessor::getProgramName (int index)
{
    return {};
}

void ValuetreeAttachmentsAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void ValuetreeAttachmentsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void ValuetreeAttachmentsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ValuetreeAttachmentsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void ValuetreeAttachmentsAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    auto sliderValue = *parameters.getRawParameterValue("SLIDER");
    auto dialValue = *parameters.getRawParameterValue("DIAL");
    auto buttonValue = *parameters.getRawParameterValue("POWER");
    auto choiceBoxValue = *parameters.getRawParameterValue("CHOICE");
    
    std::cout << "\n Slider value is: " << sliderValue << "\n Dial Value: " << dialValue << "\n Button Value: " << buttonValue << "\n Combo Box Value: " << choiceBoxValue;
}

//==============================================================================
bool ValuetreeAttachmentsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ValuetreeAttachmentsAudioProcessor::createEditor()
{
    return new ValuetreeAttachmentsAudioProcessorEditor (*this);
}

//==============================================================================
void ValuetreeAttachmentsAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
}

void ValuetreeAttachmentsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
 
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName (parameters.state.getType()))
            parameters.replaceState (ValueTree::fromXml (*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ValuetreeAttachmentsAudioProcessor();
}

//==============================================================================

AudioProcessorValueTreeState::ParameterLayout ValuetreeAttachmentsAudioProcessor::createParameters()
{
    std::vector<std::unique_ptr<RangedAudioParameter>> parameters;
    
    //Float
    parameters.push_back (std::make_unique<AudioParameterFloat> ("SLIDER", "Slider", 0.0f, 1.0f, 1.0f));
    
    //Choice
    parameters.push_back (std::make_unique<AudioParameterChoice>("CHOICE", "Choice", StringArray ("Choice1", "Choice2", "Choice3"),0));
    
    //Bool
    parameters.push_back (std::make_unique<AudioParameterBool>("POWER", "Power", false));
    
    //Int
    parameters.push_back (std::make_unique<AudioParameterInt>("DIAL", "Dial", 0, 10, 0));
                          
    return { parameters.begin(), parameters.end() };
}
