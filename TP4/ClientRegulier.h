/*
* Titre : ClientRegulier.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_REG
#define CLIENT_REG

#include "Client.h"
//#include "Restaurant.h"
#include "def.h"

class Restaurant;

class ClientRegulier : public Client {
public:
    /**
     * Constructeur par defaut
     */
    ClientRegulier();

    /**
     * Constructeur par parametres
     * @param nom Nom du client regulier
     * @param prenom Prenom du client regulier
     * @param tailleGroupe Taille du groupe
     * @param nbPoints Nombre de points du client regulier
     */
    ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int nbPoints);

    /**
     * Destructeur
     */
    virtual ~ClientRegulier();

    /**
     * getNbPoints
     * Retourne le nombre de points du client regulier
     * @return Le nombre de points du client regulier
     */
    virtual int getNbPoints() const;

    /**
     * augmenterNbPoints
     * Augmente le nombre de points du client regulier selon un bonus donne
     * @param bonus Le bonus
     */
    virtual void augmenterNbPoints(int bonus);

    /**
     * afficherClient
     * Methode d'affichage des caracteristiques du client regulier
     * @param os Le stream modifie
     */
    virtual void afficherClient(ostream &os) const;

    /**
     * getReduction
     * Retourne le montant de la reduction a laquelle le client a droit
     * @param res Le restaurant
     * @param montant Le montant a payer
     * @param estLivraison Si le client a commande en livraison
     * @return Le montant de la reduction
     */
    virtual double getReduction(const Restaurant &res, double montant, bool estLivraison);

protected:
    int nbPoints_;
};

#endif
