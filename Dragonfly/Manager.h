#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "Event.h"

namespace df {

	class Manager {
	private:
		std::string m_type; // Identifies the type of Manager
		bool manager_is_started;

	protected:
		void setType(std::string type); // Sets type string to Manager

	public:
		Manager();
		virtual ~Manager(); // Always virtualize deconstructor

		std::string getType() const; // Gets type string of Manager

		int startUp();
		void shutDown();
		bool isStarted() const; // True if startUp() was executed right; else false
		int onEvent(const Event* p_event) const; // Return number of objects the event was sent to 
	};
}

#endif // !MANAGER_H