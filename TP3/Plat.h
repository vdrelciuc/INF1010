/*
* Titre : Plat.h - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std;

enum TypePlat {
    Regulier, Bio, Custom
};

class Plat {
public:

    //Plat();

    /**
     * Constructeur par paramètres
     * @param nom le nom du plat
     * @param prix le prix du plat
     * @param cout le cout du plat
     */
    Plat(string nom = "inconnu", double prix = 0, double cout = 0);

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
     * Getter pour le type de plat
     * @return le type de plat
     */
    TypePlat getType() const;

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
     * Surcharge d'opérateur pour comparer deux plats
     * @param plat le plat à comparer
     * @return true si le plat en parametre est plus grand
     * @return false si le plat en parametre est plus petit
     */
    bool operator<(const Plat &plat) const;

    /**
     * Surcharge d'opérateur pour afficher le plat
     * @param os L'ostream qui va contenir ce qu'il faut afficher
     * @param plat le plat à afficher
     * @return l'ostream avec ce qu'il faut afficher
     */
    friend ostream &operator<<(ostream &os, const Plat &plat);

protected:
    TypePlat type_;
    string nom_;
    double prix_;
    double cout_;


};

#endif // !PLAT_H
