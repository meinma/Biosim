#pragma once
#ifndef BIOSIM_QT7_FIRSTWINDOW_HPP
#define BIOSIM_QT7_FIRSTWINDOW_HPP
#include "ui_firstwindow.h"
#include "mainwindow.h"
#include <QWidget>

namespace Ui {
	class Firstwindow;
}
class Firstwindow : public QWidget {
	Q_OBJECT

public:
	Firstwindow(QWidget * parent = Q_NULLPTR);
	~Firstwindow();

private:
	Ui::Firstwindow *ui;
	MainWindow *mw;

	private slots:
	void on_klein_clicked();
	void on_mittel_clicked();
	void on_gross_clicked();
};
 
#endif // BIOSIM_QT7_FIRSTWINDOW_HPP
