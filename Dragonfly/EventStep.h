#ifndef EVENT_STEP_H
#define EVENT_STEP_H

#include "Event.h"

namespace df {
	const std::string STEP_EVENT = "df::step";
	class EventStep : public Event {
	
	private:
		int e_step_count; // Iteration number of game loop

	public:
		EventStep(); // Default constructor
		EventStep(int init_step_count); // Constructor with an initial step count
		void setStepCount(int new_step_count);
		int getStepCount() const;
	};
}

#endif

