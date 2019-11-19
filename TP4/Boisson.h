/*
* Titre : Boisson.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef BOISSON_h
#define BOISSON_h

#include "Taxable.h"
#include <string>
#include <string_view>

using namespace std;

class Boisson : public Taxable {
public:
    /**
     * Constructeur par parametres
     * @param nom Nom de la boisson
     * @param prix Prix de la boisson
     */
    Boisson(string_view nom, double prix);

    /**
     * Destructeur
     */
    virtual ~Boisson();

    /**
     * getNom
     * Retourne le nom de la boisson
     * @return Le nom de la boisson
     */
    string_view getNom() const;

    /**
     * getPrix
     * Retourne le prix de la boisson
     * @return Le prix de la boisson
     */
    double getPrix() const;

    /**
     * setTaxe
     * Definit la taxe sur la boisson
     */
    virtual void setTaxe();

    /**
     * getTaxe
     * Retourne la taxe sur la boisson
     * @return La taxe sur la boisson
     */
    virtual double getTaxe() const;

protected:
    string nom_;
    double prix_;
    double taxe_;
};


#endif /* Boisson_h */
