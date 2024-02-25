#include "ViewObject.h"

class Prompt : public df::ViewObject { // A text that reads "Day (number day)" at the top center of the screen
private:
	void setPrompt(std::string prompt); 

public:
	Prompt();
	int eventHandler(const df::Event* p_e);
	int draw();
};