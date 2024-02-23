#include "utility.h"
#include <time.h> 

char* df::utility::getTimeString()
{
	/* Sort this functionality out later if able */
	
	/*// String to be returned; in format HH:MM:SS (hour::minutes::seconds)
	static char time_str[30];

	time_t now;
	time(&now); // System call to get time
	struct tm* p_time = localtime(&now);

	// 02 gives two digits
	sprintf(time_str, " % 02d: % 02 d : % 02 d",
		p_time->tm_hour,
		p_time->tm_min,
		p_time->tm_sec);
	return time_str;*/
	static char time_str_placehldr[30] = "Placeholder\n";
	return time_str_placehldr;
}

bool df::utility::positionsIntersect(Vector2D pos_1, Vector2D pos_2)
{
	if ((abs(pos_1.getX() - pos_2.getX()) <= 1) &&
		(abs(pos_1.getX() - pos_2.getX()) <= 1)) {
		return true;
	} else {
		return false;
	}
}