/*!
	\file
	\brief C++ file with implementation of class BiRecognizableObject
*/

#include "BiRecognizableObject.h"
#include <cmath>
#include <list>

/*!
\brief Helper function for the algorithm of recognition
\details Current function is overridden from the parent class Object.
The function is a part of the recognition algorithm.
Half of the probability goes to the difference of the sizes between canvas and current object
Another half of the probability is randomized.
\param height The height of the image
\param width The width of the image
\param allObjects The list of all existing objects in the system
\return Returns one object but in the list. It is either the pointer to current object of the class or to the undefined Object
*/
std::list<Object*> BiRecognizableObject::recognize(size_t height, size_t width, const std::list<Object*>& allObjects) {
	return ((calcHalfProbability(height, width, this->height, this->width) >= 0.5) ? (std::list<Object*>{this}) : (std::list<Object*>{new BiRecognizableObject()}));
}