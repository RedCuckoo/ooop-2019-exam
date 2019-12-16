/*!
	\file
	\brief C++ file with implementation of class SimilarRecognizableObject
*/

#include "SimilarRecognizableObject.h"
#include <algorithm>

/*!
\brief Helper function for the algorithm of recognition
\details Current function is overridden from the parent class Object.
The function is a part of the recognition algorithm.
Half of the probability goes to the difference of the sizes between canvas and current object
Another half of the probability goes to the random value
The chance of returning one of the objects that are either the same by its' type or position is equal to returning the current object
\param height The height of the image
\param width The width of the image
\param allObjects The list of all existing objects in the system
\return Returns one object but in the list. It is either the pointer to current object of the class or to the undefined Object
*/
std::list<Object*> SimilarRecognizableObject::recognize(size_t height, size_t width, const std::list<Object*>& allObjects) {
	//between 0 to 1
	if (calcHalfProbability(height, this->height, width, this->width) < 0.5) {
		std::list<Object*> similarObjects;

		for (auto i : allObjects)
			if (i->getType() == type || i->getPosition() == position)
				similarObjects.push_back(i);

		auto result = similarObjects.begin();

		std::advance(result, rand() % similarObjects.size());
		//adding undefined object
		similarObjects.insert(result, new SimilarRecognizableObject());

		result = similarObjects.begin();

		std::advance(result, rand() % similarObjects.size());

		return std::list<Object*>{*result};
	}

	//if greater than 0.5
	return std::list<Object*>{this};
}