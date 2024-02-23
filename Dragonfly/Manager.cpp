#include "Manager.h"
#include "WorldManager.h"
#include "LogManager.h"

df::Manager :: Manager() {
	
}

df::Manager :: ~Manager() {

}

std::string df::Manager::getType() const
{
	return df::Manager::m_type;
}

int df::Manager::startUp()
{
	df::Manager::manager_is_started = true;
	if (df::Manager::manager_is_started)
		return 0;
	else
		return -7;
}

void df::Manager::shutDown()
{
	df::Manager::manager_is_started = false;
}

bool df::Manager::isStarted() const
{
	bool started_fine = true;
	if (df::Manager::manager_is_started != true) { started_fine = false; }
	return started_fine;
}

void df::Manager::setType(std::string type)
{
	type = "Manager";
}

int df::Manager::onEvent(const Event* p_event) const {
	int count = 0;
	ObjectList all_objects = WM.getInstance().getAllObjects();
	ObjectListIterator all_obj_it(&all_objects);

	while (!all_obj_it.atEnd()) {
		all_obj_it.currentObject()->eventHandler(p_event);
		all_obj_it.next();
		count++;
	}
	return count;
}