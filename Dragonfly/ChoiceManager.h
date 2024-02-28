#ifndef CHOICE_MANAGER_H
#define CHOICE_MANAGER_H

#include <string>

#define CM ChoiceManager::getInstance()

class ChoiceManager {
private:
    static ChoiceManager* instance;
    std::string choices[160];
    ChoiceManager();
    int seed;


public:
    static ChoiceManager* getInstance();
    void loadChoicesFromFile(const std::string& filename);
    int* getChoicesForDay(int day);
    std::string* getChoicesStringsForDay(int day);
    void processChoice(std::string choiceChosen);
};

#endif