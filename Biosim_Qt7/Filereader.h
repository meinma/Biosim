#pragma once
#ifndef BIOSIM_QT7_FILEREADER
#define BIOSIM_QT7_FILEREADER
#include "Imagereader.h"
#include <string>
#include <vector>


class Creature {
public:
	const std::string name;
	const int staerke, geschwindigkeit;
	const int maxLebensdauer;
	const std::string eigenschaften;
	const std::string bildpfad;
	Creature(const std::string &name,const int staerke,const int geschwindigkeit,const int maxLebensdauer,const std::string &eigenschaften, const std::string& bild);
	Creature() = default;
};

 std::vector<Creature> readFile(std::string dateipfad);


#endif //BIOSIM_QT7_FILEREADER


 