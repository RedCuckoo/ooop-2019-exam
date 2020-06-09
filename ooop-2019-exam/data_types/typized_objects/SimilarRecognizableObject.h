/*!
	\file
	\brief Header file containing declaration of the class SimilarRecognizableObject

	This file contains definition of the class SimilarRecognizableObject
*/

#ifndef SIMILARRECOGNIZABLEOBJECT_H
#define SIMILARRECOGNIZABLEOBJECT_H

#include "../Object.h"

/*!
\brief Typified Object
\details Current declaration describes a typified Object class.
SimilarRecognizableObject is a type of object, which are similar one to each other
*/
class SimilarRecognizableObject : public Object{
public:
	SimilarRecognizableObject()
		: Object() {};
	SimilarRecognizableObject(std::string name, std::string type, std::string position, int height, int width, std::string parentName = "")
		: Object(name, type, position, height, width, parentName) {};

	std::list<Object*> recognize(size_t height, size_t width, const std::list<Object*>& allObjects);
};

#endif SIMILARRECOGNIZABLEOBJECT_H