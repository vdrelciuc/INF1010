/*
* Titre : Menu.h - Travail Pratique #1
* Date : 01 février 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include <fstream>

enum TypeMenu {
    Matin, Midi, Soir
};
const int MAXPLAT = 5;

class Menu {
public:
    /**
     * Constructeur par défaut
     * */
    Menu();

    /**
     * Constructeur avec paramètres
     * @param fichier fichier d'où l'on doit charger le menu
     * @param type le type de menu (Matin,Midi,Soir)
     * */
    Menu(string fichier, TypeMenu type);

    /**
     * Détruit tous les pointeurs de plats contenus dans le menu (listePlats_)
     * */
    ~Menu();

    /**
     * getNbPlats
     * Permet de récupérer le nombre de plats dans le menu
     * @return le nombre de plat dans le menu
     * */
    int getNbPlats() const;

    /**
     * afficer
     * Affiche chacun des plats du menu
     * */
    void afficher() const;

    /**
     * trouverPlat
     * Cherche un plat dans la liste de plats
     * @param nom le nom du plat que l'on cherche
     * @return le plat qui a été trouvé, ou, si on a pas trouvé, un pointeur nul
     * */
    Plat *trouverPlat(string &nom) const;

    /**
     * ajouterPlat
     * Ajoute un plat à la liste de plats du menu
     * @param plat Le plat à ajouter
     */
    void ajouterPlat(Plat &plat);

    /**
     * ajouterPlat
     * Ajoute un plat selon ses paramètres à la liste des plats du menu
     * @param nom Le nom du plat
     * @param montant Le prix de vente du plat
     * @param cout Le coût d'achet du plat
     */
    void ajouterPlat(string &nom, double montant, double cout);

    /**
     * Lit le contenu d'un fichier texte et l'enregistre dans la liste de plats du menu
     * @param fichier Le fichier texte à lire
     * @return Si la lecture du fichier s'est bien effectué ou non
     */
    bool lireMenu(string &fichier);

private :
    unsigned int capacite_;
    Plat **listePlats_;
    unsigned int nbPlats_;
    TypeMenu type_;

};

#endif // !MENU_H
