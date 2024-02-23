#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include "Object.h"
#include "ObjectListIterator.h" // forward pointer to future instantiation

namespace df {
	const int MAX_OBJECTS = 2000;

	class ObjectListIterator;

	class ObjectList {
	private:
		int count; // Num of objs in list
		df::Object* p_objs[MAX_OBJECTS]; // List of pointers to objects

	public:
		friend class ObjectListIterator; // allows ObjectListIterator to access private variables in this class
		ObjectList();

		// List actions
		int insert(df::Object* p_new_obj); // Return 0 upon success; -1 if failure; Adds pointer to obj to list
		int remove(df::Object* p_new_obj); // Return 0 upon success; -1 if failure; Removes pointer to obj from list
		void clear(); // Clears the obj list

		// List status checks
		int getCount() const; // Returns amount of objects (pointers to them) in list
		bool isEmpty() const; // Returns true if list has no pointers to objects (If count == 0); false otherwise
		bool isFull() const; // Returns true if list is at it's max capacity (if count == 2000); false otherwise
	};
}
#endif