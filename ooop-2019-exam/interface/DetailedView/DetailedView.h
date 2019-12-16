#pragma once

#include <QDialog>
#include "ui_DetailedView.h"
#include <qstringlistmodel.h>

class DetailedView : public QDialog{
	Q_OBJECT

public:
	DetailedView(size_t objIndex, QString objName, const std::vector<std::string>& present, const std::vector<std::string>& recognized, QWidget *parent = Q_NULLPTR);
	~DetailedView();

	//QStringListModel* model;
private:
	Ui::DetailedView ui;
};
