/*
* Titre : ClientOccasionnel.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_OCCASIONNEL
#define CLIENT_OCCASIONNEL

#include "Client.h"

class ClientOccasionnel : public Client {
public:
    /**
     * Constructeur par paramètres
     * @param nom le nom
     * @param prenom le prénom
     * @param tailleGroupe la taille du groupe
     */
    ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe);

    /**
     * Destructeur
     */
    virtual ~ClientOccasionnel();

    /**
     * Getter pour le nombre de points
     * @return le nombre de points
     */
    virtual int getNbPoints() const;

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient ce qu'il faut afficher
     */
    virtual void afficherClient(ostream &os) const;

    /**
     * Méthode qui calcule la réduction
     * @param res le restaurant
     * @param montant le montant de la commande
     * @param estLivraison true si c'est une livraison
     * @return la réduction donnée au client
     */
    virtual double getReduction(const Restaurant &res, double montant, bool estLivraison);
};

#endif
