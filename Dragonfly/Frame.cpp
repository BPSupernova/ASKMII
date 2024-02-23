#include "Frame.h"
#include "LogManager.h"
#include "DisplayManager.h"

#include <iostream>

df::Frame::Frame() {
	width = 0;
	height = 0;
	frame_str = "";
}

df::Frame::Frame(int new_width, int new_height, std::string the_frame_str) {
	width = new_width;
	height = new_height;
	frame_str = the_frame_str;
}

void df::Frame::setWidth(int new_width) {
	width = new_width;
}

int df::Frame::getWidth() const {
	return width;
}

void df::Frame::setHeight(int new_height) {
	height = new_height;
}

int df::Frame::getHeight() const {
	return height;
}

void df::Frame::setString(std::string new_frame_str) {
	frame_str = new_frame_str;
}

std::string df::Frame::getString() const {
	return frame_str;
}

int df::Frame::draw(Vector2D position, Color color) const {
	if (frame_str.empty()) { // Check for empty frame
		std::cout << "Error: Frame is empty\n" << std::endl;
		return -1;
	}
	
	// Determine the offset (centered at position)
	int x_offset = getWidth() / 2;
	int y_offset = getHeight() / 2;

	for (int y = 0; y < getHeight(); y++) {
		for (int x = 0; x < getWidth(); x++) {
			if (x > getString().size()) { LM.getInstance().writeLog("Frame count (1st line) of sprite is wrong on .txt file\n"); }
			Vector2D temp_pos(position.getX() + x - x_offset, position.getY() + y - y_offset);
			DM.getInstance().drawChar(temp_pos, frame_str[y * getWidth() + x], color);
		}
	}

	return 0;
}
