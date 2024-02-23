#include "Object.h"

#define STAR_CHAR '.'

class TestStar : public df::Object {

private:
	void out();

public:
	TestStar();
	int draw(void);
	int eventHandler(const df::Event* p_e);
};
