// System includes.
#include <stdlib.h>		// for rand()

// Engine includes.
#include "DisplayManager.h"
#include "EventOut.h"
#include "WorldManager.h"

// Game includes.
#include "TestStar.h"

TestStar::TestStar() {
	setType("TestStar");
	setSolidness(df::SPECTRAL);
	setVelocity(df::Vector2D((float)-1.0 / (rand() % 9 + 2), 0));
	setAltitude(0);	// Make Stars in the background.
	df::Vector2D p((float)(rand() % (int)WM.getBoundary().getHorizontal()),
		(float)(rand() % (int)WM.getBoundary().getVertical()));
	setPosition(p);
}

// Draw TestStar window.
int TestStar::draw() {
	DM.drawChar(getPosition(), STAR_CHAR, df::WHITE);
	return 0;
}

// Handle event.
// Return 0 if ignored, else 1.
int TestStar::eventHandler(const df::Event* p_e) {

	if (p_e->getType() == df::OUT_EVENT) {
		out();
		return 1;
	}

	// If get here, have ignored this event.
	return 0;
}

// If TestStar moved off window, move back to far right.
void TestStar::out() {
	df::Vector2D p((float)(WM.getBoundary().getHorizontal() + rand() % 20),
		(float)(rand() % (int)WM.getBoundary().getVertical()));
	setPosition(p);
}
