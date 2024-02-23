#include "Timekeeper.h"

Timekeeper::Timekeeper() {
	days_left = 21;
}

int Timekeeper::getTheDaysLeft() { // Solely returns the current amount of Days left
	return days_left;
}

int Timekeeper::getAndDecrementDaysLeft() { // Returns the current amount of Days left and decrements
	int days = getTheDaysLeft();
	days_left--;
	return days;
}