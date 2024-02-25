#include "ViewObject.h"
#include "EventView.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "Vector2D.h"

df::ViewObject::ViewObject() {
	setSolidness(df::SPECTRAL);
	setAltitude(df::MAX_ALTITUDE);
	setType("ViewObject");

	setValue(0);
	setDrawValue();
	setBorder(true);
	setLocation(df::ViewObjectLocation::TOP_CENTER);
	setColor(COLOR_DEFAULT);
}

int df::ViewObject::draw() {
	std::string temp_string;

	// Display view_string + value
	if (vo_border) {
		temp_string = " " + getViewString() + " " + toString(getValue());
	}
	else {
		temp_string = getViewString() + " " + toString(getValue());
	}

	// Draw centered at position
	Vector2D pos = DM.getInstance().viewToWorld(getPosition());
	DM.getInstance().drawString(pos, temp_string, CENTER_JUSTIFIED, getColor());

	if (getBorder()) {
		Vector2D border_calc = pos;

		std::string border_horizontal = temp_string;
		std::string border_vertical;
		int vertical = this->getBox().getVertical();
		// Draw the border around the sprite
		for (int i = 0; i < temp_string.size(); i++) {
			border_horizontal[i] = '-';
		}

		// Border above object
		border_calc.setY(border_calc.getY() + this->getPosition().getY() - this->getPosition().getY() - 1);
		DM.getInstance().drawString(border_calc, border_horizontal, CENTER_JUSTIFIED, getColor());

		// Border below object
		border_calc.setY(border_calc.getY() - this->getPosition().getY() + this->getPosition().getY() + 2);
		DM.getInstance().drawString(border_calc, border_horizontal, CENTER_JUSTIFIED, getColor());

		// Border on left of Object
		border_calc.setXY(this->getPosition().getX() - (temp_string.size() / 2) - 1, this->getPosition().getY()); 
		DM.getInstance().drawChar(border_calc, '|', getColor());

		border_calc.setXY(this->getBox().getHorizontal(), this->getBox().getCorner().getY());

		// Border on right of Object
		border_calc.setXY(this->getPosition().getX() + (temp_string.size() / 2) + 1, this->getPosition().getY()); 
		DM.getInstance().drawChar(border_calc, '|', getColor());
	}

	return 0;
}

int df::ViewObject::eventHandler(const Event* p_e) {
	if (p_e->getType() == df::VIEW_EVENT) {
		const EventView* p_ve = dynamic_cast <const df::EventView*> (p_e);

		// See if this event is meant for this object
		if (p_ve->getTag() == getViewString()) {
			if (p_ve->getDelta()) { // Detect a change in value
				setValue(getValue() + p_ve->getValue());
			}
			else {
				setValue(p_ve->getValue()); // New value
			}
			return 0; // Event was handled
		}
	}

	return -1; // Event was not handled; call parent eventHandler()
}

void df::ViewObject::setLocation(ViewObjectLocation new_location) {
	Vector2D screen_pos;
	int y_adjustment = 0;

	switch (new_location) {
	case TOP_LEFT:
		screen_pos.setXY(WM.getInstance().getView().getHorizontal() / 6, 1);
		if (!getBorder()) { y_adjustment = -1; }
		break;

	case TOP_CENTER:
		screen_pos.setXY((WM.getInstance().getView().getHorizontal() / 2), 1);
		if (!getBorder()) { y_adjustment = -1; }
		break;

	case TOP_RIGHT:
		screen_pos.setXY((WM.getInstance().getView().getHorizontal() / (6 / 5)), 1);
		if (!getBorder()) { y_adjustment = -1; }
		break;

	case CENTER_LEFT:
		screen_pos.setXY((WM.getInstance().getView().getHorizontal() / 6), WM.getInstance().getView().getVertical() / 2);
		break;

	case CENTER_CENTER:
		screen_pos.setXY((WM.getInstance().getView().getHorizontal() / 2), WM.getInstance().getView().getVertical() / 2);
		break;

	case CENTER_RIGHT:
		screen_pos.setXY((WM.getInstance().getView().getHorizontal() / (6 / 5)), WM.getInstance().getView().getVertical() / 2);
		break;

	case BOTTOM_LEFT:
		screen_pos.setXY(WM.getInstance().getView().getHorizontal() / 6, WM.getInstance().getView().getVertical() - 1);
		if (!getBorder()) { y_adjustment = 1; }
		break;

	case BOTTOM_CENTER:
		screen_pos.setXY(WM.getInstance().getView().getHorizontal() / 2, WM.getInstance().getView().getVertical() - 1);
		if (!getBorder()) { y_adjustment = 1; }
		break;

	case BOTTOM_RIGHT:
		screen_pos.setXY((WM.getInstance().getView().getHorizontal() / (6 / 5)), WM.getInstance().getView().getVertical() - 1);
		if (!getBorder()) { y_adjustment = 1; }
		break;
	}

	// Shift as needed (based on border)
	screen_pos.setY(screen_pos.getY() + y_adjustment);

	// Set position of object to new position
	setPosition(screen_pos);

	// Set new location
	vo_location = new_location;
}

df::ViewObjectLocation df::ViewObject::getLocation() const {
	return vo_location;
}

void df::ViewObject::setValue(int new_value) {
	vo_value = new_value;
}

int df::ViewObject::getValue() const {
	return vo_value;
}

void df::ViewObject::setBorder(bool new_border) {
	if (vo_border != new_border) {
		vo_border = new_border;

		// Reset location to account for border setting
		setLocation(getLocation());
	}
}

bool df::ViewObject::getBorder() const {
	return vo_border;
}

void df::ViewObject::setColor(Color new_color) {
	vo_color = new_color;
}

df::Color df::ViewObject::getColor() const {
	return vo_color;
}

void df::ViewObject::setViewString(std::string new_view_string) {
	view_string = new_view_string;
}

std::string df::ViewObject::getViewString() const {
	return view_string;
}

void df::ViewObject::setDrawValue(bool new_draw_value) {
	vo_draw_value = new_draw_value;
}

bool df::ViewObject::getDrawValue() const {
	return vo_draw_value;
}
