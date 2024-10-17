#ifndef CHOICE_MANAGER_H
#define CHOICE_MANAGER_H

#include <string>
#include <vector>

#define CM ChoiceManager::getInstance()

class ChoiceManager {
private:
    static ChoiceManager* instance;
    std::vector<std::string> choices;
    ChoiceManager();

public:
    static ChoiceManager* getInstance();
    void loadChoicesFromFile(const std::string& filename);
    std::vector<std::string> getChoicesForDay(int day);
    void processChoice(const std::string& choiceChosen);
};

#endif