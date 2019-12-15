#include "DetailedView.h"
#include <qstringlistmodel.h>
#include "Image.h"

DetailedView::DetailedView(const std::list<Image>& allImages, const std::list<Object*>& allObjects, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QStringList stringList;
	model = new QStringListModel;
	for (auto i : allObjects)
		stringList.push_back(QString::fromStdString(i->getName()));

	model->setStringList(stringList);

	ui.tableView->setModel(model);

}

DetailedView::~DetailedView()
{
}
