#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <sstream>
#include "Vector2D.h"
#include "Event.h"
#include "Animation.h"
#include "Box.h"

namespace df {

	enum Solidness {
		HARD, // Object causes collisions and impedes movement
		SOFT, // Object causes collisions but doesn't impede in movement
		SPECTRAL, // Object doesn't cause collisions
	};

	class Object {
	private:
		int o_id; // Unique game engine defined identifier
		std::string o_type; // Game programmer defined type
		df::Vector2D o_position; // Object's position in game world
		int o_altitude; // Drawing layer; 0 to MAX layers supported (lower drawn first)
		Solidness o_solidness; // Solidness of object (for collisions)

		Vector2D o_direction; // Direction vector
		float o_speed; // Object speed in direction

		Animation o_animation; // Object's sprite based animation
		Box o_box; // Box for sprite boundry and collisions

	public:
		Object(); // Constructs & adds object to game world via WorldManager
		virtual ~Object(); // Destroys object, which removes it from the game world via WorldManager

		virtual int eventHandler(const Event* p_e); // Object specific handler
		virtual int draw(); // Draw Object Animation; Return 0 upon success, -1 otherwise

		void setID(int new_o_id); // set the object's unique id
		int getID() const; // get the object's unique id

		void setType(std::string new_type); // Set the type identifier of object
		std::string getType() const; // Get the type identifier of object

		void setPosition(Vector2D new_pos); // Set position of object
		df::Vector2D getPosition() const; // Get position of object
	
		int setAltitude(int new_altitude); // Set the altitude of the Object; Returns 0 upon success, -1 otherwise
		int getAltitude() const; // Returns the altitude of the Object
	
		void setSpeed(float new_speed); // Sets the objects speed
		float getSpeed(); // Gets the speed of Object

		void setDirection(Vector2D new_direction); // Sets the direction of Object
		Vector2D getDirection() const; // Gets the direction vector of Object

		void setVelocity(Vector2D new_velocity); // Sets the direction and speed of Object
		Vector2D getVelocity() const; // Gets the velocity of the Object based on speed and direction

		Vector2D predictPosition(); // Predict object position based on speed and direction; Returns predicted position
	
		int setSolidness(Solidness new_solidness); // Sets the solidness of an object; Return 0 upon success, -1 otherwise
		Solidness getSolidness() const; // Returns the object's solidness

		bool isSolid() const; // Return true if object is HARD or SOFT, otherwise return false

		int setSprite(std::string sprite_label); // Set sprite for this Object to animate; Return 0 upon success, -1 otherwise

		void setAnimation(Animation new_anim); // Set animation for this Object to new one; Set bounding box to size of associated sprite
		Animation getAnimation() const; // Get the Animation for this Object
	
		void setBox(Box new_box); // Set Object's bounding box
		Box getBox() const; // Get an Object's bounding box

		std::string toString(int i); // General purpose; converts an integer to a std::string
	};
}
#endif