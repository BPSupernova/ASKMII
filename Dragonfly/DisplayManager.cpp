#include "DisplayManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include <iostream>

df::DisplayManager::DisplayManager() { 
	g_p_window = NULL;
	g_window_horizontal_chars = df::WINDOW_HORIZONTAL_CHARS_DEFAULT; 
	g_window_horizontal_pixels = df::WINDOW_HORIZONTAL_PIXELS_DEFAULT; 
	g_window_vertical_chars = df::WINDOW_VERTICAL_CHARS_DEFAULT; 
	g_window_vertical_pixels = df::WINDOW_VERTICAL_PIXELS_DEFAULT; 
	setType("DisplayManager");
}

df::DisplayManager& df::DisplayManager::getInstance() {
	static DisplayManager display_manager;
	return display_manager;
}

int df::DisplayManager::startUp() {
	if (!LM.getInstance().isStarted() == 1) {
		std::cout << "LogManager not started" << std::endl;
		return -1;
	}
	
	if (g_p_window != NULL) {
		return 0;
	}

	if (g_font.loadFromFile(FONT_FILE_DEFAULT) == false) { // load font
		std::cout << "Error! Unable to load font 'df-font.tff'." << std::endl;
		return -1;
	}

	// Creates the actual window
	sf::RenderWindow* p_window = new sf::RenderWindow(sf::VideoMode(1024,768), "Title - Dragonfly", sf::Style::Titlebar);
	g_p_window = p_window;
	if (!g_p_window) {
		std::cout << "Error! Unable to allocate RenderWindow" << std::endl;
		return -1;
	}

	// Turns off the mouse cursor when the window is active
	g_p_window->setMouseCursorVisible(false);

	// Synchronizes refresh rate with monitor
	g_p_window->setVerticalSyncEnabled(true);

	// Call to Manager::startUp()
	df::Manager::startUp();

	return 0;
}

void df::DisplayManager::shutDown() {
	// Turns on the mouse cursor when the window is active
	g_p_window->setMouseCursorVisible(true);

	// Stops synchronizing refresh rate with monitor
	g_p_window->setVerticalSyncEnabled(false);

	// Call to Manager::shutdown()
	df::Manager::shutDown();

	if (g_p_window) { // Close the window
		g_p_window->close();
		delete g_p_window;
	}
}

int df::DisplayManager::drawChar(Vector2D world_pos, char ch, Color color) const {
	if (g_p_window == NULL) {
		std::cout << "Error! Unable to see RenderWindow" << std::endl;
		return -1;
	}

	Vector2D view_pos = worldToView(world_pos);

	Vector2D pixel_pos = acsiiSpaceToPixels(view_pos); // Converts spaces to pixels (x,y coordinates)

	// Draw background rectangle; Text is "see through" in SFML
	static sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
	rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
	// Offsets of 10 and 5 are to make the rectangle appears directly under the character
	rectangle.setPosition(pixel_pos.getX() - charWidth() / 10, pixel_pos.getY() + charHeight() / 5);
	g_p_window->draw(rectangle);

	// Create character text to draw
	// Setup text to display
	static sf::Text text("", g_font);
	text.setString(ch); // Set display string
	text.setStyle(sf::Text::Bold); // Sets text style; looks better

	// Scale the text to the right size
	if (charWidth() < charHeight()) {
		text.setCharacterSize(charWidth() * 2);
	} else {
		text.setCharacterSize(charHeight() * 2);
	}
	
	// Set SFML color based on Dragonfly color
	switch (color) {
	case BLACK:
		text.setFillColor(sf::Color::Black);
		break;
	case RED:
		text.setFillColor(sf::Color::Red);
		break;
	case GREEN:
		text.setFillColor(sf::Color::Green);
		break;
	case YELLOW:
		text.setFillColor(sf::Color::Yellow);
		break;
	case BLUE:
		text.setFillColor(sf::Color::Blue);
		break;
	case MAGENTA:
		text.setFillColor(sf::Color::Magenta);
		break;
	case CYAN:
		text.setFillColor(sf::Color::Cyan);
		break;
	default:
		text.setFillColor(sf::Color::White);
		break;
	}

	text.setPosition(pixel_pos.getX(), pixel_pos.getY()); // Set position in window (in pixels)

	g_p_window->draw(text); // Draws the character

	return 0;
}

int df::DisplayManager::drawString(Vector2D world_pos, std::string str, Justification just, Color color) const {
	Vector2D string_start_pos = world_pos;
	switch (just) {
	case CENTER_JUSTIFIED: 
		string_start_pos.setX(world_pos.getX() - str.size() / 2);
		break;
	case RIGHT_JUSTIFIED:
		string_start_pos.setX(world_pos.getX() - str.size());
		break;
	case LEFT_JUSTIFIED:
	default:
		break;
	}

	// Draw the parameter string character by character
	for (int i = 0; i < str.size(); i++) {
		Vector2D temp_pos(string_start_pos.getX() + i, string_start_pos.getY());
		drawChar(temp_pos, str[i], color);
	}

	return 0;
}

int df::DisplayManager::getHorizontal() const {
	return g_window_horizontal_chars;
}

int df::DisplayManager::getVertical() const {
	return g_window_vertical_chars;
}

int df::DisplayManager::getHorizontalPixelMax() const {
	return g_window_horizontal_pixels;
}

int df::DisplayManager::getVerticalPixelMax() const {
	return g_window_vertical_pixels;
}

int df::DisplayManager::swapBuffas() {
	if (g_p_window == NULL) { // Window allocation check
		std::cout << "Error! Unable to see RenderWindow" << std::endl;
		return -1;
	}

	g_p_window->display(); // Displays the current window
	g_p_window->clear(m_window_background_color); // Clears the other buffer to get ready for the next draw call

	return 0;
}

sf::RenderWindow* df::DisplayManager::getWindow() const {
	return g_p_window;
}

bool df::DisplayManager::setBackgroundColor(Color new_color)
{
	// Set SFML color based on Dragonfly color
	switch (new_color) {
	case UNDEFINED_COLOR:
		return -1;
		break;
	case BLACK:
		m_window_background_color = sf::Color::Black;
		break;
	case RED:
		m_window_background_color = sf::Color::Red;
		break;
	case GREEN:
		m_window_background_color = sf::Color::Green; 
		break;
	case YELLOW:
		m_window_background_color = sf::Color::Yellow; 
		break;
	case BLUE:
		m_window_background_color = sf::Color::Blue; 
		break;
	case MAGENTA:
		m_window_background_color = sf::Color::Magenta; 
		break;
	case CYAN:
		m_window_background_color = sf::Color::Cyan; 
		break;
	default:
		m_window_background_color = sf::Color::White; 
		break;
	}

	return true;
}

df::Vector2D df::DisplayManager::worldToView(Vector2D world_pos) const {
	Vector2D view_origin = WM.getInstance().getView().getCorner();
	int view_x = view_origin.getX();
	int view_y = view_origin.getY();

	Vector2D view_pos(world_pos.getX() - view_x, world_pos.getY() - view_y);
	return view_pos;
}

df::Vector2D df::DisplayManager::viewToWorld(Vector2D view_pos) const {
	Vector2D world_origin = WM.getInstance().getBoundary().getCorner();
	int world_x = world_origin.getX();
	int world_y = world_origin.getY();

	Vector2D world_pos(view_pos.getX() + world_x, view_pos.getY() + world_y);
	return world_pos;
}

float df::DisplayManager::charHeight() const {
	if (getVertical() == 0) {
		return 0;
	}
	return (float) (getVerticalPixelMax() / getVertical());
}

float df::DisplayManager::charWidth() const {
	if (getHorizontal() == 0) { 
		return 0; 
	}
	return (float) (getHorizontalPixelMax() / getHorizontal());
}

df::Vector2D df::DisplayManager::acsiiSpaceToPixels(Vector2D spaces) const {
	Vector2D product;
	float product_x, product_y;
	product_x = spaces.getX() * charWidth();
	product_y = spaces.getY() * charHeight();
	product.setXY(product_x, product_y);
	return product; 
}

df::Vector2D df::DisplayManager::pixelsToAcsiiSpaces(Vector2D pixels) const {
	Vector2D quotient;
	float quotient_x, quotient_y;
	quotient_x = pixels.getX() / charWidth();
	quotient_y = pixels.getY() / charHeight();
	quotient.setXY(quotient_x, quotient_y);
	return quotient; 
}
