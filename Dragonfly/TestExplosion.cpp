// Engine includes.
#include "EventStep.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

// Game includes.
#include "TestExplosion.h"

TestExplosion::TestExplosion() {

#ifdef DF_REGISTER_INTEREST
    registerInterest(df::STEP_EVENT);
#endif

    // Link to "TestExplosion" sprite.
    if (setSprite("explosion") == 0)
        time_to_live = getAnimation().getSprite()->getFrameCount();
    else
        time_to_live = 0;

    setType("TestExplosion");

    setSolidness(df::SPECTRAL);
}

// Handle event.
// Return 0 if ignored, else 1.
int TestExplosion::eventHandler(const df::Event* p_e) {

    if (p_e->getType() == df::STEP_EVENT) {
        step();
        return 1;
    }

    // If get here, have ignored this event.
    return 0;
}

// Count down until TestExplosion finished.
void TestExplosion::step() {
    time_to_live--;
    if (time_to_live <= 0)
        WM.MarkForDelete(this);
}
