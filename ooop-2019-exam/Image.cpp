/*!
	\file
	\brief C++ file with implementation of class Image
*/

#include "Image.h"
#include <string>
#include <list>

/*!
\brief Constructor for class Image
\details Constructs a valid instance of class Image
\param name Name of the image
\param timeCreated Creation time of the image (in date-time format)
\param height Height of the image of the object (in pixels)
\param width Width of the image of the object (in pixels)
\param presentObjects The list of the unchangeble references to the object of the class Object
*/
Image::Image(std::string name, QDateTime timeCreated, size_t height, size_t width, std::list<const Object&> presentObjects) {
	this->name = name;
	this->timeCreated = timeCreated;
	this->height = ((height > 0) ? height : -height);
	this->width = ((width > 0) ? width : -width);
	this->presentObjects = presentObjects;
}

/*!
\brief Getter method
\details Getter method for the name of the image
\return Name of the image
*/
std::string Image::getName() {
	return name;
}

/*!
\brief Getter method
\details Getter method for the creation date and time of the image
\return Creation date and time of the image
*/
QDateTime Image::getTimeCreated() {
	return timeCreated;
}

/*!
\brief Getter method
\details Getter method for the height of the image
\return Height of the image
*/
size_t Image::getHeight() {
	return height;
}

/*!
\brief Getter method
\details Getter method for the width of the image
\return Width of the image
*/
size_t Image::getWidth() {
	return width;
}

/*!
\brief Getter method
\details Getter method for the list of the objects present in the image
\return List of the objects present in the image
*/
std::list<const Object&> Image::getPresentObject() {
	return presentObjects;
}
