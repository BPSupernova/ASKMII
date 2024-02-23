#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "ResourceManager.h"
#include "LogManager.h"

using std::cout;
using std::endl;

df::ResourceManager::ResourceManager() { 
	sprite_count = 0; 
	sound_count = 0;
	music_count = 0;
	setType("LogManager");
}

df::ResourceManager& df::ResourceManager::getInstance() {
	static ResourceManager resource_manager;
	return resource_manager;
}
 
int df::ResourceManager::startUp() {
	sprite_count = 0;
	sound_count = 0;
	music_count = 0;
	df::Manager::startUp();
	return 0;
}

void df::ResourceManager::shutDown() {
	// Free up any allocated resources
	
	// Free up allocated sprites
	for (int i = 0; i <= sprite_count; i++) {
		if (p_sprite[i] != NULL) { delete p_sprite[i]; }
	}
	sprite_count = 0;
	
	df::Manager::shutDown();
}

int df::ResourceManager::loadSprite(std::string filename, std::string label) {
	if (sprite_count == MAX_SPRITES) {  // Sprite array full
		LM.getInstance().writeLog("Class: ResourceManager ; Method: loadSprite -> Sprite array full\n");
		return -1; 
	}

	std::string line;
	std::ifstream myfile(filename);
	std::vector<std::string> data;
	// int line_index = 1; // As in 1st line in txt file

	// Temporary variables
	int frame_count, width, height, slowdown;
	Color color; 

	if (myfile.is_open()) { // Open file
		int line_index = 1; // As in the first line in the .txt file
		
		// Parse .txt file with certain layout (layout described in comments below)
		getline(myfile, line); // 1st line to parse ; contains frame count of sprite
		discardCarriageReturn(line); // For Windows support
		if (line == "") { LM.getInstance().writeLog("Class: DisplayManager ; Method: loadSprite -> The text file is empty on line %d\n", line_index); }
		frame_count = std::stoi(line);
		line_index++;

		getline(myfile, line); // 2nd line to parse ; contains width of sprite
		discardCarriageReturn(line); // For Windows support 
		if (line == "") { LM.getInstance().writeLog("Class: DisplayManager ; Method: loadSprite -> The text file is empty on line %d\n", line_index); }
		width = std::stoi(line);
		line_index++;

		getline(myfile, line); // 3rd line to parse ; contains height of sprite
		discardCarriageReturn(line); // For Windows support  
		if (line == "") { LM.getInstance().writeLog("Class: DisplayManager ; Method: loadSprite -> The text file is empty on line %d\n", line_index); } 
		height = std::stoi(line);
		line_index++;

		getline(myfile, line); // 4th line to parse ; contains animation slowdown (1 signals no slowdown, 0 signals stop)
		discardCarriageReturn(line); // For Windows support  
		if (line == "") { LM.getInstance().writeLog("Class: DisplayManager ; Method: loadSprite -> The text file is empty on line %d\n", line_index); } 
		slowdown = std::stoi(line);
		line_index++;

		getline(myfile, line); // 5th line to parse ; contains the color of the entire sprite -> string mapped to Dragonfly color
		discardCarriageReturn(line); // For Windows support   
		if (line == "") { LM.getInstance().writeLog("Class: DisplayManager ; Method: loadSprite -> The text file is empty on line %d\n", line_index); } 
		if (line == "black") { color = df::BLACK; }
		else if (line == "white") { color = df::WHITE; }
		else if (line == "red") { color = df::RED; }
		else if (line == "blue") { color = df::BLUE; }
		else if (line == "yellow") { color = df::YELLOW; }
		else if (line == "green") { color = df::GREEN; }
		else if (line == "cyan") { color = df::CYAN; }
		else if (line == "magenta") { color = df::MAGENTA; }
		else { color = df::COLOR_DEFAULT; }
		line_index++;

		// Create a Sprite and give it the previously read data
		Sprite *sprite_to_load = new Sprite(frame_count); // Initialize a sprite
		sprite_to_load->setWidth(width);
		sprite_to_load->setHeight(height);
		sprite_to_load->setSlowdown(slowdown);
		sprite_to_load->setColor(color);



		for (int frame_no = 1; frame_no <= frame_count; frame_no++) {
			Frame *next_frame = new Frame(); // frame to add to sprite this iteration
			std::string frame_str = ""; // characters frame consists of
			for (int h = 1; h <= height; h++) {
				getline(myfile, line);
				discardCarriageReturn(line); // For Windows support
				if (line == "") { LM.getInstance().writeLog("Class: DisplayManager ; Method: loadSprite -> The text file is empty on line %d\n", line_index); } 
				frame_str = frame_str.append(line); // Append line to frame string
				line_index++;
			}
			next_frame->setString(frame_str);
			next_frame->setWidth(width);
			next_frame->setHeight(height);

			sprite_to_load->addFrame(*next_frame);
		}

		std::cout << "File is about to close\n" << std::endl;
		myfile.close(); // Close file when done 
		std::cout << "File closed\n" << std::endl;
		//if (myfile.is_open()) { LM.getInstance().writeLog("Class: DisplayManager ; Method: loadSprite -> The text file did not close properly and is still open\n"); }

		// If no errors above, add the Sprite to the ResourceManager
		sprite_to_load->setLabel(label);
		p_sprite[sprite_count] = sprite_to_load; 
		sprite_count++;

		return 0;
	} else {
		cout << "Unable to open file" << endl;
		LM.getInstance().writeLog("Class: ResourceManager ; Method: loadSprite -> Can't open file %s\n", filename);
		return -1;
	}

	return 0;
}

int df::ResourceManager::unloadSprite(std::string label) {
	for (int i = 0; i <= sprite_count - 1; i++) {
		if (label == p_sprite[i]->getLabel()) {
			delete p_sprite[i]; // Unload / Delete Sprite

			for (int j = i; j <= sprite_count - 2; j++) { // Scoot everything over to fill in gap
				p_sprite[j] = p_sprite[j + 1];
			}
			sprite_count--;

			return 0;
		}
	}
	
	return -1; // Could not find the sprite via input label
}

int df::ResourceManager::loadSound(std::string filename, std::string label) {
	if (sound_count == MAX_SOUNDS) { // Check if max amount of sounds is already in game
		LM.getInstance().writeLog("The sound array is full\n");
		return -1;
	}

	if (sound[sound_count].loadSound(filename) == -1) {
		LM.getInstance().writeLog("Couldn't load Sound from file\n");
		return -1;
	}

	sound[sound_count].setLabel(label);
	sound_count++;
	
	return 0;
}

int df::ResourceManager::unloadSound(std::string label) {
	for (int i = 0; i < sound_count; i++) {
		if (label == sound[i].getLabel()) {
			// Scoot over remaining sounds
			for (int j = i; j < sound_count - 1; j++) {
				sound[j] = sound[j + 1];
			}

			sound_count--;
			return 0;
		}
	}
	return -1; // Sound not found
}

int df::ResourceManager::loadMusic(std::string filename, std::string label) {
	if (music_count == MAX_MUSIC) { // Check if max amount of music is already in game
		LM.getInstance().writeLog("The music array is full\n");
		return -1;
	}

	if (music[music_count].loadMusic(filename) == -1) {
		LM.getInstance().writeLog("Couldn't load Music from file\n");
		return -1;
	}

	music[music_count].setLabel(label);
	music_count++;

	return 0;;
}

int df::ResourceManager::unloadMusic(std::string label) {
	for (int i = 0; i < music_count; i++) {
		if (label == music[i].getLabel()) {
			// Can't scoot over since SFML won't allow it; signify "" label as unloaded music instead
			music[i].setLabel("");
			return 0;
		}
	}
	
	return -1; // Music not found
}

void df::ResourceManager::discardCarriageReturn(std::string& str) {
	if (str.size() > 0 && str[str.size() - 1] == '\r') { // Check for carriage return ('r') at the end of a line (Typically found at the end of lines in .txt files on solely Windows OS)
		str.erase(str.size() - 1);
	}
}

df::Sprite* df::ResourceManager::getSprite(std::string label) const {
	for (int i = 0; i <= sprite_count - 1; i++) {
		if (label == p_sprite[i]->getLabel()) { return p_sprite[i]; } // Found the sprite
	}
	
	return nullptr; // Couldn't find the sprite via input label
}

df::Sound* df::ResourceManager::getSound(std::string label) {
	for (int i = 0; i < sound_count; i++) {
		if (label == sound[i].getLabel()) {
			return (&sound[i]);
		}
	}
	return nullptr;
}

df::Music* df::ResourceManager::getMusic(std::string label) {
	for (int i = 0; i < music_count; i++) {
		if (label == music[i].getLabel()) {
			return (&music[i]);
		}
	}
	return nullptr;
}
