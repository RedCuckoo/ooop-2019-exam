#include "MainWindow.h"
#include <qstringlistmodel.h>
#include "DetailedView.h"

MainWindow::MainWindow(const std::list<Image>& allImages, const std::list<Object*>& allObjects, QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);

	this->allImages = allImages;
	this->allObjects = allObjects;

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

	/*model = new QStringListModel;
	for (auto i : allObjects)
		stringList.push_back(QString::fromStdString(i->getName()));*/




	//ui.table
	


	//model->setStringList(stringList);
	//ui.tableView->setModel(model);
	//model->setStringList(stringList);
	//ui.tableView->setModel(model);


	//ui.tableWidget->setItem()
}

int	MainWindow::on_tableWidget_cellDoubleClicked(int row, int column) {
	DetailedView* dv = new DetailedView(allImages, allObjects, );
	dv->setModal(true);
	dv->show();
	return dv->exec();
}
