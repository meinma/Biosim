#pragma once
#ifndef BIOSIM_QT7_TILE
#define BIOSIM_QT7_TILE
#include "Being.h"
#include <QPainter>
#include <QGraphicsItem>
#include <List>
#include <memory>


// Klasse Tile enthält zwei Positionen, einen Lanschaftstyp und das dazugehörige Bild, sowie das Cursorbild
// Sie wird verwendet um mit der paint() Methode die Map zu zeichnen und anschließend die hinzugefügten Kreaturen


class Tile : public  QGraphicsItem
{
	
public:
	enum Landscape { DEEPWATER, SHALLOWWATER, SAND, EARTH, ROCKS, SNOW };
	
	const int x_pos;
	const int y_pos;
	const Landscape type;
	const std::shared_ptr<QImage> image;
	const std::shared_ptr<QImage> pathImage;
	const std::shared_ptr<QImage> deadImage;

	//A-Star ALgorithmus
	Tile* parent = NULL;
	bool closed = false;
	bool opened = false;
	int gLand;
	int gWater;
	int f;
	int h;
	bool onPath;
	bool dead;
	


	//List mit Creaturen auf aktuellem Tile
	std::list <std::shared_ptr<Being>> tileKreaturen;
	//Konstruktor
	Tile(const int x_pos,const int y_pos,const Landscape& type, const std::shared_ptr<QImage>&pathImage, const std::shared_ptr<QImage> &deadImage, const std::shared_ptr<QImage>&image, QGraphicsItem*parent = NULL);
	
	//A Star
	int getLandGScore(Tile*t);
	int getWaterGScore(Tile*t);
	int getHScore(Tile*t);
	void computeLandScores(Tile*end);
	void computeWaterScores(Tile*end);

protected:
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget*widget);


};



#endif // BIOSIM_QT7_TILE