/*
* Titre : Menu.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include "PlatBio.h"
#include "PlatBioVege.h"
#include "PlatVege.h"
#include "pointers.h"
#include "def.h"
#include <fstream>
#include <vector>

using std::vector;

class Menu {
public:
    /**
     * Constructeur par defaut
     */
    Menu();

    /**
     * Constructeur par parametres
     * @param fichier Fichier a lire
     * @param type Type de menu
     */
    Menu(string fichier, TypeMenu type);

    /**
     * Constructeur par copie
     * @param menu Menu a copier
     */
    Menu(const Menu &menu);

    /**
     * Destructeur
     */
    ~Menu();

    /**
     * getListePlats
     * Retourne la liste des plats du menu
     * @return La liste des plats du menu
     */
    vector<Plat *> getListePlats() const;

    /**
     * trouverPlat
     * Trouve un plat dans le menu
     * @param nom Le nom du plat recherche
     * @return Le pointeur du plat trouve
     */
    Plat *trouverPlat(string_view nom) const;

    /**
     * allouerPlat
     * Retourne une copie d'un plat passe en parametres
     * @param plat Plat a copier
     * @return Copie du plat
     */
    Plat *allouerPlat(Plat *plat);

    /**
     * operator+=
     * Ajoute un plat dans les deux menus
     * @param plat Plat a ajouter
     * @return Le menu modifie
     */
    Menu &operator+=(owner<Plat *> plat);

    /**
     * operator=
     * Operateur de copie
     * @param menu Menu a copier
     * @return Le menu modifie
     */
    Menu &operator=(const Menu &menu);

    /**
     * lireMenu
     * Lit le menu a partir du fichier passe en parametre
     * @param fichier Le fichier a lire
     */
    void lireMenu(const string &fichier);

    /**
     * trouverPlatMoinsCher
     * Retourne le plat le moins cher du menu
     * @return Le plat le moins cher du menu
     */
    Plat *trouverPlatMoinsCher() const;

    /**
     * lirePlatDe
     * Lit un plat du fichier passe en parametre
     * @param fichier Le fichier a lire
     * @return Le plat lu
     */
    Plat *lirePlatDe(LectureFichierEnSections &fichier);

    /**
     * operator<<
     * Operateur d'affichage du menu
     * @param os Stream a modifier
     * @param menu Menu a afficher
     * @return Stream modifie
     */
    friend ostream &operator<<(ostream &os, const Menu &menu);

private :
    vector<owner<Plat *>> listePlats_;
    vector<owner<Vege *>> listePlatsVege_;

    TypeMenu type_;
};

#endif // !MENU_H
