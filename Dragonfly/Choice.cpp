#include "Choice.h"

Choice::Choice() {
    setLocation(df::BOTTOM_LEFT);
    setViewString("");
    setColor(df::WHITE);
    setBorder(false);
}

void Choice::setChoiceString(int day, int choiceNum) {
    std::string cString = ChoiceManager::getInstance()->getChoicesStringsForDay(day)[choiceNum];
    setViewString(cString);
}

int Choice::eventHandler(const df::Event* p_e) {
    return 0;
}