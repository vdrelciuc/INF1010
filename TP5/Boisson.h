/*
* Titre : Boisson.h - Travail Pratique #5
* Date : 6 avril 2019
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
     * Constructeur par paramètres
     */
    Boisson(string_view nom, double prix);

    /**
     * Setter pour la taxe, pour boisson : taxe = 12%
     */
    virtual void setTaxe();

    /**
     * Getter pour la taxe
     * @return taxe_
     */
    virtual double getTaxe() const;

    /**
     * Getter pour le nom
     * @return nom_
     */
    string_view getNom() const;

    /**
     * Getter pour le prix
     * @return prix_
     */
    double getPrix() const;

protected:
    string nom_;
    double prix_;
    double taxe_;
};


#endif /* Boisson_h */
