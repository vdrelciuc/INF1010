/*
* Titre : Vege.h - Travail Pratique #5
* Date : 6 avril 2019
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
     * @param nom le nom
     * @param vitamines les vitamines
     * @param proteines les proteines
     * @param mineraux les mineraux
     */
    Vege(string nom, double vitamines, double proteines, double mineraux);

    /**
     * Getter pour les vitamines
     * @return les vitamines
     */
    double getVitamines();

    /**
     * Getter pour les proteines
     * @return les proteines
     */
    double getProteines();

    /**
     * Getter pour les mineraux
     * @return les mineraux
     */
    double getMineraux();

    /**
     * Setter pour les vitamines
     * @param vitamines les nouvelles vitamines
     */
    void setVitamines(double vitamines);

    /**
     * Setter pour les proteines
     * @param proteines les proteines
     */
    void setProteines(double proteines);

    /**
     * Setter pour les mineraux
     * @param mineraux les mineraux
     */
    void setMineraux(double mineraux);

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient l'affichage
     */
    void afficherVege(ostream &os) const;

    /**
     * Calcule l'apport nutritif
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
