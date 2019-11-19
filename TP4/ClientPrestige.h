/*
* Titre : ClientPrestige.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"

#include "def.h"

class ClientPrestige : public ClientRegulier {
public:
    /**
     * Constructeur par defaut
     */
    ClientPrestige();

    /**
     * Constructeur par parametres
     * @param nom Nom du client prestige
     * @param prenom Prenom du client prestige
     * @param tailleGroupe Taille du groupe
     * @param nbPoints Nombre de points du client prestige
     * @param adresse Le code d'adresse du client prestige
     */
    ClientPrestige(string_view nom, string_view prenom, int tailleGroupe,
                   int nbPoints, ZoneHabitation adresse);

    /**
     * Destructeur
     */
    virtual ~ClientPrestige() {};

    /**
     * getAdresseCode
     * Retourne le code d'adresse du client prestige
     * @return Le code d'adresse du client prestige
     */
    ZoneHabitation getAdresseCode() const;

    /**
     * afficherClient
     * Methode d'affichage des caracteristiques du client prestige
     * @param os Le stream modifie
     */
    virtual void afficherClient(ostream &os) const;

    /**
     * getAdressCodeString
     * Retourne le code d'adresse du client prestige sous forme de string
     * @return Le code d'adresse du client prestige sous forme de string
     */
    string getAdressCodeString() const;

    /**
     * getReduction
     * Retourne le montant de la reduction a laquelle le client a droit
     * @param res Le restaurant
     * @param montant Le montant a payer
     * @param estLivraison Si le client a commande en livraison
     * @return Le montant de la reduction
     */
    virtual double getReduction(const Restaurant &res, double montant, bool estLivraison);

private:
    ZoneHabitation adresse_;

};

#endif

