/*
* Titre : Menu.cpp - Travail Pratique #1
* Date : 01 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Menu.h"

using namespace std;

Menu::Menu() {
    capacite_ = MAXPLAT;
    nbPlats_ = 0;
}

Menu::Menu(string fichier, TypeMenu type) {
    capacite_ = MAXPLAT;
    type_ = type;
    listePlats_ = new Plat *[capacite_];
    nbPlats_ = 0;
    lireMenu(fichier);
}

Menu::~Menu() {
    for (int i = 0; i < nbPlats_; i++) {
        delete listePlats_[i];
        listePlats_[i] = nullptr;
    }
    delete listePlats_;
}

int Menu::getNbPlats() const {
    return nbPlats_;
}

void Menu::afficher() const {
    for (int i = 0; i < nbPlats_; i++) {
        cout << "\t" << listePlats_[i]->getNom() << " - " << listePlats_[i]->getPrix() << " $ ("
             << listePlats_[i]->getCout()
             << "$ pour le restaurant)" << endl;
    }
}

Plat *Menu::trouverPlat(string &nom) const {
    for (int i = 0; i < nbPlats_; i++) {
        if (listePlats_[i]->getNom() == nom)
            return listePlats_[i];
    }
    return nullptr;
}

void Menu::ajouterPlat(Plat &plat) {
    if (nbPlats_ < capacite_) {
        listePlats_[nbPlats_] = &plat;
        nbPlats_++;
    } else
        cout << "Nous avons atteint la capacite maximale, nous ne pouvons creer de nouveaux plats." << endl;
}

void Menu::ajouterPlat(string &nom, double montant, double cout) {
    if (nbPlats_ < capacite_) {
        listePlats_[nbPlats_] = new Plat(nom, montant, cout);
        nbPlats_++;

    } else
        std::cout << "Nous avons atteint la capacite maximale, nous ne pouvons creer de nouveaux plats." << endl;
}

bool Menu::lireMenu(string &fichier) {
    string typeMenu;
    switch (type_) {
        case Matin:
            typeMenu = "MATIN";
            break;
        case Midi:
            typeMenu = "MIDI";
            break;
        case Soir:
            typeMenu = "SOIR";
            break;
    }
    ifstream lecture(fichier);
    if (lecture.fail()) {
        cout << "Erreur : la lecture du fichier a echoue." << endl;
        return false;
    } else {
        string ligne;
        bool litBonMenu = false;
        while (!lecture.eof()) {
            if (litBonMenu) {   // Lorsqu'on a trouvé le bon menu dans le fichier, enregistrer le contenu
                string nomPlat;
                double prixPlat, coutPlat;
                lecture >> nomPlat;
                if (nomPlat[0] != '-') {
                    lecture >> prixPlat >> coutPlat;
                    ajouterPlat(nomPlat, prixPlat, coutPlat);
                } else
                    litBonMenu = false;
            } else { // Tant qu'on a pas trouvé le bon menu dans le fichier, continuer la lecture
                getline(lecture, ligne);
                if (ligne == "-" + typeMenu) {
                    litBonMenu = true;
                }
            }
        }
    }
    return true;
}