#include <string>
#include "Vector2D.h"

namespace df {
	class utility {
	public:
		char* getTimeString();
		bool positionsIntersect(Vector2D pos_1, Vector2D pos_2);
	};
}
