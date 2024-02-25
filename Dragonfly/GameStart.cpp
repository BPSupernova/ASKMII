// Engine includes.
#include "Color.h"
#include "EventKeyboard.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

// Game includes.
#include "GameStart.h"
#include "Music.h"
#include "Day.h"

GameStart::GameStart() {
    setType("GameStart");

    // Link to "message" sprite.
    setSprite("start screen");

    // Put in center of screen.
    setLocation(df::CENTER_CENTER);

    // Register for "keyboard" event.
#ifdef DF_REGISTER_INTEREST
    registerInterest(df::KEYBOARD_EVENT);
#endif

    // Play start music.
    p_music = RM.getMusic("start music");
    playMusic();
}

GameStart::~GameStart() {
    // Create Day
    Timekeeper* tk = new Timekeeper(); // Creates a Timekeeper that counts down the 21 days

    Day twewntyFirstDay = Day(tk->getAndDecrementDaysLeft() + 1); // Spawns the 21st day by spawning a day before that immediately deletes itself
}

// Play start music.
void GameStart::playMusic() {
    p_music->play();
}

// Handle event.
// Return 0 if ignored, else 1.
int GameStart::eventHandler(const df::Event* p_e) {

    if (p_e->getType() == df::KEYBOARD_EVENT) {
        df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*)p_e;
        if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
            switch (p_keyboard_event->getKey()) {
            case df::Keyboard::P: 			// play
                start();
                break;
            case df::Keyboard::Q:			// quit
                GM.setGameOver();
                break;
            default:
                break;
            }
        return 1;
    }

    // If get here, have ignored this event.
    return 0;
}

void GameStart::start() {
    // Pause start music.
    p_music->pause();

    // When game starts, destroy this object.
    WM.MarkForDelete(this);
}

// Override default draw so as not to display "value".
int GameStart::draw() {
    df::Object::draw();
    return 0;
}