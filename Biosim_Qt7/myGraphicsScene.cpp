#include "myGraphicsScene.hpp"

//Laden des Cursorbildes im Konstruktor
myGraphicsScene::myGraphicsScene(QObject*parent): startTile(NULL),endTile(NULL), QGraphicsScene(parent)
{
	Image curs(Image::readImage("cursor/cursor.tga"));
	cursor = new uchar[curs.colorvalues.size()];
	std::copy(curs.colorvalues.begin(), curs.colorvalues.end(), cursor);
	mouse = *new QImage(cursor, curs.breite, curs.hoehe, QImage::Format_ARGB32);

}
//Speichert die letzten beiden geclickten Tiles und zeigt den Cursor über diesen an
void myGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent*event) {
	startTile = endTile;
	endTile = ((Tile*)itemAt(event->scenePos(), QTransform()));
	if (endTile == NULL)
		return;
	endTile->setCursor(QPixmap::fromImage(mouse)); //SCHEI?E
}


myGraphicsScene::~myGraphicsScene() {
	delete cursor;
}

