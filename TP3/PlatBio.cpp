/*
* Titre : PlatBio.cpp - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe) : Plat(nom, prix, cout) {
    ecoTaxe_ = ecotaxe;
    type_ = Bio;
}

double PlatBio::getEcoTaxe() const {
    return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe) {
    ecoTaxe_ = ecoTaxe;
}

ostream &operator<<(ostream &os, const PlatBio &plat) {
    Plat platNormal = static_cast<Plat>(plat);
    os << platNormal << "\t\tcomprend une taxe ecologique de : " << plat.ecoTaxe_ << "$" << endl;

    return os;
}
