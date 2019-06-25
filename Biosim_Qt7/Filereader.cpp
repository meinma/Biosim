#include "Filereader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex> 
#include <stdexcept>
using namespace std;


// Wirft eine Exception, wenn das wort leer ist oder nicht ausschließlich aus normalen Buchstaben und Leerzeichen besteht
void checkName(string wort) {
	if (wort.length() == 0)
		throw invalid_argument("Das erste Wort darf nicht leer sein. Fehler in Zeile: ");
	regex erlaubt("([[:alpha:]]||[[:blank:]])+");
	if (!regex_match(wort, erlaubt))
		throw invalid_argument("Falsche Eingabe beim ersten Wort. Es sind nur Buchstaben und Leerzeichen erlaubt."
			"Es wurden jedoch noch andere Zeichen verwendet. Fehler in Zeile: ");
}

// Eine Exception wird geworfen, falls wort nicht nur aus Zahlen und normalen Buchstaben besteht 
void checkEigenschaft(string wort) {
	regex erlaubt("([[:alnum:]]||[[:blank:]]||_)+");
	if (!regex_match(wort, erlaubt))
		throw invalid_argument("Falsche Eingabe beim 5. Wort. Es sind nur Zahlen und normale Buchstaben erlaubt. Fehler in Zeile: ");
}

// checkZahlen wirft eine Exception falls das wort andere Symbole enthält
void checkZahlen(string wort) {
	regex erlaubt("[[:d:]]+");
	if (!regex_match(wort, erlaubt))
		throw invalid_argument("Falsche Eingabe. Es sind nur Zahlen erlaubt, und es wurde etwas anderes eingelesen. Fehler in Zeile: ");
}

// wirft eine Exception falls das wort leer ist oder nicht in POSIX Standard
void checkPosixStandard(string wort) {
	if (wort.empty())
		throw invalid_argument("Der Posix_Pfad des Bilds darf nicht leer sein. Fehler in Zeile: ");
	regex erlaubt("(([a-zA-Z0-9_]*/?[a-zA-Z0-9_]+)*\\.[[:lower:]]{3})");
	if (!regex_match(wort, erlaubt))
		throw invalid_argument("Der Dateipfad befindet sich nicht in POSIX Standard. Fehler in Zeile: ");
}

// Es wird eine Exception geworfen, falls eine Leerzeile eingelesen wird
void checkLeerzeile(string line) {
	if (line.empty())
		throw length_error("Es wurde eine Leerzeile eingelesen. Zeile: ");
}

//Konstruktor der Klasse Creature
Creature::Creature(const std::string& n,const int st,const int ge, const int leb, const string& eig, const string&b) :
	name(n), staerke(st), geschwindigkeit(ge), maxLebensdauer(leb), eigenschaften(eig),
	bildpfad(b)
{
}


//readFile(string datenpfad) liest eine Textdatei ein und speichert die enthaltenen Kreaturen in einem Vektor, der jedoch noch nicht zurück gegeben wird
vector<Creature> readFile(string dateipfad) {
	ifstream datei;
	vector <Creature> creature;
	datei.open(dateipfad.c_str(), ios::in);
	if (!datei) {
		cout << "Die Datei konnte nicht eingelesen werden. Ueberpruefen sie bitte den Dateipfad. \n";
	}
	int zeile = 1;
	vector <int> zeichenfehler;
	vector <int> leerzeile;
	string s;
	while (getline(datei, s)) {
		stringstream linestream(s);
		string name;
		getline(linestream, name, ',');
		string staerke;
		getline(linestream, staerke, ',');
		string geschwindigkeit;
		getline(linestream, geschwindigkeit, ',');
		string lebensdauer;
		getline(linestream, lebensdauer, ',');
		string eigenschaften;
		getline(linestream, eigenschaften, ',');
		string bildpfad;
		getline(linestream, bildpfad, '\n');
		try {
			checkLeerzeile(s);
			checkName(name);
			checkZahlen(staerke);
			checkZahlen(geschwindigkeit);
			checkZahlen(lebensdauer);
			checkEigenschaft(eigenschaften);
			checkPosixStandard(bildpfad);

			int strength = stoi(staerke);
			int v = stoi(geschwindigkeit);
			int live = stoi(lebensdauer); 

			creature.push_back(Creature(name, strength, v, live, eigenschaften, bildpfad));
		}
		catch (const invalid_argument &ia) {
			zeichenfehler.push_back(zeile);
			cerr << ia.what() << zeile << " \n";
		}
		catch (const length_error &le) {
			leerzeile.push_back(zeile);
			cerr << le.what() << zeile << "\n";
		}
		zeile++;
	}

	if (zeichenfehler.size() > 0) {
		cout << "\nEs gibt Fehler in der Eingabe in den Zeilen: ";
		for (int i = 0; i < zeichenfehler.size() - 1; i++) {
			cout << zeichenfehler.at(i) << ", ";
		}
		cout << zeichenfehler.at(zeichenfehler.size() - 1) << "\n";
	}

	if (leerzeile.size() > 0) {
		cout << "Es gibt Leerzeilen in der Datei an den Stellen: ";
		for (int i = 0; i < leerzeile.size() - 1; i++) {
			cout << leerzeile.at(i) << ", ";
		}
		cout << leerzeile.at(leerzeile.size() - 1) << " \n";
	}

	cout << "Es wurden " << zeile - 1 << " Zeilen eingelesen. \n";
	cout << zeichenfehler.size() << " Zeilen sind fehlerhaft. \n";
	cout << "Damit sind " << zeile - 1 - zeichenfehler.size() << " Zeilen fehlerfrei. \n";

	zeichenfehler.clear();
	leerzeile.clear();
	return creature; 

}











