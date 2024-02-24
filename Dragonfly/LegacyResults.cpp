#include "EventKeyboard.h"
#include "GameManager.h"

#include "LegacyResults.h"

// Want to end game after results are shown and encourage them to play again

LegacyResults::LegacyResults() {

}

LegacyResults::~LegacyResults() {

}

int LegacyResults::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*)p_e;
        if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
            switch (p_keyboard_event->getKey()) {
            case df::Keyboard::Q: // Quit
                GM.setGameOver();
                break;
            
            default:
                break;
            }
        return 1;
    }
	
	return 0;
}
