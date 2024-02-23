#include "EventKeyboard.h"

df::EventKeyboard::EventKeyboard() {
	this->setType(df::KEYBOARD_EVENT);
	key_val = Keyboard::UNDEFINED_KEY;
	keyboard_action = UNDEFINIED_KEYBOARD_ACTION;
}

void df::EventKeyboard::setKey(Keyboard::Key new_key) {
	key_val = new_key;
}

df::Keyboard::Key df::EventKeyboard::getKey() const {
	return key_val;
}

void df::EventKeyboard::setKeyboardAction(EventKeyboardAction new_action) {
	keyboard_action = new_action;
}

df::EventKeyboardAction df::EventKeyboard::getKeyboardAction() const {
	return keyboard_action;
}
