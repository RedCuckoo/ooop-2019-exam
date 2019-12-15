#ifndef OBJECTRECOGNITION_H
#define OBJECTRECOGNITION_H

#include <QTime>
#include <vector>
#include "Object.h"
#include "Image.h"

class ObjectRecognition{
private:
	std::vector<Image> images;
	std::vector<Object*> objects;
public:
	ObjectRecognition(const std::vector<Image>& images, const std::vector<Object*>& objects) : images(images), objects(objects) {};
	void run(QTime begin, QTime end, Object* stat);
};


#endif //OBJECTRECOGNITION_H