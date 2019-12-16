#include "MainWindow.h"
#include <qstringlistmodel.h>
#include "interface/DetailedView/DetailedView.h"
#include <QMessageBox>
#include "interface/AlgorithmResults/AlgorithmResults.h"

/*!
\brief Constructor for main interface window MainWindow
\detail Sets the window according to the provided parameters
\param allImages The list of all Images in the system
\param allObjects The list of all Objects in the system
\param algorithmResults The results of the algorithm (described in Simulation)
*/
MainWindow::MainWindow(const std::list<Image>& allImages, const std::list<Object*>& allObjects, std::vector<std::pair<Object*, std::vector<size_t>>> algorithmResults, QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);

	this->allImages = allImages;
	this->allObjects = allObjects;
	this->algorithmResults = algorithmResults;

	QStringList stringList;

	for (size_t i = 0, size = allObjects.size(); i < size; i++)
		ui.tableWidget->insertRow(ui.tableWidget->rowCount());

	auto objIt = allObjects.begin();

	for (size_t rows = 0, rowsCount = ui.tableWidget->rowCount(); rows < rowsCount; ++rows) {
		for (size_t columns = 0, columnsCount = ui.tableWidget->columnCount(); columns < columnsCount; ++columns) {
			ui.tableWidget->setItem(rows, columns, new QTableWidgetItem((*(*objIt))[columns]));
		}
		++objIt;
	}
}

/*!
\brief A slot for the main interface window
\details Opens up a modal DetailedView window, based on the object in the row
\param row The index of a row in the tableWidget
\param column The index of a column the tableWidget
*/
int	MainWindow::on_tableWidget_cellDoubleClicked(int row, int column) {
	std::list<Object*>::iterator objIt = allObjects.begin();
	std::advance(objIt, row);
	DetailedView* dv = new DetailedView(row, ui.tableWidget->item(row,0)->text(), (*objIt)->getBelong(), (*objIt)->getRecognized());
	dv->setModal(true);
	dv->show();
	return dv->exec();
}

/*!
\brief A slot for the main interface window
\details Opens up a modal AlgorithmResults window, based on the selected objects
*/
int MainWindow::on_actionAlgorithm_view_triggered() {
	if (!ui.tableWidget->selectedItems().size()) {
		QMessageBox* warn = new QMessageBox;
		warn->setText("<p align = 'center'><br>Please, select a few objects<\\br><\\p>");
		warn->setWindowTitle("Empty selection");
		warn->setModal(true);
		warn->show();
		return warn->exec();
	}
	else {
		std::list<Object*> to_show;
		std::list<Object*>::iterator listIt;
		for (size_t i = 0, size = ui.tableWidget->rowCount(); i < size; ++i) {
			listIt = allObjects.begin();
			if (ui.tableWidget->isItemSelected(ui.tableWidget->item(i, 0))) {
				std::advance(listIt, i);
				to_show.push_back(*listIt);
			}
		}

		AlgorithmResults* algRes = new AlgorithmResults(to_show, algorithmResults);
		algRes->show();
		return algRes->exec();
	}
	return 0;
}