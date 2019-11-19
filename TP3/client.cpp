/*
* Titre : Client.cpp - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Client.h"

Client::Client() {
    nom_ = "inconnu";
    prenom_ = "inconnu";
    statut_ = Occasionnel;
}

Client::Client(string nom, string prenom, int tailleGroupe) {
    nom_ = nom;
    prenom_ = prenom;
    tailleGroupe_ = tailleGroupe;
    statut_ = Occasionnel;
}

Client::~Client() {
}

StatutClient Client::getStatut() const {
    return statut_;
}

int Client::getTailleGroupe() const {
    return tailleGroupe_;
}

string Client::getNom() const {
    return nom_;
}

string Client::getPrenom() const {
    return prenom_;
}

string Client::convertirStatutString() const {
    string affichage;
    switch (statut_) {
        case Occasionnel:
            affichage = "Occasionnel";
            break;
        case Fidele:
            affichage = "Fidele";
            break;
        case Prestige:
            affichage = "Prestige";
            break;
    }

    return affichage;
}

void Client::setNom(string nom) {
    nom_ = nom;
}

void Client::setPrenom(string prenom) {
    prenom_ = prenom;
}

void Client::setStatut(StatutClient statutClient) {
    statut_ = statutClient;
}

void Client::setTailleGroupe(int tailleGroupe) {
    tailleGroupe_ = tailleGroupe;
}

ostream &operator<<(ostream &os, const Client &client) {
    os << "- " << client.prenom_ << " " << client.nom_ << " ; Statut : " << client.convertirStatutString();

    return os;
}
