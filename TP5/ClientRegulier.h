/*
* Titre : ClientRegulier.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_REG
#define CLIENT_REG

#include "Client.h"
#include "def.h"

class ClientRegulier : public Client {
public:
    /**
     * Contructeur par défaut
     */
    ClientRegulier();

    /**
     * Constructeur par paramètres
     * @param nom le nom
     * @param prenom le prénom
     * @param tailleGroupe la taille du groupe
     * @param nbPoints le nombre de points
     */
    ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int nbPoints);

    /**
     * Destructeur
     */
    virtual ~ClientRegulier();

    /**
     * Getter pour le nombre de points
     * @return
     */
    virtual int getNbPoints() const;

    /**
     * Fonction qui augmente le nombre de points
     * @param bonus le nombre de points à ajouter
     */
    void augmenterNbPoints(int bonus);

    /**
     * Return un string pour l'adresse
     * @return l'adresse du client en string
     */
    virtual void afficherClient(ostream &os) const;

    /**
     * Calcule la réduction
     * @param res le restaurant
     * @param montant le montant
     * @param estLivraison true si c'est une livraison
     * @return la réduction offerte au client
     */
    virtual double getReduction(const Restaurant &res, double montant, bool estLivraison);

protected:
    int nbPoints_;
};

#endif
