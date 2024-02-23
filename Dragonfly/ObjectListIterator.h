#ifndef OBJECTLIST_ITERATOR_H
#define OBJECTLIST_ITERATOR_H

#include "Object.h"
#include "ObjectList.h"

namespace df {
	class ObjectList;
	class ObjectListIterator {
	private:
		ObjectListIterator(); // Given list when created
		int ol_index; // Index into list
		const ObjectList* p_olist; // ObjectList being iterated over

	public:
		ObjectListIterator(const ObjectList* p_list); // Constructs an iterator, over the indicated list
		void first(); // Iterator is set to the first item in list
		void next(); // Iterator is set to the next item in the list
		bool atEnd(); // Return true if at the end of the list
		df::Object* currentObject() const; // Returns the pointer to the current item in the list; NULL if atEnd or empty
	};
}

#endif 
