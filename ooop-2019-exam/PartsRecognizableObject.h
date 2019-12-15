/*!
	\file
	\brief Header file containing declaration of the class PartsRecognizableObject

	This file contains definition of the class PartsRecognizableObject
*/

#ifndef PARTSRECOGNIZABLEOBJECT_H
#define PARTSRECOGNIZABLEOBJECT_H

#include "Object.h"

/*!
\brief Typified Object
\details Current declaration describes a typified Object class.
PartsRecognizableObject is a type of object, which consist of other objects, so the recognition algorithm can misrecognise them
*/
class PartsRecognizableObject : public Object {
private:
	bool cover(const std::list<Object*>& partObjects, double approximation = 0.2);
public:
	PartsRecognizableObject()
		: Object() {};
	PartsRecognizableObject(std::string name, std::string type, std::string position, int height, int width, Object* parent = nullptr)
		: Object(name, type, position, height, width, parent) {};

	std::list<Object*> recognize(size_t height, size_t width, const std::list<Object*>& allObjects);
};

#endif PARTSRECOGNIZABLEOBJECT_H
