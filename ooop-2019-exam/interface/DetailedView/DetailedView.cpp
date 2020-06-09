#include "DetailedView.h"
#include <qstringlistmodel.h>
#include "../../data_types/Image.h"
#include <QTableWidgetItem>

/*!
\brief Constructor for interface window DetailedView
\detail Sets the window according to the provided parameters
\param objIndex The index of the object in the common list
\param objName The name of the object
\param present The list of the Images where current object is present
\param recognized The list of the Images where current object was recognized
*/
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
}

/*!
\brief Destructor for interface window DetailedView
*/
DetailedView::~DetailedView(){

}
