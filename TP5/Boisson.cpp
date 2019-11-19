/*
* Titre : Boisson.cpp - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Boisson.h"

Boisson::Boisson(string_view nom, double prix) : nom_(nom), prix_(prix) {
    setTaxe();
}

void Boisson::setTaxe() {
    taxe_ = .12;
}

double Boisson::getTaxe() const {
    return taxe_;
}

string_view Boisson::getNom() const {
    return nom_;
}

double Boisson::getPrix() const {
    return prix_;
}
