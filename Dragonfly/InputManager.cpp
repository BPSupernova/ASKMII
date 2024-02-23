#include "InputManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"


df::InputManager::InputManager() {

}

df::InputManager& df::InputManager::getInstance() {
	static InputManager input_manager;
	return input_manager;
}

int df::InputManager::startUp() {
	if (!DM.getInstance().isStarted() == 1) { // Check to ensureDisplayManager is started; if not, InputManager won't be started
		LM.getInstance().writeLog("Display Manager hasn't been started\n");
		return -1;
	}
	
	sf::RenderWindow *window = DM.getInstance().getWindow(); // Gets the window from the DisplayManager to enable input on

	window->setKeyRepeatEnabled(false); // Disables key repeat (when holding down) in the window

	df::Manager::startUp();
	return 0;
}

void df::InputManager::shutDown() {
	sf::RenderWindow* window = DM.getInstance().getWindow(); // Gets the window from the DisplayManager to enable input on

	window->setKeyRepeatEnabled(true); // Enables key repeat (when holding down) in the window

	df::Manager::shutDown();
}

void df::InputManager::getInput() const {
	sf::Event event;
	sf::RenderWindow* window = DM.getInstance().getWindow(); // Gets the window from the DisplayManager to enable input on 
	
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) { // Key was pressed
			// create EventKeyboard (key and action)
			
			EventKeyboard key_pressed_event;
			key_pressed_event.setKeyboardAction(df::KEY_PRESSED);

			switch (event.key.code) { // Determine the key pressed
			case sf::Keyboard::A:
				key_pressed_event.setKey(df::Keyboard::A);
				break;
			case sf::Keyboard::B:
				key_pressed_event.setKey(df::Keyboard::B);
				break;
			case sf::Keyboard::C: 
				key_pressed_event.setKey(df::Keyboard::C);
				break;
			case sf::Keyboard::D:
				key_pressed_event.setKey(df::Keyboard::D);
				break;
			case sf::Keyboard::E: 
				key_pressed_event.setKey(df::Keyboard::E);
				break;
			case sf::Keyboard::F:
				key_pressed_event.setKey(df::Keyboard::F);
				break;
			case sf::Keyboard::G:
				key_pressed_event.setKey(df::Keyboard::G);
				break;
			case sf::Keyboard::H:
				key_pressed_event.setKey(df::Keyboard::H);
				break;
			case sf::Keyboard::I:
				key_pressed_event.setKey(df::Keyboard::I);
				break;
			case sf::Keyboard::J:
				key_pressed_event.setKey(df::Keyboard::J);
				break;
			case sf::Keyboard::K:
				key_pressed_event.setKey(df::Keyboard::K);
				break;
			case sf::Keyboard::L:
				key_pressed_event.setKey(df::Keyboard::L);
				break;
			case sf::Keyboard::M:
				key_pressed_event.setKey(df::Keyboard::M);
				break;
			case sf::Keyboard::N:
				key_pressed_event.setKey(df::Keyboard::N);
				break;
			case sf::Keyboard::O:
				key_pressed_event.setKey(df::Keyboard::O);
				break;
			case sf::Keyboard::P:
				key_pressed_event.setKey(df::Keyboard::P);
				break;
			case sf::Keyboard::Q:
				key_pressed_event.setKey(df::Keyboard::Q);
				break;
			case sf::Keyboard::R:
				key_pressed_event.setKey(df::Keyboard::R);
				break;
			case sf::Keyboard::S:
				key_pressed_event.setKey(df::Keyboard::S);
				break;
			case sf::Keyboard::T:
				key_pressed_event.setKey(df::Keyboard::T);
				break;
			case sf::Keyboard::U:
				key_pressed_event.setKey(df::Keyboard::U);
				break;
			case sf::Keyboard::V:
				key_pressed_event.setKey(df::Keyboard::V);
				break;
			case sf::Keyboard::W:
				key_pressed_event.setKey(df::Keyboard::W);
				break;
			case sf::Keyboard::X:
				key_pressed_event.setKey(df::Keyboard::X);
				break;
			case sf::Keyboard::Y:
				key_pressed_event.setKey(df::Keyboard::Y);
				break;
			case sf::Keyboard::Z:
				key_pressed_event.setKey(df::Keyboard::Z);
				break;
			case sf::Keyboard::Num0:
				key_pressed_event.setKey(df::Keyboard::NUM0);
				break;
			case sf::Keyboard::Num1:
				key_pressed_event.setKey(df::Keyboard::NUM1);
				break;
			case sf::Keyboard::Num2:
				key_pressed_event.setKey(df::Keyboard::NUM2);
				break;
			case sf::Keyboard::Num3:
				key_pressed_event.setKey(df::Keyboard::NUM3);
				break;
			case sf::Keyboard::Num4:
				key_pressed_event.setKey(df::Keyboard::NUM4);
				break;
			case sf::Keyboard::Num5:
				key_pressed_event.setKey(df::Keyboard::NUM5);
				break;
			case sf::Keyboard::Num6:
				key_pressed_event.setKey(df::Keyboard::NUM6);
				break;
			case sf::Keyboard::Num7:
				key_pressed_event.setKey(df::Keyboard::NUM7);
				break;
			case sf::Keyboard::Num8:
				key_pressed_event.setKey(df::Keyboard::NUM8);
				break;
			case sf::Keyboard::Num9:
				key_pressed_event.setKey(df::Keyboard::NUM9);
				break;
			case sf::Keyboard::F1:
				key_pressed_event.setKey(df::Keyboard::F1);
				break;
			case sf::Keyboard::F2:
				key_pressed_event.setKey(df::Keyboard::F2);
				break;
			case sf::Keyboard::F3:
				key_pressed_event.setKey(df::Keyboard::F3);
				break;
			case sf::Keyboard::F4:
				key_pressed_event.setKey(df::Keyboard::F4);
				break;
			case sf::Keyboard::F5:
				key_pressed_event.setKey(df::Keyboard::F5);
				break;
			case sf::Keyboard::F6:
				key_pressed_event.setKey(df::Keyboard::F6);
				break;
			case sf::Keyboard::F7:
				key_pressed_event.setKey(df::Keyboard::F7);
				break;
			case sf::Keyboard::F8:
				key_pressed_event.setKey(df::Keyboard::F8);
				break;
			case sf::Keyboard::F9:
				key_pressed_event.setKey(df::Keyboard::F9);
				break;
			case sf::Keyboard::F10:
				key_pressed_event.setKey(df::Keyboard::F10);
				break;
			case sf::Keyboard::F11:
				key_pressed_event.setKey(df::Keyboard::F11);
				break;
			case sf::Keyboard::F12:
				key_pressed_event.setKey(df::Keyboard::F12);
				break;
			case sf::Keyboard::LShift:
				key_pressed_event.setKey(df::Keyboard::LEFTSHIFT);
				break;
			case sf::Keyboard::RShift:
				key_pressed_event.setKey(df::Keyboard::RIGHTSHIFT);
				break;
			case sf::Keyboard::LControl:
				key_pressed_event.setKey(df::Keyboard::LEFTCONTROL);
				break;
			case sf::Keyboard::RControl:
				key_pressed_event.setKey(df::Keyboard::RIGHTCONTROL);
				break;
			case sf::Keyboard::Tab:
				key_pressed_event.setKey(df::Keyboard::TAB);
				break;
			case sf::Keyboard::Escape:
				key_pressed_event.setKey(df::Keyboard::ESCAPE);
				break;
			case sf::Keyboard::Return:
				key_pressed_event.setKey(df::Keyboard::RETURN);
				break;
			case sf::Keyboard::Space:
				key_pressed_event.setKey(df::Keyboard::SPACE);
				break;
			case sf::Keyboard::Add:
				key_pressed_event.setKey(df::Keyboard::PLUS);
				break;
			case sf::Keyboard::Subtract:
				key_pressed_event.setKey(df::Keyboard::MINUS);
				break;
			case sf::Keyboard::Tilde:
				key_pressed_event.setKey(df::Keyboard::TILDE);
				break;
			case sf::Keyboard::Pause:
				key_pressed_event.setKey(df::Keyboard::PAUSE);
				break;
			case sf::Keyboard::Up:
				key_pressed_event.setKey(df::Keyboard::UPARROW);
				break;
			case sf::Keyboard::Down:
				key_pressed_event.setKey(df::Keyboard::DOWNARROW);
				break;
			case sf::Keyboard::Left:
				key_pressed_event.setKey(df::Keyboard::LEFTARROW);
				break;
			case sf::Keyboard::Right:
				key_pressed_event.setKey(df::Keyboard::RIGHTARROW);
				break;
			case sf::Keyboard::Period:
				key_pressed_event.setKey(df::Keyboard::PERIOD);
				break;
			case sf::Keyboard::Comma:
				key_pressed_event.setKey(df::Keyboard::COMMA);
				break;
			case sf::Keyboard::Slash:
				key_pressed_event.setKey(df::Keyboard::SLASH);
				break;
			default:
				key_pressed_event.setKey(df::Keyboard::UNDEFINED_KEY);
				break;
			}

			// send EventKeyboard to all objects
			onEvent(&key_pressed_event);
		}
		if (event.type == sf::Event::KeyReleased) { // Key was released
			// create EventKeyboard (key and action)
			EventKeyboard key_released_event;
			key_released_event.setKeyboardAction(df::KEY_RELEASED);

			switch (event.key.code) { // Determine the key pressed
			case sf::Keyboard::A:
				key_released_event.setKey(df::Keyboard::A);
				break;
			case sf::Keyboard::B:
				key_released_event.setKey(df::Keyboard::B);
				break;
			case sf::Keyboard::C:
				key_released_event.setKey(df::Keyboard::C);
				break;
			case sf::Keyboard::D:
				key_released_event.setKey(df::Keyboard::D);
				break;
			case sf::Keyboard::E:
				key_released_event.setKey(df::Keyboard::E);
				break;
			case sf::Keyboard::F:
				key_released_event.setKey(df::Keyboard::F);
				break;
			case sf::Keyboard::G:
				key_released_event.setKey(df::Keyboard::G);
				break;
			case sf::Keyboard::H:
				key_released_event.setKey(df::Keyboard::H);
				break;
			case sf::Keyboard::I:
				key_released_event.setKey(df::Keyboard::I);
				break;
			case sf::Keyboard::J:
				key_released_event.setKey(df::Keyboard::J);
				break;
			case sf::Keyboard::K:
				key_released_event.setKey(df::Keyboard::K);
				break;
			case sf::Keyboard::L:
				key_released_event.setKey(df::Keyboard::L);
				break;
			case sf::Keyboard::M:
				key_released_event.setKey(df::Keyboard::M);
				break;
			case sf::Keyboard::N:
				key_released_event.setKey(df::Keyboard::N);
				break;
			case sf::Keyboard::O:
				key_released_event.setKey(df::Keyboard::O);
				break;
			case sf::Keyboard::P:
				key_released_event.setKey(df::Keyboard::P);
				break;
			case sf::Keyboard::Q:
				key_released_event.setKey(df::Keyboard::Q);
				break;
			case sf::Keyboard::R:
				key_released_event.setKey(df::Keyboard::R);
				break;
			case sf::Keyboard::S:
				key_released_event.setKey(df::Keyboard::S);
				break;
			case sf::Keyboard::T:
				key_released_event.setKey(df::Keyboard::T);
				break;
			case sf::Keyboard::U:
				key_released_event.setKey(df::Keyboard::U);
				break;
			case sf::Keyboard::V:
				key_released_event.setKey(df::Keyboard::V);
				break;
			case sf::Keyboard::W:
				key_released_event.setKey(df::Keyboard::W);
				break;
			case sf::Keyboard::X:
				key_released_event.setKey(df::Keyboard::X);
				break;
			case sf::Keyboard::Y:
				key_released_event.setKey(df::Keyboard::Y);
				break;
			case sf::Keyboard::Z:
				key_released_event.setKey(df::Keyboard::Z);
				break;
			case sf::Keyboard::Num0:
				key_released_event.setKey(df::Keyboard::NUM0);
				break;
			case sf::Keyboard::Num1:
				key_released_event.setKey(df::Keyboard::NUM1);
				break;
			case sf::Keyboard::Num2:
				key_released_event.setKey(df::Keyboard::NUM2);
				break;
			case sf::Keyboard::Num3:
				key_released_event.setKey(df::Keyboard::NUM3);
				break;
			case sf::Keyboard::Num4:
				key_released_event.setKey(df::Keyboard::NUM4);
				break;
			case sf::Keyboard::Num5:
				key_released_event.setKey(df::Keyboard::NUM5);
				break;
			case sf::Keyboard::Num6:
				key_released_event.setKey(df::Keyboard::NUM6);
				break;
			case sf::Keyboard::Num7:
				key_released_event.setKey(df::Keyboard::NUM7);
				break;
			case sf::Keyboard::Num8:
				key_released_event.setKey(df::Keyboard::NUM8);
				break;
			case sf::Keyboard::Num9:
				key_released_event.setKey(df::Keyboard::NUM9);
				break;
			case sf::Keyboard::F1:
				key_released_event.setKey(df::Keyboard::F1);
				break;
			case sf::Keyboard::F2:
				key_released_event.setKey(df::Keyboard::F2);
				break;
			case sf::Keyboard::F3:
				key_released_event.setKey(df::Keyboard::F3);
				break;
			case sf::Keyboard::F4:
				key_released_event.setKey(df::Keyboard::F4);
				break;
			case sf::Keyboard::F5:
				key_released_event.setKey(df::Keyboard::F5);
				break;
			case sf::Keyboard::F6:
				key_released_event.setKey(df::Keyboard::F6);
				break;
			case sf::Keyboard::F7:
				key_released_event.setKey(df::Keyboard::F7);
				break;
			case sf::Keyboard::F8:
				key_released_event.setKey(df::Keyboard::F8);
				break;
			case sf::Keyboard::F9:
				key_released_event.setKey(df::Keyboard::F9);
				break;
			case sf::Keyboard::F10:
				key_released_event.setKey(df::Keyboard::F10);
				break;
			case sf::Keyboard::F11:
				key_released_event.setKey(df::Keyboard::F11);
				break;
			case sf::Keyboard::F12:
				key_released_event.setKey(df::Keyboard::F12);
				break;
			case sf::Keyboard::LShift:
				key_released_event.setKey(df::Keyboard::LEFTSHIFT);
				break;
			case sf::Keyboard::RShift:
				key_released_event.setKey(df::Keyboard::RIGHTSHIFT);
				break;
			case sf::Keyboard::LControl:
				key_released_event.setKey(df::Keyboard::LEFTCONTROL);
				break;
			case sf::Keyboard::RControl:
				key_released_event.setKey(df::Keyboard::RIGHTCONTROL);
				break;
			case sf::Keyboard::Tab:
				key_released_event.setKey(df::Keyboard::TAB);
				break;
			case sf::Keyboard::Escape:
				key_released_event.setKey(df::Keyboard::ESCAPE);
				break;
			case sf::Keyboard::Return:
				key_released_event.setKey(df::Keyboard::RETURN);
				break;
			case sf::Keyboard::Space:
				key_released_event.setKey(df::Keyboard::SPACE);
				break;
			case sf::Keyboard::Add:
				key_released_event.setKey(df::Keyboard::PLUS);
				break;
			case sf::Keyboard::Subtract:
				key_released_event.setKey(df::Keyboard::MINUS);
				break;
			case sf::Keyboard::Tilde:
				key_released_event.setKey(df::Keyboard::TILDE);
				break;
			case sf::Keyboard::Pause:
				key_released_event.setKey(df::Keyboard::PAUSE);
				break;
			case sf::Keyboard::Up:
				key_released_event.setKey(df::Keyboard::UPARROW);
				break;
			case sf::Keyboard::Down:
				key_released_event.setKey(df::Keyboard::DOWNARROW);
				break;
			case sf::Keyboard::Left:
				key_released_event.setKey(df::Keyboard::LEFTARROW);
				break;
			case sf::Keyboard::Right:
				key_released_event.setKey(df::Keyboard::RIGHTARROW);
				break;
			case sf::Keyboard::Period:
				key_released_event.setKey(df::Keyboard::PERIOD);
				break;
			case sf::Keyboard::Comma:
				key_released_event.setKey(df::Keyboard::COMMA);
				break;
			case sf::Keyboard::Slash:
				key_released_event.setKey(df::Keyboard::SLASH);
				break;
			default:
				key_released_event.setKey(df::Keyboard::UNDEFINED_KEY);
				break;
			}

			// send EventKeyboard to all objects
			onEvent(&key_released_event);
		}
		if (event.type == sf::Event::MouseMoved) { // Mouse was moved
			// create EventMouse (x, y, and action)
			EventMouse mouse_moved_event;
			mouse_moved_event.setMouseAction(df::MOVED);
			Vector2D mouse_curr_pos;
			mouse_curr_pos.setXY(event.mouseMove.x, event.mouseMove.y); // Sets position of event to position of mouse cursor
			mouse_curr_pos = DM.getInstance().pixelsToAcsiiSpaces(mouse_curr_pos);
			mouse_moved_event.setMouseCursorPos(mouse_curr_pos);
			mouse_moved_event.setMouseButton(df::Mouse::UNDEFINED_BUTTON);
			
			// send EventMouse to all objects
			onEvent(&mouse_moved_event);
		}
		if (event.type == sf::Event::MouseButtonPressed) { // Mouse was clicked
			// create EventMouse (x, y, and action)
			EventMouse mouse_button_event;
			mouse_button_event.setMouseAction(df::CLICKED);
			Vector2D mouse_curr_pos;

			mouse_curr_pos.setXY((float) event.mouseButton.x, (float) event.mouseButton.y); // Sets position of event to position of mouse cursor
			mouse_curr_pos = DM.getInstance().pixelsToAcsiiSpaces(mouse_curr_pos); 
			mouse_button_event.setMouseCursorPos(mouse_curr_pos); 

			switch (event.mouseButton.button) {
			case sf::Mouse::Left:
				mouse_button_event.setMouseButton(df::Mouse::LEFT);
				break;
			case sf::Mouse::Right:
				mouse_button_event.setMouseButton(df::Mouse::RIGHT);
				break;
			case sf::Mouse::Middle:
				mouse_button_event.setMouseButton(df::Mouse::MIDDLE);
				break;
			default:
				mouse_button_event.setMouseButton(df::Mouse::UNDEFINED_BUTTON);
				break;
			}
			// send EventMouse to all objects
			onEvent(&mouse_button_event);
		}
	}
}
