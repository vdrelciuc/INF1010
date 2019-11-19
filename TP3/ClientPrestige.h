/*
* Titre : ClientPrestige.h - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"
#include <string>

using namespace std;

enum AddressCode {
    Zone1, Zone2, Zone3
};

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
     * @param tailleGroupe Nombre de gens qui accompagnent le client prestige
     * @param nbPoints Nombre de points de fidelite du client prestige
     * @param addresse Zone de livraison du client prestige
     */
    ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AddressCode addresse);

    /**
     * getAddresseCode
     * Retourne la zone de livraison du client prestige
     * @return La zone de livraison du client prestige
     */
    AddressCode getAddresseCode() const;

    /**
     * setAddressCode
     * Definit la zone de livraison du client prestige
     * @param addressCode La zone de livraison du client prestige
     */
    void setAddressCode(AddressCode addressCode);

    /**
     * operator<<
     * Modifie un stream en fonction des donnes d'un client prestige
     * @param os Le stream a modifier
     * @param client Le client prestige dont on prend les donnees
     * @return Le stream modifie
     */
    friend ostream &operator<<(ostream &os, ClientPrestige client);

    /**
     * getAddressCodeString
     * Retourne la zone de livraison du client prestige sous forme de string
     * @return Zone de livraison du client prestige sous forme de string
     */
    string getAddressCodeString() const;

private:
    AddressCode addresse_;

};

#endif;

