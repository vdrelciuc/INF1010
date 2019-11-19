/*
* Titre : Plat.h - Travail Pratique #2
* Date : 6 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std;

class Plat {
public:
    /**
     * Constructeur par défaut
     */
    Plat();

    /**
     * Constructeur par paramètres
     * @param nom Nom du plat
     * @param prix Prix du plat
     * @param cout Coût du plat
     */
    Plat(string nom, double prix, double cout);

    /**
     * getNom
     * Retourne le nom du plat
     * @return Le nom du plat
     */
    string getNom() const;

    /**
     * getPrix
     * Retourne le prix du plat
     * @return Le prix du plat
     */
    double getPrix() const;

    /**
     * getCout
     * Retourne le cout du plat
     * @return Le cout du plat
     */
    double getCout() const;

    /**
     * setMom
     * Change le nom du plat
     * @param nom Le nouveau nom du plat
     */
    void setNom(string nom);

    /**
     * setPrix
     * Change le prix du plat
     * @param prix Le nouveau prix du plat
     */
    void setPrix(double prix);

    /**
     * Surcharge de l'opérateur < (plus petit que)
     * Retourne si le prix du plat actuel est inférieur à celui
     * du plat donné en paramètres
     * @param plat Plat dont le prix est comparé
     * @return Si le plat actuel est moins cher
     */
    bool operator<(const Plat &plat) const;

    /**
     * Surcharge de l'opérateur << (ostream)
     * Passe les paramètres d'un plat dans un ostream
     * @param os Stream de données
     * @param plat Plat dont nous passons les paramètres en stream
     * @return Stream de données
     */
    friend ostream &operator<<(ostream &os, const Plat &plat);

private:
    string nom_;
    double prix_;
    double cout_;

};

#endif // !PLAT_H
