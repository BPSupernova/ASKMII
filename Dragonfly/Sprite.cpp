#include "Sprite.h"
#include "LogManager.h"

df::Sprite::Sprite(int max_frames) {
	frame_count = 0;
	width = 0;
	height = 0;

	frame = new Frame[max_frames];
	if (!frame) {
		LM.getInstance().writeLog("Class: Sprite -> Method: Constructor -> Frames were not properly allocated to Sprite\n");
		max_frame_count = 0;
	}

	max_frame_count = max_frames;
	color = df::COLOR_DEFAULT;
}

df::Sprite::~Sprite() { // Destroy sprite deleting any allocated frames
	if (frame != NULL) {
		frame = NULL;
	}
}

void df::Sprite::setWidth(int new_width) {
	width = new_width;
}

int df::Sprite::getWidth() const {
	return width;
}

void df::Sprite::setHeight(int new_height) {
	height = new_height;
}

int df::Sprite::getHeight() const {
	return height;
}

void df::Sprite::setColor(Color new_color) {
	color = new_color;
}

df::Color df::Sprite::getColor() const {
	return color;
}

int df::Sprite::getFrameCount() const {
	return frame_count;
}

int df::Sprite::addFrame(Frame new_frame) {
	if (frame_count == max_frame_count) { return -1; } // Check if frame array is full
	else {
		frame[frame_count] = new_frame;
		frame_count++;
	}
	return 0;
}

df::Frame df::Sprite::getFrame(int frame_number) const {
	if ((frame_number < 0) || (frame_number >= frame_count)) { // Check if the requested frame is in bounds
		Frame *empty = new Frame(); // Make an empty frame
		return *empty;
	}
	return frame[frame_number];
}

void df::Sprite::setLabel(std::string new_label) {
	label = new_label;
}

std::string df::Sprite::getLabel() const {
	return label;
}

void df::Sprite::setSlowdown(int new_sprite_slowdown) {
	slowdown = new_sprite_slowdown;
}

int df::Sprite::getSlowdown() const {
	return slowdown;
}

int df::Sprite::draw(int frame_number, Vector2D position) const {
	frame[frame_number].draw(position, getColor());
	return 0;
}
