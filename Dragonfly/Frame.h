#ifndef FRAME_H
#define FRAME_H

#include <string>

#include "Color.h"
#include "Vector2D.h"

namespace df {
	class Frame {
	private:
		int width; // Width of frame
		int height; // Height of frame
		std::string frame_str; // All frame characters stored as a string
	
	public:
		Frame(); // Create empty frame
		Frame(int new_width, int new_height, std::string the_frame_str); // Create frame with a set width & height & string
		
		void setWidth(int new_width); // Set width of frame
		int getWidth() const; // Get the width of the frame
		
		void setHeight(int new_height); // Set the height of the frame
		int getHeight() const; // Get the height of the frame
		
		void setString(std::string new_frame_str); // Set frame characters (stored as string)
		std::string getString() const; // Get frame characters
		
		int draw(Vector2D position, Color color) const;
	};
}

#endif