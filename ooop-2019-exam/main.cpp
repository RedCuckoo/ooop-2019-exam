//Variant 24
//OOOP Exam
//Objects on images recognition
//Momotenko Yurii
//K-29

#include "interface/MainWindow/MainWindow.h"
#include <QtWidgets/QApplication>
#include <qdebug.h>
#include <random>
#include <time.h>
#include "simulation/Simulation.h"
#include "data_types/Object.h"
#include "data_types/Image.h"

int main(int argc, char *argv[]){
	//srand(time(0));

	QApplication a(argc, argv);

	std::vector<std::pair<Object*, std::vector<size_t>>> algorithmResults;
	std::pair<std::list<Image>, std::list<Object*>> systemLoad =  Simulation("system_example").run(QDateTime::fromString("2019", "yyyy"), QDateTime::fromString("2020", "yyyy"),algorithmResults);
	
	MainWindow mainWindow(systemLoad.first, systemLoad.second,algorithmResults);
	mainWindow.show();
	return a.exec();
}
