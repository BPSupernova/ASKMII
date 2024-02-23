// Engine includes
#include "DisplayManager.h"
#include "Event.h"

#include "Prompt.h"

Prompt::Prompt() {
	std::string prompt = generatePrompt();
	setPrompt(prompt);
}

int Prompt::eventHandler(const df::Event* p_e) {
	return 0;
}

std::string Prompt::generatePrompt() {
	// Implement function
}

void Prompt::setPrompt(std::string prompt) {
	setViewString(prompt);
}
