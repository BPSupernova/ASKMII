#include "Object.h"
#include "ResourceManager.h"

#include "DayNumDisplay.h"
#include "Prompt.h"
#include "Choice.h"
#include "PointsSystem.h"
#include "LegacyResults.h"

class Day : public df::Object {

private:
	int day_index; // Index of the day it is before the end of the world (Ex: Day 21 = 21 days left til the player dies)
	DayNumDisplay days_left_display; // The text that says "Days Left (num)"
	Prompt make_choice_prompter; // The text that says "What will you do today?"
	Choice days_choice; // The set of choices for the particular day (randomly generated or whatnot)
	df::Music* p_music; // The music that plays while the game is running

	// All other necessary attributes covered in base Object class (mainly in reference to Sprite)

	void startDay(); // A method that moves / animates text from the left of the screen to the center of the screen
	void endDay(); // A method that cleans up the display once the choice has been made

	void makeChoice(int code); // Based on input, decide which choice the player has chosen

public:
	Day(int day);
	~Day(); 
	int eventHandler(const df::Event* p_e);
	int draw();
	void playMusic();

	void setDayNumDisplay(DayNumDisplay display); 
	DayNumDisplay getDayNumDisplay() const;

	void setPrompt(Prompt new_prompt);
	Prompt getPrompt() const;

	void setChoice(Choice new_choice);
	Choice getChoice() const;
};