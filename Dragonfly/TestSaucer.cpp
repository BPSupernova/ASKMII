// System includes.
#include <stdlib.h>		// for rand()

// Engine includes.
#include "EventCollision.h"
#include "TestEventNuke.h"
#include "EventOut.h"
#include "EventView.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

// Game includes.
#include "TestExplosion.h"
#include "TestPoints.h"
#include "TestSaucer.h"

TestSaucer::TestSaucer() {

    // Setup "TestSaucer" sprite.
    setSprite("saucer");

    // Set object type.
    setType("TestSaucer");

    // Set speed in horizontal direction.
    setVelocity(df::Vector2D(-0.25, 0)); // 1 space left every 4 frames

    // Move TestSaucer to start location.
    moveToStart();

    // Register interest in "nuke" event.
#ifdef DF_REGISTER_INTEREST
    registerInterest(NUKE_EVENT);
#endif
}

TestSaucer::~TestSaucer() {
    // Send "view" event with points to interested ViewObjects.
    // Add 10 points.
    df::EventView ev(POINTS_STRING, 10, true);
    WM.onEvent(&ev);
}

// Handle event.
// Return 0 if ignored, else 1.
int TestSaucer::eventHandler(const df::Event* p_e) {

    if (p_e->getType() == df::OUT_EVENT) {
        out();
        return 1;
    }

    if (p_e->getType() == df::COLLISION_EVENT) {
        const df::EventCollision* p_collision_event = dynamic_cast <df::EventCollision const*> (p_e);
        hit(p_collision_event);
        return 1;
    }

    if (p_e->getType() == NUKE_EVENT) {

        // Create explosion.
        TestExplosion* p_explosion = new TestExplosion;
        p_explosion->setPosition(this->getPosition());

        // Delete self.
        WM.MarkForDelete(this);

        // Saucers appear stay around perpetually
        new TestSaucer;
    }

    // If get here, have ignored this event.
    return 0;
}

// If moved off left edge, move back to far right.
void TestSaucer::out() {

    // If haven't moved off left edge, then nothing to do.
    if (getPosition().getX() >= 0)
        return;

    // Otherwise, move back to far right.
    moveToStart();

    // Spawn new TestSaucer to make the game get harder.
    new TestSaucer;

}

// Called with TestSaucer collides.
void TestSaucer::hit(const df::EventCollision* p_collision_event) {

    // If TestSaucer on TestSaucer, ignore.
    if ((p_collision_event->getObject1()->getType() == "TestSaucer") &&
        (p_collision_event->getObject2()->getType() == "TestSaucer"))
        return;

    // If Bullet, create explosion and make new TestSaucer.
    if ((p_collision_event->getObject1()->getType() == "TestBullet") ||
        (p_collision_event->getObject2()->getType() == "TestBullet")) {

        // Create an explosion.
        TestExplosion* p_explosion = new TestExplosion;
        p_explosion->setPosition(this->getPosition());

        // Play "explode" sound
        df::Sound* p_sound = RM.getSound("explode");
        p_sound->play();

        // Saucers appear stay around perpetually.
        new TestSaucer;
    }

    // If Hero, mark both objects for destruction.
    if (((p_collision_event->getObject1()->getType()) == "TestHero") ||
        ((p_collision_event->getObject2()->getType()) == "TestHero")) {
        WM.MarkForDelete(p_collision_event->getObject1());
        WM.MarkForDelete(p_collision_event->getObject2());
    }

}

// Move TestSaucer to starting location on right side of window.
void TestSaucer::moveToStart() {
    df::Vector2D temp_pos;

    // Get world boundaries.
    int world_horiz = (int)WM.getBoundary().getHorizontal();
    int world_vert = (int)WM.getBoundary().getVertical();

    // x is off right side of window.
    temp_pos.setX((float)(world_horiz + rand() % world_horiz + 3));

    // y is in vertical range.
    temp_pos.setY(rand() % (world_vert - 4) + 4.0f);

    // If collision, move right slightly until empty space.
#ifdef STL
    std::vector<Object*> collision_list = WM.getCollisions(this, temp_pos);
    while (!collision_list.empty()) {
        temp_pos.setX(temp_pos.getX() + 1);
        collision_list = WM.getCollisions(this, temp_pos);
    }
#else
    df::ObjectList collision_list = WM.getCollisions(this, temp_pos);
    while (!collision_list.isEmpty()) {
        temp_pos.setX(temp_pos.getX() + 1);
        collision_list = WM.getCollisions(this, temp_pos);
    }
#endif

    WM.moveObject(this, temp_pos);
}