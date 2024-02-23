#include "ObjectList.h"

df::ObjectList::ObjectList() {
	count = 0;
}

int df::ObjectList::insert(df::Object* p_new_obj) {
	if (count == MAX_OBJECTS) {
		return -1;
	}
	p_objs[count] = p_new_obj; 
	count++;
	return 0;
}

int df::ObjectList::remove(df::Object* p_new_obj) {
	for (int i = 0; i < count; i++) {
		if (p_objs[i] == p_new_obj) {
			for (int j = i; j < count - 1; j++) {
				p_objs[j] = p_objs[j + 1];
			}
			count--;
			return 0;
		}
	}

	return -1;
}

void df::ObjectList::clear() {
	count = 0;
}

int df::ObjectList::getCount() const {
	return count;
}

bool df::ObjectList::isEmpty() const {
	if (count == 0) { return true; }
	return false;
}

bool df::ObjectList::isFull() const {
	if (count == MAX_OBJECTS) { return true; }
	return false;
}
