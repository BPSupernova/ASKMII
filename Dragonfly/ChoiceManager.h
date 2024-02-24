#ifndef CHOICE_MANAGER_H
#define CHOICE_MANAGER_H

#include <string>

class ChoiceManager {
private:
    static ChoiceManager* instance;
    std::string choices[160];
    ChoiceManager();


public:
    static ChoiceManager* getInstance();
    void loadChoicesFromFile(const std::string& filename);
    std::string* getChoicesForDay(int day);
    void processChoice(std::string choiceChosen);
};

#endif