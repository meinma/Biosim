#include "firstwindow.hpp"

Firstwindow::Firstwindow(QWidget * parent) : QWidget(parent),ui(new Ui::Firstwindow) {
	ui->setupUi(this);
	ui->textEdit->setText("Waehlen Sie unten die bevorzugte Groesse der Landkarte.");
	ui->textEdit->setReadOnly(true);
	ui->klein->setText("Klein");
	ui->mittel->setText("Mittel");
	ui->gross->setText("Gross");
}

Firstwindow::~Firstwindow() {
	delete ui;
	delete mw;
}

void Firstwindow::on_klein_clicked() {
	mw = new MainWindow(32,16);
	mw->show();
	close();
}

void Firstwindow::on_mittel_clicked() {
	mw = new MainWindow(128,64);
	mw->show();
	close();

}

void  Firstwindow::on_gross_clicked() {
	mw = new MainWindow(500,400);
	mw->show();
	close();
}
