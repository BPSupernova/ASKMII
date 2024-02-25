// Engine includes
#include "DisplayManager.h"
#include "Event.h"

#include "Prompt.h"

Prompt::Prompt() {
	std::string prompt = "What will you do today?";
	setPrompt(prompt);
	setBorder(false);
}

int Prompt::eventHandler(const df::Event* p_e) {
	return 0;
}

int Prompt::draw() {
	std::string temp_string;

	// Display view_string 
	temp_string = getViewString();

	// Draw centered at position
	df::Vector2D pos = DM.getInstance().viewToWorld(getPosition());
	DM.getInstance().drawString(pos, temp_string, df::CENTER_JUSTIFIED, getColor());
	return 0;
}

void Prompt::setPrompt(std::string prompt) {
	setViewString(prompt);
}
