#include "TestObject.h"
#include "EventStep.h" 
#include "DisplayManager.h"
#include "WorldManager.h"

df::TestObject::TestObject() {
	setSprite("Test");
}

df::TestObject::~TestObject() {

}

int df::TestObject::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::STEP_EVENT) {
		const EventStep *p_se = dynamic_cast <const df::EventStep*> (p_e);
		// return 8;
	}

	if (p_e->getType() == df::UNDEFINED_EVENT) {
		return -2;
	}

	if (p_e->getType() == df::KEYBOARD_EVENT) {
		const EventKeyboard *p_ke = dynamic_cast <const df::EventKeyboard*> (p_e);
		kbd(p_ke);
		// return 19;
	}

	if (p_e->getType() == df::MSE_EVENT) {
		const EventMouse* p_me = dynamic_cast <const df::EventMouse*> (p_e);
		mouse(p_me);
		// return -61;
	}

	return 0;
}

// int df::TestObject::draw() {
//	  DM.getInstance().drawChar(this->getPosition(), '$', df::CYAN);
//	  return 0;
// }

void df::TestObject::kbd(const df::EventKeyboard* p_keyboard_event) {
	switch (p_keyboard_event->getKey()) {
	case df::Keyboard::U: // draw the character in the color green
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
			setAltitude(this->getAltitude() + 1);
			DM.getInstance().drawChar(this->getPosition(), '$', df::GREEN); // Doesn't stick around since it doesn't modify draw(); just interrupts it
		break;
	}
}

void df::TestObject::mouse(const df::EventMouse* p_mouse_event) {
	if ((p_mouse_event->getMouseAction() == df::CLICKED) &&
		(p_mouse_event->getMouseButton() == df::Mouse::LEFT)) {
		setAltitude(MAX_ALTITUDE);
		DM.getInstance().drawChar(this->getPosition(), '$', df::YELLOW); // Doesn't stick around since it doesn't modify draw(); just interrupts it
	}
}

