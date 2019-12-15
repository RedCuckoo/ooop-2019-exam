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
	MainWindow(const std::list<Image>& allImages, const std::list<Object*>& allObjects, QWidget *parent = Q_NULLPTR);
private:
	Ui::MainWindowClass ui;
	QStringListModel* model;
	std::list<Image> allImages;
	std::list<Object*> allObjects;
private slots:
	int on_tableWidget_cellDoubleClicked(int, int);
};

#endif MAINWINDOW_H