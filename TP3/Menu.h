/*
* Titre : Menu.h - Travail Pratique #3
* Date : 21 f�vrier 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <vector>
#include"PlatBio.h"
#include"PlatCustom.h"


enum TypeMenu {
    Matin, Midi, Soir
};

class Menu {
public:
    /**
     * Constructeur par d�faut
     */
    Menu();

    /**
     * Contructeur par param�tres
     * @param fichier le fichier contenant le menu
     * @param type le moment de la journ�e qui correspond au menu
     */
    Menu(string fichier, TypeMenu type);

    /**
     * Constructeur par copie
     * @param menu Le menu que l'on veut copier
     */
    Menu(const Menu &menu);


    /**
     * Getter pour la liste de plat
     * @return la liste de plats
     */
    vector<Plat *> getListePlats() const;

    /**
     * Getter pour le type de menu
     * @return le type de menu
     */
    TypeMenu getTypeMenu() const;

    /**
     * M�thode qui permet de trouver un plat dans le menu
     * @param nom le nom du plat qu'on cherche
     * @return un pointeur vers le plat qu'on cherche
     */
    Plat *trouverPlat(const string &nom) const;

    /**
     * Surcharge d'operateur pour ajouter un plat
     * @param plat le plat qu'on veut ajouter
     * @return le nouveau menu
     */
    Menu &operator+=(const Plat &plat);

    /**
     * Surcharge d'op�rateur pour ajouter un Plat
     * @param plat le Plat � ajouter
     * @return le nouveau menu
     */
    Menu &operator+=(PlatBio *plat);

    /**
     * Surcharge d'op�rateur pour copier un menu
     * @param menu le menu � copier
     * @return le nouveau menu
     */
    Menu &operator=(const Menu &menu);

    /**
     * M�thode qui lit le fichier et cr�e le menu
     * @param fichier le fichier qui contient le menu
     */
    void lireMenu(const string &fichier);

    /**
     * M�thode qui trouve le plat le moins cher
     * @return le plat le moins cher
     */
    Plat *trouverPlatMoinsCher() const;

    /**
     * Surcharge d'op�rateur pour afficher le menu
     * @param os L'ostream qui va contenir ce qu'il faut afficher
     * @param menu le menu � afficher
     * @return l'ostream avec ce qu'il faut afficher
     */
    friend ostream &operator<<(ostream &os, const Menu &menu);

private :
    vector<Plat *> listePlats_;
    TypeMenu type_;

};

#endif // !MENU_H
