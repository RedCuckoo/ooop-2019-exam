/*!
	\file
	\brief C++ file with implementation of class Object
*/

#include "Object.h"
#include <string>
#include <vector>

/*!
\brief Constructor for class Object
\details Defines an undefined instance of class Object
*/
Object::Object() {
	name = "";
	type = "";
	position = "";
	height = 0;
	width = 0;
}

/*!
\brief Constructor for class Object
\details Constructs a valid instance of class Object
\param name Name of the object
\param type Type of the object, like in real life (e.g animal, human, etc)
\param position Position of the object (e.g standing, running etc)
\param height Height of the image of the object (in pixels)
\param width Width of the image of the object (in pixels)
\param parent Parent object of the current object (e.g object Human will be a parent object for the object Hand)
*/
Object::Object(std::string name, std::string type, std::string position, int height, int width, std::string parentName) {
	this->name = name;
	this->type = type;
	this->position = position;
	this->height = ((height>0) ? height : -height);
	this->width = ((width >0) ? width : -width);
	this->parentName = parentName;
}

/*!
\brief Getter method
\details Getter method for the name of the object
\return Name of the object
*/
std::string Object::getName() {
	return name;
}

/*!
\brief Getter method
\details Getter method for the type of the object
\return Type of the object
*/
std::string Object::getType() {
	return type;
}

/*!
\brief Getter method
\details Getter method for the position of the object
\return Position of the object
*/
std::string Object::getPosition() {
	return position;
}

/*!
\brief Getter method
\details Getter method for the height of the object
\return Height of the object
*/
size_t Object::getHeight() {
	return height;
}

/*!
\brief Getter method
\details Getter method for the width of the object
\return Width of the object
*/
size_t Object::getWidth() {
	return width;
}

/*!
\brief Getter method
\details Getter method for the parent of the object
\return Parent of the object
*/
Object* Object::getParent() {
	return parent;
}

/*!
\brief Setter method
\details Setter method for the parent of the object
*/
void Object::setParent(const std::list<Object*>& allObjects) {
	if (parentName == "")
		return;

	for (auto i : allObjects) {
		if (i->type == parentName) {
			parent = i;
			return;
		}
	}
}

/*!
\brief Undefined object check
\details Checks whether current object is undefined or not
\return True value if the current object is undefined, false value vise versa
*/
bool Object::isUndef() {
	return ((name == "" && type == "" && position == "" && height == 0 && width == 0) ? true : false);
}

/*!
\brief Helper function for delta calculation
\details The function makes parameter positive and returns some part of maxProbability depending on it's value.
maxProbability is the biggest amount of probability (out of 1) the parameter can hold.
\param delta Given parameter to be normized
\return Normized delta
*/
double Object::calcDelta(int delta, const double maxProbability){
	if (delta < 0)
		delta = -delta;

	++delta;

	return (maxProbability / delta);
}

/*!
\brief Helper function for delta calculation
\details The function calculates the probablity, half of it comes from the size difference (between object and canvas),
another half comes from the random value
\param objHeight Height of the object
\param height Height of the image
\param objWidth Width of the object
\param width Width of the object
\return Normized delta
*/
double Object::calcHalfProbability(size_t objHeight, size_t height, size_t objWidth, size_t width) {
	double curProbability = calcDelta(height - objHeight) + calcDelta(width - objWidth);
	curProbability = fmod(curProbability, 0.5);
	curProbability += fmod((double)rand(), 0.5);
	return curProbability;
}

/*!
\brief Overloaded operator[]
\details Returns on of the fields depending in the index
\param i Provided index
*/
QString Object::operator[](size_t i) const {
	std::vector<QString> res = {
		QString::fromStdString(name),
		QString::fromStdString(type),
		QString::fromStdString(position),
		QString::fromStdString(std::to_string(height) + 'x' + std::to_string(width)),
		QString::fromStdString(parentName)
	};
	return res[i];
}

/*!
\brief Overloaded operator==
\details Returns on of the fields depending in the index
\param to_compare The Object which is comparing with the current Object
\return True value if they are equal, false value otherwise
*/
bool Object::operator==(const Object& to_compare) const {
	return (name == to_compare.name
		&& type == to_compare.type
		&& position == to_compare.position
		&& height == to_compare.height
		&& width == to_compare.width
		&& parentName == to_compare.parentName);
}

/*!
\brief Setter method
\details Adds name to the list of the images, where this object is present
\param name Name of the Image
*/
void Object::addBelong(std::string name) {
	belong.push_back(name);
}

/*!
\brief Setter method
\details Adds name to the list of the images, where this object is recognized
\param name Name of the Image
*/
void Object::addRecognized(std::string name) {
	recognized.push_back(name);
}

/*!
\brief Checks if the object is present on some image
\return True value if the object is present on some image, false value otherwise
*/
bool Object::isNotPresent() const{
	return (belong.size() == 0 && recognized.size() == 0);
}

/*!
\brief Getter method
\details Getter method for the list of the names of the images where this object belong
\return List of the names of the images where this object belong
*/
std::vector<std::string> Object::getBelong() const{
	return belong;
}

/*!
\brief Getter method
\details Getter method for the list of the names of the images where this object was recognized
\return List of the names of the images where this object was recognized
*/
std::vector<std::string> Object::getRecognized() const{
	return recognized;
}
