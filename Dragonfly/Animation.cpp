#include <iostream> 
#include "Animation.h"
#include "LogManager.h"

df::Animation::Animation() {
	p_sprite = NULL; 
	name = "Unset Anim Name\n";
	index = 0;
	slowdown_count = 4;
}

void df::Animation::setSprite(Sprite* p_new_sprite) {
	p_sprite = p_new_sprite;
	index = 0;
}

df::Sprite* df::Animation::getSprite() const {
	return p_sprite;
}

void df::Animation::setName(std::string new_name) {
	name = new_name;
}

std::string df::Animation::getName() const {
	return std::string();
}

void df::Animation::setIndex(int new_index) {
	index = new_index;
}

int df::Animation::getIndex() const {
	return index;
}

void df::Animation::setSlowdownCount(int new_slowdown_count) {
	slowdown_count = new_slowdown_count;
}

int df::Animation::getSlowdownCount() const {
	return slowdown_count;
}

df::Box df::Animation::getBox() const {
	// If there is no Sprite return a unit box centered at (0,0)
	if (!p_sprite) {
		Box no_sprite_box(Vector2D(-0.5, -0.5), 0.99, 0.99);
		return no_sprite_box;
	}

	// Create Box around centered Sprite
	Vector2D corner(-1 * p_sprite->getWidth() / 2.0, -1 * p_sprite->getHeight() / 2.0);
	Box sprite_box(corner, p_sprite->getWidth(), p_sprite->getHeight());

	return sprite_box;
}

int df::Animation::draw(Vector2D position) {
	if (this->getSprite() == NULL) {
		LM.getInstance().writeLog("This animation has no sprite (Sprite is NULL)\n");
		return -1;
	}

	int anim_count;

	// Ask Sprite to draw current frame
	int draw_index = getIndex();
	p_sprite->draw(draw_index, position);

	// If slowdown count is -1, then animation is frozen
	if (getSlowdownCount() == -1) {
		LM.getInstance().writeLog("Animation is frozen\n");
		return -1;
	}

	// Increment Counter
	anim_count = getSlowdownCount();
	anim_count++;

	// Advance sprite index, if appropriate
	if (anim_count >= p_sprite->getSlowdown()) {
		anim_count = 0;
		draw_index++;

		// If on the last frame loop to the beginning (Restart animation)
		if (draw_index >= p_sprite->getFrameCount()) {
			draw_index = 0;
		}

		// Set index for next draw()
		setIndex(draw_index);
	}

	setSlowdownCount(anim_count);

	return 0;
}
