#include "ChoiceManager.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "LogManager.h"
#include "PointsManager.h"

ChoiceManager* ChoiceManager::instance = nullptr;

ChoiceManager::ChoiceManager() {
    std::srand(time(0));
}

ChoiceManager* ChoiceManager::getInstance() {
    if (!instance) {
        instance = new ChoiceManager();
    }
    return instance;
}

void ChoiceManager::loadChoicesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string choice;
    if (file.is_open()) {
        while (std::getline(file, choice)) {
            choices.push_back(choice);
        }
        file.close();
    }
    else {
        LM.getInstance().writeLog("ChoiceManager : Can't load choices file.");
    }
}

std::vector<std::string> ChoiceManager::getChoicesForDay(int day) {

    std::vector<std::string> dayChoices;
    int totalChoices = choices.size();
    std::srand(time(0) + day); // Seed with day to get different choices each day

    for (int i = 0; i < 4; ++i) {
        int randomIndex = std::rand() % totalChoices;
        dayChoices.push_back(choices[randomIndex]);
    }

    return dayChoices;
}


void ChoiceManager::processChoice(const std::string& choiceChosen) {
    int fullChoice = 0;
    for (int i = 0; i < 160; i++) {
        if (choices[i] == choiceChosen) {
            fullChoice = i;
            break;
        }
    }
    PointsManager::getInstance().readValuesFromFile(fullChoice);
    LM.getInstance().writeLog("Action [%s] taken", choiceChosen);
}