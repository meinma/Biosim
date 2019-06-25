#ifndef BIOSIM_QT7_MAINWINDOW_H
#define BIOSIM_QT7_MAINWINDOW_H
#include "Filereader.h"
#include "Imagereader.h"
#include "ui_mainwindow.h"
#include "Tile.h"
#include "myGraphicsScene.hpp"
#include "AStar.hpp"
#include <vector>
#include <QtWidgets/QMainWindow>
#include <noiseutils.h>
#include <noise/noise.h>
#include <list>
#include <QTimer>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
	
    MainWindow(int breite, int laenge,QWidget *parent = 0);
	std::vector<std::vector<std::shared_ptr<Tile>>>map;  //Map mir den verschiedenen Tiles
	const int mapLaenge;
	const int mapBreite;
	const std::vector <Creature> kreaturen;   // Vector mit Kreaturen aus der Textdatei
    ~MainWindow();


private:
    Ui::MainWindow *ui;
	myGraphicsScene *scene;
	uchar *seicht;
	uchar *tief;
	uchar *gestein;
	uchar *erde;
	uchar *sd;
	uchar *schnee;
	uchar *pfad;
	uchar *tot;
	QTimer *timer;
	int schrittZahl;   // Schrittzahl wird für die KI gespeichert 
	

	std::list <std::shared_ptr<Being>> kreaturenliste; // Liste mit Kreaturen, die in der Anwendung platziert wurden
	std::vector <std::shared_ptr<QImage>> kreaturenImages; // Vector mit QImages zu den Kreaturen aus der Textdatei

	noise::utils::NoiseMap noisemap;
	noise::utils::NoiseMapBuilderPlane noisemapBuilder;
	noise::module::Perlin myModule;

	private slots:
	void on_pushButton_Platzieren_clicked();
	void on_pushButton_Start_clicked();
	void on_pushButton_Schritt_clicked();
	void on_pushButton_Pause_clicked();
	void keyPressEvent(QKeyEvent *keyEvent);

	void schrittZahlUpdate();
	void strength_Updated(int);
	void speed_Updated(int);
	void life_Updated(int);
	void properties_Updated(int);

	void buildNoisemap();
	void action();
	bool wachsenVorbedingung(Being&b);
	bool paarungVorbedingung(Being&b);
	bool jagenVorbedingung(Being&b);
	bool angriffVorbedingung(Being&b);
};



#endif // BIOSIM_QT7_MAINWINDOW_H
