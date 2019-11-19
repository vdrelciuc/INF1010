/*
* Titre : Restaurant.cpp - Travail Pratique #1
* Date : 01 février 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Restaurant.h"

Restaurant::Restaurant() {
    capaciteTables_ = INTTABLES;
    nbTables_ = 0;
    tables_ = new Table *[capaciteTables_];
    nom_ = nullptr;
    momentJournee_ = Matin;
    chiffreAffaire_ = 0;
    menuMatin_ = new Menu();
}

Restaurant::Restaurant(string &fichier, string &nom, TypeMenu moment) {
    capaciteTables_ = INTTABLES;
    nbTables_ = 0;
    tables_ = new Table *[capaciteTables_];
    lireTable(fichier);
    nom_ = &nom;
    momentJournee_ = moment;
    chiffreAffaire_ = 0;
    menuMatin_ = new Menu(fichier, Matin);
    menuMidi_ = new Menu(fichier, Midi);
    menuSoir_ = new Menu(fichier, Soir);
}

Restaurant::~Restaurant() {
    for (int i = 0; i < nbTables_; i++) {
        delete tables_[i];
        tables_[i] = nullptr;
    }
    delete tables_;
    delete menuMatin_;
    delete menuMidi_;
    delete menuSoir_;
}

void Restaurant::setMoment(TypeMenu moment) {
    momentJournee_ = moment;
}

string Restaurant::getNom() const {
    return *nom_;
}

TypeMenu Restaurant::getMoment() const {
    return momentJournee_;
}

void Restaurant::lireTable(string &fichier) {
    ifstream lecture(fichier);
    if (lecture.fail())
        cout << "Erreur : la lecture du fichier a echoue." << endl;
    else {
        string ligne;
        bool litUneTable = false;
        while (!lecture.eof()) {
            if (litUneTable) {
                int idTable, nbPlaces;
                lecture >> idTable >> nbPlaces;
                ajouterTable(idTable, nbPlaces);
            } else {
                getline(lecture, ligne);
                if (ligne == "-TABLES") {
                    litUneTable = true;
                }
            }
        }
    }
}

void Restaurant::ajouterTable(int id, int nbPlaces) {
    if (nbTables_ < capaciteTables_) {
        tables_[nbTables_] = new Table(id, nbPlaces);
        nbTables_++;
    } else
        cout << "Erreur : le nombre de tables maximal a ete atteint." << endl;
}

void Restaurant::libererTable(int id) {
    for (int i = 0; i < nbTables_; i++) {
        if (tables_[i]->getId() == id) {
            chiffreAffaire_ += tables_[i]->getChiffreAffaire();
            tables_[i]->libererTable();
        }
    }
}

void Restaurant::commanderPlat(string &nom, int idTable) {
    Plat *plat = nullptr;
    switch (momentJournee_) {
        case Matin:
            plat = menuMatin_->trouverPlat(nom);
            break;
        case Midi:
            plat = menuMidi_->trouverPlat(nom);
            break;
        case Soir:
            plat = menuSoir_->trouverPlat(nom);
            break;
    }
    if (plat == nullptr)
        cout << "Erreur : plat introuvable." << endl;
    else {
        for (int i = 0; i < nbTables_; i++) {
            if (tables_[i]->getId() == idTable) {
                tables_[i]->commander(plat);
            }
        }
    }
}

void Restaurant::placerClients(int nbClients) {
    int indexPlusPetiteTable = -1, capacitePlusPetiteTable = 100;
    for (int i = 0; i < nbTables_; i++) {
        if (!tables_[i]->estOccupee() && tables_[i]->getNbPlaces() >= nbClients)
            if (tables_[i]->getNbPlaces() < capacitePlusPetiteTable) {
                capacitePlusPetiteTable = tables_[i]->getNbPlaces();
                indexPlusPetiteTable = i;
            }
    }
    if (indexPlusPetiteTable > -1)
        tables_[indexPlusPetiteTable]->placerClient();
    else
        cout << "Erreur : il n'y a pas/plus de table disponible pour le client." << endl;
}

void Restaurant::afficher() const {
    if (chiffreAffaire_ > 0)
        cout << "Le restaurant " << *nom_ << " a fait un chiffre d'affaire de : " << chiffreAffaire_ << "$" << endl;
    else
        cout << "Le restaurant " << *nom_ << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule."
             << endl;

    cout << "-Voici les tables : " << endl;
    for (int i = 0; i < nbTables_; i++) {
        tables_[i]->afficher();
        cout << endl;
    }

    cout << "Voici son menu : " << endl;
    cout << "Matin : " << endl;
    menuMatin_->afficher();
    cout << "Midi : " << endl;
    menuMidi_->afficher();
    cout << "Soir : " << endl;
    menuSoir_->afficher();
}

