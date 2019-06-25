#pragma once
#ifndef BIOSIM_QT7_BEING
#define BIOSIM_QT7_BEING
#include "Filereader.h"
#include <memory>

//Klasse Being enthält eine Kreautur und ihr zugehöriges QImage, wird in eine Liste in Tile hinzugefügt bei Kreaturenplatzierung und mittels dieser dargestellt
// Die Variable alive dient dazu Lebewesen später wieder zu löschen 

class Tile;   
class Being
{
public:
	enum Zustand { WARTEN, WACHSEN, WANDERN, AUSRUHEN, ANGRIFF, JAGEN, PAARUNG, TOT};
	const Creature creature;
	const std::shared_ptr <QImage> image;
	Zustand aktuellerZustand;  //hält den aktuellen Zustand fest für die KI
	//Konstruktor
	Being(const Creature & creature, const std::shared_ptr<QImage> &image, int lp, int lw);
	bool alive;
	Tile *tile; //speichert das Tile auf welchem, das Being gerade ist
	int lebensdauer;  //veränderliche Lebensdauer die schließlich auf0 sinkt, wenn das Lebewesen tot ist und sich so vom const maxLebensdauer unterscheidet
	int letztesWachsen;  // Um die Vorbedingung für Zustand Wachsen zu prüfen, muss das gespeichert werden, notwendig für die KI
	int ausruhSchritte; //Wird zum Ausruhen gebraucht
	int totesZeit; //braucht man damit 10 Schritte das deadBild angezeigt wird
	int letztePaarung;
	bool löschen; //wird gebraucht, damit ein totes Tier aus der Kreaturenliste gelöscht werden kann
	Tile *ziel; //Hier wird das zufällige Ziel gspeichert
	std::vector<Tile*> path;
	Being *beute;
};


#endif // !BIOSIM_QT7_BEING