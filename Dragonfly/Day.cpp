#include "GameManager.h"
#include "EventKeyboard.h"
#include "LogManager.h"

#include "Day.h"
#include "LegacyResults.h"

Day::Day(int day) {
    day_index = day;
    switch (day) { // Set the Day's Sprite based on what day it is
    case 21:
        setSprite("temp");
        break;
    case 20:
        setSprite("temp");
        break;
    case 19:
        setSprite("temp");
        break;
    case 18:
        setSprite("temp");
        break;
    case 17:
        setSprite("temp");
        break;
    case 16:
        setSprite("temp");
        break;
    case 15:
        setSprite("temp");
        break;
    case 14:
        setSprite("temp");
        break;
    case 13:
        setSprite("temp");
        break;
    case 12:
        setSprite("temp");
        break;
    case 11:
        setSprite("temp");
        break;
    case 10:
        setSprite("temp");
        break;
    case 9:
        setSprite("temp");
        break;
    case 8:
        setSprite("temp");
        break;
    case 7:
        setSprite("temp");
        break;
    case 6:
        setSprite("temp");
        break;
    case 5:
        setSprite("temp");
        break;
    case 4:
        setSprite("temp");
        break;
    case 3:
        setSprite("temp");
        break;
    case 2:
        setSprite("temp");
        break;
    case 1:
        setSprite("temp");
        break;
    default:
        LM.getInstance().writeLog("There is no sprite to set for this Day\n");
        break;
    }

    p_music->play();
    startDay();
}

Day::~Day() {

    endDay();

    if (day_index == 1) {
        new LegacyResults; 
    } else {
        new Day(day_index--); // Create the next Day
    }
    p_music->pause();
}

int Day::eventHandler(const df::Event* p_e) {
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

void Day::makeChoice(int code) { // Up choice Code -> 1; Down Choice Code -> -1; Left Choice Code -> -5; Right Choice Code -> 5 
    // Throw a call to the Choice's allocatePoints method (or whatever it may be called) -> Ex: void allocatePoints(int code)
    WM.getInstance().MarkForDelete(this);
}

void Day::setDayNumDisplay(DayNumDisplay display) {
    days_left_display = display;
}

DayNumDisplay Day::getDayNumDisplay() const {
    return days_left_display;
}

void Day::setPrompt(Prompt new_prompt) {
    make_choice_prompter = new_prompt;
}

Prompt Day::getPrompt() const {
    return make_choice_prompter;
}

void Day::setChoice(Choice new_choice) {
    days_choice = new_choice;
}

Choice Day::getChoice() const {
    return days_choice;
}

void Day::startDay() {
    DayNumDisplay day_num_display = *(new DayNumDisplay); 
    day_num_display.setDisplayedValue(day_index);

    Prompt prompt = *(new Prompt); // Should already have prompt created in being constructed

    setDayNumDisplay(day_num_display);
    setPrompt(prompt);

    // Create new set of Choices
    // Move the DayNumDisplay closer to Top Center
    // Move the Prompt closer to right under DayNumDisplay
    // Move the Choice closer to inbetween (CENTER-CENTER) and (BOTTOM-CENTER)
    // Move Day sprite closer to inbetween (CENTER-CENTER) and (BOTTOM-CENTER)
}

void Day::endDay() {
    WM.MarkForDelete(&(getPrompt()));
    WM.MarkForDelete(&(getDayNumDisplay()));
    // Maybe delete choice object and then everything else, then delete this item somehow
}

void Day::playMusic() {
    p_music->play();
}