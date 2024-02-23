#include "EventCollision.h"
#include "Object.h"

class TestBullet : public df::Object {

private:
	void out();
	void hit(const df::EventCollision* p_collision_event);

public:
	TestBullet(df::Vector2D hero_pos);
	int eventHandler(const df::Event* p_e);
};
