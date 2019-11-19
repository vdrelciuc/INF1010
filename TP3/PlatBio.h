/*
* Titre : PlatBio.h - Travail Pratique #3
* Date : 21 f�vrier 2019
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
     * Constructeur par param�tres
     * @param nom le nom du plat
     * @param prix le prix du plat
     * @param cout le cout du plat
     * @param ecotaxe l'ecotaxe � appliquer
     */
    PlatBio(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0);

    /**
     * Getter pour l'ecotaxe
     * @return l'ecotaxe
     */
    double getEcoTaxe() const;

    /**
     * Setter pour l'ecotaxe
     * @param ecoTaxe la nouvelle ecotaxe
     */
    void setEcoTaxe(double ecoTaxe);

    /**
     * Surcharge d'op�rateur pour afficher le PlatBio
     * @param os L'ostream qui va contenir ce qu'il faut afficher
     * @param plat le PlatBio � afficher
     * @return l'ostream avec ce qu'il faut afficher
     */
    friend ostream &operator<<(ostream &os, const PlatBio &plat);

private:
    double ecoTaxe_;
};

#endif // !PLAT_BIO_H