/*
  ==============================================================================

    PluginEditor.h
 
    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainTutorial1AudioProcessorEditor  : public juce::AudioProcessorEditor,
                                           public juce::Slider::Listener
{
public:
    GainTutorial1AudioProcessorEditor (GainTutorial1AudioProcessor&);
    ~GainTutorial1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider *slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GainTutorial1AudioProcessor& audioProcessor;
    
    juce::Slider gainSlider;
public:
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttach; // Order destruct !
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainTutorial1AudioProcessorEditor)
};
