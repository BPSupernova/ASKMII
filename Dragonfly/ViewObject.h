#ifndef VIEW_OBJECT_H
#define VIEW_OBJECT_H

#include "Object.h"
#include "Event.h"

namespace df {
	enum ViewObjectLocation {
		UNDEFINED = -1, 
		TOP_LEFT, TOP_CENTER, TOP_RIGHT,
		CENTER_LEFT, CENTER_CENTER, CENTER_RIGHT,
		BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT,
	};

	class ViewObject : public Object {
	private: 
		std::string view_string; // Label for value (e.g., "Points")
		int vo_value; // Value displayed by ViewObject (e.g., points)
		bool vo_draw_value; // True if should draw value
		bool vo_border; // True if a border should be drawn around display
		Color vo_color; // Color for text (and border)
		ViewObjectLocation vo_location; // Location of the ViewObject

	public:
		ViewObject(); // Construct ViewObject with defaults; SPECTRAL & on MAX_ALTITUDE

		virtual int draw() override; // Draw view string and it's value
		virtual int eventHandler(const Event* p_e) override; // Handle View Event if tag matches view_string; Return 0 if ignored, 1 if handled

		void setLocation(ViewObjectLocation new_location); // General location of ViewObject on the screen
		ViewObjectLocation getLocation() const; // Get general location of ViewObject on the screen

		void setValue(int new_value); // Set the View Object's value
		int getValue() const; // Get the View Object's value

		void setBorder(bool new_border); // Set whether or not the ViewObject will display a border
		bool getBorder() const; // Get whether the ViewObject will display a border (true = display border)

		void setColor(Color new_color); // Set the ViewObject's color
		Color getColor() const; // Get the color of the ViewObject

		void setViewString(std::string new_view_string); // Set the view display string
		std::string getViewString() const; // Get view display string

		void setDrawValue(bool new_draw_value = true); // Set draw_value to true with the display string
		bool getDrawValue() const; // Get draw value (true if draw value with display string)
	};	
}

#endif
