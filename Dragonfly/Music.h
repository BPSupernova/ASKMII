#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.hpp>
#include <string>

namespace df {
	class Music {
	private:
		Music(Music const&); // SFML won't allow a copy
		void operator = (Music const&); // SFML won't allow music assignment
		sf::Music music; // SFML Music
		std::string label; // Text label to identify music

	public:
		Music();

		int loadMusic(std::string filename); // Associate music buffer with file; Return 0 upon success, -1 otherwise

		void setLabel(std::string new_label); // Set label associated with music
		std::string getLabel() const; // Get label associated with music

		void play(bool loop = true); // Play music; If loop is true, repeat play when done
		void stop(); // Stop the music
		void pause(); // Pause the music

		sf::Music* getMusic(); // Return pointer to SFML music
	};
}

#endif
