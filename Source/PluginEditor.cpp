/*
  ==============================================================================

    PluginEditor.cpp
 
    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainTutorial1AudioProcessorEditor::GainTutorial1AudioProcessorEditor (GainTutorial1AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    
    //sliderAttach = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.treeState, GAIN_ID, gainSlider);
    sliderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, GAIN_ID, gainSlider);
    
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setRange(-48.0f, 0.0f);
    gainSlider.setValue(-24.0f);
    gainSlider.addListener(this);
    addAndMakeVisible(&gainSlider);
}

GainTutorial1AudioProcessorEditor::~GainTutorial1AudioProcessorEditor()
{
    gainSlider.removeListener(this);
}

//==============================================================================
void GainTutorial1AudioProcessorEditor::paint (juce::Graphics& g)
{

}

void GainTutorial1AudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

void GainTutorial1AudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    //if (slider == &gainSlider)
    //{
    //    audioProcessor.rawVolume = pow(10, gainSlider.getValue() / 20);
    //}
    if (slider == &gainSlider)
    {
        audioProcessor.rawVolume = gainSlider.getValue();
    }
}
