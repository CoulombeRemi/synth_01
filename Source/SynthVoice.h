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
#include "maximilian.h"

//https://docs.juce.com/master/classSynthesiserVoice.html

class SynthVoice : public SynthesiserVoice {

public:

	bool canPlaySound(SynthesiserSound* sound) {
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}

	/**********************************************/

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) {

		// le enveloppe doit savoir quand il se fait trigger
		env01.trigger = 1;

		level = velocity;
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		std::cout << midiNoteNumber << std::endl;// voir la note midi dans la console
	}

	/**********************************************/

	void stopNote(float velocity, bool allowTailOff) {
		
		env01.trigger = 0;
		allowTailOff = true;

		if (velocity == 0){
			clearCurrentNote();
		}
		
	}

	/**********************************************/

	void pitchWheelMoved(int newPitchWheelValue) {

	}

	/**********************************************/

	void controllerMoved(int controllerNumber, int newControllerValue) {

	}

	/**********************************************/

	void renderNextBlock(AudioBuffer< float > &outputBuffer, int startSample, int numSamples) {

		// attack de 2sec
		env01.setAttack(2000);
		env01.setDecay(500);
		env01.setSustain(0.8);
		env01.setRelease(2000);

		for (int sample = 0; sample < numSamples; sample++){
			// valeur dans les () => la note pressee, valeur en Hz
			double theWave = osc01.sinewave(frequency);
			double theSound = env01.adsr(theWave, env01.trigger) * level;
			double filteredSound = filt01.lores(theSound, 200, 0.1);

			for (int channel = 0; channel < outputBuffer.getNumChannels; channel++){
				// (, destination channel, )
				outputBuffer.addSample(channel, startSample, filteredSound);
			}
			++startSample;
		}
	}

private:
	double level;
	double frequency;

	// variable lib. maximilian
	maxiOsc osc01;
	maxiEnv env01;
	maxiFilter filt01;
};
