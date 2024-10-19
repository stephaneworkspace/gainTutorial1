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
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setRange(0.0, 1.0);
    gainSlider.setValue(0.5);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

GainTutorial1AudioProcessorEditor::~GainTutorial1AudioProcessorEditor()
{
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
    if (slider == &gainSlider)
    {
        audioProcessor.rawVolume = gainSlider.getValue();
    }
}
