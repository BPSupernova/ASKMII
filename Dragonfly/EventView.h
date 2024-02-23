#ifndef EVENTVIEW_H
#define EVENTVIEW_H

#include "Event.h"

namespace df {
	const std::string VIEW_EVENT = "df::view";

	class EventView : public Event {
	private:
		std::string tag; // Tag to associate
		int value; // Value for view
		bool delta; // True if change in value, else replace value

	public:
		EventView(); // Create new event with tag VIEW_EVENT, value 0, and delta false
		EventView(std::string new_tag, int new_value, bool new_delta); // Create view event with tag, value, and delta as indicated
		
		void setTag(std::string new_tag); // Set tag to new tag
		std::string getTag() const; // Get tag

		void setValue(int new_value); // Set value to new value
		int getValue() const; // Get the value for view

		void setDelta(bool new_delta); // Set delta to new delta
		bool getDelta() const; // Get delta
	};

}

#endif
