/*
* Titre : Menu.h - Travail Pratique #3
* Date : 21 février 2019
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
     * Constructeur par défaut
     */
    Menu();

    /**
     * Contructeur par paramètres
     * @param fichier le fichier contenant le menu
     * @param type le moment de la journée qui correspond au menu
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
     * Méthode qui permet de trouver un plat dans le menu
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
     * Surcharge d'opérateur pour ajouter un Plat
     * @param plat le Plat à ajouter
     * @return le nouveau menu
     */
    Menu &operator+=(PlatBio *plat);

    /**
     * Surcharge d'opérateur pour copier un menu
     * @param menu le menu à copier
     * @return le nouveau menu
     */
    Menu &operator=(const Menu &menu);

    /**
     * Méthode qui lit le fichier et crée le menu
     * @param fichier le fichier qui contient le menu
     */
    void lireMenu(const string &fichier);

    /**
     * Méthode qui trouve le plat le moins cher
     * @return le plat le moins cher
     */
    Plat *trouverPlatMoinsCher() const;

    /**
     * Surcharge d'opérateur pour afficher le menu
     * @param os L'ostream qui va contenir ce qu'il faut afficher
     * @param menu le menu à afficher
     * @return l'ostream avec ce qu'il faut afficher
     */
    friend ostream &operator<<(ostream &os, const Menu &menu);

private :
    vector<Plat *> listePlats_;
    TypeMenu type_;

};

#endif // !MENU_H
