/*!
	\file
	\brief Header file containing declaration of the class BiRecognizableObject

	This file contains definition of the class BiRecognizableObject
*/

#ifndef BIRECOGNIZABLEOBJECT_H
#define BIRECOGNIZABLEOBJECT_H

#include "Object.h"

/*!
\brief Typified Object
\details Current declaration describes a typified Object class.
BiRecognizableObject is a type of object, which can be EITHER recognized or NOT
*/
class BiRecognizableObject : public Object {
public:
	BiRecognizableObject()
		: Object() {};
	BiRecognizableObject(std::string name, std::string type, std::string position, int height, int width, Object* parent = nullptr)
		: Object(name, type, position, height, width, parent) {};

	std::list<Object*> recognize(size_t height, size_t width, const std::list<Object*>& allObjects);
};

#endif BIRECOGNIZABLEOBJECT_H