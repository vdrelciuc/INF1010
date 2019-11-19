/*
* Titre : PlatBio.cpp - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe) : Plat(nom, prix, cout), ecoTaxe_(ecotaxe) {
}


PlatBio::~ PlatBio() {}

double PlatBio::getEcoTaxe() const {
    return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe) {
    ecoTaxe_ = ecoTaxe;
}

Plat *PlatBio::clone() const {
    return new PlatBio(nom_, prix_, cout_, ecoTaxe_);
}

double PlatBio::getPrixDeRevient() {
    return prix_ - cout_ + ecoTaxe_;
}

void PlatBio::afficherPlat(ostream &os) const {
    Plat::afficherPlat(os);
    os << "PLAT BIO  \t comprend une taxe ecologique de : " << ecoTaxe_ << "$" << endl;
}
