/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ValuetreeAttachmentsAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    ValuetreeAttachmentsAudioProcessorEditor (ValuetreeAttachmentsAudioProcessor&);
    ~ValuetreeAttachmentsAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //slider
    Slider slider;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    //dial
    Slider dial;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> dialAttatchment;
    //button
    TextButton powerButton;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> buttonAttatchment;
    //box
    ComboBox choiceBox;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> boxAttatchment;
    
    ValuetreeAttachmentsAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ValuetreeAttachmentsAudioProcessorEditor)
};
