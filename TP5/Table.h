/*
* Titre : Table.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef TABLE_H
#define TABLE_H

#include "Plat.h"
#include "Client.h"
#include <vector>

class Client;

class Table {
public:
    /**
     * Constructeur par paramètres
     * @param id l'id de la table
     * @param nbPlaces le nombre de places
     */
    Table(int id = -1, int nbPlaces = 1);

    /**
     * Getter pour l'id
     * @return l'id de la table
     */
    int getId() const;

    /**
     * Getter pour le nombre de places
     * @return le nombre de places
     */
    int getNbPlaces() const;

    /**
     * Getter pour l'occupation de la table
     * @return true si occupé, false si non
     */
    bool estOccupee() const;

    /**
     * Getter pour si la table est pleine
     * @return true si la table est pleine
     */
    bool estPleine() const;

    /**
     * Getter pour le nombre de clients à la table
     * @return le nombre de clients à la table
     */
    int getNbClientsATable() const;

    /**
     * Getter pour la commande de la table
     * @return un vector contenant les plats de la commande
     */
    vector<Plat *> getCommande() const;

    /**
     * Getter pour le client principal
     * @return le client principal
     */
    Client *getClientPrincipal() const;

    /**
     * Getter pour le chiffre d'affaire
     * @return le chiffre d'affaire
     */
    double getChiffreAffaire() const;

    /**
     * Libère la table de ses clients
     */
    void libererTable();

    /**
     * Place un certain nombre de clients sur la table
     * @param nbClients le nombre de clients à placer
     */
    void placerClients(int nbClients);

    /**
     * Setter pour l'id de la table
     * @param id nouvel id de la table
     */
    void setId(int id);

    /**
     * Setter pour le client principal
     * @param clientPrincipal le client principal de la table
     */
    void setClientPrincipal(Client *clientPrincipal);

    /**
     * Commande un plat à la table
     * @param plat le plat à commander
     */
    void commander(Plat *plat);

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient l'affichage
     * @param table la table à afficher
     * @return l'ostream contenant l'affichage
     */
    friend ostream &operator<<(ostream &os, const Table &table);

private:
    vector<Plat *> commande_;
    int id_;
    int nbPlaces_;
    int nbClientsATable_;
    Client *clientPrincipal_;
};

#endif // !TABLE_H
