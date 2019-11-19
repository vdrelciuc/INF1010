/*
* Titre : PlatBioVege.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef PLAT_BIOVEGE_H
#define PLAT_BIOVEGE_H

#include "PlatBio.h"
#include "Vege.h"
#include "def.h"

class PlatBioVege :
        public PlatBio, public Vege {
public:
    /**
     * Constructeur par paramètres
     * @param nom le nom
     * @param prix le prix
     * @param cout le cout
     * @param ecotaxe l'écotaxe
     * @param vitamines les vitamines
     * @param proteines les proteines
     * @param mineraux les mineraux
     */
    PlatBioVege(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0,
                double vitamines = 0, double proteines = 0, double mineraux = 0);

    /**
     * Destructeur
     */
    virtual ~PlatBioVege();

    /**
     * Méthode pour copier un plat
     * @return une copie de ce plat
     */
    virtual Plat *clone() const;

    /**
     * Calcule l'apport nutritif du plat
     * @return l'apport nutritif du plat
     */
    virtual double calculerApportNutritif() const;

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient ce qu'il faut afficher
     */
    virtual void afficherPlat(ostream &os) const;
};

#endif
