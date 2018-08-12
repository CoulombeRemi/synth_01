/*
  ==============================================================================

    SynthVoice.h
    Created: 10 Aug 2018 8:50:03pm
    Author:  Remi PC

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"

//https://docs.juce.com/master/classSynthesiserVoice.html

class SynthVoice : public SynthesiserVoice {

public:

	bool canPlaySound(SynthesiserSound* sound) {
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}

	/**********************************************/

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) {
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		std::cout << midiNoteNumber << std::endl;// voir la note midi dans la console
	}

	/**********************************************/

	void stopNote(float velocity, bool allowTailOff) {
		clearCurrentNote();
	}

	/**********************************************/

	void pitchWheelMoved(int newPitchWheelValue) {

	}

	/**********************************************/

	void controllerMoved(int controllerNumber, int newControllerValue) {

	}

	/**********************************************/

	void renderNextBlock(AudioBuffer< float > &outputBuffer, int startSample, int numSamples) {
	
	}

private:
	double level;
	double frequency;
};
