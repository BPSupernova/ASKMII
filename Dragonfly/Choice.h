#include "InputManager.h"
#include "ViewObject.h"
#include "ChoiceManager.h"
#include <string>

class Choice : public df::ViewObject {
private:
    std::string choiceString;

public:
    Choice();
    void setChoiceString(int day, int choiceNum);
    int eventHandler(const df::Event* p_e);
    int draw();
};