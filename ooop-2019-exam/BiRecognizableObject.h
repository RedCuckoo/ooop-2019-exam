/*!
	\file
	\brief Header file containing declaration of the class BiRecognizableObject

	This file contains definition of the class BiRecognizableObject
*/

#ifndef BIRECOGNIZABLEOBJECT_H
#define BIRECOGNIZABLEOBJECT_H

#include "Object.h"

class BiRecognizableObject : public Object {
public:
	BiRecognizableObject()
		: Object() {};
	BiRecognizableObject(std::string name, std::string type, std::string position, int height, int width, Object* parent = nullptr)
		: Object(name, type, position, height, width, parent) {};

	void recognize();
};

#endif BIRECOGNIZABLEOBJECT_H