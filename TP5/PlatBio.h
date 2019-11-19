/*
* Titre : PlatBio.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef PLAT_BIO_H
#define PLAT_BIO_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

class PlatBio : public Plat {
public:
    /**
     * Constructeur par paramètres
     * @param nom le nom
     * @param prix le prix
     * @param cout le cout
     * @param ecotaxe l'écotaxe
     */
    PlatBio(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0);

    /**
     * Destructeur
     */
    virtual ~PlatBio();

    /**
     * Getter pour l'écotaxe
     * @return l'écotaxe
     */
    double getEcoTaxe() const;

    /**
     * Setter pour l'écotaxe
     * @param ecoTaxe la nouvelle écotaxe
     */
    void setEcoTaxe(double ecoTaxe);

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient ce qu'il faut afficher
     */
    virtual void afficherPlat(ostream &os) const;

    /**
     * Getter pour le profit du plat
     * @return le profit sur le plat
     */
    virtual double getPrixDeRevient();

    /**
     * Méthode qui copie un plat
     * @return une copie de ce plat
     */
    virtual Plat *clone() const;

protected:
    double ecoTaxe_;

};

#endif // !PLAT_BIO_H
