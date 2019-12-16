#include "DetailedView.h"
#include <qstringlistmodel.h>
#include "Image.h"
#include <QTableWidgetItem>

DetailedView::DetailedView(size_t objIndex, QString objName, const std::vector<std::string>& present, const std::vector<std::string>& recognized, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	ui.textBrowser->setText("Statistics for \"" + objName + "\"");
	ui.textBrowser_left->setText("Present at:");
	ui.textBrowser_right->setText("Recognized at:");
	
	ui.tableWidget_left->insertColumn(0);
	ui.tableWidget_left->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
	ui.tableWidget_right->insertColumn(0);
	ui.tableWidget_right->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));

	for (size_t i = 0, size = present.size(); i < size; ++i) {
		ui.tableWidget_left->insertRow(i);
		ui.tableWidget_left->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(present[i])));
	}	
	
	for (size_t i = 0, size = recognized.size(); i < size; ++i) {
		ui.tableWidget_right->insertRow(i);
		ui.tableWidget_right->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(recognized[i])));
	}

	//QStringList stringList;
	//model = new QStringListModel;
	//for (auto i : allObjects)
	//	stringList.push_back(QString::fromStdString(i->getName()));

	//model->setStringList(stringList);

	//ui.tableView->setModel(model);

}

DetailedView::~DetailedView()
{
}
