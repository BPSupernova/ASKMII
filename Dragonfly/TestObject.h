#ifndef TEST_OBJECT
#define TEST_OBJECT

#include "Object.h"
#include "EventKeyboard.h"
#include "EventMouse.h"

namespace df {

	class TestObject : public Object {
	public:
		TestObject();
		~TestObject();
		int eventHandler(const df::Event* p_e) override; // Returns an integer code based on the Event type; -2 for base Event; 10 for Step
		// int draw(); // Override the default Object draw()
		void kbd(const df::EventKeyboard* p_keyboard_event);
		void mouse(const df::EventMouse* p_mouse_event);
	};
}

#endif