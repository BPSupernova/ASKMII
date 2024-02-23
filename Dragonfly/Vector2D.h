#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace df {
	class Vector2D {
	private:
		float x_comp; // Horizontal component to vector
		float y_comp; // Vertical component to vector

	public:
		// Create Vector with (x,y)
		Vector2D(float init_x, float init_y);

		// Default vector; x_comp = 0, y_comp = 0
		Vector2D();

		// Get/Set Horizontal Component
		void setX(float new_x);
		float getX() const;

		// Get/Set Vertical Component
		void setY(float new_y);
		float getY() const;

		// Set Both The Horizontal & Vertical Components
		void setXY(float new_x, float new_y);

		// Return magnitude of vector
		float getMagnitude() const;

		// Normalize vector (trnasform to unit vector w/length == 1)
		void normalize();

		// Scales vector by the given magnitude
		void scale(float scale_magnitude);

		// Overwrites the '+' operator for this class; allows adding two vectors, resulting in returning a new Vector
		Vector2D operator+(const Vector2D& other) const;

		bool operator==(const Vector2D& other) const;
	};
}
#endif