#ifndef BOX_H
#define BOX_H

#include "Vector2D.h"

namespace df {
	class Box {
	private:
		Vector2D corner; // Upper left corner of box
		float horizontal; // Horizontal dimension of box
		float vertical; // Vertical dimension of box

	public:
		Box(); // Create a Box with corner at (0,0), and 0 for the horizontal and vertical dimensions

		// Create a box with an upper-left corner, horizontal, and vertical sizes
		Box(Vector2D init_corner, float init_horizontal, float init_vertical);

		void setCorner(Vector2D new_corner); // Set the upper left corner of the Box
		Vector2D getCorner() const; // Get (the position of the) upper left corner of the Box

		void setHorizontal(float new_horizontal); // Set horizontal size of Box
		float getHorizontal() const; // Get horizontal size of Box

		void setVertical(float new_vertical); // Set the vertical size of Box
		float getVertical() const; // Get the vertical size of Box
	};
}

#endif