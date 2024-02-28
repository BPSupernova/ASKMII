#include "ChoiceManager.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "LogManager.h"
#include "PointsManager.h"

ChoiceManager* ChoiceManager::instance = nullptr;

ChoiceManager::ChoiceManager() {
    for (int i = 0; i < 160; i++) {
        choices[i] = "";
    }

    loadChoicesFromFile("choices.txt");
    std::srand(time(0));
    seed = std::rand() % 100000;
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
    int index = 0;
    if (file.is_open()) {
        while (std::getline(file, choice) && index < 160) {
            choices[index] = choice;
            index++;
        }
        file.close();
    }
    else {
        LM.getInstance().writeLog("ChoiceManager : Can't load choices file.");
    }
}

int* ChoiceManager::getChoicesForDay(int day) {

    std::srand(seed + day);

    int* dayChoices = new int[4];
    int totalChoices = 160;

    for (int i = 0; i < 4; ++i) {
        int randomIndex = (std::rand() + i) % totalChoices;
        dayChoices[i] = randomIndex;
    }

    return dayChoices;
}

std::string* ChoiceManager::getChoicesStringsForDay(int day) {

    int* choiceIndex = getChoicesForDay(day);
    LM.getInstance().writeLog("ChoiceIndex: %d\n", choiceIndex[0]);

    std::string* dayChoices = new std::string[4];

    for (int i = 0; i < 4; i++) {
        dayChoices[i] = choices[choiceIndex[i]];
    }

    return dayChoices;
}

void ChoiceManager::processChoice(std::string choiceChosen) { 
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
