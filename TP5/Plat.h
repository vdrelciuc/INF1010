/*
* Titre : Plat.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef PLAT_H
#define PLAT_H

#include "LectureFichierEnSections.h"
#include <string>
#include <string_view>
#include <iostream>
#include "def.h"

using namespace std;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepte en INF1010.

class Plat {
public:
    /**
     * Constructeur par paramètres
     * @param nom le nom du plat
     * @param prix le prix
     * @param cout le cout
     */
    Plat(string_view nom = "inconnu", double prix = 0, double cout = 0);

    /**
     * Destructeur
     */
    virtual ~Plat();

    /**
     * Getter pour le nom
     * @return le nom
     */
    string getNom() const;

    /**
     * Getter pour le prix
     * @return le prix
     */
    double getPrix() const;

    /**
     * Getter pour le cout
     * @return le cout
     */
    double getCout() const;

    /**
     * Setter pour le nom
     * @param nom le nouveau nom
     */
    void setNom(string nom);

    /**
     * Setter pour le prix
     * @param prix le nouveau prix
     */
    void setPrix(double prix);

    /**
     * Calcule le profit sur le plat
     * @return le profit du plat
     */
    virtual double getPrixRevient();

    /**
     * Clone le plat
     * @return un clone du plat
     */
    virtual Plat *clone() const;

    /**
     * Surcharge d'opérateur pour comparer le prix des plats
     * @param plat le plat à comparer
     * @return true si le plat appelant est moins cher
     */
    bool operator<(const Plat &plat) const;

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient ce qu'il faut afficher
     */
    virtual void afficherPlat(ostream &os) const;


protected:
    string nom_;
    double prix_;
    double cout_;
};

#endif // !PLAT_H
