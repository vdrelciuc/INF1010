/*
* Titre : PlatCustom.cpp - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "PlatCustom.h"

PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients): Plat(nom,prix,cout) {
    nbIngredients_ = nbIngredients;
    supplement_ = calculerSupplement();
    type_ = Custom;
}

int PlatCustom::getNbIngredients() const {
    return nbIngredients_;
}

double PlatCustom::getSupplement() const {
    return supplement_;
}

void PlatCustom::setNbIngredients(int nbIngredients) {
    nbIngredients_ = nbIngredients;
}

ostream &operator<<(ostream &os, const PlatCustom &plat) {
    Plat platNormal = static_cast<Plat>(plat);
    os << platNormal << "\t\tcontients " << plat.nbIngredients_
       << " elements modifies pour un supplement total de : " << plat.supplement_ << "$" << endl;

    return os;
}

double PlatCustom::calculerSupplement() {
    supplement_ = nbIngredients_ * FRAIS_CUSTOMISATION;
    return supplement_;
}
