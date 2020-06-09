/*!
	\file
	\brief Header file containing declaration of the Qt interface class

	This file contains definition of the interface window which shows the results of the algorithm provided in the variant
*/

#ifndef ALGORITHMRESULTS_H
#define ALGORITHMRESULTS_H

#include <QDialog>
#include "ui_AlgorithmResults.h"
#include "../../data_types/Object.h"

/*!
\brief Interface window
\details Current  window show the results of the algorithm for the selected items
*/
class AlgorithmResults : public QDialog{
	Q_OBJECT

public:
	AlgorithmResults(std::list<Object*> to_demonstrate, std::vector<std::pair<Object*, std::vector<size_t>>> algorithmResults, QWidget *parent = Q_NULLPTR);
	~AlgorithmResults();

private:
	Ui::AlgorithmResults ui;
};

#endif //ALGORITHMRESULTS_H