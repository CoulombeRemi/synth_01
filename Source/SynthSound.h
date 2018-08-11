/*
  ==============================================================================

    SynthSound.h
    Created: 10 Aug 2018 8:49:50pm
    Author:  Remi PC

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

// https://docs.juce.com/master/classSynthesiserSound.html


class SynthSound : public SynthesiserSound {

	public :
		bool appliesToNote(int /*midiNoteNumber*/) {
			return true;
		}
		bool 	appliesToChannel(int /*midiChannel*/) {
			return true;
		}
};
