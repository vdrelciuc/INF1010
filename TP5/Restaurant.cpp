/*
* Titre : Restaurant.cpp - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Restaurant.h"
#include "LectureFichierEnSections.h"
#include "debogageMemoire.hpp"
#include <cassert>

using namespace std;

//constructeurs 
Restaurant::Restaurant() :
        Restaurant{"menu.txt", "Inconnu", TypeMenu::Matin} {
}

Restaurant::Restaurant(const string &nomFichier, string_view nom, TypeMenu moment) :
        nom_{nom},
        momentJournee_{moment},
        chiffreAffaire_{0},
        tables_(new GestionnaireTables()),
        menuMatin_{new GestionnairePlats{nomFichier, TypeMenu::Matin}},
        menuMidi_{new GestionnairePlats{nomFichier, TypeMenu::Midi}},
        menuSoir_{new GestionnairePlats{nomFichier, TypeMenu::Soir}},
        fraisLivraison_{} {
    tables_->lireTables(nomFichier);
    lireAdresses(nomFichier);
}

// Destructeur.
Restaurant::~Restaurant() {
    delete menuMatin_;
    delete menuMidi_;
    delete menuSoir_;
    delete tables_;
}


// Setters.

void Restaurant::setMoment(TypeMenu moment) {
    momentJournee_ = moment;
}

void Restaurant::setNom(string_view nom) {
    nom_ = nom;
}

void Restaurant::setChiffreAffaire(double chiffre) {
    chiffreAffaire_ = chiffre;
}
// Getters.

string Restaurant::getNom() const {
    return nom_;
}

TypeMenu Restaurant::getMoment() const {
    return momentJournee_;
}
// Autres methodes.

void Restaurant::libererTable(int id) {
    if (Table *table = tables_->getTable(id)) {
        chiffreAffaire_ += table->getChiffreAffaire();
        chiffreAffaire_ += calculerReduction(table->getClientPrincipal(), table->getChiffreAffaire(),
                                             table->getId() == INDEX_TABLE_LIVRAISON);
        table->libererTable();
    }
}

ostream &operator<<(ostream &os, const Restaurant &restaurent) {
    os << "Le restaurant " << restaurent.getNom();
    if (restaurent.chiffreAffaire_ != 0)
        os << " a fait un chiffre d'affaire de : " << restaurent.chiffreAffaire_ << "$" << endl;
    else
        os << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;

    os << "-Voici les tables : " << endl;

    restaurent.tables_->afficherTables(os);

    os << "-Voici son menu : " << endl;
    for (TypeMenu typeMenu : {TypeMenu::Matin, TypeMenu::Midi, TypeMenu::Soir}) {
        GestionnairePlats *menu = restaurent.getMenu(typeMenu);
        os << restaurent.getNomTypeMenu(typeMenu) << " : " << endl;
        menu->afficherPlats(os);
        os << "Le plat le moins cher est : ";
        menu->trouverPlatMoinsCher()->afficherPlat(os);
        os << endl;
    }
    return os;
}

string Restaurant::getNomTypeMenu(TypeMenu typeMenu) const {
    switch (typeMenu) {
        case TypeMenu::Matin:
            return "Matin";
        case TypeMenu::Midi:
            return "Midi";
        case TypeMenu::Soir:
            return "Soir";
    }
    return "";
}

void Restaurant::commanderPlat(string nom, int idTable) {
    if (Table *table = getTable(idTable); table && table->estOccupee())
        if (Plat *plat = menuActuel()->trouverPlat(nom)) {
            table->commander(plat);
            return;
        }
    cout << "Erreur : table vide ou plat introuvable." << endl << endl;
}

bool Restaurant::operator<(const Restaurant &autre) const {
    return chiffreAffaire_ < autre.chiffreAffaire_;
}

bool Restaurant::placerClients(Client *client) {
    const int tailleGroupe = client->getTailleGroupe();
    Table *meilleureTable = nullptr;
    meilleureTable = tables_->getMeilleureTable(tailleGroupe);

    if (meilleureTable) {
        client->setTable(meilleureTable);
        meilleureTable->placerClients(tailleGroupe);
        meilleureTable->setClientPrincipal(client);
        return true;
    } else
        return false;
}

bool Restaurant::livrerClient(Client *client, const vector<string> &commande) {
    if (dynamic_cast<ClientPrestige *>(client)) {
        (tables_->getTable(INDEX_TABLE_LIVRAISON))->setClientPrincipal(client);
        tables_->getTable(INDEX_TABLE_LIVRAISON)->placerClients(1);
        for (unsigned int i = 0; i < commande.size(); i++)
            commanderPlat(commande[i], INDEX_TABLE_LIVRAISON);
        libererTable(INDEX_TABLE_LIVRAISON);
        return true;
    } else {
        return false;
    }
}

double Restaurant::calculerReduction(Client *client, double montant, bool estLivraison) {
    return client->getReduction(*this, montant, estLivraison);
}

double Restaurant::getFraisLivraison(ZoneHabitation zone) const {
    return fraisLivraison_[static_cast<int>(zone)];
}

GestionnairePlats *Restaurant::getMenu(TypeMenu typeMenu) const {
    switch (typeMenu) {
        case TypeMenu::Matin :
            return menuMatin_;
        case TypeMenu::Midi  :
            return menuMidi_;
        case TypeMenu::Soir  :
            return menuSoir_;
    }
    assert(false && "Le type du menu est invalide");
    return nullptr;  // On ne devrait jamais se rendre � cette ligne.
}

GestionnairePlats *Restaurant::menuActuel() const {
    return getMenu(momentJournee_);
}

Table *Restaurant::getTable(int id) const {
    return tables_->getTable(id);
}

void Restaurant::lireAdresses(const string &nomFichier) {
    LectureFichierEnSections fichier{nomFichier};
    fichier.allerASection("-ADDRESSES");
    while (!fichier.estFinSection()) {
        int zone;
        double frais;
        fichier >> zone >> frais;
        fraisLivraison_[zone] = frais;
    }
}

double Restaurant::getChiffreAffaire() {
    return chiffreAffaire_;
}

string getNomTypeMenu(TypeMenu typeMenu) {
    return string{nomsDesTypesDeMenu[static_cast<int>(typeMenu)]};
}

GestionnaireTables *Restaurant::getTables() const {
    return tables_;
}