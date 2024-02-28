#include "EventKeyboard.h"
#include "GameManager.h"
#include "DisplayManager.h"
#include "LegacyResults.h"

// Want to end game after results are shown and encourage them to play again

LegacyResults::LegacyResults() {
    setViewString("You Died As An Average Joe!");
    setLocation(df::CENTER_CENTER);
    setColor(df::MAGENTA);
    setPosition(df::Vector2D(this->getPosition().getX(), this->getPosition().getY() + 2));

    df::Vector2D quit_prompt_pos(40, 16);
    Prompt quit_text;
    quit_text.setViewString("Press q to quit, and thanks for playing!");
    quit_text.setPosition(quit_prompt_pos);
    setPrompt(quit_text);

    df::Vector2D tombstone_pos(40, 8.5);
    df::Object tombstone;
    tombstone.setPosition(tombstone_pos);
    tombstone.setSprite("tombstone");
    setTombstone(tombstone);

    // Play start music.
    p_music = RM.getMusic("end music");
    playMusic();
}

LegacyResults::~LegacyResults() {

}

int LegacyResults::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*)p_e;
        if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
            switch (p_keyboard_event->getKey()) {
            case df::Keyboard::Q: // Quit
                GM.setGameOver();
                break;
            
            default:
                break;
            }
        return 1;
    }
	
	return 0;
}

int LegacyResults::draw() {
    std::string temp_string;

    // Display view_string 
    temp_string = getViewString();

    // Draw centered at position
    df::Vector2D pos = DM.getInstance().viewToWorld(getPosition());
    DM.getInstance().drawString(pos, temp_string, df::CENTER_JUSTIFIED, getColor());
    return 0;
}

// Play start music.
void LegacyResults::playMusic() {
    p_music->play(false);
}

void LegacyResults::setPrompt(Prompt new_prompt) {
    quit_prompt = new_prompt;
}

Prompt LegacyResults::getPrompt() const {
    return quit_prompt;
}

void LegacyResults::setTombstone(df::Object new_stone) {
    tombstone = new_stone;
}


