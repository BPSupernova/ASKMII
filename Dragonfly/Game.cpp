// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"

// Game includes.
#include "GameStart.h"
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
    RM.loadSprite("sprites/gamestart-spr.txt", "start screen");
    RM.loadSprite("sprites/21-ExplodingTVSprite.txt", "temp");
    RM.loadSprite("sprites/earth-spr.txt", "man");
    RM.loadSprite("sprites/observeman-spr.txt", "smileman");
    RM.loadSprite("sprites/creepysmileman-spr.txt", "creepsmileman");
    RM.loadSprite("sprites/evilman-spr.txt", "evilman");
    RM.loadSprite("sprites/clock-spr.txt", "clock");
    RM.loadSprite("sprites/cloud-spr.txt", "cloud");
    RM.loadSprite("sprites/mushroomcloud-spr.txt", "mushroom cloud");
    RM.loadSprite("sprites/tombstone-spr.txt", "tombstone");

    RM.loadSound("sounds/mixkit-skateboard-idle-movement-3094.mp3", "day transition");
    RM.loadMusic("sounds/for-elevator-jazz-music-124005.mp3", "start music");
    RM.loadMusic("sounds/glass-of-wine-143532.mp3", "glass 'o wine");
    RM.loadMusic("sounds/legacy-of-handel-legendary-passacaglia-background-music-25-second-191894.mp3", "end music");
}

// Populate world with some objects.
void populateWorld(void) {

    // Spawn some Stars.
    // for (int i = 0; i < 16; i++)
    //    new TestStar;

    // Create GameStart object.
    new GameStart();
}