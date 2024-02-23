#include "Object.h"

#define RETICLE_CHAR '+'

class TestReticle : public df::Object {

public:
	TestReticle();
	int draw(void);
	int eventHandler(const df::Event* p_e);
};