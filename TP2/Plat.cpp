/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 6 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Plat.h"

//constructeurs
Plat::Plat() {
    nom_ = "Inconnu";
    prix_ = 0;
    cout_ = 0;
}

Plat::Plat(string nom, double prix, double cout) {
    nom_ = nom;
    prix_ = prix;
    cout_ = cout;
}

string Plat::getNom() const {
    return nom_;
}

double Plat::getPrix() const {
    return prix_;
}

double Plat::getCout() const {
    return cout_;
}

void Plat::setNom(string nom) {
    nom_ = nom;
}

void Plat::setPrix(double prix) {
    prix_ = prix;
}

bool Plat::operator<(const Plat &plat) const {
    if (prix_ < plat.getPrix())
        return true;
    return false;
}

ostream &operator<<(ostream &os, const Plat &plat) {
    os << plat.getNom() << " - " << plat.getPrix() << " $ (" << plat.getCout() << "$ pour le restaurant)" << endl;
    return os;
}