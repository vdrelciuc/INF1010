/*
* Titre : ClientOccasionnel.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_OCCASIONNEL
#define CLIENT_OCCASIONNEL

#include "Client.h"

class ClientOccasionnel : public Client {
public:
    /**
     * Constructeur par parametres
     * @param nom Nom du client occasionnel
     * @param prenom Prenom du client occasionnel
     * @param tailleGroupe Taille du groupe
     */
    ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe);

    /**
     * Destructeur
     */
    virtual ~ClientOccasionnel();

    /**
     * getNbPoints
     * Retourne le nombre de points du client occasionnel
     * @return Le nombre de points du client occasionnel
     */
    virtual int getNbPoints() const;

    /**
     * afficherClient
     * Methode d'affichage des caracteristiques du client occasionnel
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
};

#endif
