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
}

std::pair<std::list<Image>,std::list<Object*>> Simulation::run(const QDateTime& from, const QDateTime& to) {
	std::list<Image> generatedImages;
	for (auto i : images) {
		if (i.getTimeCreated() >= from && i.getTimeCreated() <= to)
			generatedImages.push_back(i);
	}

	return std::pair<std::list<Image>, std::list<Object*>>{images, objects};
}
