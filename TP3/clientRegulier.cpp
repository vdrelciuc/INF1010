/*
* Titre : ClientRegulier.cpp - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "ClientRegulier.h"

ClientRegulier::ClientRegulier() {
    nbPoints_ = 0;
}

ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints) : Client(nom, prenom,
                                                                                                   tailleGroupe) {
    nbPoints_ = nbPoints;
    statut_ = Fidele;
}

int ClientRegulier::getNbPoints() const {
    return nbPoints_;
}

void ClientRegulier::setNbPoints(int nbPoints) {
    nbPoints_ = nbPoints;
}

void ClientRegulier::augmenterNbPoints(int bonus) {
    nbPoints_ += bonus;
}

ostream &operator<<(ostream &os, const ClientRegulier &client) {
    os << static_cast<Client>(client) << "; Possede " << client.nbPoints_ << " points.";

    return os;
}
