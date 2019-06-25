#include "mainwindow.h"
#include "firstwindow.hpp"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	Firstwindow f;
	f.show();
	return a.exec();
	
}
