#include "ViewObject.h"
#include "ResourceManager.h"
#include "Music.h"
#include "Prompt.h"

class LegacyResults : public df::ViewObject {
private:
	df::Object tombstone;
	df::Music* p_music;
	Prompt quit_prompt;

public:
	LegacyResults();
	~LegacyResults();
	int eventHandler(const df::Event* p_e);
	int draw();
	void playMusic();

	void setPrompt(Prompt new_prompt);
	Prompt getPrompt() const;

	void setTombstone(df::Object new_stone);
};
