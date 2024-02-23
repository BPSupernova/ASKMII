#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "Manager.h"

#define IM df::InputManager::getInstance()

namespace df {
	class InputManager : public Manager {
	private:
		InputManager(); // Private -> Singleton design
		InputManager(InputManager const&); // Don't allow copy -> Singleton design
		void operator=(InputManager const&); // Don't allow assignment

	public:
		static InputManager& getInstance(); // Get the sole instance of the InputManager
		int startUp(); // Gets a window ready to capture input; Return 0 upon success, -1 otherwise
		void shutDown(); // Reverts get to normal window mode

		void getInput() const; // Gets input from the keyboard and mouse; Passes the event along to all Objects
	};
}

#endif