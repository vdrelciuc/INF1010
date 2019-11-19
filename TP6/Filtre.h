/*
* Titre : Filtre.h - Travail pratique #6
* Date : 16 avril 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef FILTRE
#define FILTRE

#include "def.h"
#include "Menu.h"

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <QStringList>
#include <QObject>

using namespace std;

class Filtre: public QObject {
        Q_OBJECT
public:
	Filtre(Menu* menu = nullptr);
    QStringList getNomPlatsFiltres();

public slots:
    void clicOptionVege();
    void clicOptionBio();
    void choixTypeMenu(TypeMenu typeMenu);

signals:
    void choixFiltrageModifie();

private:
    void filtrerPlats(map<QString, Plat*>& plats);
	Menu* menu_;
    TypeMenu typeMenu_;
	bool isVegeOption_;
	bool isBioOption_;
};
#endif
