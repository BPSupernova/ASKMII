#include "Box.h"

df::Box::Box() {
	// Set Box upper left corner position to (0,0)
	Vector2D init_box_pos;
	init_box_pos.setXY(0, 0);
	corner = init_box_pos;

	horizontal = 0;
	vertical = 0;
}

df::Box::Box(Vector2D init_corner, float init_horizontal, float init_vertical) {
	// Set Box upper left corner position
	corner = init_corner;

	horizontal = init_horizontal;
	vertical = init_vertical;
}

void df::Box::setCorner(Vector2D new_corner) {
	corner = new_corner;
}

df::Vector2D df::Box::getCorner() const {
	return corner;
}

void df::Box::setHorizontal(float new_horizontal) {
	horizontal = new_horizontal;
}

float df::Box::getHorizontal() const {
	return horizontal;
}

void df::Box::setVertical(float new_vertical) {
	vertical = new_vertical;
}

float df::Box::getVertical() const {
	return vertical;
}
