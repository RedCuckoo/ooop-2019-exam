#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets/QMainWindow>
#include <list>
#include "ui_MainWindow.h"
#include "Object.h"
#include <qstringlistmodel.h>
#include "Image.h"

class MainWindow : public QMainWindow{
	Q_OBJECT

public:
	MainWindow(const std::list<Image>& allImages, const std::list<Object*>& allObjects, std::vector<std::pair<Object*, std::vector<size_t>>> algorithmResults, QWidget *parent = Q_NULLPTR);
private:
	Ui::MainWindowClass ui;
	QStringListModel* model;
	std::list<Image> allImages;
	std::list<Object*> allObjects;
	std::vector<std::pair<Object*, std::vector<size_t>>> algorithmResults;
private slots:
	int on_tableWidget_cellDoubleClicked(int, int);
	int on_actionAlgorithm_view_triggered();
};

#endif MAINWINDOW_H