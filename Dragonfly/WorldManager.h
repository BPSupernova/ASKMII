#ifndef WORLD_MANAGER_H
#define WORLD_MANAGER_H

#include "Manager.h"
#include "ViewObject.h"
#include "ObjectList.h"
#include <stdio.h>
#include <map>

#define WM df::WorldManager::getInstance()

namespace df {
	const int MAX_ALTITUDE = 4;

	class WorldManager : public Manager {
	private:
		Box world_boundary; // World boundary
		Box view; // Player view of the game world (their visual window)

		Object* p_obj_followed; // The Object view is following

		WorldManager(); // Singleton
		WorldManager(WorldManager const&); // Doesn't allow copying
		void operator = (WorldManager const&); // Doesn't allow assignment

		df::ObjectList object_updates; // All game Objects to update
		df::ObjectList deletions; // All game Objects to delete

	public:
		static WorldManager &getInstance(); // Get WorldManager instance
		int startUp(); // Initialize everything in game world; Return 0 upon success
		void shutDown(); // Shutdown the game world and delete all game world Objects

		void setBoundary(Box new_boundary); // Set the game world boundary
		Box getBoundary() const; // Get the game world boundary

		void setView(Box new_view); // Set player view of game world
		Box getView() const; // Get player view of game world

		void setViewPosition(Vector2D view_pos); // Set view to center window on position view_pos; View edge will not go beyond world_boundary
		int setViewFollowing(Object* p_new_obj_to_follow); // Set view to center window on Object; Set NULL to stop following; If parameter object not legit, return -1; Return 0 upon success

		int insertObjectToWorld(Object* p_o); // Inserts Object into game world; 0 upon success, -1 otherwise
		int removeObjectFromWorld(Object* p_o); // Deletes Object from game world; 0 upon success, -1 otherwise

		df::ObjectList getAllObjects() const; // Returns a list of all game Objects in the world
		df::ObjectList getObjectsOfType(std::string type) const; // Returns a list of all game Objects in the world of the parameter type

		void UpdateWorld(); // Continually updates the game world and marks Objects for deletion
		int MarkForDelete(Object *p_o); // Indicates an Object to be deleted at the end of the current game loop; 0 upon success, -1 otherwise
		void draw(); // Draws all objects in the world

		ObjectList getCollisions(const Object* p_o, Vector2D where); // Returns list of objects collided w/at position 'where'; only solid objects collide; doesn't consider solidness of p_o
		int moveObject(Object* p_o, Vector2D where); // Move object; if solid send collision events; if object is SPECTRAL or there is no collision w/a solid, move is ok; return 0 upon success, -1 otherwise
		bool positionsIntersect(Vector2D pos_1, Vector2D pos_2); // Helper function to detect collisions via overlap
		bool boxIntersectsBox(Box A, Box B); // Return true if the two Boxes intersect, false otherwise
	
		Box getWorldBox(const Object* p_o); // Convert relative bounding Box for Object to absolute world Box
		Box getWorldBox(const Object* p_o, Vector2D where); // Does what getWorldBox() does to an Object at position where
	};
}

#endif

