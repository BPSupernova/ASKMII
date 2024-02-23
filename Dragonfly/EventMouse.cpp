#include "EventMouse.h"

df::EventMouse::EventMouse() {
	this->setType(df::MSE_EVENT);
	mouse_action = UNDEFINED_MOUSE_ACTION;
	mouse_button = Mouse::UNDEFINED_BUTTON;
	Vector2D init_mouse_pos;
	mouse_screen_position = init_mouse_pos;
}

void df::EventMouse::setMouseAction(EventMouseAction new_mouse_action) {
	mouse_action = new_mouse_action;
}

df::EventMouseAction df::EventMouse::getMouseAction() const {
	return mouse_action;
}

void df::EventMouse::setMouseButton(Mouse::MouseButton new_button) {
	mouse_button = new_button;
}

df::Mouse::MouseButton df::EventMouse::getMouseButton() const {
	return mouse_button;
}

void df::EventMouse::setMouseCursorPos(Vector2D new_pos) {
	mouse_screen_position = new_pos;
}

df::Vector2D df::EventMouse::getMouseCursorPos() const {
	return mouse_screen_position;
}
