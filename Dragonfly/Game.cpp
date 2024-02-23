// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"

// Game includes.
#include "TestStart.h"
#include "TestStar.h"

// Function prototypes.
void loadResources(void);
void populateWorld(void);

int main(int argc, char* argv[]) {

    // Start up game manager.
    if (GM.startUp()) {
        LM.writeLog("Error starting game manager!");
        GM.shutDown();
        return 0;
    }

    // Set flush of logfile during development (when done, make false).
    LM.setFlush(true);

    // Load game resources.
    loadResources();

    // Populate game world with some objects.
    populateWorld();

    // Run game (this blocks until game loop is over).
    GM.run();

    // Shut everything down.
    GM.shutDown();
}

// Load resources (sprites, sound effects, music).
void loadResources(void) {
    RM.loadSprite("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sprites/saucer-spr.txt", "saucer");
    RM.loadSprite("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sprites/ship-spr.txt", "ship");
    RM.loadSprite("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sprites/bullet-spr.txt", "bullet");
    RM.loadSprite("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sprites/explosion-spr.txt", "explosion");
    RM.loadSprite("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sprites/gamestart-spr.txt", "gamestart");
    RM.loadSprite("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sprites/gameover-spr.txt", "gameover");
    RM.loadSound("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sounds/fire.wav", "fire");
    RM.loadSound("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sounds/explode.wav", "explode");
    RM.loadSound("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sounds/nuke.wav", "nuke");
    RM.loadSound("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sounds/game-over.wav", "game over");
    RM.loadMusic("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sounds/start-music.wav", "start music");
}

// Populate world with some objects.
void populateWorld(void) {

    // Spawn some Stars.
    for (int i = 0; i < 16; i++)
        new TestStar;

    // Create GameStart object.
    new TestStart();
}
