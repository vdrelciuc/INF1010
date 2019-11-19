/*
* Titre : Plat.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef PLAT_H
#define PLAT_H

#include "LectureFichierEnSections.h"
#include <string>
#include <string_view>
#include <iostream>
#include "def.h"

using std::string, std::string_view, std::ostream;

class Plat {
public:
    /**
     * Constructeur par paramètres
     * @param nom le nom à donner au plat
     * @param prix le prix du plat
     * @param cout le cout du plat
     */
    Plat(string_view nom = "inconnu", double prix = 0, double cout = 0);

    /**
     * Destructeur
     */
    virtual ~Plat();

    /**
     * Getter pour le nom
     * @return le nom du plat
     */
    string getNom() const;

    /**
     * Getter pour le prix
     * @return le prix du plat
     */
    double getPrix() const;

    /**
     * Getter pour le cout
     * @return le cout du plat
     */
    double getCout() const;

    /**
     * Setter pour le nom
     * @param nom le nom du plat
     */
    void setNom(string nom);

    /**
     * Setter pour le prix
     * @param prix le prix du plat
     */
    void setPrix(double prix);

    /**
     * Getter pour le revenu sur le plat
     * @return le revenu du plat
     */
    double getPrixRevient();

    /**
     * Fonction de copie du plat
     * @return Un plat identique à l'appelant
     */
    virtual Plat *clone() const;

    /**
     * Surcharge d'opérateur pour l'opérateur "plus petit que"
     * @param plat le plat à comparer
     * @return true si plus petit, false si plus grand ou égal
     */
    bool operator<(const Plat &plat) const;

    /**
     * Fonction d'affichage du plat
     * @param os ostream contenant l'affichage
     */
    virtual void afficherPlat(ostream &os) const;

protected:
    string nom_;
    double prix_;
    double cout_;
};

#endif // !PLAT_H
