#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Manager.h"

#define GM df::GameManager::getInstance()

namespace df {
	class GameManager : public Manager {
	private:
		GameManager();
		GameManager(GameManager const&);
		void operator = (GameManager const&);
		int frame_time;
		bool game_over; // The game loop should stop running if true
		int m_step_count; // Number of iterations through the game loop
	public:
		static GameManager& getInstance();

		int startUp();
		void shutDown();
		void run(); // Runs the game loop

		void setGameOver(bool new_game_over = true);
		bool getGameOver() const; 

		int getFrameTime() const; // Frame time in milliseconds
		int getStepCount() const; // Game loop step count 
	};
}
#endif