#include "GameManager.h"
#include "EventKeyboard.h"
#include "LogManager.h"
#include "Vector2D.h"

#include "Day.h"
#include "ChoiceManager.h"

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

    df::Vector2D start_pos = df::Vector2D(40, 12); // Sprite for each day spawns in the center of the screen
    setPosition(start_pos);

    p_music = RM.getMusic("glass 'o wine");
    p_music->play();
    startDay();
}

Day::~Day() {

    endDay();

    if (day_index == 1) { // Show what Legacy the player received
        new LegacyResults; 
    } else {
        day_index--;
        new Day(day_index); // Create the next Day
        LM.getInstance().writeLog("Day: %d\n", day_index);
    }
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
    p_music->pause();
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
    DayNumDisplay day_num_display = DayNumDisplay(); 
    day_num_display.setDisplayedValue(day_index);
    day_num_display.setLocation(df::TOP_CENTER);

    Prompt prompt = Prompt(); // Should already have prompt created in being constructed
    prompt.setLocation(df::TOP_CENTER);

    df::Vector2D downward_adjustment = df::Vector2D(0, 1);
    prompt.setPosition(day_num_display.getPosition() + downward_adjustment); 

    setDayNumDisplay(day_num_display);
    setPrompt(prompt);

    Choice top_choice = Choice();
    Choice bottom_choice = Choice(); 
    Choice left_choice = Choice();
    Choice right_choice = Choice(); 

    /*
    top_choice.setPosition(this->getPosition() + df::Vector2D(0, -3)); // Up and down in Vector seems to be switched for some reason
    bottom_choice.setPosition(this->getPosition() + df::Vector2D(0, 3));
    left_choice.setPosition(this->getPosition() + df::Vector2D(-5, 0));
    right_choice.setPosition(this->getPosition() + df::Vector2D(5, 0));

    int* choice_set = ChoiceManager::getInstance()->getChoicesForDay(day_index);

    top_choice.setChoiceString(day_index, choice_set[0]); 
    bottom_choice.setChoiceString(day_index, choice_set[0]); 
    left_choice.setChoiceString(day_index, choice_set[0]); 
    right_choice.setChoiceString(day_index, choice_set[0]); 
    */

    // Create new set of Choices
    // Move the DayNumDisplay closer to Top Center
    // Move the Prompt closer to right under DayNumDisplay
    // Move the Choice closer to inbetween (CENTER-CENTER) and (BOTTOM-CENTER)
    // Move Day sprite closer to inbetween (CENTER-CENTER) and (BOTTOM-CENTER)
}

void Day::endDay() {
    // Do something here if necessary
}

void Day::playMusic() {
    p_music->play();
}