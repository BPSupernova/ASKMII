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
    // RM.loadSprite("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sprites/saucer-spr.txt", "saucer");
    
    RM.loadSound("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sounds/mixkit - skateboard - idle - movement - 3094.wav", "day transition");
    RM.loadMusic("C:/Users/Ben/source/repos/dragonfly/Dragonfly/sounds/glass - of - wine - 143532.mp3", "glass 'o wine");
}

// Populate world with some objects.
void populateWorld(void) {

    // Spawn some Stars.
    // for (int i = 0; i < 16; i++)
    //    new TestStar;

    // Create GameStart object.
    new GameStart();
}
