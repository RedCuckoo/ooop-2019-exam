/*!
	\file
	\brief Header file containing declaration of the class NeighbourRecognizableObject

	This file contains definition of the class NeighbourRecognizableObject
*/

#ifndef NEIGHBOURRECOGNIZABLEOBJECT_H
#define NEIGHBOURRECOGNIZABLEOBJECT_H

#include "Object.h"

class NeighbourRecognizableObject : public Object {
public:
	NeighbourRecognizableObject()
		: Object() {};
	NeighbourRecognizableObject(std::string name, std::string type, std::string position, int height, int width, Object* parent = nullptr)
		: Object(name, type, position, height, width, parent) {};

	void recognize();
};

#endif NEIGHBOURRECOGNIZABLEOBJECT_H
