/*
* Titre : Menu.h - Travail pratique #6
* Date : 16 avril 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef MENU
#define MENU

#include "Plat.h"
#include "def.h"
#include "erreurfichierintrouvable.h"

#include <map>
#include <QFile>
#include <QString>

using namespace std;

class Menu{
public:
    Menu(QString nomFichier);
	~Menu();
	//getteurs
    map<QString, Plat*> getMenu(TypeMenu typeMenu) const;
    Plat* getPlat(QString nomPlat) const;

private:
	//autres m�thodes
    void lirePlats(QString nomFichier, TypeMenu type, map<QString, Plat*>& menu);
	void ajouterPlat(TypeMenu typeMenu, Plat* plat);
    void supprimerPlatsDuMenu(map<QString, Plat*> menu);
    void lireFichier(QString fichier);
    map<QString, Plat*> menuMatin_;
    map<QString, Plat*> menuMidi_;
    map<QString, Plat*> menuSoir_;


};
#endif
