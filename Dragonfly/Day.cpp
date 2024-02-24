#include "GameManager.h"
#include "EventKeyboard.h"
#include "LogManager.h"

#include "Day.h"
#include "LegacyResults.h"

Day::Day(int day) {
    day_index = day;
    switch (day) { // Set the Day's Sprite based on what day it is
    case 21:
        setSprite("tv");
        break;
    default:
        LM.getInstance().writeLog("There is no sprite to set for this Day\n");
        break;
    }

    p_music->play();
    startDay();
}

Day::~Day() {
    if (day_index == 1) {
        new LegacyResults; 
    } else {
        new Day(day_index--); // Create the next Day
    }
    p_music->pause();
}

int eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*)p_e;
        if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
            switch (p_keyboard_event->getKey()) {
            case df::Keyboard::W: // Top choice
                makeChoice(1);
                break;
            case df::Keyboard::S: // Bottom choice
                makeChoice(-1);
                break;
            case df::Keyboard::A: // Left Choice         
                makeChoice(-5);
                break;
            case df::Keyboard::D: // Right Choice (as in direction)
                makeChoice(5);
                break;
            default:
                break;
            }
        return 1;
    }
}

void makeChoice(int code) { // Up choice Code -> 1; Down Choice Code -> -1; Left Choice Code -> -5; Right Choice Code -> 5 
    // Throw a call to the Choice's allocatePoints method (or whatever it may be called) -> Ex: void allocatePoints(int code)
}

void Day::startDay() {
    // Move the DayNumDisplay closer to Top Center
    // Move the Prompt closer to right under DayNumDisplay
    // Move the Choice closer to inbetween (CENTER-CENTER) and (BOTTOM-CENTER)
    // Move Day sprite closer to inbetween (CENTER-CENTER) and (BOTTOM-CENTER)
}

void Day::endDay() {
    // Maybe delete choice object and then everything else, then delete this item somehow
}

void Day::playMusic() {
    p_music->play();
}