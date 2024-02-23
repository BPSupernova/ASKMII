#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include <Windows.h>
#include "EventStep.h"
#include "Clock.h"
#include <stdio.h>
#include <iostream>

df::GameManager::GameManager() {
	game_over = false;
	m_step_count = 0;
	frame_time = 33;
	setType("GameManager");
}

df::GameManager &df::GameManager::getInstance() {
	static GameManager game_manager;
	return game_manager;
}

int df::GameManager::startUp() {
	LM.startUp();
	WM.startUp();
	DM.startUp();

	// Set up game world and player view boundaries
	Box default_view_and_boundary;
	default_view_and_boundary.setHorizontal(DM.getHorizontal());
	default_view_and_boundary.setVertical(DM.getVertical());
	WM.setBoundary(default_view_and_boundary);
	WM.setView(default_view_and_boundary);

	IM.startUp();
	RM.startUp();
	df::Manager::startUp();
	timeBeginPeriod(1);
	return 0;
}

void df::GameManager::shutDown() {
	RM.shutDown();
	IM.shutDown();
	DM.shutDown();
	WM.shutDown();
	LM.shutDown();
	df::Manager::shutDown(); 
	timeEndPeriod(1);
	game_over = true;
}

void df::GameManager::run() {
	df::Clock clock;
	
	while (!game_over) {
		long int b = clock.delta();
		/* printf("%ld\n", b); FOR TESTING ONLY */

		IM.getInput(); // get input
		WM.UpdateWorld(); // update world
		WM.draw(); // draw objects in world
		DM.swapBuffas(); // swaps the drawing buffers to get ready for next call to draw

		// Sends a Step Event to all game objects
		EventStep s(getStepCount());
		onEvent(&s);

		long int loop_time = clock.split();
		/* printf("%ld\n", loop_time); FOR TESTING ONLY */
		if (33 - loop_time < 0) { continue; }
		else { Sleep(33 - loop_time); }
	}
}

void df::GameManager::setGameOver(bool new_game_over) {
	game_over = new_game_over;
}

bool df::GameManager::getGameOver() const {
	return game_over;
}

int df::GameManager::getFrameTime() const {
	return frame_time;
}

int df::GameManager::getStepCount() const {
	return m_step_count;
}
