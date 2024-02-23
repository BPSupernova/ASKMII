#include "EventCollision.h"

df::EventCollision::EventCollision() {
	this->setType(df::COLLISION_EVENT);
	p_obj1 = NULL;
	p_obj2 = NULL;
	c_pos.setXY(0,0);
}

df::EventCollision::EventCollision(Object* p_o1, Object* p_o2, Vector2D p) {
	
	this->setType(df::COLLISION_EVENT);
	p_obj1 = p_o1;
	p_obj2 = p_o2;
	c_pos = p;
}

void df::EventCollision::setObject1(Object* initiator_obj) {
	p_obj1 = initiator_obj;
}

df::Object* df::EventCollision::getObject1() const {
	return p_obj1;
}

void df::EventCollision::setObject2(Object* victum_obj) {
	p_obj2 = victum_obj;
}

df::Object* df::EventCollision::getObject2() const {
	return p_obj2;
}

void df::EventCollision::setCollisionLocation(Vector2D new_pos) {
	c_pos = new_pos;
}

df::Vector2D df::EventCollision::getCollisionLocation() const {
	return c_pos;
}
