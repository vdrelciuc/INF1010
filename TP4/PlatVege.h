/*
* Titre : PlatVege.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"

class PlatVege :
        public Vege, public Plat, public Taxable {
public:
    /**
     * Contructeur par paramètres
     * @param nom le nom du plat
     * @param prix le prix du plat
     * @param cout le cout du plat
     * @param vitamines les vitamines du plat
     * @param proteines les proteines du plat
     * @param mineraux les mineraux du plat
     */
    PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
             double proteines = 0, double mineraux = 0);

    /**
     * Destructeur
     */
    virtual ~PlatVege();

    /**
     * Fonction de copie du plat
     * @return un plat identique à l'appelant
     */
    virtual Plat *clone() const;

    /**
     * Fonction d'affichage du plat
     * @param os l'ostream qui contient l'affichage
     */
    virtual void afficherPlat(ostream &os) const;

    /**
     * Fonction de calcul de l'apport nutritif
     * @return l'apport nutritif
     */
    virtual double calculerApportNutritif() const;

    /**
     * Setter pour la taxe
     */
    virtual void setTaxe();

    /**
     * Getter pour la taxe
     * @return la taxe
     */
    virtual double getTaxe() const;

protected:
    double taxe_;
};

#endif
