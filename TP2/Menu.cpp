/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 6 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "Menu.h"

using namespace std;

//constructeurs

Menu::Menu() {
    type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type) {
    type_ = type;

    //lecture du fichier -- creation du menu
    lireMenu(fichier);
}

Menu::Menu(const Menu &menu) : type_(menu.type_), listePlats_(menu.listePlats_) {}

//destructeur
Menu::~Menu() {
    for (int i = 0; i < listePlats_.size(); i++) {
        listePlats_[i] = nullptr;
    }
    listePlats_.clear();
}

//getters

int Menu::getNbPlats() const {
    return listePlats_.size();
}

vector<Plat *> Menu::getListePlats() const {
    return listePlats_;
}

//autres methodes

ostream &operator<<(ostream &os, const Menu &menu) {
    for (int i = 0; i < menu.getListePlats().size(); i++) {
        os << "\t";
        os << *menu.getListePlats()[i];
    }
    return os;
}

Menu &Menu::operator+=(Plat *plat) {
    listePlats_.push_back(plat);
    return *this;
}

Menu &Menu::operator=(const Menu &menu) {
    if (this != &menu) {
        type_ = menu.type_;
        for (int i = 0; i < listePlats_.size(); i++) {
            delete listePlats_[i];
        }
        listePlats_.clear();
        for (int i = 0; i < menu.listePlats_.size(); i++) {
            listePlats_.push_back(new Plat(menu.getListePlats()[i]->getNom(), menu.getListePlats()[i]->getPrix(),
                                           menu.getListePlats()[i]->getCout()));
        }
    }
    return *this;
}

bool Menu::lireMenu(const string &fichier) {
    ifstream file(fichier, ios::in);

    if (!file) {
        cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl;
        return false;
    } else {
        string type;
        switch (type_) {
            case Matin :
                type = "-MATIN";
                break;
            case Midi :
                type = "-MIDI";
                break;
            case Soir :
                type = "-SOIR";
                break;
        }
        string ligne;

        string nom;

        string prixString;
        double prix;

        string coutString;
        int cout;


        // lecture
        while (!file.eof()) {
            getline(file, ligne);
            //trouver le bon type de menu (section)
            if (ligne == type) {
                //commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu
                getline(file, ligne);
                int curseur;
                while (ligne[0] != '-' && !file.eof()) {
                    //trouver le nom
                    for (int i = 0; i < int(ligne.size()); i++) {
                        if (ligne[i] == ' ') {
                            curseur = i;
                            break;
                        }
                        nom += ligne[i];
                    }
                    //trouver le prix

                    for (int i = curseur + 1; i < int(ligne.size()); i++) {
                        if (ligne[i] == ' ') {
                            curseur = i;
                            break;
                        }
                        prixString += ligne[i];

                    }
                    //passer le prixString en double --- indice dans l'enonce
                    prix = stof(prixString.c_str());

                    for (int i = curseur + 1; i < int(ligne.size()); i++) {
                        if (ligne[i] == ' ')
                            break;
                        coutString += ligne[i];
                    }

                    cout = int(stof(coutString.c_str()));

                    *this += new Plat(nom, prix, cout);

                    nom = "";
                    prixString = "";
                    coutString = "";

                    getline(file, ligne);
                }
            }
        }

        file.close();
        return true;
    }
}

Plat *Menu::trouverPlatMoinsCher() const {
    Plat minimum(*listePlats_[0]);
    int found = -1;

    for (unsigned i = 0; i < listePlats_.size(); ++i) {
        if (*listePlats_[i] < minimum) {
            minimum = *listePlats_[i];
            found = i;
        }
    }

    return listePlats_[found];

}

Plat *Menu::trouverPlat(const string &nom) const {
    for (int i = 0; i < listePlats_.size(); i++) {
        if (listePlats_[i]->getNom() == nom)
            return listePlats_[i];
    }
    return nullptr;
}
