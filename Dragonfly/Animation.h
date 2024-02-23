#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include "Sprite.h"
#include "Box.h"

namespace df {
	class Animation {
	private:
		Sprite* p_sprite; // Sprite associated with Animation
		std::string name; // Sprite name in ResourceManager
		int index; // Current index frame for Sprite
		int slowdown_count; // Slowdown counter

	public:
		Animation(); // Constructor

		// Set associated sprite to new one; sprite is managed by ResourceManager; Set sprite index to 0 (first frame)
		void setSprite(Sprite* p_new_sprite);
		Sprite* getSprite() const; // Return pointer to associated Sprite

		void setName(std::string new_name); // Set sprite name (in ResourceManager)
		std::string getName() const; // Get sprite name (in ResourceManager)

		void setIndex(int new_index); // Set index of current Sprite frame to be displayed
		int getIndex() const; // Get the index of the current Sprite frame to be displayed

		void setSlowdownCount(int new_slowdown_count); // Set animation slowdown count (-1 means stop animation)
		int getSlowdownCount() const; // Get animation slowdown count (-1 means stop animation)

		Box getBox() const; // Get the bounding box of the associated sprite

		// Draw a single frame centered at the position (x,y); Drawing accounts for slowdown, and advances Sprite frame; Return 0 upon success, -1 otherwise
		int draw(Vector2D position);

	};
}

#endif
