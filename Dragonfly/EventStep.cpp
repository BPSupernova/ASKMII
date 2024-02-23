#include "EventStep.h"

df::EventStep::EventStep() {
	e_step_count = 0;
	this->setType(df::STEP_EVENT);
}

df::EventStep::EventStep(int init_step_count) {
	e_step_count = init_step_count;
	this->setType(df::STEP_EVENT);
}

void df::EventStep::setStepCount(int new_step_count) {
	e_step_count = new_step_count;
}

int df::EventStep::getStepCount() const
{
	return e_step_count;
}
