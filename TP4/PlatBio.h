/*
* Titre : PlatBio.h - Travail Pratique #4
* Date : 22 mars 2019
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
     * @param nom le nom du plat
     * @param prix le prix du plat
     * @param cout le cout du plat
     * @param ecotaxe l'écotaxe pour le plat
     */
    PlatBio(string nom = "inconnu", double prix = 0,
            double cout = 0, double ecotaxe = 0);

    /**
     * Destructeur
     */
    virtual ~PlatBio();

    /**
     * Getter pour l'écotaxe
     * @return
     */
    double getEcoTaxe() const;

    /**
     * Setter pour l'écotaxe
     * @param ecoTaxe la nouvelle écotaxe
     */
    void setEcoTaxe(double ecoTaxe);

    /**
     * Fonction d'affichage du plat
     * @param os l'ostream qui contient l'affichage
     */
    virtual void afficherPlat(ostream &os) const;

    /**
     * Getter pour le revenu du plat
     * @return le revenu du plat
     */
    double getPrixDeRevient();

    /**
     * Fonction de copie du plat
     * @return un plat identique à l'appelant
     */
    virtual Plat *clone() const;

protected:
    double ecoTaxe_;

};

#endif // !PLAT_VERT_H
