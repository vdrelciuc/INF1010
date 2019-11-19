/*
* Titre : PlatVege.h - Travail Pratique #5
* Date : 6 avril 2019
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
     * Constructeur par paramètres
     * @param nom le nom
     * @param prix le prix
     * @param cout le cout
     * @param vitamines les vitamines
     * @param proteines les proteines
     * @param mineraux les mineraux
     */
    PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
             double proteines = 0, double mineraux = 0);

    /**
     * Destructeur
     */
    virtual ~PlatVege();

    /**
     * Setter pour la taxe, pour un platVege la taxe est de 7%
     */
    void setTaxe();

    /**
     * Getter pour la taxe
     * @return la taxe
     */
    double getTaxe() const;

    /**
     * Méthode pour copier un plat
     * @return une copie de ce plat
     */
    virtual Plat *clone() const;

    /**
     * Calcule l'apport nutritif
     * @return l'apport nutritif
     */
    virtual double calculerApportNutritif() const;

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient ce qu'il faut afficher
     */
    virtual void afficherPlat(ostream &os) const;

protected:
    double taxe_;
};

#endif
