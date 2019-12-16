/*!
	\file
	\brief Header file containing declaration of the Qt interface class

	This file contains definition of the interface window which shows the short info for the object provided in the variant
*/

#ifndef DETAILEDVIEW_H
#define DETAILEDVIEW_H

#include <QDialog>
#include "ui_DetailedView.h"
#include <qstringlistmodel.h>

class DetailedView : public QDialog{
	Q_OBJECT

public:
	DetailedView(size_t objIndex, QString objName, const std::vector<std::string>& present, const std::vector<std::string>& recognized, QWidget *parent = Q_NULLPTR);
	~DetailedView();

private:
	Ui::DetailedView ui;
};

#endif //DETAILEDVIEW_H