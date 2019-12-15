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
#include "Object.h"
#include "Image.h"

class Simulation{
private:
	std::list<Object*> objects;
	std::list<Image> images;

	std::vector<std::string> parseImage(std::string input);
public:
	Simulation(const std::string& simulation_folder_name);
	std::pair<std::list<Image>, std::list<Object*>> run(const QDateTime& from, const QDateTime& to);
};

#endif SIMULATION_H