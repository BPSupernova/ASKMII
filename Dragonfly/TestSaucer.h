#include "Object.h"
#include "EventCollision.h"

class TestSaucer : public df::Object {

private:
	void moveToStart();
	void out();
	void hit(const df::EventCollision* p_collision_event);

public:
	TestSaucer();
	~TestSaucer();
	int eventHandler(const df::Event* p_e);
};
