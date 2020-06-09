/*!
	\file
	\brief Header file containing declaration of the class NeighbourRecognizableObject

	This file contains definition of the class NeighbourRecognizableObject
*/

#ifndef NEIGHBOURRECOGNIZABLEOBJECT_H
#define NEIGHBOURRECOGNIZABLEOBJECT_H

#include "../Object.h"

/*!
\brief Typified Object
\details Current declaration describes a typified Object class.
NeighbourRecognizableObject is a type of object, which can be 
*/
class NeighbourRecognizableObject : public Object {
public:
	NeighbourRecognizableObject()
		: Object() {};
	NeighbourRecognizableObject(std::string name, std::string type, std::string position, int height, int width, std::string parentName = "")
		: Object(name, type, position, height, width, parentName) {};

	std::list<Object*> recognize(size_t height, size_t width, const std::list<Object*>& allObjects);
};

#endif NEIGHBOURRECOGNIZABLEOBJECT_H
