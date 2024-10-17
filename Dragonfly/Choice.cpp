#include "Choice.h"
#include "ChoiceManager.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include <vector> 

Choice::Choice() {
    setLocation(df::BOTTOM_LEFT);
    setViewString("");
    setColor(df::RED);
    setBorder(false);
}

void Choice::setChoiceString(int day, int choiceNum) {
    std::vector<std::string> stringChoices = ChoiceManager::getInstance()->getChoicesForDay(day);
    if (choiceNum < stringChoices.size()) {
        choiceString = stringChoices[choiceNum];
        LM.getInstance().writeLog("Choice String: %s\n", choiceString.c_str());
        setViewString(choiceString);
    }
    else {
        LM.getInstance().writeLog("Error: Choice number out of range for day %d\n", day);
    }
}

int Choice::eventHandler(const df::Event* p_e) {
    return 0;
}

int Choice::draw() {
    std::string temp_string;

    // Display view_string 
    temp_string = getViewString();

    // Draw centered at position
    df::Vector2D pos = DM.getInstance().viewToWorld(getPosition());
    DM.getInstance().drawString(pos, temp_string, df::CENTER_JUSTIFIED, getColor());
    return 0;
}