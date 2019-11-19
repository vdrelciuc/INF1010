/*
* Titre : Table.cpp - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Table.h"

//constructeurs
Table::Table() {
    id_ = -1;
    nbPlaces_ = 1;
    nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces) {
    id_ = id;
    nbPlaces_ = nbPlaces;
    nbClientsATable_ = 0;
}

//getters
int Table::getId() const {
    return id_;
}

int Table::getNbPlaces() const {
    return nbPlaces_;
}

bool Table::estOccupee() const {
    return nbClientsATable_ != 0;
}

bool Table::estPleine() const {
    return nbPlaces_ == 0;
}

int Table::getNbClientsATable() const {
    return nbClientsATable_;
}

vector<Plat *> Table::getCommande() const {
    return commande_;
}

Client *Table::getClientPrincipal() const {
    return clientPrincipal_;
}

double Table::getMontantAPayer() const {
    double montant = 0;
    for(int i=0; i<commande_.size(); i++){
        switch(commande_[i]->getType()){
            case Regulier:
                montant += commande_[i]->getPrix();
                break;
            case Bio:
                montant += commande_[i]->getPrix() + static_cast<PlatBio*>(commande_[i])->getEcoTaxe();
                break;
            case Custom:
                montant += commande_[i]->getPrix() + static_cast<PlatCustom*>(commande_[i])->getSupplement();
                break;
        }
    }
    return montant;
}

//setters
void Table::setId(int id) {
    id_ = id;
}


void Table::libererTable() {
    nbPlaces_ += nbClientsATable_;
    nbClientsATable_ = 0;
    commande_.clear();
}

void Table::placerClients(int nbClient) {
    nbPlaces_ -= nbClient;
    nbClientsATable_ = nbClient;
}

void Table::setClientPrincipal(Client *clientPrincipal) {
    clientPrincipal_ = clientPrincipal;
}

//autres methodes
void Table::commander(Plat *plat) {
    commande_.push_back(plat);
}

double Table::getChiffreAffaire() const {
    double chiffre = 0;
    for (unsigned i = 0; i < commande_.size(); ++i) {
        chiffre += commande_[i]->getPrix() - commande_[i]->getCout();
        switch (commande_[i]->getType()) {
            case Bio:
                chiffre += static_cast<PlatBio *>(commande_[i])->getEcoTaxe();
                break;
            case Custom:
                chiffre += static_cast<PlatCustom *>(commande_[i])->getSupplement();
                break;
        }
    }
    return chiffre;
}

//affichage
ostream &operator<<(ostream &os, const Table &table) {
    os << "La table numero " << table.id_;
    if (table.estOccupee()) {
        os << " est occupee. ";
        if (!table.commande_.empty()) {
            os << "Le client principal est:" << endl;
            switch(table.clientPrincipal_->getStatut()){
                case Occasionnel:
                    os << *table.getClientPrincipal() << endl;
                    break;
                case Fidele:
                    os << *static_cast<ClientRegulier*>(table.getClientPrincipal()) << endl;
                    break;
                case Prestige:
                    os << *static_cast<ClientPrestige*>(table.getClientPrincipal()) << endl;
                    break;
            }
            os << "Voici la commande passee par les clients : " << endl;
            for (unsigned i = 0; i < table.commande_.size(); ++i) {
                switch(table.commande_[i]->getType()){
                    case Regulier:
                        os << "\t" << *table.commande_[i];
                        break;
                    case Bio:
                        os << "\t" << *static_cast<PlatBio*>(table.commande_[i]);
                        break;
                    case Custom:
                        os << "\t" << *static_cast<PlatCustom*>(table.commande_[i]);
                        break;
                }
            }
        } else
            os << "Mais ils n'ont rien commande pour l'instant. " << endl;
    } else
        os << " est vide. " << endl;

    return os;
}
