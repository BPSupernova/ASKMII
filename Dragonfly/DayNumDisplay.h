#include "ViewObject.h"
#include "Timekeeper.h"

#define DAY_STRING "Days Left"

class DayNumDisplay : public df::ViewObject { // A text that reads "Day (number day)" at the top center of the screen
public:
	DayNumDisplay();
	void setDisplayedValue(Timekeeper tk);
	int eventHandler(const df::Event* p_e);
};
