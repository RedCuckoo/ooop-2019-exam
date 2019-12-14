/*!
	\file
	\brief Header file containing declaration of the class PartsRecognizableObject

	This file contains definition of the class PartsRecognizableObject
*/

#ifndef PARTSRECOGNIZABLEOBJECT_H
#define PARTSRECOGNIZABLEOBJECT_H

#include "Object.h"

class PartsRecognizableObject : public Object {
public:
	PartsRecognizableObject()
		: Object() {};
	PartsRecognizableObject(std::string name, std::string type, std::string position, int height, int width, Object* parent = nullptr)
		: Object(name, type, position, height, width, parent) {};

	void recognize();
};

#endif PARTSRECOGNIZABLEOBJECT_H
