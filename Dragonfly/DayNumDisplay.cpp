#include "Timekeeper.h"
#include "DayNumDisplay.h"

DayNumDisplay::DayNumDisplay() {
    setLocation(df::TOP_CENTER);
    setViewString(DAY_STRING);
    setColor(df::GREEN);
    setBorder(false);
}

void DayNumDisplay::setDisplayedValue(Timekeeper tk) {
    if (tk.getTheDaysLeft() > 21 || tk.getTheDaysLeft() < 1) {
        setValue(21);
    }
    else {
        setValue(tk.getTheDaysLeft());
    }
}


int DayNumDisplay::eventHandler(const df::Event* p_e) {
	return 0;
}
