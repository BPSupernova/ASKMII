#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>

#include "Manager.h"
#include "Sprite.h"
#include "Sound.h"
#include "Music.h"

#define RM df::ResourceManager::getInstance()

namespace df {
	const int MAX_SPRITES = 500;
	const int MAX_SOUNDS = 50;
	const int MAX_MUSIC = 50;

	class ResourceManager : public Manager {
	private:
		ResourceManager(); // Singleton design pattern
		ResourceManager(ResourceManager const&); // Singleton design pattern -> disallows copy
		void operator = (ResourceManager const&); // Singleton design pattern -> disallows assignment
		Sprite* p_sprite[MAX_SPRITES];  // Array of sprites
		int sprite_count; // Number of loaded sprites

		Sound sound[MAX_SOUNDS]; // Array of sound buffers
		int sound_count; // Count of number of loaded sounds
		
		Music music[MAX_MUSIC]; // Array of music buffers ("" signifies unloaded Music)
		int music_count; // Count of number of loaded musics

	public:
		static ResourceManager& getInstance(); // Get the sole instance of the ResourceManager

		int startUp(); // Get ResourceManager ready to manage resources
		void shutDown(); // Shut down the ResourceManager, freeing up any allocated Sprites

		int loadSprite(std::string filename, std::string label); // Load sprite from file & assign label to it; 0 upon success, -1 otherwise
		int unloadSprite(std::string label); // Unload the sprite with the indicated label; 0 upon success, -1 otherwise

		int loadSound(std::string filename, std::string label); // Load Sound from file; Return 0 upon success, -1 otherwise
		int unloadSound(std::string label); // Remove sound with indicated label; Return 0 upon success, -1 otherwise

		int loadMusic(std::string filename, std::string label); // Associate file with Music; Return 0 upon success, -1 otherwise
		int unloadMusic(std::string label); // Remove label for Music with indicated label; Return 0 upon success; -1 otherwise 

		void discardCarriageReturn(std::string &str); // If parsing from a Windows OS text file with both \n and \r, remove the \r (carriage return char)

		Sprite* getSprite(std::string label) const; // Find Sprite with indicated label; Return pointer to it if found, otherwise return NULL

		Sound* getSound(std::string label); // Find Sound with indicated label; Return pointer to it if found, NULL otherwise
	
		Music* getMusic(std::string label); // Find Music with indicated label; Return pointer to it if found, NULL otherwise
	};
}

#endif