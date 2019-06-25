#pragma once
#ifndef BIOSIM_QT7_MYGRAPHICSSCENE
#define BIOSIM_QT7_MYGRAPHICSSCENE
#include <QGraphicsscene>
#include <QGraphicsSceneEvent>
#include <QCursor>
#include <QKeyEvent>
#include "Tile.h"
// Klasse myGraphicsScene die von QGraphicsScene erbt und immer die letzten beide geclickten Tiles speichert und das QImage zum Cursor
class myGraphicsScene : public QGraphicsScene {
public:
	Tile* startTile;
	Tile* endTile;
	myGraphicsScene(QObject *parent = NULL);
	~myGraphicsScene();
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent*event);
private:
	uchar* cursor;
	QImage mouse;
};




#endif // !BIOSIM_QT7_MYGRAPHICSSCENE

