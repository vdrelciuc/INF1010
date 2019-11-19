/*
* Titre : ClientRegulier.cpp - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "ClientRegulier.h"

ClientRegulier::ClientRegulier() {
    nbPoints_ = 0;
}

ClientRegulier::ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int npoints) :
        Client(nom, prenom, tailleGroupe), nbPoints_(npoints) {
}

ClientRegulier::~ClientRegulier() {}

int ClientRegulier::getNbPoints() const {
    return nbPoints_;
}


void ClientRegulier::augmenterNbPoints(int bonus) {
    nbPoints_ += bonus;
}


void ClientRegulier::afficherClient(ostream &os) const {
    Client::afficherClient(os);
    os << "Le client a " << nbPoints_ << " points." << endl;
}

double ClientRegulier::getReduction(const Restaurant &res, double montant, bool estLivraison) {
    if (nbPoints_ > SEUIL_DEBUT_REDUCTION)
        return -montant * TAUX_REDUC_REGULIER;
    return 0;
}
