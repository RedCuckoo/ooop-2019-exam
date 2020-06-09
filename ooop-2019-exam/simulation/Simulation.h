/*!
	\file
	\brief Header file containing class Simulation
	This file contains definition of objects definition system
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <list>
#include <vector>
#include "../data_types/Object.h"
#include "../data_types/Image.h"

class Simulation{
private:
	std::list<Object*> objects;
	std::vector<Object*> objects_vector;
	std::list<Image> images;
	std::vector<std::pair<Object*, std::vector<size_t>>> algorithmResults;
	std::vector<std::string> parseImage(std::string input);
	std::list<Object*>::iterator findObject(const Object* to_find);
	std::list<std::list<Object*>> findNotIsYes(std::list<Object*> imagesObjects, std::list<Object*> recognized);
	void calcResult(const std::list<Object*>& imagesObjects, const std::list<Object*>& recognized);
public:
	Simulation(const std::string& simulation_folder_name);
	std::pair<std::list<Image>, std::list<Object*>> run(const QDateTime& from, const QDateTime& to, std::vector<std::pair<Object*, std::vector<size_t>>>& algorithmResults);
};

#endif SIMULATION_H