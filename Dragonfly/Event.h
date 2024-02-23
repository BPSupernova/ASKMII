#ifndef EVENT_H
#define EVENT_H

#include <string>

namespace df {
	const std::string UNDEFINED_EVENT = "df::undefined";

	class Event {
	private:
		std::string event_type; // Holds the Event's type

	public:
		Event(); // Creates base Event
		virtual ~Event(); // Virtual destructor allows polymorphism

		void setType(std::string new_type); 
		std::string getType() const;
	};
}

#endif