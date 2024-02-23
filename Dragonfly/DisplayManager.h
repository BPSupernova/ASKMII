#ifndef DISPLAY_MANAGER_H // Guard
#define DISPLAY_MANAGER_H

// System includes
#include <SFML/Graphics.hpp>
#include <Windows.h>

// Other includes
#include "Color.h"
#include "Manager.h"
#include "Vector2D.h"

#define DM df::DisplayManager::getInstance()

namespace df {

	// Defaults for the SFML window
	const int WINDOW_HORIZONTAL_PIXELS_DEFAULT = 1024;
	const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
	const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 80;
	const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
	const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar;
	const sf::Color WINDOW_BACKGROUND_COLOR_DEFAULT = sf::Color::Black;
	const std::string WINDOW_TITLE_DEFAULT = " Dragonfly";
	const std::string FONT_FILE_DEFAULT = "C:/Users/Ben/source/repos/dragonfly/df-font.ttf";

	enum Justification { // Centers a string to the left, right, or center of their x,y position
		LEFT_JUSTIFIED,
		CENTER_JUSTIFIED, 
		RIGHT_JUSTIFIED,
	};

	class DisplayManager : public Manager {
	private:
		DisplayManager(); // Singleton
		DisplayManager(DisplayManager const&); // Prohibits copying (singleton design) 
		void operator=(DisplayManager const&); // Prohibits assignment (singleton design)
		sf::Font g_font; //Font used for ASCII graphics
		sf::RenderWindow* g_p_window; // Pointer to the SFML window
		sf::Color m_window_background_color; // The background window color
		int g_window_horizontal_pixels; // Horizontal pixels in the window
		int g_window_vertical_pixels; // Vertical pixels in the window
		int g_window_horizontal_chars; // Horizontal ASCII spaces in the window
		int g_window_vertical_chars; // Vertical ASCII spaces in the window

	public:
		static DisplayManager& getInstance(); // Get the sole instance of the DisplayManager

		int startUp(); // Opens the graphics window, ready for text-based display; Returns 0 upon success, -1 otherwise
		void shutDown(); // Closes the graphics window
	
		// Draws a character at window location (x,y) w/color; Return 0 upon success; -1 otherwise
		int drawChar(Vector2D world_pos, char ch, Color color) const; 

		//Draws a string at window location (x,y) with the default color; justified to the left, right, or center; Return 0 upon success, -1 otherwise
		int drawString(Vector2D world_pos, std::string str, Justification just, Color color) const;  

		int getHorizontal() const; // Return window's horizontal maximum (in characters)
		int getVertical() const; // Return window's vertical maximum (in characters)

		int getHorizontalPixelMax() const; // Returns the window's horizontal maximum (in pixels)
		int getVerticalPixelMax() const; // Returns the window's vertical maximum (in pixels)

		int swapBuffas(); // Renders the current window buffer; Returns 0 upon success, -1 otherwise

		sf::RenderWindow* getWindow() const; // Return pointer to the SFML graphics window

		bool setBackgroundColor(Color new_color); // Sets the default background color; Returns true upon success, false otherwise

		Vector2D worldToView(Vector2D world_pos) const; // Converts the position in the game world to the player view position
		Vector2D viewToWorld(Vector2D view_pos) const; // Converts the position in the player view window to game world coordinates

		// Helper functions that compute character height and width based on the game window size
		float charHeight() const; // Computes the height of a character in pixels, based on the window size
		float charWidth() const; // Computes the width of a character in pixels, based on the window size
		Vector2D acsiiSpaceToPixels(Vector2D spaces) const; // Converts ASCII spaces (x,y) to window pixels (x,y)
		Vector2D pixelsToAcsiiSpaces(Vector2D pixels) const; // Converts window pixels (x,y) to ASCII spaces (x,y)
	};
}

#endif // !DISPLAY_MANAGER_H