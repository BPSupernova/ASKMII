#include "ChoiceManager.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "LogManager.h"

ChoiceManager* ChoiceManager::instance = nullptr;

ChoiceManager::ChoiceManager() {
    loadChoicesFromFile("choices.txt");
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
    std::srand(time(0));
    int* dayChoices = new int[4];
    int totalChoices = 160;

    for (int i = 0; i < 4; ++i) {
        int randomIndex = std::rand() % totalChoices;
        dayChoices[i] = randomIndex;
    }

    return dayChoices;
}

std::string* ChoiceManager::getChoicesStringsForDay(int day) {
    std::srand(time(0));
    std::string* dayChoices = new std::string[4];
    int totalChoices = 160;

    for (int i = 0; i < 4; ++i) {
        int randomIndex = std::rand() % totalChoices;
        dayChoices[i] = choices[randomIndex];
    }

    return dayChoices;
}

void ChoiceManager::processChoice(std::string choiceChosen) {
    LM.getInstance().writeLog("Action [%s] taken", choiceChosen);
}
