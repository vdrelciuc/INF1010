/*
* Titre : PlatVege.cpp - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "PlatVege.h"

PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux) :
        Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux) {
    setTaxe();
}

PlatVege::~ PlatVege() {}

Plat *PlatVege::clone() const {
    return new PlatVege(Plat::nom_, prix_, cout_, vitamines_, proteines_, mineraux_);
}


void PlatVege::afficherPlat(ostream &os) const {
    Plat::afficherPlat(os);
    Vege::afficherVege(os);
    os << "(Apport nutritif " << calculerApportNutritif() << "mg)" << endl;
}

double PlatVege::calculerApportNutritif() const {
    return (vitamines_ * proteines_ / mineraux_) * RAPPORT_NUTRITIF;
}

void PlatVege::setTaxe() {
    taxe_ = 0.07;
}

double PlatVege::getTaxe() const {
    return taxe_;
}