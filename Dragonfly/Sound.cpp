#include "Sound.h"

df::Sound::Sound() {
	sound = *(new sf::Sound());
	sound_buffer = *(new sf::SoundBuffer());
	label = "Unlabeled\n";
}

df::Sound::~Sound() {
	sound.resetBuffer();
}

int df::Sound::loadSound(std::string filename) {
	sound_buffer.loadFromFile(filename);
	sound.setBuffer(sound_buffer);
	return 0;
}

void df::Sound::setLabel(std::string new_label) {
	label = new_label;
}

std::string df::Sound::getLabel() const {
	return label;
}

void df::Sound::play(bool loop) {
	sound.setLoop(loop);
	sound.play();
}

void df::Sound::stop() {
	sound.stop();
}

void df::Sound::pause() {
	sound.pause();
}

sf::Sound df::Sound::getSound() const {
	return sound;
}
