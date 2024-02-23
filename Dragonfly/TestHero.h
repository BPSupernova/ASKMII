#include "EventKeyboard.h"
#include "EventMouse.h"
#include "Object.h"
#include "TestReticle.h"

class TestHero : public df::Object {

private:
	TestReticle* p_reticle;
	int fire_slowdown;
	int fire_countdown;
	int move_slowdown;
	int move_countdown;
	int nuke_count;
	void mouse(const df::EventMouse* p_mouse_event);
	void kbd(const df::EventKeyboard* p_keyboard_event);
	void move(int dy);
	void fire(df::Vector2D target);
	void step();
	void nuke();

public:
	TestHero();
	~TestHero();
	int eventHandler(const df::Event* p_e);
};

