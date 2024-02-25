#include "Music.h"
#include "ViewObject.h"

class GameStart : public df::ViewObject {

private:
	df::Music* p_music;
	void start();

public:
	GameStart();
	~GameStart();
	int eventHandler(const df::Event* p_e);
	int draw();
	void playMusic();
};