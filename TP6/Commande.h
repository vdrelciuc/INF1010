/*
* Titre : Commande.h - Travail pratique #6
* Date : 16 avril 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef COMMANDE
#define COMMANDE

#include "Plat.h"
#include "erreurplatintrouvable.h"
#include "erreurcommandevide.h"
#include "def.h"

#include <map>
#include <string>
#include <QStringList>
#include <QObject>

using namespace std;

class Commande: public QObject {
        Q_OBJECT
public:
    Commande();
    QStringList getCommande();
    void ajouterPlat(QString nomPlat);
    void retirerPlat(QString nomPlat);
    void viderCommande();

signals:
    void commandeModifie();

private:
    QStringList commande_;
};
#endif
