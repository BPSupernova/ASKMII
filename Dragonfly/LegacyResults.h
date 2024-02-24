#include "Object.h"

class LegacyResults : public df::Object {
private:

public:
	LegacyResults();
	~LegacyResults();
	int eventHandler(const df::Event* p_e); 
};
