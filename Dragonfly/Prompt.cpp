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

void Prompt::setPrompt(std::string prompt) {
	setViewString(prompt);
}
