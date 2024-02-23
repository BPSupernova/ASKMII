#ifndef EVENT_COLLISION_H
#define EVENT_COLLISION_H

#include "Event.h"
#include "Object.h"

namespace df {
	const std::string COLLISION_EVENT = "df::collision";

	class EventCollision : public Event {
	private:
		Vector2D c_pos; // Where the collision occurred
		Object* p_obj1; // Object causing collision
		Object* p_obj2; // Object being collided with

	public:
		EventCollision(); // Create collision event at (0,0) with object1 & object2 NULL

		// Collision event between o1 and o2 at position p; o1 caused the collision, moving into o2
		EventCollision(Object* p_o1, Object* p_o2, Vector2D p);

		void setObject1(Object* initiator_obj); // Set the object causing the collision
		Object* getObject1() const; // Returns the object causing the collision

		void setObject2(Object* victum_obj); // Set the object being collided with
		Object* getObject2() const; // Returns the object being collided with

		void setCollisionLocation(Vector2D new_pos); // Set the position of the collision
		Vector2D getCollisionLocation() const; // Returns the position of the collision
	};
}

#endif