/*
* Titre : Table.cpp - Travail Pratique #1
* Date : 01 février 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#include <iostream>
#include "Table.h"

Table::Table() {
    capacite_ = MAXCAP;
    id_ = -1;
    nbPlaces_ = 1;
    nbPlats_ = 0;
    occupee_ = false;
    commande_ = new Plat *[MAXCAP];
}

Table::Table(int id, int nbPlaces) {
    capacite_ = MAXCAP;
    id_ = id;
    nbPlaces_ = nbPlaces;
    nbPlats_ = 0;
    occupee_ = false;
    commande_ = new Plat *[MAXCAP];
}

Table::~Table() {
    for (int i = 0; i < nbPlats_; i++) {
        commande_[i] = nullptr;
    }
    delete commande_;
}

int Table::getId() const {
    return id_;
}

int Table::getNbPlaces() const {
    return nbPlaces_;
}

bool Table::estOccupee() const {
    return occupee_;
}

void Table::libererTable() {
    for (int i = 0; i < nbPlats_; i++) {
        commande_[i] = nullptr;
    }
    occupee_ = false;
    nbPlats_ = 0;
}

void Table::placerClient() {
    if (!occupee_)
        occupee_ = true;
    else
        cout << "Erreur : table deja occupee. Impossible de placer le client." << endl;
}

void Table::setId(int id) {
    id_ = id;
}

void Table::commander(Plat *plat) {
    if (nbPlats_ < capacite_) {
        commande_[nbPlats_] = plat;
        nbPlats_++;
    } else
        cout << "Erreur : trop grande commande." << endl;
}

double Table::getChiffreAffaire() {
    double chiffreAffaire = 0;
    for (int i = 0; i < nbPlats_; i++) {
        chiffreAffaire += commande_[i]->getPrix() - commande_[i]->getCout();
    }
    return chiffreAffaire;
}

void Table::afficher() const {

    if (occupee_) {
        if (nbPlats_ > 0) {
            cout << "\tLa table numero " << id_ << " est occupee. Voici la commande passee par les clients : " << endl;
            for (int i = 0; i < nbPlats_; i++) {
                cout << "\t";
                commande_[i]->afficher();
            }
        } else {
            cout << "\tLa table numero " << id_ << " est occupee, mais ils n'ont rien commande pour l'instant." << endl;
        }
    } else {
        cout << "\tLa table numero " << id_ << " est libre." << endl;
    }
}