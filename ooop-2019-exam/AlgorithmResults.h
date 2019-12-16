#pragma once

#include <QDialog>
#include "ui_AlgorithmResults.h"
#include "Object.h"

class AlgorithmResults : public QDialog
{
	Q_OBJECT

public:
	AlgorithmResults(std::list<Object*> to_demonstrate, std::vector<std::pair<Object*, std::vector<size_t>>> algorithmResults, QWidget *parent = Q_NULLPTR);
	~AlgorithmResults();

private:
	Ui::AlgorithmResults ui;
};
