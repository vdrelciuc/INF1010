/*
* Titre : Boisson.cpp - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Boisson.h"

Boisson::Boisson(string_view nom, double prix) : nom_(nom), prix_(prix) {
    setTaxe();
}

Boisson::~Boisson() {}

string_view Boisson::getNom() const {
    return nom_;
}

double Boisson::getPrix() const {
    return prix_;
}

void Boisson::setTaxe() {
    taxe_ = 0.12;
}

double Boisson::getTaxe() const {
    return taxe_;
}