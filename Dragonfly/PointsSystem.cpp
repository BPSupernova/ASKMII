#include "PointsSystem.h"
#include "LogManager.h"

PointsSystem::PointsSystem() {
	legacies[0] = "A Loser";
	legacies[1] = "An Unfulfilled Man";
	legacies[2] = "The Main Antagonist";
	legacies[3] = "Average Joe";
	legacies[4] = "An Enigma";
	legacies[5] = "A Gentleman";
	legacies[6] = "An Unsung Hero";
	legacies[7] = "An Absolute Legend";
	
	for (int i = 0; i < legacies->size(); i++) {
		points[i] = 0;
	}
}

void PointsSystem::setLegacy(std::string new_legacy, int legacy_index) {
	legacies[legacy_index] = new_legacy;
}

std::string PointsSystem::getLegacy(int legacy_index) {
	return legacies[legacy_index];
}

void PointsSystem::setLegacyPoints(int new_points, std::string legacy) {
	for (int i = 0; i < legacies->size(); i++) {
		if (legacies[i] == legacy) {
			points[i] = new_points;
		}
	}
}

int PointsSystem::getLegacyPoints(std::string legacy) {
	for (int i = 0; i < legacies->size(); i++) {
		if (legacies[i] == legacy) {
			return points[i];
		}
	}
	
	LM.getInstance().writeLog("Class: PointsSystem ; Method: getLegacyPoints -> Invalid legacy input (legacy doesn't exist)");
	return -1; // Points not found
}
