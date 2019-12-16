/*!
	\file
	\brief C++ file with implementation of class Simulation
*/

#include "Simulation.h"
#include "BiRecognizableObject.h"
#include "PartsRecognizableObject.h"
#include "SimilarRecognizableObject.h"
#include "NeighbourRecognizableObject.h"
#include <fstream>
#include <qdebug.h>
#include "MainWindow.h"
#include <qapplication.h>
#include <algorithm>

std::vector<std::string> Simulation::parseImage(std::string input) {
	std::vector<std::string> res;
	size_t brackCount = 0;
	size_t prevPos = 0;
	for (size_t i = 0, size = input.size(); i < size; ++i) {
		if (input[i] == '"') {
			++brackCount;

			if (brackCount % 2) {
				//if odd
				prevPos = i + 1;
			}
			else {
				//if even
				res.push_back(input.substr(prevPos, i - prevPos));
			}
		}
	}
	return res;
}

/*!
	\brief Constructor for class Simulation
	\details The construstor builds the system for the simulation from the provided folder.
	The folder MUST contain three files required for a succesfull project simulation.
	These files are:
		images.txt (with images description in the next format: ["name"]["dd MM yyyy hh:mm:ss"]["height"]["width"]["objName1, objName2, ..."];)
		objects.txt (with objects description in the next format: ["name"]["type"]["position"]["height"]["width"]{"name of parent obj})
	\param [in] simulation_folder_name The name of the folder which contains files for system simulation
*/
Simulation::Simulation(const std::string& simulation_folder_name) {
	
	std::string working_string;
	std::vector<std::string> parsingRes;
	QString dateFormat = "dd MM yyyy hh:mm:ss";

	std::ifstream input(simulation_folder_name + "/objects.txt");
	int randType;
	bool parentIsPresent;
	Object* to_add;
	while (input.good()) {
		std::getline(input, working_string);

		parsingRes = parseImage(working_string);

		if (parsingRes.size() != 6)
			parsingRes.push_back("");
		
		
		randType = rand() % 4;
		
		switch (randType) {
		case 0:
			to_add = new BiRecognizableObject(parsingRes[0], parsingRes[1], parsingRes[2], std::stoi(parsingRes[3]), std::stoi(parsingRes[4]), parsingRes[5]);
			break;
		case 1:
			to_add = new SimilarRecognizableObject(parsingRes[0], parsingRes[1], parsingRes[2], std::stoi(parsingRes[3]), std::stoi(parsingRes[4]), parsingRes[5]);
			break;
		case 2:
			to_add = new NeighbourRecognizableObject(parsingRes[0], parsingRes[1], parsingRes[2], std::stoi(parsingRes[3]), std::stoi(parsingRes[4]),parsingRes[5]);
			break;
		case 3:
			to_add = new PartsRecognizableObject(parsingRes[0], parsingRes[1], parsingRes[2], std::stoi(parsingRes[3]), std::stoi(parsingRes[4]), parsingRes[5]);
			break;
		}

		objects.push_back(to_add);
	}

	input.close();

	//set parent from name
	for (auto i : objects)
		i->setParent(objects);
	

	input.open(simulation_folder_name + "/images.txt");
	while (input.good()) {
		std::getline(input, working_string);
		parsingRes = parseImage(working_string);
		images.push_back(Image(parsingRes[0], QDateTime::fromString(QString::fromStdString(parsingRes[1]), dateFormat), std::stoi(parsingRes[2]), std::stoi(parsingRes[3]), objects, parsingRes[4]));
	}

	input.close();

	for (auto i : objects) {
		algorithmResults.push_back(std::pair <Object*, std::vector<size_t>>{i, { 0,0,0,0 }});
		objects_vector.push_back(i);
	}
}

std::list<Object*>::iterator Simulation::findObject(const Object* to_find) {
	for (auto i = objects.begin(), end = objects.end(); i != end; ++i) {
		if (to_find == *i)
			return i;
	}
	return objects.end();
}

std::list<std::list<Object*>> Simulation::findNotIsYes(std::list<Object*> imagesObjects, std::list<Object*> recognized) {
	std::list<Object*> is;
	bool notInc = false;
	for (auto im = imagesObjects.begin(); im != imagesObjects.end();) {
		notInc = false;
		for (auto rec = recognized.begin(); rec != recognized.end();) {
			if (**im == (**rec)) {
				is.push_back(*im);
				
				im = imagesObjects.erase(im);
				if (im == imagesObjects.begin())
					notInc = true;
				rec = recognized.erase(rec);
				if (rec == recognized.begin())
					continue;
			}
			if(rec !=recognized.end())
				++rec;
		}
		if(!notInc && im != imagesObjects.end())
			++im;
	}
	//first is positive negative, middle is positive positive, last is negative positive
	return std::list<std::list<Object*>>{imagesObjects, is, recognized};
}


void Simulation::calcResult(const std::list<Object*>& imagesObjects, const std::list<Object*>& recognized) {
	std::list<std::list<Object*>> notIsYes = findNotIsYes(imagesObjects, recognized);

	std::vector<bool> changedObject(objects.size());
	for (size_t i = 0, size = changedObject.size(); i < size; ++i)
		changedObject[i] = 0;

	//negative negative - 0
	//negative positive - 1
	//positive negative - 2
	//positive positive - 3

	auto notIsYesIt = notIsYes.begin();
	std::vector<Object*>::iterator objIt;
	size_t distance;
	//these are positive negative (present but not recognized)
	if (notIsYesIt != notIsYes.end()) {
		for (auto i : *notIsYesIt) {
			if (i->isUndef())
				continue;

			objIt = std::find(objects_vector.begin(), objects_vector.end(), i);
			distance = std::distance(objects_vector.begin(), objIt);
			++algorithmResults[distance].second[2];
			changedObject[distance] = 1;
		}
	}

	++notIsYesIt;
	//positive positive
	if (notIsYesIt != notIsYes.end()) {
		for (auto i : *notIsYesIt) {
			if (i->isUndef())
				continue;
			objIt = std::find(objects_vector.begin(), objects_vector.end(), i);
			distance = std::distance(objects_vector.begin(), objIt);
			++algorithmResults[distance].second[3];
			changedObject[distance] = 1;
		}
	}

	++notIsYesIt;
	//negative positive
	if (notIsYesIt != notIsYes.end()) {
		for (auto i : *notIsYesIt) {
			if (i->isUndef())
				continue;
			objIt = std::find(objects_vector.begin(), objects_vector.end(), i);
			distance = std::distance(objects_vector.begin(), objIt);
			++algorithmResults[distance].second[1];
			changedObject[distance] = 1;
		}
	}

	//negative negative
	for (size_t i = 0, size = changedObject.size(); i < size; ++i) {
		if (changedObject[i]) {
			++algorithmResults[i].second[0];
		}
	}
}

std::pair<std::list<Image>,std::list<Object*>> Simulation::run(const QDateTime& from, const QDateTime& to, std::vector<std::pair<Object*, std::vector<size_t>>>& algorithmResults) {
	std::vector<Image> generatedImages;
	for (auto i : images) {
		if (i.getTimeCreated() >= from && i.getTimeCreated() <= to)
			generatedImages.push_back(i);
	}
	
	std::sort(generatedImages.begin(), generatedImages.end(), [](const Image& im1, const Image& im2) {
		return (im1.getTimeCreated() < im2.getTimeCreated());
		});
	
	std::list<Object*> onImage;
	std::list<Object*> recognized;
	for (auto i : generatedImages) {
		onImage = i.getPresentObject();
		recognized = i.recognize(objects);

		for (auto j : onImage) {
			j->addBelong(i.getName());
		}
		
		for (auto j : recognized) {
			j->addRecognized(i.getName());
		}

		calcResult(onImage, recognized);
	}
	
	algorithmResults = this->algorithmResults;
	return std::pair<std::list<Image>, std::list<Object*>>{images, objects};
}
