#include "ViewObject.h"

class TestGameOver : public df::ViewObject {

private:
	int time_to_live;
	df::Music* p_music;
	void step();

public:
	TestGameOver();
	~TestGameOver();
	int eventHandler(const df::Event* p_e);
	int draw();
};