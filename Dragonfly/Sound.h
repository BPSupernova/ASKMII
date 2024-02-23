#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <string>

namespace df {
	class Sound {
	private:
		sf::Sound sound; // The SFML sound
		sf::SoundBuffer sound_buffer; // SFML sound buffer associated with sound
		std::string label; // Text label to identify sound

	public:
		Sound();
		~Sound();

		int loadSound(std::string filename); // Load sound buffer from file; Return 0 upon success, -1 otherwise

		void setLabel(std::string new_label); // Set the label associated with the Sound
		std::string getLabel() const; // Get the label associated with the Sound

		void play(bool loop = false); // Play the sound; if loop is true repeat play when done
		void stop(); // Stop playing the sound
		void pause(); // Pause the sound

		sf::Sound getSound() const; 
	};
}

#endif