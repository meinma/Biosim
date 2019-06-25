#pragma once
#ifndef BIOSIM_QT7_IMAGEREADER
#define BIOSIM_QT7_IMAGEREADER
#include <vector>
#include <QImage>

class Image {
public:
	const int breite;
	const int hoehe;
	const int bitInPixel;
	std::vector<uchar>colorvalues; 
	Image(int breite, int hoehe, int bitInPixel, std::vector<uchar>&colorvalues);
	static Image readImage(std::string dateipfad);
};





#endif //BIOSIM_QT7_IMAGEREADER