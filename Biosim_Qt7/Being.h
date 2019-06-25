#pragma once
#ifndef BIOSIM_QT7_BEING
#define BIOSIM_QT7_BEING
#include "Filereader.h"
#include <memory>

//Klasse Being enth�lt eine Kreautur und ihr zugeh�riges QImage, wird in eine Liste in Tile hinzugef�gt bei Kreaturenplatzierung und mittels dieser dargestellt
// Die Variable alive dient dazu Lebewesen sp�ter wieder zu l�schen 

class Tile;   
class Being
{
public:
	enum Zustand { WARTEN, WACHSEN, WANDERN, AUSRUHEN, ANGRIFF, JAGEN, PAARUNG, TOT};
	const Creature creature;
	const std::shared_ptr <QImage> image;
	Zustand aktuellerZustand;  //h�lt den aktuellen Zustand fest f�r die KI
	//Konstruktor
	Being(const Creature & creature, const std::shared_ptr<QImage> &image, int lp, int lw);
	bool alive;
	Tile *tile; //speichert das Tile auf welchem, das Being gerade ist
	int lebensdauer;  //ver�nderliche Lebensdauer die schlie�lich auf0 sinkt, wenn das Lebewesen tot ist und sich so vom const maxLebensdauer unterscheidet
	int letztesWachsen;  // Um die Vorbedingung f�r Zustand Wachsen zu pr�fen, muss das gespeichert werden, notwendig f�r die KI
	int ausruhSchritte; //Wird zum Ausruhen gebraucht
	int totesZeit; //braucht man damit 10 Schritte das deadBild angezeigt wird
	int letztePaarung;
	bool l�schen; //wird gebraucht, damit ein totes Tier aus der Kreaturenliste gel�scht werden kann
	Tile *ziel; //Hier wird das zuf�llige Ziel gspeichert
	std::vector<Tile*> path;
	Being *beute;
};


#endif // !BIOSIM_QT7_BEING