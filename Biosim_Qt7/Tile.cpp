
#include "Tile.h"
#include "mainwindow.h"

Tile::Tile(const int x, const int y, const Landscape& t, const std::shared_ptr<QImage>& pi, const std::shared_ptr<QImage> &di, const std::shared_ptr<QImage>& i, QGraphicsItem*parent) : x_pos(x), y_pos(y), type(t), pathImage(pi), deadImage(di), image(i), QGraphicsItem(parent),f(0),h(0),onPath(false),dead(false)
{
	// Tabelle mit Schwierigkeit zur Berechnung der gKosten wird angelegt
	switch (type) {
	DEEPWATER: gLand = -1;
		gWater = 3;
		break;
	SHALLOWWATER: gLand = -1;
		gWater = 1;
		break;
	SAND: gLand = 1;
		gWater = -1;
		break;
	EARTH: gLand = 1;
		gWater = -1;
		break;
	ROCKS: gLand = 4;
		gWater = -1;
		break;
	SNOW: gLand = 2;
		gWater = -1;
		break;
	default: gLand = 0;
		gWater = 0;
		break;
	}
}


QRectF Tile::boundingRect() const {
	return QRectF(x_pos * 32, y_pos * 32, 32, 32);
}

void Tile::paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget*widget) {
	QRectF rect = boundingRect();
	painter->drawImage(rect,*image);

	if (tileKreaturen.size() != 0) {
		std::list <std::shared_ptr<Being>>::const_iterator iterator;
		for (iterator = tileKreaturen.begin(); iterator != tileKreaturen.end(); ++iterator) {
			painter->drawImage(rect,(*iterator)->image->mirrored());
		}
	}

	if (onPath)
		painter->drawImage(rect,*pathImage);
	if (dead)
		painter->drawImage(rect,deadImage->mirrored());
	
	
}

//A Star Algorithmus 
// G-Fkt, wobei die Schwierigkeit der einzelnen Landschaftstypen mit einberechnet wird und Diagonalschritte teuerer sind als gerade Schritte
int Tile::getLandGScore(Tile*t) {
	return t->gLand + ((x_pos == t->x_pos || y_pos == t->y_pos) ? 10 : 14);
}

int Tile::getWaterGScore(Tile*t) {
	return t->gWater + ((x_pos == t->x_pos || y_pos == t->y_pos) ? 10 : 14);
}

//Heuristische Fkt zum Abstand einschätzen mit Hilfe der Manhattan Norm
int Tile::getHScore(Tile*t) {
	return (abs(x_pos - t->x_pos) + abs(y_pos - t->y_pos))*10;
}

void Tile::computeLandScores(Tile* end) {
	gLand = getLandGScore(parent);
	h = getHScore(end);
	f = gLand + h;
}

void Tile::computeWaterScores(Tile*end) {
	gWater = getWaterGScore(parent);
	h = getHScore(end);
	f = gWater + h;
}

