/*
* Titre : Vege.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef VEGE_H
#define VEGE_H

#include <iostream>
#include <string_view>
#include <string>
#include"Taxable.h"

using namespace std;

class Vege {
public:
    /**
     * Constructeur par paramètres
     * @param nom le nom du plat
     * @param vitamines les vitamines du plat
     * @param proteines les proteines du plat
     * @param mineraux les mineraux du plat
     */
    Vege(string nom, double vitamines, double proteines, double mineraux);

    /**
     * Destructeur
     */
    virtual ~Vege();

    /**
     * Getter des vitamines
     * @return les vitamines
     */
    double getVitamines() const;

    /**
     * Getter des proteines
     * @return les proteines
     */
    double getProteines() const;

    /**
     * Getter des mineraux
     * @return les mineraux
     */
    double getMineraux() const;

    /**
     * Setter des vitamines
     * @param vitamines les vitamines
     */
    void setVitamines(double vitamines);

    /**
     * Setter des proteines
     * @param proteines les proteines
     */
    void setProteines(double proteines);

    /**
     * Setter des mineraux
     * @param mineraux les mineraux
     */
    void setMineraux(double mineraux);

    /**
     * Fonction d'affichage du plat
     * @param os l'ostream qui contient l'affichage
     */
    void virtual afficherVege(ostream &os) const;

    /**
     * Fonction qui calcule l'apport nutritif
     * @return l'apport nutritif
     */
    virtual double calculerApportNutritif() const = 0;

protected:
    double vitamines_;
    double proteines_;
    double mineraux_;

    string nom_;
};

#endif
