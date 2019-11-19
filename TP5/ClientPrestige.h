/*
* Titre : ClientPrestige.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"
#include "def.h"

class ClientPrestige : public ClientRegulier {
public:
    /**
     * Constructeur par défaut
     */
    ClientPrestige();

    /**
     * Constructeur par paramètres
     * @param nom le nom
     * @param prenom le prénom
     * @param tailleGroupe la taille du groupe
     * @param nbPoints le nombre de points
     * @param adresse l'adresse du client
     */
    ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, int nbPoints, ZoneHabitation adresse);

    /**
     * Destructeur
     */
    virtual ~ClientPrestige() {};

    /**
     * Getter pour la zone d'habitation
     * @return
     */
    ZoneHabitation getAdresseCode() const;

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient ce qu'il faut afficher
     */
    virtual void afficherClient(ostream &os) const;

    /**
     * Return un string pour l'adresse
     * @return l'adresse du client en string
     */
    string getAdressCodeString() const;

    /**
     * Méthode qui calcule la réduction
     * @param res le restaurant
     * @param montant le montant de la commande
     * @param estLivraison true si c'est une livraison
     * @return la réduction offerte au client
     */
    virtual double getReduction(const Restaurant &res, double montant, bool estLivraison);

private:
    ZoneHabitation adresse_;

};

#endif

