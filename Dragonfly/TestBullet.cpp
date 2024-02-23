// Engine includes.
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "EventOut.h"

// Game includes.
#include "TestBullet.h"
#include "TestSaucer.h"

TestBullet::TestBullet(df::Vector2D hero_pos) {

	// Link to "bullet" sprite.
	setSprite("bullet");

	// Set other object properties.
	setType("Bullet");
	setVelocity(df::Vector2D(1, 0)); // Move 1 space right every game loop.

	// Set starting location, based on hero's position passed in.
	df::Vector2D p(hero_pos.getX() + 3, hero_pos.getY());
	setPosition(p);
}


// Handle event.
// Return 0 if ignored, else 1.
int TestBullet::eventHandler(const df::Event* p_e) {

	if (p_e->getType() == df::OUT_EVENT) {
		out();
		return 1;
	}

	if (p_e->getType() == df::COLLISION_EVENT) {
		const df::EventCollision* p_collision_event = dynamic_cast <const df::EventCollision*> (p_e);
		hit(p_collision_event);
		return 1;
	}

	// If get here, have ignored this event.
	return 0;
}

// If Bullet moves outside world, mark self for deletion.
void TestBullet::out() {
	WM.MarkForDelete(this);
}

// If Bullet hits Saucer, mark Saucer and Bullet for deletion.
void TestBullet::hit(const df::EventCollision* p_collision_event) {
	if ((p_collision_event->getObject1()->getType() == "TestSaucer") ||
		(p_collision_event->getObject2()->getType() == "TestSaucer")) {
		WM.MarkForDelete(p_collision_event->getObject1());
		WM.MarkForDelete(p_collision_event->getObject2());
	}
}
