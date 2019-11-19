/*
* Titre : GestionnaireTables.cpp - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"

GestionnaireTables::~GestionnaireTables() {
    for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
        delete (*it);
}

void GestionnaireTables::lireTables(const string &nomFichier) {
    LectureFichierEnSections fichier{nomFichier};
    fichier.allerASection("-TABLES");
    while (!fichier.estFinSection()) {
        int id, nbPlaces;
        fichier >> id >> nbPlaces;
        ajouter(new Table(id, nbPlaces));
    }
}

Table *GestionnaireTables::getTable(int id) const {
    for (set<Table *>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
        if ((*it)->getId() == id)
            return *it;
    return nullptr;
}

Table *GestionnaireTables::getMeilleureTable(int tailleGroupe) const {
    Table *meilleureTable = nullptr;

    for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
        if (!(*it)->estOccupee() && (*it)->getId() != ID_TABLE_LIVRAISON) {
            int placesACetteTable = (*it)->getNbPlaces();
            if (placesACetteTable >= tailleGroupe &&
                (!meilleureTable || placesACetteTable < meilleureTable->getNbPlaces()))
                meilleureTable = (*it);
        }
    }

    if (meilleureTable) {
        return meilleureTable;
    } else {
        return nullptr;
    }

}

void GestionnaireTables::afficherTables(ostream &os) const {
    for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
        os << *(*it);
}

GestionnaireTables &GestionnaireTables::operator+=(Table *table) {
    ajouter(table);
    return *this;
}

