/*
* Titre : ClientPrestige.cpp - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "ClientPrestige.h"
#include "Restaurant.h"

ClientPrestige::ClientPrestige() {
    adresse_ = ZoneHabitation::Zone3;
}

ClientPrestige::ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, int nbPoints,
                               ZoneHabitation adresse) :
        ClientRegulier(nom, prenom, tailleGroupe, nbPoints), adresse_(adresse) {
}

ZoneHabitation ClientPrestige::getAdresseCode() const {
    return adresse_;
}

void ClientPrestige::afficherClient(ostream &os) const {
    ClientRegulier::afficherClient(os);
    os << "Le client habite dans la zone " << getAdressCodeString() << endl;
}

string ClientPrestige::getAdressCodeString() const {
    string zone;
    switch (adresse_) {
        case ZoneHabitation::Zone1:
            zone = "Zone 1";
            break;
        case ZoneHabitation::Zone2:
            zone = " Zone 2";
            break;
        case ZoneHabitation::Zone3:
            zone = "Zone 3";
            break;

        default:
            zone = "erreur zone";
            break;
    }
    return zone;
}

double ClientPrestige::getReduction(const Restaurant &res, double montant, bool estLivraison) {
    double reduction = 0;
    reduction = -montant * TAUX_REDUC_PRESTIGE;
    if (nbPoints_ < SEUIL_LIVRAISON_GRATUITE && estLivraison)
        reduction += res.getFraisLivraison(adresse_);
    return reduction;
}
