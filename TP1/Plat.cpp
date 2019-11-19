/*
* Titre : Plat.cpp - Travail Pratique #1
* Date : 01 février 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Plat.h"

using namespace std;

Plat::Plat() {
    nom_ = "inconnu";
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

void Plat::afficher() const {
    cout << nom_ << " - " << prix_ << " $ (" << cout_ << "$ pour le restaurant)" << endl;
}