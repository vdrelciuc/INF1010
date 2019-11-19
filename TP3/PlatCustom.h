/*
* Titre : PlatCustom.h - Travail Pratique #2
* Date : 11 F�vrier 2019
* Auteur : Fatou S. MOUNZEO
*/

#ifndef PLAT_CUSTOM_H
#define PLAT_CUSTOM_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

const double FRAIS_CUSTOMISATION = 0.75;

class PlatCustom : public Plat {
public:

    /**
     * Constructeur par param�tres
     * @param nom le nom du plat
     * @param prix le prix du plat
     * @param cout le cout du plat
     * @param nbIngredients le nombre d'ingr�dients ajout�s
     */
    PlatCustom(string nom, double prix, double cout, int nbIngredients);

    /**
    * Getter pour le nombre d'ingr�dients ajout�s
    * @return le nombre d'ingr�dients ajout�s
    */
    int getNbIngredients() const;

    /**
     * Getter pour le supplement au prix
     * @return le supplement au prix
     */
    double getSupplement() const;

    /**
     * Setter pour le nombre d'ingredients
     * @param nIngredients le nouveau nombre d'ingredients
     */
    void setNbIngredients(int nIngredients);

    /**
     * Surcharge d'op�rateur pour afficher le PlatCustom
     * @param os L'ostream qui va contenir ce qu'il faut afficher
     * @param plat le PlatCustom � afficher
     * @return l'ostream avec ce qu'il faut afficher
     */
    friend ostream &operator<<(ostream &os, const PlatCustom &plat);

private:
    double supplement_;
    int nbIngredients_;

    double calculerSupplement();


};

#endif // !PLAT_VERT_H
