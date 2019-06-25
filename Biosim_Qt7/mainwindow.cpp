#include "mainwindow.h"
#include "time.h"
#include "Being.h"
#include <QMessageBox>


Tile::Landscape getLandscape(double value) {
	if (value <= -0.667)	return Tile::DEEPWATER;
	else if (value > -0.667 && value <= -0.333) return Tile::SHALLOWWATER;
	else if (value > -0, 333 && value <= 0.0) return Tile::SAND;
	else if (value > 0.0 && value <= 0.333) return Tile::EARTH;
	else if (value > 0.333 && value <= 0.667) return Tile::ROCKS;
	else return Tile::SNOW;
}

//Build der Noisemap
void MainWindow::buildNoisemap() {

	noisemapBuilder.SetDestNoiseMap(noisemap);
	noisemapBuilder.SetSourceModule(myModule);
	noisemapBuilder.SetDestSize(mapBreite, mapLaenge);
	srand(time(NULL));
	double random = (double)rand();
	noisemapBuilder.SetBounds(random, random + 1, random, random + 1);
	noisemapBuilder.Build();

}

MainWindow::MainWindow(int breite, int laenge, QWidget*parent) :
	QMainWindow(parent), mapBreite(breite), mapLaenge(laenge),
	kreaturen(readFile("Kreaturen.txt")), schrittZahl(0),
	ui(new Ui::MainWindow), scene(new myGraphicsScene(this)), timer(new QTimer(this))
{
	try {

		// Fehlermeldung und Schließen des Programms, falls der Kreaturenvektor leer ist
		if (kreaturen.empty()) {
			throw std::invalid_argument("Die Textdatei ist leer. Es konnten keine Kreaturen erstellt werden.");
		}

		//Laden der Bilder für Lanschaft und Cursor

		Image deepwater(Image::readImage("terrain/deep_sea.tga"));
		tief = new uchar[deepwater.colorvalues.size()];
		std::reverse_copy(deepwater.colorvalues.begin(), deepwater.colorvalues.end() - 27, tief);
		std::shared_ptr<QImage> dw(new QImage(tief, deepwater.breite, deepwater.hoehe, QImage::Format_RGB888));

		Image shallowwater(Image::readImage("terrain/shallow_water.tga"));
		seicht = new uchar[shallowwater.colorvalues.size()];
		std::reverse_copy(shallowwater.colorvalues.begin(), shallowwater.colorvalues.end() - 27, seicht);
		std::shared_ptr<QImage> sw(new QImage(seicht, shallowwater.breite, shallowwater.hoehe, QImage::Format_RGB888));

		Image sand(Image::readImage("terrain/sand.tga"));
		sd = new uchar[sand.colorvalues.size()];
		std::reverse_copy(sand.colorvalues.begin(), sand.colorvalues.end() - 27, sd);
		std::shared_ptr<QImage> s(new QImage(sd, sand.breite, sand.hoehe, QImage::Format_RGB888));

		Image earth(Image::readImage("terrain/earth.tga"));
		erde = new uchar[earth.colorvalues.size()];
		std::reverse_copy(earth.colorvalues.begin(), earth.colorvalues.end() - 27, erde);
		std::shared_ptr<QImage> e(new QImage(erde, earth.breite, earth.hoehe, QImage::Format_RGB888));

		Image rocks(Image::readImage("terrain/rocks.tga"));
		gestein = new uchar[rocks.colorvalues.size()];
		std::reverse_copy(rocks.colorvalues.begin(), rocks.colorvalues.end() - 27, gestein);
		std::shared_ptr<QImage> r(new QImage(gestein, rocks.breite, rocks.hoehe, QImage::Format_RGB888));

		Image snow(Image::readImage("terrain/snow.tga"));
		schnee = new uchar[snow.colorvalues.size()];
		std::reverse_copy(snow.colorvalues.begin(), snow.colorvalues.end() - 27, schnee);
		std::shared_ptr<QImage> sn(new QImage(schnee, snow.breite, snow.hoehe, QImage::Format_RGB888));

		Image path(Image::readImage("path/path.tga"));
		pfad = new uchar[path.colorvalues.size()];
		std::copy(path.colorvalues.begin(), path.colorvalues.end(), pfad);
		std::shared_ptr<QImage> p(new QImage(pfad, path.breite, path.hoehe, QImage::Format_ARGB32));

		Image dead(Image::readImage("dead/dead.tga"));
		tot = new uchar[dead.colorvalues.size()];
		std::copy(dead.colorvalues.begin(), dead.colorvalues.end(), tot);
		std::shared_ptr<QImage> d(new QImage(tot, dead.breite, dead.hoehe, QImage::Format_ARGB32));

		buildNoisemap();

		// Die Größe des Vektors wird an die Größe der Map angepasst und der Vektor wird mit den einzelnen Tiles befüllt
		map.resize(mapBreite);
		for (auto &i : map) i.resize(mapLaenge);
		for (int i = 0; i < mapBreite; i++)
		{
			for (int j = 0; j < mapLaenge; j++)
			{
				double value = noisemap.GetValue(i, j);
				Tile::Landscape type = getLandscape(value);

				map[i][j] = std::make_shared<Tile>(i, j, type, p, d, (type == Tile::DEEPWATER ? dw :
					type == Tile::SHALLOWWATER ? sw :
					type == Tile::SAND ? s :
					type == Tile::EARTH ? e :
					type == Tile::ROCKS ? r :
					sn));

				scene->addItem(map[i][j].get());
			}
		}

		// Initialisieren der Liste der QImages
		for (int i = 0; i < kreaturen.size(); i++) {
			Image im(Image::readImage(kreaturen[i].bildpfad));
			uchar * arr = new uchar[im.colorvalues.size()];
			std::copy(im.colorvalues.begin(), im.colorvalues.end(), arr);
			kreaturenImages.push_back(std::make_shared<QImage>(arr, im.breite, im.hoehe, QImage::Format_ARGB32));
		}


		//Beschriftung der einzelnen Buttons, Labels und der Statusbar
		ui->setupUi(this);
		ui->graphicsView->setScene(scene);
		ui->statusBar->showMessage("Schrittzahl: 0      Kreaturenanzahl: 0");
		ui->label_Simulationssteuerung->setText("Simulationssteuerung:");
		ui->label_Staerke->setText("Staerke:");
		ui->label_Geschwindigkeit->setText("Geschwindigkeit:");
		ui->label_Lebensdauer->setText("Lebensdauer:");
		ui->label_Eigenschaften->setText("Eigenschaften:");
		ui->pushButton_Schritt->setText("Schritt");
		ui->pushButton_Start->setText("Start");
		ui->pushButton_Pause->setText("Pause");
		ui->pushButton_Platzieren->setText("Platzieren");

		// Initialisierung der ComboBox mit Namen der Kreaturen aus eingelesener Datei
		for (int i = 0; i < kreaturen.size(); i++) {
			ui->comboBox->addItem(QString::fromStdString(kreaturen[i].name));
		}

		/* Die LineEdits werden anglegt und mit Signal und Slot verknüpft,
		sodass sich der Inhalt ändert, sobald eine andere Kreatur aus der Combobox ausgewählt wird */

		ui->lineEdit_Staerke->setText(QString::number(kreaturen[0].staerke));
		ui->lineEdit_Staerke->setReadOnly(true);
		connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(strength_Updated(int)));

		ui->lineEdit_Geschwindigkeit->setText(QString::number(kreaturen[0].geschwindigkeit));
		ui->lineEdit_Geschwindigkeit->setReadOnly(true);
		connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(speed_Updated(int)));

		ui->lineEdit_Lebensdauer->setText(QString::number(kreaturen[0].maxLebensdauer));
		ui->lineEdit_Lebensdauer->setReadOnly(true);
		connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(life_Updated(int)));

		ui->lineEdit_Eigenschaften->setText(QString::fromStdString(kreaturen[0].eigenschaften));
		ui->lineEdit_Eigenschaften->setReadOnly(true);
		connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(properties_Updated(int)));
		// Timer wird mit SLOT on_push_Button_SChritt_clicked verbunden
		connect(timer, SIGNAL(timeout()), this, SLOT(action()));
	}

	catch (const std::invalid_argument &ia) {
		QMessageBox::critical(this, "Fehler", QString::fromStdString(ia.what()));
		QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);
	}
}

MainWindow::~MainWindow()
{

	delete ui;
	delete tief;
	delete seicht;
	delete sd;
	delete erde;
	delete gestein;
	delete schnee;
	delete pfad;
	delete tot;
	delete timer;
}

// Definition der SLOTS: Dialog beim Drücken eines Button
void MainWindow::on_pushButton_Schritt_clicked() {
	//Vermeidung, dass während des Plays noch der Einzelschritt Knopf gedrückt wird
	if (timer->isActive())
		return;
	action();
}

void MainWindow::on_pushButton_Start_clicked() {
	timer->start(1000);
}
void MainWindow::on_pushButton_Pause_clicked() {
	timer->stop();
}


void MainWindow::on_pushButton_Platzieren_clicked() {
	if (!scene->endTile) {
		QMessageBox::critical(this, "Fehler", "Es muss erst eine Kachel gewählt werden, bevor man eine Kreatur platzieren kann");
		return;
	}
	int currentIndex = ui->comboBox->currentIndex();
	Creature selectedCreature(kreaturen[currentIndex]);
	bool istWasserbewohner = (selectedCreature.eigenschaften.find("Wasserbewohner") != std::string::npos);

	//Überprüfe ob die Landschaft zur Kreatur passt
	if ((!istWasserbewohner && (scene->endTile->type == Tile::DEEPWATER || scene->endTile->type == Tile::SHALLOWWATER)))
	{
		scene->endTile->unsetCursor();
		QMessageBox::critical(this, "Fehler", "Diese Kreatur darf nicht im Wasser platziert werden. Bitte waehlen Sie erneut eine Kachel");
		return;
	}

	if (istWasserbewohner && (scene->endTile->type != Tile::DEEPWATER && scene->endTile->type != Tile::SHALLOWWATER))
	{
		scene->endTile->unsetCursor();
		QMessageBox::critical(this, "Fehler", "Diese Kreatur darf nicht an Land platziert werden. Bitte waehlen sie erneut eine Kachel.");
		return;
	}

	//Ausgewählte Kreatur wird mit Bild in die Liste des Tiles und in die Liste der gesamten Anwendung hinzugefügt, dann wird die Scene aktualisiert
	std::shared_ptr<Being> created(new Being(selectedCreature, kreaturenImages[currentIndex], schrittZahl, schrittZahl));
	std::shared_ptr<Being> s1(created);
	created->tile = scene->endTile;
	//Listen einheitlich 2 shared pointer
	scene->endTile->tileKreaturen.push_back(created);
	kreaturenliste.push_back(s1);

	scene->update(scene->sceneRect());
	scene->endTile->unsetCursor();
	ui->statusBar->showMessage("Schrittzahl: "+QString::number(schrittZahl)+
		"      Kreaturenanzahl: "+QString::number(kreaturenliste.size()));
}

/*Sobald der Name in der Combobox verändert wird,
ändern sich dementsprechend auch die anderen Eigenschaften der Kreatur in den LineEdits */

void MainWindow::strength_Updated(int index) {
	ui->lineEdit_Staerke->setText(QString::number(kreaturen[index].staerke));
}
void MainWindow::speed_Updated(int index) {
	ui->lineEdit_Geschwindigkeit->setText(QString::number(kreaturen[index].geschwindigkeit));
}
void MainWindow::life_Updated(int index) {
	ui->lineEdit_Lebensdauer->setText(QString::number(kreaturen[index].maxLebensdauer));
}
void MainWindow::properties_Updated(int index) {
	ui->lineEdit_Eigenschaften->setText(QString::fromStdString(kreaturen[index].eigenschaften));
}


void MainWindow::keyPressEvent(QKeyEvent *keyEvent) {
	if (keyEvent->key() == Qt::Key_A) {
		try {
			//Abfrage ob 2 Tiles asugewählt worden sind
			if (scene->startTile == NULL || scene->endTile == NULL)
				throw std::invalid_argument("Es muessen 2 Tiles ausgewaehlt werden");
			//Abfrage ob auf dem Startile ine Kreatur platziert ist
			if (scene->startTile->tileKreaturen.empty())
				throw std::invalid_argument("Es muss eine Kreatur auf der Startkachel platziert sein");
			std::vector<Tile*> path;
			//Je nachdem ob der Pfad im Wasser oder an Land ist, Aufruf des dazugehörigen A*-Algorithmus
			if (scene->startTile->type == Tile::DEEPWATER || scene->startTile->type == Tile::SHALLOWWATER)
				path = aStarWater(*scene->startTile->tileKreaturen.back(), scene->endTile, map);
			else
				path = aStarLand(*scene->startTile->tileKreaturen.back(), scene->endTile, map);
			//Pfad wird in MainWindow dargestellt
			std::vector<Tile*>::iterator iterator;
			for (iterator = path.begin(); iterator != path.end(); ++iterator) {
				(*iterator)->onPath = true;
			}
			scene->update();
			path.clear();

		}
		catch (const std::invalid_argument &ia) {
			QMessageBox::critical(this, "Fehler", ia.what());
		}
		catch (const std::runtime_error &re) {
			QMessageBox::critical(this, "Fehler", re.what());
		}
	}
}



//Bedingung die geprüft wird, bevor in den Zustand Wachsen gewchselt werden kann
bool MainWindow::wachsenVorbedingung(Being&b) {
	int x = b.tile->x_pos;
	int y = b.tile->y_pos;
	int anzahlPflanzen = 0;
	std::list<std::shared_ptr<Being>>::const_iterator iterator;
	if ((b.lebensdauer / 100) < (schrittZahl - b.letztesWachsen)) {
		//Überprüfen ob die Anzahl Pflanzen gleichen Typs >2 und <5 in der Umgebung von 5 kacheln
		for (int i = x - 5; i < x + 6; i++) {
			for (int j = y - 5; j < y + 6; j++) {
				if (i == x && j == y)
					continue;
				if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size())
					continue;
				if (map[i][j]->tileKreaturen.empty())
					continue;
				for (iterator = map[i][j]->tileKreaturen.begin(); iterator != map[i][j]->tileKreaturen.end(); iterator++) {
					if (b.creature.name == (*iterator)->creature.name)
						anzahlPflanzen++;
				}
			}
		}
		if ((anzahlPflanzen > 2) && (anzahlPflanzen < 10))
			return true;
		else
			return false;
	}
	return false;
}
//Bedingung, die geprüft wird, bevor in den Zustand Paarung gewechselt wird
bool MainWindow::paarungVorbedingung(Being&b) {
	if ((b.lebensdauer > 0.5 * b.creature.maxLebensdauer) && ((b.lebensdauer / 50) < (schrittZahl - b.letztePaarung))) {
		int x = b.tile->x_pos;
		int y = b.tile->y_pos;
		int anzahlTiere = 0;
		std::list<std::shared_ptr<Being>>::const_iterator it;
		//Überprüfe ob Tiere gleichen Typs in Umgebung von 3 Kacheln > 1 und < 5
		for (int i = x - 3; i < x + 4; i++) {
			for (int j = y - 3; j < y + 4; j++) {
				if (i == x && j == y)
					continue;
				if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size())
					continue;
				if (map[i][j]->tileKreaturen.empty())
					continue;
				for (it = map[i][j]->tileKreaturen.begin(); it != map[i][j]->tileKreaturen.end(); it++) {
					if ((b.creature.name) == ((*it)->creature.name))
						anzahlTiere++;
				}
			}
		}
		if ((anzahlTiere > 1) && (anzahlTiere < 5))
			return true;
		else
			return false;
	}
	return false;
}
//Bedingung, die geprüft wird bevor in den Zustand Jagen gewechselt wird
bool MainWindow::jagenVorbedingung(Being&b) {
	try {
		if (b.lebensdauer < 0.6*b.creature.maxLebensdauer) {
			// Es wird geprüft ob im Umfeld von 10 Kacheln eine passende Beute gefunden wird, wenn ja wird der Pfad gespeichert
			bool istFleischfresser = (b.creature.eigenschaften.find("Fleischfresser") != std::string::npos);
			int x = b.tile->x_pos;
			int y = b.tile->y_pos;
			bool istWasserbewohner = b.creature.eigenschaften.find("Wasserbewohner") != std::string::npos;
			std::list<std::shared_ptr<Being>>::const_iterator it;
			for (int i = x - 10; i < x + 11; i++) {
				for (int j = y - 10; j < y + 11; j++) {
					if (i == x && j == y)
						continue;
					if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size())
						continue;
					if (map[i][j]->tileKreaturen.empty())
						continue;
					if (istWasserbewohner && (map[i][j]->type != Tile::DEEPWATER && map[i][j]->type != Tile::SHALLOWWATER))
						continue;
					if (!istWasserbewohner && (map[i][j]->type == Tile::DEEPWATER || map[i][j]->type == Tile::SHALLOWWATER))
						continue;
					for (it = map[i][j]->tileKreaturen.begin(); it != map[i][j]->tileKreaturen.end(); it++) {
						if (istFleischfresser && ((*it)->creature.eigenschaften.find("Pflanzenfresser") != std::string::npos) && ((*it)->aktuellerZustand != Being::TOT) && ((*it)->creature.geschwindigkeit != 0)) {
							b.ziel = NULL;
							b.beute = it->get();
							// Der Pfad zum Beutetier wird gespeichert, je nachdem ob im Wasser oder an Land und Pflanzen- oder Fleischfresser
							if (istWasserbewohner)
								b.path = aStarWater(b, b.beute->tile, map);
							else
								b.path = aStarLand(b, b.beute->tile, map);
							return true;
						}
						if (!istFleischfresser && ((*it)->creature.eigenschaften.find("fresser") == std::string::npos) && ((*it)->aktuellerZustand != Being::TOT)) { 
							b.ziel = NULL;
							b.beute = it->get();
							if (istWasserbewohner)
								b.path = aStarWater(b, b.beute->tile, map);
							else
								b.path = aStarLand(b, b.beute->tile, map);
							return true;
						}
					}
				}
			}
			return false;
		}
		else
			return false;
	}
	catch (const std::runtime_error &re) {
		return false;
	}
}
//Bedingung, die geprüft wird bevor in den Zustand Angriff gewechselt wird
bool MainWindow::angriffVorbedingung(Being&b) {
	int x = b.tile->x_pos;
	int y = b.tile->y_pos;
	bool fleischFresser = b.creature.eigenschaften.find("Fleischfresser") != std::string::npos;
	//Überprüfen ob Beutetier auf benachbartem Feld platziert ists
	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if (i == x && j == y)
				continue;
			if (i < 0 || i >= map.size() || j < 0 || j >= map[0].size())
				continue;
			if (map[i][j].get() == b.beute->tile)
				return true;
			for (std::list<std::shared_ptr<Being>>::const_iterator it = map[i][j]->tileKreaturen.begin(); it != map[i][j]->tileKreaturen.end(); it++) {
				if (fleischFresser && ((*it)->creature.eigenschaften.find("Pflanzenfresser") != std::string::npos) && ((*it)->aktuellerZustand != Being::TOT) && ((*it)->creature.geschwindigkeit != 0)) {
					b.beute = it->get();
					return true;
				}
				if (!fleischFresser && ((*it)->creature.eigenschaften.find("fresser") == std::string::npos) && ((*it)->aktuellerZustand != Being::TOT)) {
					b.beute = it->get();
					return true;
				}
			}
		}
	}
	return false;
}
//Update der Schrittzahl mitsamt der Statusbar
void MainWindow::schrittZahlUpdate() {
	schrittZahl++;
	ui->statusBar->showMessage(QString::fromStdString("Schrittzahl: ")+QString::number(schrittZahl)+
		QString::fromStdString("      Kreaturenanzahl: ")+QString::number(kreaturenliste.size()));
}

void MainWindow::action() {
	schrittZahlUpdate();
	//Iterator zum Durchgehen der Kreaturenliste
	std::list <std::shared_ptr<Being>>::iterator iterator;
	for (iterator = kreaturenliste.begin(); iterator != kreaturenliste.end(); iterator++) {
		if ((*iterator)->aktuellerZustand == Being::WARTEN) {
			if (wachsenVorbedingung(**iterator)) {
				(*iterator)->aktuellerZustand = Being::WACHSEN;
			}
			else {
				//Lebensdauer wird beim Warten verringert ja nach Landschaftstyp
				if ((*iterator)->tile->type == Tile::DEEPWATER || (*iterator)->tile->type == Tile::ROCKS || (*iterator)->tile->type == Tile::SNOW)
					(*iterator)->lebensdauer -= 25;
				else {
					(*iterator)->lebensdauer -= 10;
				}
			}
		}
		else if ((*iterator)->aktuellerZustand == Being::WACHSEN) {
			srand((unsigned int)time(NULL));
			int erfolgreich = 0;
			bool istWasserbewohner = (*iterator)->creature.eigenschaften.find("Wasserbewohner") != std::string::npos;
			int versuche = 0;
			while (versuche < 20)
			{
				bool sprung = false;
				versuche++;
				//Berechnen von Zufallspositionen in der Umgebung von 5 Kacheln
				int x = rand() % (((*iterator)->tile->x_pos + 5) - ((*iterator)->tile->x_pos - 4)) + (*iterator)->tile->x_pos - 5;
				if (x < 0 || x >= map.size())
					continue;
				int y = rand() % (((*iterator)->tile->y_pos + 5) - ((*iterator)->tile->y_pos - 4)) + (*iterator)->tile->y_pos - 5;
				if (y < 0 || y >= map[0].size())
					continue;
				if (istWasserbewohner && (map[x][y]->type != Tile::DEEPWATER && map[x][y]->type != Tile::SHALLOWWATER))
					continue;
				if (!istWasserbewohner && (map[x][y]->type == Tile::DEEPWATER || map[x][y]->type == Tile::SHALLOWWATER))
					continue;
				for (std::list<std::shared_ptr<Being>>::const_iterator it = map[x][y]->tileKreaturen.begin(); it != map[x][y]->tileKreaturen.end(); it++) {
					if ((*it)->creature.eigenschaften.find("Pflanze") != std::string::npos) {
						sprung = true;
						break;
					}
				}
				if (sprung)
					continue;
				//Erstellen einer neuen Kreatur gleichen Typs, die auf den zufällig berechneten Standort gesetzt wird
				std::shared_ptr<Being> neu(new Being((*iterator)->creature, (*iterator)->image, schrittZahl, schrittZahl));
				std::shared_ptr<Being>neu2(neu);
				neu->tile = map[x][y].get();
				neu->letztesWachsen = schrittZahl;
				kreaturenliste.push_back(neu);
				map[x][y]->tileKreaturen.push_back(neu2);
				erfolgreich++;
				//Abbruch nach 2 neuen Kreaturen
				if (erfolgreich == 2) {
					(*iterator)->letztesWachsen = schrittZahl;
					break;
				}
			}
			(*iterator)->aktuellerZustand = Being::WARTEN;

		}
		else if ((*iterator)->aktuellerZustand == Being::TOT) {
			//Zeit wird gesetzt, damit der Totenkopf 10 Sekunden erscheint
			if ((*iterator)->alive == true) {
				(*iterator)->alive = false;
				(*iterator)->tile->dead = true;
				(*iterator)->totesZeit = schrittZahl + 10;
			}
			//Totenkopf und tote Kreatur von Tile löschen
			if ((*iterator)->totesZeit == schrittZahl) {
				(*iterator)->tile->dead = false;
				(*iterator)->löschen = true;
				(*iterator)->tile->tileKreaturen.remove(*iterator);
			}
		}
		else if ((*iterator)->aktuellerZustand == Being::AUSRUHEN) {
			//Solange Ausruhen bis Ausruhschritte auf 0 sind
			if ((*iterator)->ausruhSchritte == 0)
				(*iterator)->aktuellerZustand = Being::WANDERN;
			else {
				(*iterator)->ausruhSchritte--;
				(*iterator)->lebensdauer -= 5;
			}
		}
		else if ((*iterator)->aktuellerZustand == Being::WANDERN) {
			// Es wird ein zufälliges Ziel zum Wandern gesucht, wenn keines vorhanden ist
			int speed = ceil((*iterator)->creature.geschwindigkeit / 20);
			if ((*iterator)->ziel == NULL) {

				bool istWasserbewohner = (*iterator)->creature.eigenschaften.find("Wasserbewohner") != std::string::npos;
				srand((unsigned int)time(NULL));
				while ((*iterator)->ziel == NULL) {
					try {
						int x = rand() % (((*iterator)->tile->x_pos + 10) - ((*iterator)->tile->x_pos - 10 + 1)) + (*iterator)->tile->x_pos - 10;
						if (x < 0 || x >= map.size())
							continue;
						int y = rand() % (((*iterator)->tile->y_pos + 10) - ((*iterator)->tile->y_pos - 10 + 1)) + (*iterator)->tile->y_pos - 10;
						if (y < 0 || y >= map[0].size())
							continue;
						if (istWasserbewohner && (map[x][y]->type != Tile::DEEPWATER && map[x][y]->type != Tile::SHALLOWWATER))
							continue;
						if (!istWasserbewohner && (map[x][y]->type == Tile::DEEPWATER || map[x][y]->type == Tile::SHALLOWWATER))
							continue;
						//Sobald ein geeignetes Tile gefunden wurde, wird der Weg und das Zieltile gespeichert
						if (istWasserbewohner)
							(*iterator)->path = aStarWater(**iterator, map[x][y].get(), map);
						else
							(*iterator)->path = aStarLand(**iterator, map[x][y].get(), map);
						(*iterator)->ziel = map[x][y].get();
					}
					catch (const std::runtime_error &re) {
						continue;
					}
				}
			}
			if (paarungVorbedingung(**iterator))
				(*iterator)->aktuellerZustand = Being::PAARUNG;
			else if (jagenVorbedingung(**iterator))
				(*iterator)->aktuellerZustand = Being::JAGEN;
			//Ist das Ziel erreicht, wird die Anzahl der Ausruhschritte festgelegt
			else if ((*iterator)->tile == (*iterator)->ziel) {
				(*iterator)->aktuellerZustand = Being::AUSRUHEN;
				(*iterator)->ausruhSchritte = ((*iterator)->lebensdauer / (*iterator)->creature.maxLebensdauer) * 5;
				(*iterator)->ziel = NULL;
			}
			//Aufgrund der jeweiligen Schnelligeit mehrere Tiles aufeinmal laufen
			else {
				for (int i = 0; i < speed; i++) {
					if ((*iterator)->path.empty()) {
						(*iterator)->ziel = NULL;
						break;
					}
					if ((*iterator)->tile == (*iterator)->ziel)
						break;
					(*iterator)->tile->tileKreaturen.remove(*iterator);
					(*iterator)->tile = (*iterator)->path.back();
					(*iterator)->path.back()->tileKreaturen.push_back(*iterator);
					(*iterator)->path.pop_back();
					(*iterator)->lebensdauer -= 2;
				}
			}
		}

		else if ((*iterator)->aktuellerZustand == Being::PAARUNG) {
			srand((unsigned int)time(NULL));
			int erfolgreich = 0;
			bool istWasserbewohner = (*iterator)->creature.eigenschaften.find("Wasserbewohner") != std::string::npos;
			int versuche = 0;
			while (versuche < 15)
			{
				bool sprung = false;
				versuche++;
				//Zufallsposition im Abstand von 3 Tiles bestimmen
				int x = rand() % (((*iterator)->tile->x_pos + 3) - ((*iterator)->tile->x_pos - 2)) + (*iterator)->tile->x_pos - 3;
				if (x < 0 || x >= map.size())
					continue;
				int y = rand() % (((*iterator)->tile->y_pos + 3) - ((*iterator)->tile->y_pos - 2)) + (*iterator)->tile->y_pos - 3;
				if (y < 0 || y >= map[0].size())
					continue;
				for (std::list<std::shared_ptr<Being>>::const_iterator it = map[x][y]->tileKreaturen.begin(); it != map[x][y]->tileKreaturen.end(); it++) {
					if ((*it)->creature.eigenschaften.find("Tier") != std::string::npos) {
						sprung = true;
						break;
					}
				}
				if (sprung)
					continue;
				if (istWasserbewohner && (map[x][y]->type != Tile::DEEPWATER && map[x][y]->type != Tile::SHALLOWWATER))
					continue;
				if (!istWasserbewohner && (map[x][y]->type == Tile::DEEPWATER || map[x][y]->type == Tile::SHALLOWWATER))
					continue;
				//2 neue Kreaturen auf die zufälligen Tiles setzen und Lebensdauer anpassen
				std::shared_ptr<Being> c1(new Being((*iterator)->creature, (*iterator)->image, schrittZahl, schrittZahl));
				std::shared_ptr<Being> c2(c1);
				c1->tile = map[x][y].get();
				c1->lebensdauer = (*iterator)->lebensdauer * 0.5;
				kreaturenliste.push_back(c1);
				map[x][y]->tileKreaturen.push_back(c2);
				erfolgreich++;
				//Abbruch nach 2 neuen Kreaturen
				if (erfolgreich == 2) {
					(*iterator)->letztePaarung = schrittZahl;
					(*iterator)->lebensdauer = 0.75 * (*iterator)->lebensdauer;
					break;
				}

			}

			(*iterator)->aktuellerZustand = Being::WANDERN;
		}
		else if ((*iterator)->aktuellerZustand == Being::JAGEN) {
			if (angriffVorbedingung(**iterator))
				(*iterator)->aktuellerZustand = Being::ANGRIFF;
			else {
				jagenVorbedingung(**iterator);

				for (int i = 0; i < (ceil((*iterator)->creature.geschwindigkeit / 10)); i++) {
					//jagenVorbedingung(**iterator);
					if ((*iterator)->path.empty()) {
						(*iterator)->aktuellerZustand = Being::WANDERN;
						break;
					}
					if ((*iterator)->path.back() == (*iterator)->beute->tile)
						break;
					(*iterator)->lebensdauer -= 10;
					(*iterator)->tile->tileKreaturen.remove(*iterator);
					(*iterator)->tile = (*iterator)->path.back();
					(*iterator)->tile->tileKreaturen.push_back(*iterator);
					(*iterator)->path.pop_back();
				}
			}
		}
		else if ((*iterator)->aktuellerZustand == Being::ANGRIFF) {
			//Abbruch falls das Beutetier tot ist, oder der Angreifer seine maximale Lebensdauer erreicht
			if (((*iterator)->beute->aktuellerZustand == Being::TOT) || ((*iterator)->lebensdauer >= (*iterator)->creature.maxLebensdauer)) {
				if ((*iterator)->lebensdauer >= (*iterator)->creature.maxLebensdauer)
					(*iterator)->lebensdauer = (*iterator)->creature.maxLebensdauer;
				(*iterator)->beute = NULL;
				(*iterator)->ausruhSchritte = ((*iterator)->lebensdauer / (*iterator)->creature.maxLebensdauer) * 5;
				(*iterator)->aktuellerZustand = Being::AUSRUHEN;
			}
			//Angriff falls sich die Beute noch auf einer Nachbarkachel befindet
			else if (angriffVorbedingung(**iterator)) {
				(*iterator)->beute->lebensdauer -= (*iterator)->creature.staerke;
				(*iterator)->lebensdauer += ((*iterator)->creature.staerke) / 2;
				(*iterator)->aktuellerZustand = Being::ANGRIFF;
			}
			else {
				(*iterator)->aktuellerZustand = Being::JAGEN;
				//jagenVorbedingung(**iterator);
			}
		}
		else {
			(*iterator)->aktuellerZustand = Being::TOT;
		}
		// Überprüfen, dass alle Kreaturen, die keine Lebensdauer mehr haben, in den Zustand Tot wechseln
		if (((*iterator)->lebensdauer <= 0) && ((*iterator)->aktuellerZustand != Being::TOT))
			(*iterator)->aktuellerZustand = Being::TOT;
	}

// Die toten Kreaturen werden aus der Kreaturenliste gelöscht
	for (std::list<std::shared_ptr<Being>>::const_iterator it = kreaturenliste.begin(); it != kreaturenliste.end();) {
		if (((*it)->aktuellerZustand == Being::TOT) && ((*it)->löschen))
			kreaturenliste.erase(it++);
		else
			++it;
	}
	scene->update();

}
