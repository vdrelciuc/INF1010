/*
* Titre : Commande.cpp - Travail pratique #6
* Date : 16 avril 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Commande.h"

Commande::Commande() {

}
QStringList Commande::getCommande() {
	return commande_;
}
void Commande::ajouterPlat(QString nomPlat) {
    commande_.push_back(nomPlat);
    emit commandeModifie();
}

void Commande::retirerPlat(QString nomPlat) {
    if(commande_.removeOne(nomPlat)){
        emit commandeModifie();
    }
   else{
        throw ErreurPlatIntrouvable(LABEL_MEAL_NOT_FOUND);
    }

}

void Commande::viderCommande(){
    if(commande_.size() == 0){
        throw ErreurCommandeVide(LABEL_NO_MEAL);
    }
    commande_.clear();
    emit commandeModifie();
}
