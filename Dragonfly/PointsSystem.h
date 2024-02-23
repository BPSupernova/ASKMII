#include <string>

class PointsSystem {
private:
	// Adjust number upon adding or removing legacies from game plan
	// The names of the legacies players can obtain at the end of the game
	std::string legacies[8]; 
	int points[8]; // Associated with the legacies and the points alloted to each one

public:
	PointsSystem(); // Set all indices to be legacies written up in game plan and give them all an initial points count of 0

	void setLegacy(std::string new_legacy, int legacy_index); // Sets the title of a legacy at the indicated legacy_index
	std::string getLegacy(int legacy_index); // Returns the legacy at the given index with the PointsSystem

	void setLegacyPoints(int new_points, std::string legacy); // Sets the amount of points associated with a given legacy
	int getLegacyPoints(std::string legacy); // Returns the amount of points a legacy has
};