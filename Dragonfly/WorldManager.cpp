#include "WorldManager.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "utility.h"
#include <iostream>

df::WorldManager::WorldManager() {
	object_updates = ObjectList();
	deletions = ObjectList();
	p_obj_followed = NULL;
	
	Vector2D zero_zero;
	world_boundary = *(new Box(zero_zero, df::WINDOW_HORIZONTAL_CHARS_DEFAULT, df::WINDOW_VERTICAL_CHARS_DEFAULT)); // World boundary
	view = *(new Box(zero_zero, df::WINDOW_HORIZONTAL_CHARS_DEFAULT, df::WINDOW_VERTICAL_CHARS_DEFAULT)); // Player view of the game world (their visual window)

	setType("WorldManager");
}

df::WorldManager &df::WorldManager::getInstance() { 
	static WorldManager world_manager;
	return world_manager;
}

int df::WorldManager::startUp()
{
	object_updates.clear();
	deletions.clear();
	df::Manager::startUp();
	return 0;
}

void df::WorldManager::shutDown() {
	ObjectList ol = object_updates; // Copy list
	ObjectListIterator li(&ol);
	
	for (li.first(); !li.atEnd(); li.next()) {
		MarkForDelete(li.currentObject());
	}
	df::Manager::shutDown();
}

void df::WorldManager::setBoundary(Box new_boundary) {
	world_boundary = new_boundary;
}

df::Box df::WorldManager::getBoundary() const {
	return world_boundary;
}

void df::WorldManager::setView(Box new_view) {
	view = new_view;
}

df::Box df::WorldManager::getView() const { 
	return view;
}

void df::WorldManager::setViewPosition(Vector2D view_pos) {
	// Check whether horizontal of view_pos is out of world boundary; adjust accordingly if so
	int x = view_pos.getX() - view.getHorizontal() / 2;
	if (x + view.getHorizontal() > world_boundary.getHorizontal()) {
		x = world_boundary.getHorizontal() - view.getHorizontal();
	}
	if (x < 0) { x = 0; } 

	// Check whether vertical of view_pos is out of world boundary; adjust accordingly if so
	int y = view_pos.getY() - view.getVertical() / 2;
	if (y + view.getVertical() > world_boundary.getVertical()) {
		y = world_boundary.getVertical() - view.getVertical();
	}
	if (y < 0) { y = 0; }

	// Set view
	Vector2D new_corner(x, y);
	view.setCorner(new_corner);
}

int df::WorldManager::setViewFollowing(Object* p_new_obj_to_follow) {
	// Set to NULL to "disable" following
	if (p_new_obj_to_follow == NULL) {
		p_obj_followed == NULL;
		return 0; // Still ok, means view isn't following anything particular
	}
	
	bool found_obj_to_follow = false;

	// Iterate over all objects in world to find the object we want to follow
	ObjectList ol = object_updates; // Copy list 
	ObjectListIterator li(&ol); 

	while (!li.atEnd()) {
		if (li.currentObject() == p_new_obj_to_follow) {
			found_obj_to_follow = true;
			break;
		}
	}

	if (found_obj_to_follow) {
		p_obj_followed = p_new_obj_to_follow;
		setViewPosition(p_obj_followed->getPosition());
		return 0; // Success, object to follow found
	}
	
	LM.getInstance().writeLog("Class: WorldManager ; Method: setViewFollowing -> Invalid Object parameter");
	return -1; // Object not found ; likely parameter was not legit
}

int df::WorldManager::insertObjectToWorld(Object* p_o) {
	object_updates.insert(p_o);
	return 0;
}

int df::WorldManager::removeObjectFromWorld(Object* p_o) {
	object_updates.remove(p_o);
	return 0;
}

df::ObjectList df::WorldManager::getAllObjects() const {
	return object_updates;
}

df::ObjectList df::WorldManager::getObjectsOfType(std::string type) const {
	ObjectList list;
	ObjectListIterator list_iterator(&object_updates);

	for (list_iterator.first(); !list_iterator.atEnd(); list_iterator.next()) {
		if (list_iterator.currentObject()->getType() == type) {
			list.insert(list_iterator.currentObject());
		}
	}
	return list;
}

void df::WorldManager::UpdateWorld() {
	ObjectListIterator update_pos_iterator(&object_updates);
	ObjectListIterator deleter_iterator(&deletions);
	
	while (!update_pos_iterator.atEnd()) {
		Vector2D new_pos = update_pos_iterator.currentObject()->predictPosition(); // Add velocity to position
		
		if (new_pos == update_pos_iterator.currentObject()->getPosition()) {
			//std::cout << "Stationary object" << std::endl;
			;
		} else {
			moveObject(update_pos_iterator.currentObject(), new_pos); // Moves object in game world; also handles collisions
		}
		update_pos_iterator.next();
	}

	while (!deleter_iterator.atEnd()) {
		delete(deleter_iterator.currentObject());
		deleter_iterator.next();
	}
	deletions.clear();
}

int df::WorldManager::MarkForDelete(Object* p_o) {
	ObjectListIterator deletor_iterator(&deletions);

	while (!deletor_iterator.atEnd()) {
		if (deletor_iterator.currentObject() == p_o) {
			return 0;
		}
		deletor_iterator.next();
	}
	deletions.insert(p_o);
	return -1;
}

void df::WorldManager::draw() {
	ObjectListIterator artist_it(&object_updates);

	while (!artist_it.atEnd()) {
		Object* p_temp_o = artist_it.currentObject();
		
		for (int altitude_draw = 0; altitude_draw <= MAX_ALTITUDE; altitude_draw++) {
			if (p_temp_o->getAltitude() == altitude_draw) {
				Box temp_box = getWorldBox(p_temp_o);
				if (boxIntersectsBox(temp_box, view) || 
					dynamic_cast <ViewObject *> (p_temp_o)) {
					p_temp_o->draw();
				}
			}
		}
		
		artist_it.next();
	}
}

df::ObjectList df::WorldManager::getCollisions(const Object* p_o, Vector2D where)
{
	// if (p_o == NULL) { return ObjectList(); }
	ObjectList collision_list;
	ObjectListIterator collision_seeker(&object_updates);

	while (!collision_seeker.atEnd()) {
		Object* p_temp_o = collision_seeker.currentObject();

		if (p_temp_o != p_o) { // Do not consider self
			// Check if they are at the same location and are both solid
			Box p_o_bounding_box = getWorldBox(p_o, where);
			Box p_temp_bounding_box = getWorldBox(p_temp_o);

			if (boxIntersectsBox(p_o_bounding_box, p_temp_bounding_box) && p_temp_o->isSolid()) {
				collision_list.insert(p_temp_o); // Object collided with
			}
		}
		collision_seeker.next();
	}

	return collision_list;
}

int df::WorldManager::moveObject(Object* p_o, Vector2D where) {
	if (p_o->isSolid()) { // For collisions to occur object must be solid
		ObjectList collisions = getCollisions(p_o, where);

		if (!collisions.isEmpty()) {
			bool do_move = true; // Assume the object can move

			ObjectListIterator collision_iterator(&collisions);
			while (!collision_iterator.atEnd()) {
				Object* p_temp_o = collision_iterator.currentObject();
				EventCollision c(p_o, p_temp_o, where); // Collision event
				
				// Send collision event to both objects
				p_o->eventHandler(&c);
				p_temp_o->eventHandler(&c);

				// If both HARD, then cannot move
				if ((p_o->getSolidness() == df::HARD) && (p_temp_o->getSolidness() == df::HARD)) {
					do_move = false; // Prohibits movement
				}
				collision_iterator.next();
			}
			if (!do_move) { return -1; } // The object is not allowed to move post collision
		}
	}
	Box orig_box = getWorldBox(p_o); // Original bounding box
	p_o->setPosition(where); // Reaching here means the collision is not made up of two HARD objects, allow move
	Box new_box = getWorldBox(p_o); // New bounding box

	if (boxIntersectsBox(orig_box, world_boundary) && !boxIntersectsBox(new_box, world_boundary)) { // Check if object was repositioned outside window
		// Generate an out of bounds event and send to the Object
		EventOut out_event;
		p_o->eventHandler(&out_event);
	}

	if (p_obj_followed == p_o) {
		setViewPosition(p_o->getPosition());
	}
	
	return 0;
}

bool df::WorldManager::positionsIntersect(Vector2D pos_1, Vector2D pos_2) {
	if ((abs(pos_1.getX() - pos_2.getX()) <= 1) &&
		(abs(pos_1.getY() - pos_2.getY()) <= 1)) {
		return true;
	} else {
		return false;
	}
}

bool df::WorldManager::boxIntersectsBox(Box A, Box B) {
	bool x_overlap = false; // Horizontal overlap
	bool y_overlap = false; // Vertical overlap

	// Test horizontal overlap
		// Left side of A in B
	if (B.getCorner().getX() <= A.getCorner().getX() &&
		A.getCorner().getX() <= (B.getCorner().getX() + B.getHorizontal())) {
		x_overlap = true;
	}

		// Left side of B in A
	if (A.getCorner().getX() <= B.getCorner().getX() &&
		B.getCorner().getX() <= (A.getCorner().getX() + A.getHorizontal())) {
		x_overlap = true;
	}

	// Test for vertical overlap
		// Top side of A in B
	if (B.getCorner().getY() <= A.getCorner().getY() &&
		A.getCorner().getY() <= (B.getCorner().getY() + B.getVertical())) {
		y_overlap = true; 
	}
		// Top side of B in A
	if (A.getCorner().getY() <= B.getCorner().getY() &&
		B.getCorner().getY() <= (A.getCorner().getY() + A.getVertical())) {
		y_overlap = true; 
	}

	if (x_overlap && y_overlap) { return true; } // Boxes ddo intersect

	return false; // Boxes do not intersect
}

df::Box df::WorldManager::getWorldBox(const Object* p_o) {
	Box box_in_world = p_o->getBox();
	return getWorldBox(p_o, p_o->getPosition());
}

df::Box df::WorldManager::getWorldBox(const Object* p_o, Vector2D where) {
	Box box_in_world_coords = p_o->getBox();
	Vector2D box_in_world_corner = box_in_world_coords.getCorner();
	box_in_world_corner.setX(box_in_world_corner.getX() + where.getX());
	box_in_world_corner.setY(box_in_world_corner.getY() + where.getY());
	box_in_world_coords.setCorner(box_in_world_corner);
	return box_in_world_coords;
}
