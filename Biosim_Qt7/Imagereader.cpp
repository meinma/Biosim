#include "Imagereader.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex> 
#include <stdexcept>
#include <vector>
using namespace std;

// wirft eine Exception, wenn die Datei nicht im tga-Format ist
void pruefeTGAformat(string dateipfad) {
	regex tgaformat("([[:graph:]]+).tga");
	if (!regex_match(dateipfad, tgaformat))
		throw invalid_argument (" Das Bild ist nicht im tga-Format!");
}

// wirft eine Exception, wenn die Eingabe nicht 0 ist
void istnull(int eingabe) {
	if (eingabe != 0)
		throw invalid_argument("Das Bild kann nicht eingelesen werden. Denn es erfuellt nicht die geforderten Eigenschaften: "
			"Farbpalettentyp, Laenge der Bild ID und X, Y-Nullpunkt muessen 0 sein.");
}

// wenn der Bildtyp nicht 2 ist wird eine Exception geworfen
void checkBildTyp(int bildtyp) {
	if (bildtyp != 2)
		throw invalid_argument("Das Bild kann nicht geoeffnet werden. Es ist vom falschen Typ.");
}

// wirft eine Exception falls die Anzahl der Bit/Pixel nicht 24 oder 32 ist
void checkBitInPixel(int bitsInPixel) {
	if ((bitsInPixel != 24) && (bitsInPixel != 32))
		throw invalid_argument("Das Bild kann nicht eingelesen werden. Es werden nur 24 oder 32 Bit pro Pixel unterstuetzt.");
}

// Überprüft ob die Datei geöffnet werden konnte, wenn nicht wird eine Exception geworfen
void istOffen(const ifstream& file) {
	if (!file.is_open())
		throw invalid_argument("Das Bild konnte nicht geoeffnet werden, ueberpruefen Sie den Bildpfad.");
	
}
//Konstruktor der Klasse Image
Image::Image(int b, int h, int bIP, std::vector<uchar>&c) :
	breite(b), hoehe(h), bitInPixel(bIP), colorvalues(c)
{

}

// Es wird ein Bildpfad übergeben und ein Objekt der Klasse Image, die dem Bild entspricht zurück gegeben
Image Image::readImage(string dateipfad) {
	ifstream datei;
	datei.open(dateipfad.c_str(), ios::in | ios::binary);
	
		istOffen(datei);
		pruefeTGAformat(dateipfad);
		char header[18];
		datei.read(header, 18);
		int laengeBildID = header[0];
		int farbPalettentyp = header[1];
		int bildtyp = header[2];
		int x_Nullpunkt = header[8];
		int y_Nullpunkt = header[10];
		int breite = header[12];
		int hoehe = header[14];
		int bitInPixel = header[16];

		// cout << laengeBildID << "\n" << farbPalettentyp << "\n" << bildtyp << "\n" << x_Nullpunkt << "\n" << y_Nullpunkt << "\n" << breite << "\n" << hoehe << "\n" << bitInPixel << "\n";

		istnull(laengeBildID);
		istnull(farbPalettentyp);
		checkBildTyp(bildtyp);
		istnull(x_Nullpunkt);
		istnull(y_Nullpunkt);
		checkBitInPixel(bitInPixel);
		vector <uchar> colorvalues;
		while (!datei.eof())
		{
			colorvalues.push_back(datei.get());
		}
	
		 return Image(breite, hoehe, bitInPixel, colorvalues);
}
/*
 int main(int argc, const char*argv[]) {
	string bilddatei = argv[1];


	try {

		Image i1(Image::readImage(bilddatei));
	 }
	 catch (const invalid_argument &ia)
	 {
		 cerr << ia.what() << "\n";
	 }


	return 0;
} 
*/