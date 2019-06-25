#include "Being.h"



Being::Being(const Creature &c, const std::shared_ptr<QImage> &img, int lw, int lp) : creature(c), image(img), alive(true), löschen(false), lebensdauer(creature.maxLebensdauer), letztesWachsen(lw), letztePaarung(lp),totesZeit(NULL), ziel(NULL), ausruhSchritte(0), beute(NULL)
{
	if (creature.geschwindigkeit == 0)
		aktuellerZustand = WARTEN;
	else aktuellerZustand = WANDERN;
}

