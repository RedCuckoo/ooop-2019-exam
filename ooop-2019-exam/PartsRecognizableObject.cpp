/*!
	\file
	\brief C++ file with implementation of class PartsRecognizableObject
*/

#include "PartsRecognizableObject.h"

/*!
\brief Helper function, coverage check
\detail Checks whether all the objects in the list are lying in the setted approximity relatively to this object
\param partObjects The list of objects, which are child to the current one
\param approximation The approximation for which the check should be completed (number from 0 to 1)
\return True if the objects are of the size with the approximation, false vise versa
*/
bool PartsRecognizableObject::cover(const std::list<Object*>& partObjects, double approximation) {
	if (!partObjects.size())
		return false;

	double allAreas = 0;
	for (auto i : partObjects)
		allAreas += (i->getWidth() * i->getHeight());

	return (abs(allAreas - (width * height)) > (allAreas - allAreas * approximation)) ? false : true;
}

/*!
\brief Helper function for the algorithm of recognition
\details Current function is overridden from the parent class Object.
The function is a part of the recognition algorithm.
The chance of recognising just part of the object is 2:3 while of recognizing the whole object is 1:3
\param height The height of the image
\param width The width of the image
\param allObjects The list of all existing objects in the system
\return Returns one object but in the list. It is either the pointer to current object of the class or to the undefined Object
*/
std::list<Object*> PartsRecognizableObject::recognize(size_t height, size_t width, const std::list<Object*>& allObjects) {
	if (calcHalfProbability(this->height, height, this->width, width) < (2 / 3)) {
		std::list<Object*> partsObject;

		for (auto i : allObjects)
			if (i->getParent() == this)
				partsObject.push_back(i);

		if (!cover(partsObject))
			return std::list<Object*>{new PartsRecognizableObject()};

		if (!partsObject.size())
			partsObject.push_back(new PartsRecognizableObject());

		return partsObject;
	}

	return std::list<Object*>{this};
}