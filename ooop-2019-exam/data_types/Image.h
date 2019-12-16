/*!
	\file
	\brief Header file containing declaration of the class Image

	This file contains definition of the class Image, a description of the image of the object of the type Object
*/

#ifndef IMAGE_H
#define IMAGE_H

#include <QDateTime>
#include <list>
#include <string>
#include "Object.h"

/*!
\brief Image class
\detail Current class implements an image with the provided fields
*/
class Image{
private:
	static size_t idCounter;
	size_t id;
	std::string name;
	QDateTime timeCreated;
	size_t height;
	size_t width;
	std::list<Object*> presentObjects;
	std::vector<std::string> parsePresentObjectNames(std::string input) const;
public:
	Image(std::string name, QDateTime timeCreated, size_t height, size_t width, std::list<Object*> allObjects, std::string presentObjectNames);
	std::string getName() const;
	QDateTime getTimeCreated() const;
	size_t getHeight() const;
	size_t getWidth() const;
	std::list<Object*> getPresentObject() const;
	std::list<Object*> recognize(const std::list<Object*>& allObjects);
};

#endif //IMAGE_H