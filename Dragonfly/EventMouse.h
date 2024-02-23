#ifndef EVENT_MOUSE_H
#define EVENT_MOUSE_H

#include "Event.h"

#include "Vector2D.h"

namespace df {
	const std::string MSE_EVENT = "df::mouse"; 

	enum EventMouseAction { // Mouse actions recognized by Dragonfly
		UNDEFINED_MOUSE_ACTION = -1,
		CLICKED, MOVED,
	};

	namespace Mouse {
		enum MouseButton {
			UNDEFINED_BUTTON = -1,
			LEFT, MIDDLE, RIGHT,
		};
	}

	class EventMouse : public Event {
	private:
		EventMouseAction mouse_action; // Mouse action
		Mouse::MouseButton mouse_button; // Mouse button associated w/Event
		Vector2D mouse_screen_position; // Mouse cursor x,y coordinates on the screen

	public:
		EventMouse();

		void setMouseAction(EventMouseAction new_mouse_action); // Load mouse event's action
		EventMouseAction getMouseAction() const; // Get mouse event's action

		void setMouseButton(Mouse::MouseButton new_button); // Set mouse event's button
		Mouse::MouseButton getMouseButton() const; // Returns the mouse button associated with the event

		void setMouseCursorPos(Vector2D new_pos); // Set's the mouse event's position
		Vector2D getMouseCursorPos() const; // Returns the position of the mouse event
	};
}

#endif 