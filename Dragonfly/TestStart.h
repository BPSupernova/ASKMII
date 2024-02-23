#include "Music.h"
#include "ViewObject.h"

class TestStart : public df::ViewObject {

private:
	df::Music* p_music;
	void start();

public:
	TestStart();
	int eventHandler(const df::Event* p_e);
	int draw();
	void playMusic();
};
