/*
* Titre : PlatBioVege.h - Travail Pratique #4
* Date : 22 mars 2019
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
     * @param nom le nom du plat
     * @param prix le prix du plat
     * @param cout le cout du plat
     * @param ecotaxe l'écotaxe du plat
     * @param vitamines les vitamines du plat
     * @param proteines les proteines du plat
     * @param mineraux les mineraux du plat
     */
    PlatBioVege(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0,
                double vitamines = 0, double proteines = 0, double mineraux = 0);

    /**
     * Destructeur
     */
    virtual ~PlatBioVege();

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
     * Fonction qui calcule l'apport nutritif du plat
     * @return l'apport nutritif
     */
    virtual double calculerApportNutritif() const;

};

#endif
