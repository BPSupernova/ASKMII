#include "Object.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "LogManager.h"

using std::stringstream;

df::Object::Object() {
	static int unique_id = 0; // Variable id is obtained from
	o_id = unique_id; 
	unique_id += 1; // Increment for next object

	o_type = "Object";

	df::Vector2D intitial_vec;
	o_position = intitial_vec; // Default position when initialized in game world (0,0)
	
	o_altitude = (MAX_ALTITUDE / 2); // Set initial altitude to half the max

	o_solidness = df::HARD; // Initializes object to enable collisions and impede movement when overlapping with other objects

	// Initialize object as stationary
	o_speed = 0;
	o_direction.setXY(0,0);

	o_animation = *(new Animation());
	
	df::Vector2D o_box_corner_pos;
	o_box_corner_pos.setXY(-0.5, -0.5);
	o_box.setCorner(o_box_corner_pos);
	o_box.setHorizontal(0.99);
	o_box.setVertical(0.99);

	WM.getInstance().insertObjectToWorld(this); // Add self into the game world  
}

df::Object::~Object() {
	WM.getInstance().removeObjectFromWorld(this); // Destroy Object and delete from WorlManager
}

int df::Object::eventHandler(const Event* p_e)
{
	return 0;
}

int df::Object::draw() {
	Vector2D obj_position = o_position;
	if (o_animation.getSprite() == NULL) {
		return -1;
	}
	return o_animation.draw(obj_position);
}

void df::Object::setID(int new_o_id) {
	o_id = new_o_id;
}

int df::Object::getID() const {
	return o_id;
}

void df::Object::setType(std::string new_type) {
	o_type = new_type;
}

std::string df::Object::getType() const {
	return o_type;
}

void df::Object::setPosition(Vector2D new_pos) {
	o_position = new_pos;
}

df::Vector2D df::Object::getPosition() const {
	return o_position;
}

int df::Object::setAltitude(int new_altitude) {
	if (new_altitude < 0 || new_altitude > MAX_ALTITUDE) { 
		return -1; 
	}
	o_altitude = new_altitude;
	return 0;
}

int df::Object::getAltitude() const {
	return o_altitude;
}

void df::Object::setSpeed(float new_speed) {
	o_speed = new_speed;
}

float df::Object::getSpeed() {
	return o_speed;
}

void df::Object::setDirection(Vector2D new_direction) {
	o_direction = new_direction;
}

df::Vector2D df::Object::getDirection() const {
	return o_direction;
}

void df::Object::setVelocity(Vector2D new_velocity) {
	o_speed = new_velocity.getMagnitude();
	new_velocity.normalize();
	o_direction = new_velocity;
}

df::Vector2D df::Object::getVelocity() const {
	Vector2D return_vector;
	return_vector = o_direction;
	return_vector.scale(o_speed);
	return return_vector;
}

df::Vector2D df::Object::predictPosition() {
	return o_position + getVelocity();
}

int df::Object::setSolidness(Solidness new_solidness) {
	o_solidness = new_solidness;
	if (new_solidness == NULL) { return -1; }
	return 0;
}

df::Solidness df::Object::getSolidness() const {
	return o_solidness;
}

bool df::Object::isSolid() const {
	if (o_solidness != df::HARD && o_solidness != df::SOFT) { return false; }
	return true;
}

int df::Object::setSprite(std::string sprite_label) {
	Sprite* p_o_sprite = RM.getSprite(sprite_label);
	if (p_o_sprite == NULL) {
		LM.getInstance().writeLog("Class: Object ; Method: setSprite -> Parameter sprite is NULL");
		return -1;
	}
	
	o_animation.setSprite(p_o_sprite);
	setBox(o_animation.getBox());

	return 0;
}

void df::Object::setAnimation(Animation new_anim) {
	o_animation = new_anim;
}

df::Animation df::Object::getAnimation() const {
	return o_animation;
}

void df::Object::setBox(Box new_box) {
	o_box = new_box;
}

df::Box df::Object::getBox() const {
	return o_box;
}

std::string df::Object::toString(int i) {
	std::stringstream ss; // Create a stringstream
	ss << 1; // Add the number to the stream
	
	return ss.str(); // Returns string with contents of stream
}
