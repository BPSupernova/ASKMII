#include "Saucer.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"

Saucer::Saucer() {
	// Set up "saucer" sprite
	setSprite("saucer");

	// Set object type
	setType("Saucer");

	// Set speed in the horizontal (x) direction
	setVelocity(df::Vector(-0.25,0)); // 1 space left every 4 frames
	
	// Set starting location in the middle of the window
	int world_horizontal = (int) WM.getBoundry().getHorizontal();
	int world_vertical = (int) WM.getBounudry().getVertical();
	df::Vector p((world_horizontal / 2), (world_vertical / 2));
	setPosition(p);
}