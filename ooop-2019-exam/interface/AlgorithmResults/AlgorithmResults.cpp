#include "AlgorithmResults.h"
#include <QTableWidgetItem>

/*!
\brief Constructor for interface window AlgorithmResults
\detail Sets the window according to the provided parameters
\param to_demonstrate The list of the objects for which the information has to be shown
\param algorithmResults The results of the algorithm (described in Simulation)
*/
AlgorithmResults::AlgorithmResults(std::list<Object*> to_demonstrate, std::vector<std::pair<Object*, std::vector<size_t>>> algorithmResults, QWidget *parent) : QDialog(parent){
	ui.setupUi(this);
	for (size_t i = 0, size = to_demonstrate.size(); i < size; ++i)
		ui.tableWidget->insertRow(ui.tableWidget->rowCount());
	
	auto demIt = to_demonstrate.begin();
	size_t mark = 0;
	for (size_t rows = 0, rowsCount = ui.tableWidget->rowCount(); rows < rowsCount; ++rows) {
		for (size_t columns = 0, columnsCount = ui.tableWidget->columnCount(); columns < columnsCount; ++columns) {
			for (size_t i = 0, size = algorithmResults.size(); i < size; ++i) {
				if (*algorithmResults[i].first == **demIt) {
					mark = i;
					break;
				}
			}
					
			if (columns == 0)
				ui.tableWidget->setItem(rows, columns, new QTableWidgetItem(QString::fromStdString((*demIt)->getName())));
			else
				ui.tableWidget->setItem(rows, columns, new QTableWidgetItem(QString::fromStdString(std::to_string(algorithmResults[mark].second[columns - 1]))));
		}
		++demIt;
	}
}

/*!
\brief Destructor for interface window AlgorithmResults
*/
AlgorithmResults::~AlgorithmResults(){

}
