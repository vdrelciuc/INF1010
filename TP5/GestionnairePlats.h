/*
* Titre : GestionnairePlats.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#pragma once

#include "Plat.h"
#include "Vege.h"
#include "GestionnaireGenerique.h"
#include "Foncteur.h"

#include <utility>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;


class GestionnairePlats : public GestionnaireGenerique<pair<string, Plat *>, map<string, Plat *>> {
public:
    /**
     * Constructeur par paramètres
     * @param nomFichier le nom du ficher contenant les plats
     * @param type le type de menu (Matin, Midi, Soir)
     */
    GestionnairePlats(const string &nomFichier, TypeMenu type);

    /**
     * Constructeur par copie
     * @param gestionnaire le gestionnaire à copier
     */
    GestionnairePlats(GestionnairePlats *gestionnaire);

    /**
     *
     * Destructeur
     */
    ~GestionnairePlats();

    /**
     * Getter pour le type de menu
     * @return le type de menu
     */
    TypeMenu getType() const;

    /**
     * Méthode qui crée un nouveau plat
     * @return le plat qui a été créé
     */
    Plat *allouerPlat(Plat *);

    /**
     * Méthode qui trouve le plat le moins cher
     * @return le plat le moins cher du menu
     * @return nullptr si aucun plat
     */
    Plat *trouverPlatMoinsCher() const;

    /**
     * Méthode qui trouve le plat le plus cher
     * @return le plat trouvé
     * @return nullptr si aucun plat
     */
    Plat *trouverPlatPlusCher() const;

    /**
     * Méthode qui trouve un plat selon son nom
     * @param nom le nom du plat à trouver
     * @return le plat trouvé
     * @return nullptr si aucun plat a ce nom
     */
    Plat *trouverPlat(const string &nom) const;

    /**
     * Méthode qui trouve les plats dand un intervalle de prix
     * @param borneInf la borne inférieur de prix
     * @param borneSup la borne supérieur de prix
     * @return un vector avec tous les plats qui ont été trouvés
     */
    vector<pair<string, Plat *>> getPlatsEntre(double borneInf, double borneSup);

    /**
     * Méthode qui lit les plats du fichier
     * @param nomFichier le fichier où lire les plats
     * @param type le type de menu que l'on veut remplir
     */
    void lirePlats(const string &nomFichier, TypeMenu type);

    /**
     * Méthode qui lit une section du fichier
     * @param fichier la section à lire
     * @return une pair liant un nom à un plat
     */
    pair<string, Plat *> lirePlatDe(LectureFichierEnSections &fichier);

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient l'affichage
     */
    void afficherPlats(ostream &os);

private:
    TypeMenu type_;
};