/*!
	\file
	\brief Header file containing declaration of the class Object

	This file contains definition of the class Object, a description of the image of the object of the type Image
*/

#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <list>
#include <vector>
#include <QString>

/*!
\brief Object class
\detail Current class implements an object with provided fields. 
*/
class Object{
protected:
	std::string name;
	std::string type;
	std::string position;
	size_t height;
	size_t width;
	Object* parent;
	std::string parentName;
	std::vector<std::string> belong;
	std::vector<std::string> recognized;

	static double calcDelta(int delta, const double maxProbability = 0.5);
	static double calcHalfProbability(size_t objHeight, size_t height, size_t objWidth, size_t width);
public:
	Object();
	Object(std::string name, std::string type, std::string position, int height, int width, std::string parentName = "");
	std::string getName();
	std::string getType();
	std::string getPosition(); 
	size_t getHeight();
	size_t getWidth();
	Object* getParent();
	std::vector<std::string> getBelong() const;
	std::vector<std::string> getRecognized() const;

	void setParent(const std::list<Object*>& allObjects);
	bool isUndef();

	void addBelong(std::string name);
	void addRecognized(std::string name);
	bool isNotPresent() const;

	QString operator[](size_t i) const;
	bool operator==(const Object& to_compare) const;

	virtual std::list<Object*> recognize(size_t height, size_t width, const std::list<Object*>& allObjects) = 0;
};

#endif //OBJECT_H