/*
* Titre : Taxable.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef TAXABLE_H
#define TAXABLE_H

class Taxable {
public:
    /**
     * Destructeur
     */
    virtual ~Taxable() {};

    /**
     * Setter pour la taxe
     */
    virtual void setTaxe() = 0;

    /**
     * Getter pour la taxe
     * @return la taxe du plat
     */
    virtual double getTaxe() const = 0;
};

#endif /* Taxable_h */
