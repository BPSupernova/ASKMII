#include "Vector2D.h"
#include <math.h>

df::Vector2D::Vector2D(float init_x, float init_y) {
	x_comp = init_x;
	y_comp = init_y;
}

df::Vector2D::Vector2D() {
	x_comp = 0;
	y_comp = 0;
}

void df::Vector2D::setX(float new_x) {
	x_comp = new_x;
}

float df::Vector2D::getX() const {
	return x_comp;
}

void df::Vector2D::setY(float new_y) {
	y_comp = new_y;
}

float df::Vector2D::getY() const {
	return y_comp;
}

void df::Vector2D::setXY(float new_x, float new_y) {
	x_comp = new_x;
	y_comp = new_y;
}

float df::Vector2D::getMagnitude() const {
	return (float) (sqrt((x_comp * x_comp) + (y_comp * y_comp)));
}

void df::Vector2D::normalize() { 
	float length = getMagnitude();
	if (length > 0) {
		x_comp = (x_comp / length);
		y_comp = (y_comp / length);
	}
}

void df::Vector2D::scale(float scale_magnitude) {
	x_comp = x_comp * scale_magnitude;
	y_comp = y_comp * scale_magnitude;
}

df::Vector2D df::Vector2D::operator+(const Vector2D& other) const {
	Vector2D v;
	v.x_comp = this->getX() + other.getX();
	v.y_comp = this->getY() + other.getY();
	return v; // The sum of the two vectors
}

bool df::Vector2D::operator==(const df::Vector2D& other) const {
	return this->getX() == other.getX() && this->getY() == other.getY();
}