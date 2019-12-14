/*!
	\file
	\brief Header file containing declaration of the class SimilarRecognizableObject

	This file contains definition of the class SimilarRecognizableObject
*/

#ifndef SIMILARRECOGNIZABLEOBJECT_H
#define SIMILARRECOGNIZABLEOBJECT_H

#include "Object.h"

class SimilarRecognizableObject : public Object{
public:
	SimilarRecognizableObject()
		: Object() {};
	SimilarRecognizableObject(std::string name, std::string type, std::string position, int height, int width, Object* parent = nullptr)
		: Object(name, type, position, height, width, parent) {};

	void recognize();
};

#endif SIMILARRECOGNIZABLEOBJECT_H