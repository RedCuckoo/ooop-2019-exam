/*!
	\file
	\brief C++ file with implementation of class Image
*/

#include "Image.h"
#include <string>
#include <vector>
#include <list>

size_t Image::idCounter = 0;

/*!
\brief Get fields from the inout
\details The function is parsing input string and gets the fields in the form
\input Input string contains different objects name, separated with a ','
\return The vector of the names of the objects
*/
std::vector<std::string> Image::parsePresentObjectNames(std::string input) const {
	size_t prevPos = 0;
	std::vector<std::string> res;
	for (size_t i = 0, size = input.size(); i < size; ++i) {
		if (input[i] == ',') {
			res.push_back(input.substr(prevPos, i - prevPos));
			prevPos = i + 2;
			i += 2;
		}
	}
	return res;
}

/*!
\brief Constructor for class Image
\details Constructs a valid instance of class Image
\param name Name of the image
\param timeCreated Creation time of the image (in date-time format)
\param height Height of the image of the object (in pixels)
\param width Width of the image of the object (in pixels)
\param presentObjects The list of the unchangeble references to the object of the class Object
*/
Image::Image(std::string name, QDateTime timeCreated, size_t height, size_t width, std::list<Object*> allObjects, std::string presentObjectNames) {
	id = idCounter++;
	this->name = name;
	this->timeCreated = timeCreated;
	this->height = ((height > 0) ? height : -height);
	this->width = ((width > 0) ? width : -width);

	std::vector<std::string> parseRes = parsePresentObjectNames(presentObjectNames);
	
	for (auto i : parseRes) {
		for (auto j : allObjects) {
			if (i == j->getName()) {
				presentObjects.push_back(j);
				break;
			}
		}
	}
}

/*!
\brief Getter method
\details Getter method for the name of the image
\return Name of the image
*/
std::string Image::getName() const{
	return name;
}

/*!
\brief Getter method
\details Getter method for the creation date and time of the image
\return Creation date and time of the image
*/
QDateTime Image::getTimeCreated() const{
	return timeCreated;
}

/*!
\brief Getter method
\details Getter method for the height of the image
\return Height of the image
*/
size_t Image::getHeight() const{
	return height;
}

/*!
\brief Getter method
\details Getter method for the width of the image
\return Width of the image
*/
size_t Image::getWidth() const{
	return width;
}

/*!
\brief Getter method
\details Getter method for the list of the objects present in the image
\return List of the objects present in the image
*/
std::list<Object*> Image::getPresentObject() const{
	return presentObjects;
}

/*!
\brief Recognition function for the Image
\details The function runs the recognition algorithm for each object
\param allObjects The list of all existing objects in the system
\return Returns the list of the Objects which were recognized
*/
std::list<Object*> Image::recognize(const std::list<Object*>& allObjects) {
	std::list<std::list<Object*>> res;
	for (auto i : presentObjects) {
		res.push_back(i->recognize(height, width, allObjects));
	}

	std::list<Object*> ans;
	for (auto i : res) {
		for (auto j : i) {
			ans.push_back(j);
		}
	}

	return ans;
}