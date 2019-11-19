/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 6 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Table.h"

//constructeurs
Table::Table() {
    id_ = -1;
    nbPlaces_ = 1;
    nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces) {
    id_ = id;
    nbPlaces_ = nbPlaces;
    nbClientsATable_ = 0;
}

Table::Table(const Table &table) : id_(table.id_), nbPlaces_(table.nbPlaces_), nbClientsATable_(table.nbClientsATable_){
    for(int i = 0; i < table.commande_.size(); i++){
        commande_.push_back(table.commande_[i]);
    }
}

//destructeur
Table::~Table() {
    for (int i=0; i<commande_.size(); i++){
        commande_[i] = nullptr;
    }
    commande_.clear();
}

//getters
int Table::getId() const {
    return id_;
}

int Table::getNbPlaces() const {
    return nbPlaces_;
}

int Table::getnbClientATable() const {
    return nbClientsATable_;
}

bool Table::estPleine() const {
    return nbPlaces_ == 0;
}

bool Table::estOccupee() const {
    return nbClientsATable_ != 0;
}

vector<Plat *> Table::getCommande() const {
    return commande_;
}

//setters
void Table::setId(int id) {
    id_ = id;
}

void Table::libererTable() {
    nbPlaces_ += nbClientsATable_;
    nbClientsATable_ = 0;
    for (int i = 0; i < commande_.size(); i++) {
        commande_[i] = nullptr;
    }
    commande_.clear();
}

void Table::placerClient(int nbClients) {
    nbClientsATable_ = nbClients;
    nbPlaces_ -= nbClients;
}

//autres methodes
void Table::commander(Plat *plat) {
    commande_.push_back(plat);
}

double Table::getChiffreAffaire() const {
    double chiffre = 0;
    for (int i = 0; i < commande_.size(); i++) {
        chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
    }
    return chiffre;
}

//affichage
ostream &operator<<(ostream &os, const Table &table) {
    os << "La table numero " << table.getId();
    if (table.estOccupee()) {
        os << " est occupee. ";
        if (table.getCommande().size() != 0) {
            os << "Voici la commande passee par les clients : " << endl;
            for (int i = 0; i < table.getCommande().size(); i++) {
                os << "\t";
                os << *table.getCommande()[i];
            }
        } else
            os << "Mais ils n'ont rien conmmande pour l'instant. " << endl;
    } else {
        os << " est libre. " << endl;
    }
    return os;
}

