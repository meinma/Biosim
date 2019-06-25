#pragma once
#ifndef BIOSIM_QT7_ASTAR
#define BIOSIM_QT7_ASTAR
#include "Tile.h"
#include "mainwindow.h"
#include <vector>



std::vector<Tile*>aStarWater(Being &startBeing, Tile*ende,const std::vector<std::vector<std::shared_ptr<Tile>>>&map);
std::vector<Tile*>aStarLand (Being &startBeing, Tile*ende,const std::vector<std::vector<std::shared_ptr<Tile>>>&map);


 




#endif // !BIOSIM_QT7_ASTAR

