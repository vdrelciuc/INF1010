/*
* Titre : Taxable.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef TAXABLE_H
#define TAXABLE_H

class Taxable {
public:
    /**
     * Setter pour la taxe
     */
    virtual void setTaxe() = 0;

    /**
     * Getter pour la taxe
     * @return la taxe
     */
    virtual double getTaxe() const = 0;
};

#endif /* Taxable_h */
