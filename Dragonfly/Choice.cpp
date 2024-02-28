#include "Choice.h"
#include "ChoiceManager.h"
#include "LogManager.h"
#include "DisplayManager.h"

Choice::Choice() {
    setLocation(df::BOTTOM_LEFT);
    setViewString("");
    setColor(df::RED);
    setBorder(false);
}

void Choice::setChoiceString(int day, int choiceNum) {
    std::string *stringChoices = ChoiceManager::getInstance()->getChoicesStringsForDay(day);
    std::string cString = stringChoices[1];
    LM.getInstance().writeLog("cString: %s\n", cString);
    setViewString(cString);
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