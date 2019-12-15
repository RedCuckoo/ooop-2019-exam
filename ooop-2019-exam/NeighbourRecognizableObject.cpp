/*!
	\file
	\brief C++ file with implementation of class NeighbourRecognizableObject
*/

#include "NeighbourRecognizableObject.h"

/*!
\brief Helper function for the algorithm of recognition
\details Current function is overridden from the parent class Object.
The function is a part of the recognition algorithm.
The equal chance of returning one of the objects that are either the same by its' type or position
\param height The height of the image
\param width The width of the image
\param allObjects The list of all existing objects in the system
\return Returns one object but in the list. It is either the pointer to current object of the class or to the undefined Object
*/
std::list<Object*> NeighbourRecognizableObject::recognize(size_t height, size_t width, const std::list<Object*>& allObjects) {
	std::list<Object*> neighbourObjects;
	int size = rand() % (allObjects.size() / 2);
	size = rand() % size;
	auto cur = std::find(allObjects.begin(), allObjects.end(), this);
	
	for (auto i = cur; i != allObjects.end(); ++i) {
		if (i == cur) 
			//not doing anything with cur
			for (auto j = cur; j != allObjects.begin();) {
				--j;
				neighbourObjects.push_back(*j);
			}
		neighbourObjects.push_back(*i);
	}

	neighbourObjects.push_back(new NeighbourRecognizableObject());
	
	cur = neighbourObjects.begin();
	std::advance(cur, rand() % neighbourObjects.size());

	//TODO: ask about the logic of this method
	return (std::list<Object*>{*cur});
}