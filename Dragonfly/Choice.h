#include "InputManager.h"
#include "ViewObject.h"
#include "ChoiceManager.h"

class Choice : public df::ViewObject {
private:

public:
	Choice();
	void setChoiceString(int day, int choiceNum);
	int eventHandler(const df::Event* p_e);
};