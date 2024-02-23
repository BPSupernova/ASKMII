// Engine includes.
#include "LogManager.h"
#include "DisplayManager.h"
#include "EventMouse.h"
#include "WorldManager.h"

// Game includes.
#include "TestReticle.h"

TestReticle::TestReticle() {
    setType("TestReticle");
    setSolidness(df::SPECTRAL);
    setAltitude(df::MAX_ALTITUDE); // Make TestReticle in the foreground.

    // TestReticle moves with mouse, so register.
#ifdef DF_REGISTER_INTEREST
    registerInterest(df::MSE_EVENT);
#endif

    // Start TestReticle in center of window.
    df::Vector2D p(WM.getBoundary().getHorizontal() / 2,
        WM.getBoundary().getVertical() / 2);
    setPosition(p);
}

// Handle event.
// Return 0 if ignored, else 1.
int TestReticle::eventHandler(const df::Event* p_e) {

    if (p_e->getType() == df::MSE_EVENT) {
        const df::EventMouse* p_mouse_event = dynamic_cast <const df::EventMouse*> (p_e);
        if (p_mouse_event->getMouseAction() == df::MOVED) {
            // Change location to new mouse position.
            setPosition(p_mouse_event->getMouseCursorPos());
            return 1;
        }
    }

    // If get here, have ignored this event.
    return 0;
}

// Draw TestReticle on window.
int TestReticle::draw() {
    DM.drawChar(getPosition(), RETICLE_CHAR, df::RED);
    return 0;
}