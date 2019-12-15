#pragma once

#include <QDialog>
#include "ui_DetailedView.h"
#include "Image.h"
#include <qstringlistmodel.h>

class DetailedView : public QDialog{
	Q_OBJECT

public:
	DetailedView(const std::list<Image>& allImages, const std::list<Object*>& allObjects, QWidget *parent = Q_NULLPTR);
	~DetailedView();

	QStringListModel* model;
private:
	Ui::DetailedView ui;
};
