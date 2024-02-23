#include "ObjectListIterator.h"
#include "LogManager.h"

df::ObjectListIterator::ObjectListIterator(const ObjectList* p_list) {
	p_olist = p_list;
	first();
}

void df::ObjectListIterator::first() {
	ol_index = 0;
}

void df::ObjectListIterator::next() {
	if (ol_index < p_olist->count && ol_index < MAX_OBJECTS) {
		ol_index++; 
	}
	else {
		LM.writeLog("Class: ObjectListIterator ; Method: next() ; List is at max capacity/is full\n"); 
	}
}

bool df::ObjectListIterator::atEnd() {
	return (ol_index == p_olist -> count);
}

df::Object* df::ObjectListIterator::currentObject() const {
	if (ol_index < p_olist->count && ol_index < MAX_OBJECTS) {
		return p_olist->p_objs[ol_index];
	}
	else if (ol_index == p_olist->count) {
		return NULL;
	} else {
		LM.writeLog("Class: ObjectListIterator ; Method: currentObject() ; Can't access indexes past max capacity or object list size\n"); 
	}
	return NULL;
}
