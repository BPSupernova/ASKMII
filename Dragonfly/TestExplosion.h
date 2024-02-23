#include "Object.h"

class TestExplosion : public df::Object {

private:
	int time_to_live;
	void step();

public:
	TestExplosion();
	int eventHandler(const df::Event* p_e);
};