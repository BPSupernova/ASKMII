#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include "Frame.h"

namespace df {
	class Sprite {
	private:
		int width; // Sprite width
		int height; // Sprite height
		
		int max_frame_count; // Max number frames sprite can have
		int frame_count; // Actual number frames sprite has
		
		Color color; // Optional color for the entire sprite
		int slowdown; // Animation slowdown (1 signals no slowdown, 0 signals stop)
		Frame* frame; // Array of frames
		std::string label; // Text label to identify sprite
		Sprite(); // Sprite always has one argument, the frame count
	
	public:
		~Sprite(); // Destroy sprite, deleting any allocated frames
		Sprite(int max_frames); // Create sprite with indicated max number of frames

		void setWidth(int new_width); // Set the width of sprite
		int getWidth() const; // Get the width of the sprite
		
		void setHeight(int new_height); // Set the height of sprite
		int getHeight() const; // Get the height of sprite

		void setColor(Color new_color); // Set the sprite color
		Color getColor() const; // Get sprite color

		int getFrameCount() const; // Get the total count of frame in the sprite

		int addFrame(Frame new_frame); // Add frame to sprite; Return -1 if frame array is full, else 0
		Frame getFrame(int frame_number) const; // Get next frame (indicated by number); Return empty frame if out of range

		void setLabel(std::string new_label); // Get label associated with sprite
		std::string getLabel() const; // Get label associated with sprite

		void setSlowdown(int new_sprite_slowdown); // Set animation slowdown value; Value in multiples of GameManager frame time
		int getSlowdown() const; // Get animation slowdown value; Value in multiples  of GameManager frame time

		int draw(int frame_number, Vector2D position) const; // Draw indicated frame centered at position (x,y); 0 upon success, -1 otherwise
	};
}

#endif