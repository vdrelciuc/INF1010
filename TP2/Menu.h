/*
* Titre : Menu.h - Travail Pratique #2
* Date : 6 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include <fstream>
#include <vector>

enum TypeMenu {
    Matin, Midi, Soir
};
const int MAXPLAT = 5;

class Menu {
public:
    /**
     * Constucteur par défaut
     * */
    Menu();

    /**
     * Constucteur par paramètres
     * @param fichier est le fichier à lire pour le menu
     * @param type est le moment de la journée associé au menu
     * */
    Menu(string fichier, TypeMenu type);

    /**
     * Constucteur par copie
     * @param &menu est le menu à copier
     * */
    Menu(const Menu &menu);

    /**
     * Destructeur de menu
     * */
    ~Menu();

    /**
     * Permet de recevoir le nombre de plats
     * @return le nombre de plats
     * */
    int getNbPlats() const;

    /**
     * Permet de recevoir la liste des plats
     * @return un vector avec la liste des plats dans le menu
     * */
    vector<Plat *> getListePlats() const;

    /**
     * Surcharge de l'opérateur << afin de pouvoir afficher les informations sur le menu
     * @param &os stocke ce qu'il y a à afficher
     * @param &menu est le menu qu'il faut afficher
     * @return os qui sera utilisé dans un cout
     * */
    friend ostream &operator<<(ostream &os, const Menu &menu);

    /**
     * Permet de trouver un plat par son nom
     * @param &nom est le nom du plat à chercher
     * @return nullptr si on ne trouve pas de plat
     * @return pointeur vers le plat qui a été trouvé
     * */
    Plat *trouverPlat(const string &nom) const;

    /**
     * Permet de trouver le plat qui coûte le moins cher
     * @return pointeur vers le plat le moins cher
     * */
    Plat *trouverPlatMoinsCher() const;

    /**
     * Surcharge de l'opérateur += afin d'ajouter un plat au menu
     * @param *plat est un pointeur vers le plat à ajouter
     * */
    Menu &operator+=(Plat *plat);

    /**
     * Surcharge de l'opérateur = afin de rendre ce menu pareil à un autre.
     * @param &menu est le menu à imiter
     * */
    Menu &operator=(const Menu &menu);

    /**
     * Permet de lire un fichier et de remplir le menu avec celui-ci
     * @param le fichier à lire
     * @return false si erreur à lire le fichier
     * @return true si bonne lecture
     * */
    bool lireMenu(const string &fichier);


private :
    vector<Plat *> listePlats_;
    TypeMenu type_;

};

#endif // !MENU_H
