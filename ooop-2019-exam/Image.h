/*!
	\file
	\brief Header file containing declaration of the class Image

	This file contains definition of the class Image, a description of the image of the object of the type Object
*/

#ifndef IMAGE_H
#define IMAGE_H

//change it with your own date class if you wouldn't like to stick with Qt framework
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
	std::list<const Object&> presentObjects;
public:
	Image(std::string name, QDateTime timeCreated, size_t height, size_t width, std::list<const Object&> presentObjects);
	std::string getName();
	QDateTime getTimeCreated();
	size_t getHeight();
	size_t getWidth();
	std::list<const Object&> getPresentObject();
};

#endif //IMAGE_H