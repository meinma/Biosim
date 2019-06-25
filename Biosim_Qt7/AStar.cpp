#include "AStar.hpp"
#include <list>

struct LessThanGWater
{
	bool operator()(const Tile&l, const Tile&r)const {
		return l.gWater < r.gWater;
	}

};


std::vector<Tile*>aStarWater(Being& startBeing, Tile* end, const std::vector<std::vector<std::shared_ptr<Tile>>> &map) {

	std::vector<Tile*> path;
	Tile* start = startBeing.tile;
	Tile* current;
	Tile* child;
	/*
	if (startBeing.creature.geschwindigkeit == 0)
		throw std::invalid_argument("Es gibt keinen Pfad, weil die Kreatur sich nicht fortbewegen kann");

	if (end->type != 0 && end->type != 1)
		throw std::invalid_argument("Es gibt keinen Weg zwischen Wasser und Gelaende");
*/

	//Definition der open und close List
	//std::priority_queue <Tile, std::vector<Tile>, LessThanGWater> openList;
	std::list <Tile*>openList; // *****                       priority queue                  ********
	std::list <Tile*>closedList;
	std::list <Tile*>::iterator i;

	unsigned int  n = 0;
	openList.push_back(start);
	start->opened = true;

	//Das Tile mit dem geringsten f-Wert wird zum aktuellen Tile gemacht
	while (n == 0 || (current != end && n < 500))
	{
		
		for (i = openList.begin(); i != openList.end(); ++i)
		{
			if (i == openList.begin() || (*i)->f <= current->f)
				current = (*i);
		}
		
		// Abbruch falls das Ende erreicht wird
		if (current == end)
			break;

		// Das aktuelle Tile wird aus der openList entfernt und zur closedList hinzugefügt
		openList.remove(current);
		current->opened = false;
		closedList.push_back(current);
		current->closed = true;

		// Alle adjazenten Tiles des aktuellen Tile werden gesucht
		for (int x = -1; x < 2; x++) {
			for (int y = -1; y < 2; y++) {
				// Wenn das aktuelle Tile erreicht ist wird dieses übersprungen
				if (x == 0 && y == 0)
				{
					continue;
				}
				// Wenn das Tile nicht auf der map ist überspringen
				if (current->x_pos + x < 0 || current->y_pos + y < 0 || current->x_pos + x >= map.size() || current->y_pos + y >= map[0].size())
					continue;

				child = map[current->x_pos + x][current->y_pos + y].get();
				// Wenn das Tile schon in der closedListe ist oder nicht betreten werden darf überspringen
				if ((child->closed) || ((child->type != 0) && (child->type != 1)))
					continue;
				//Prüfen ob es eine Ecke ist
				if (x != 0 && y != 0) {
					//Wenn das nächste horizontale Tile in der closedList ist oder die falsche Landschaft hat überspringen
					if ((map[current->x_pos][current->y_pos + y]->closed) || ((map[current->x_pos][current->y_pos + y]->type != 0) && (map[current->x_pos][current->y_pos + y]->type != 1)))
						continue;
					//Wenn das nächste vertikale Tile in der closedList ist oder die falsche Lanschaft hat überspringen
					if ((map[current->x_pos + x][current->y_pos]->closed) || ((map[current->x_pos + x][current->y_pos]->type != 0) && (map[current->x_pos + x][current->y_pos]->type != 1)))
						continue;
				}

				if (child->opened) {
					// Vergleich der GKosten, falls die GKosten schlechter sind als die durch die der current Point geht, dann ist der Pfad besser wenn der currentPoint parent ist
					if (child->gWater > child->getWaterGScore(current)) {
						child->parent = current;
						child->computeWaterScores(end);
					}
				}

				else {
					//Hinzufügen zur openList mit currentPoint als parent
					openList.push_back(child);
					child->opened = true;
					child->parent = current;
					child->computeWaterScores(end);
				}
			}
		}
		n++;
	}

	//Reset
	for (i = openList.begin(); i != openList.end(); ++i) {
		(*i)->opened = false;
	}
	for (i = closedList.begin(); i != closedList.end(); ++i) {
		(*i)->closed = false;
	}
	//50 ist die obere Schranke, wenn sie erreicht ist, wird die Suche beendet und eine Fehlermeldung ausgegeben
	if (n > 100) throw std::runtime_error("Es gibt keinen Pfad");

	// Rekonstruktion des Pfades vom Endpunkt aus //Hier möglicherweise Fehler
	while ((current->parent != NULL) && (current != start)) {
		path.push_back(current);
		current = current->parent;
		n++;
	}

	return path;

}



std::vector<Tile*>aStarLand(Being &startBeing, Tile* end, const std::vector<std::vector<std::shared_ptr<Tile>>>&map) {

	std::vector<Tile*> path;
	Tile* start = startBeing.tile;
	Tile* current;
	Tile* child;
	/*
	if (startBeing.creature.geschwindigkeit == 0)
		throw std::invalid_argument("Es gibt keinen Pfad, weil die Kreautur sich nicht fortbewegen kann");

	if (end->type == 0 || end->type == 1)
		throw std::invalid_argument("Es gibt keinen Weg zwischen Land und Gewaesser");
*/

	//Definition der open und close List
	std::list <Tile*>openList;
	std::list <Tile*>closedList;
	std::list <Tile*>::iterator i;

	unsigned int  n = 0;

	openList.push_back(start);
	start->opened = true;

	//Das Tile mit dem geringsten f-Wert wird zum aktuellen Tile gemacht
	while (n == 0 || (current != end && n < 500))
	{
		for (i = openList.begin(); i != openList.end(); ++i)
		{
			if (i == openList.begin() || (*i)->f <= current->f)
				current = (*i);
		}
		// Abbruch falls das Ende erreicht wird
		if (current == end)
			break;

		// Das aktuelle Tile wird aus der openList entfernt und zur closedList hinzugefügt
		openList.remove(current);
		current->opened = false;
		closedList.push_back(current);
		current->closed = true;

		// Alle adjazenten Tiles des aktuellen Tile werden gesucht
		for (int x = -1; x < 2; x++) {
			for (int y = -1; y < 2; y++) {
				// Wenn das aktuelle Tile erreicht ist wird dieses übersprungen
				if (x == 0 && y == 0)
				{
					continue;
				}
				// Wenn das Tile ncht auf der map ist überspringen
				if (current->x_pos + x < 0 || current->y_pos + y < 0 || current->x_pos + x >= map.size() || current->y_pos + y >= map[0].size())
					continue;

				child = map[current->x_pos + x][current->y_pos + y].get();
				// Wenn das Tile schon in der closedListe oder den falschen Landschaftstyp hat ist überspringen
				if (child->closed || (child->type == 0 || child->type == 1))
					continue;
				//Prüfen ob es eine Ecke ist
				if (x != 0 && y != 0) {

					//Wenn das nächste horizontale Tile in der closedList ist oder die falsche Landschaft hat überspringen
					if (map[current->x_pos][current->y_pos + y]->closed ||
						map[current->x_pos][current->y_pos + y]->type == 0 ||
						map[current->x_pos][current->y_pos + y]->type == 1)
						continue;
					//Wenn das nächste vertikale Tile in der closedList ist oder die falsche Lanschaft hat überspringen
					if (map[current->x_pos + x][current->y_pos]->closed ||
						map[current->x_pos + x][current->y_pos]->type == 0 ||
						map[current->x_pos + x][current->y_pos]->type == 1)
						continue;
				}

				if (child->opened) {
						// Vergleich der GKosten, falls die GKosten schlechter sind als die durch die der current Point geht, dann ist der Pfad besser wenn der currentPoint parent ist
					if (child->gLand > child->getLandGScore(current)) {
						child->parent = current;
						child->computeLandScores(end);
					}
				}

				else {
					//Hinzufügen zur openList mit currentPoint als parent
					openList.push_back(child);
					child->opened = true;
					child->parent = current;
					child->computeLandScores(end);
				}
			}
		}
		n++;
	}

	//Reset
	for (i = openList.begin(); i != openList.end(); ++i) {
		(*i)->opened = false;
	}
	for (i = closedList.begin(); i != closedList.end(); ++i) {
		(*i)->closed = false;
	}
	//50 ist die obere Schranke, die Suche wird beendet und eine Fehlermeldung ausgegeben, sofern 50 überschritten wird *******Hier leigt der Fehler ******ii
	if (n > 100) throw std::runtime_error("Es gibt keinen Pfad");

	// Rekonstruktion des Pfads vom Endpunkt aus *****************Hier Fehler anschließend iterator out of range**************
	while ((current->parent != NULL) && (current != start)) {
		path.push_back(current);
		current = current->parent;
		n++;
	}

	return path;

}

