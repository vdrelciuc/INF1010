/*
* Titre : ClientPrestige.cpp - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "ClientPrestige.h"


ClientPrestige::ClientPrestige() {
    addresse_ = Zone3;
}

ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AddressCode addresse)
        : ClientRegulier(nom, prenom, tailleGroupe, nbPoints) {
    addresse_ = addresse;
    statut_ = Prestige;
}

void ClientPrestige::setAddressCode(AddressCode addressCode) {
    addresse_ = addressCode;
}

AddressCode ClientPrestige::getAddresseCode() const {
    return addresse_;
}

string ClientPrestige::getAddressCodeString() const {
    string affichage;
    switch (addresse_) {
        case Zone1:
            affichage = "Zone 1";
            break;
        case Zone2:
            affichage = "Zone 2";
            break;
        case Zone3:
            affichage = "Zone 3";
            break;
    }
    return affichage;
}

ostream &operator<<(ostream &os, ClientPrestige client) {
    os << static_cast<Client>(client) << "Habite dans la " << client.getAddressCodeString() << endl ;

    return os;
}
