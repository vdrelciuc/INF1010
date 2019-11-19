/*
* Titre : ClientRegulier.h - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_REG
#define CLIENT_REG

#include "Client.h"
#include <vector>
#include <string>

using namespace std;

const double TAUX_REDUC_REGULIER = 0.1;
const double TAUX_REDUC_PRESTIGE = 0.2;
const double SEUIL_DEBUT_REDUCTION = 75;
const double SEUIL_LIVRAISON_GRATUITE = 200;

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
     * @param tailleGroupe Nombre de gens qui accompagnent le client regulier
     * @param nbPoints Nombre de points de fidelite du client regulier
     */
    ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints);

    /**
     * getNbPoints
     * Retourne le nombre de points du client regulier
     * @return Nombre de points du client regulier
     */
    int getNbPoints() const;

    /**
     * setNbPoints
     * Definit le nombde de points du client regulier
     * @param nbPoints Le nombre de points du client regulier
     */
    void setNbPoints(int nbPoints);

    /**
     * augmenterNbPoints
     * Augmente le nombre de points du client regulier
     * @param bonus Le bonus a ajouter au nombre de points actuels du client regulier
     */
    void augmenterNbPoints(int bonus);

    /**
     * operator<<
     * Modifie un stream en fonction des donnees du client regulier
     * @param os Le stream a modifier
     * @param client Le client done les donnees sont passees au stream
     * @return Le stream modifie
     */
    friend ostream &operator<<(ostream &os, const ClientRegulier &client);

protected:
    int nbPoints_;
};

#endif
