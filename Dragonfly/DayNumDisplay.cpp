#include "DayNumDisplay.h"

DayNumDisplay::DayNumDisplay() {
    setLocation(df::TOP_CENTER);
    setViewString(DAY_STRING);
    setColor(df::GREEN);
    setBorder(false);
}

void DayNumDisplay::setDisplayedValue(int days) {
    if (days > 21 || days < 1) {
        setValue(21);
    }
    else {
        setValue(days);
    }
}


int DayNumDisplay::eventHandler(const df::Event* p_e) {
	return 0;
}
