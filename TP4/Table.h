/*
* Titre : Table.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
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
     * @return le nombre de place
     */
    int getNbPlaces() const;

    /**
     * Getter pour l'ocupation de la table
     * @return true s'il y a des clients, false si vide
     */
    bool estOccupee() const;

    /**
     * Getter pour si la table est pleine
     * @return true si la table est pleine, false s'il y a de la place
     */
    bool estPleine() const;

    /**
     * Getter pour le nombre de client à table
     * @return le nombre de clients à table
     */
    int getNbClientsATable() const;

    /**
     * Getter pour la commande de la table
     * @return un vector contenant les plats commandés
     */
    vector<Plat *> getCommande() const;

    /**
     * Getter pour le client principal de la table
     * @return le client principal
     */
    Client *getClientPrincipal() const;

    /**
     * Getter pour le chiffre d'affaire
     * @return le chiffre d'affaire
     */
    double getChiffreAffaire() const;

    /**
     * Fonction pour libérer la table
     */
    void libererTable();

    /**
     * Fonction qui place des clients sur la table
     * @param nbClients le nombre de clients à placer
     */
    void placerClients(int nbClients);

    /**
    * Setter pour l'id de la table
    * @param id l'id de la table
    */
    void setId(int id);

    /**
     * Setter pour le client principal
     * @param clientPrincipal le client principal
     */
    void setClientPrincipal(Client *clientPrincipal);

    /**
     * Fonction pour commander un plat
     * @param plat le plat à commander
     */
    void commander(Plat *plat);

    /**
     * Surcharge d'opérateur pour l'affichage
     * @param os l'ostream qui contient l'affichage
     * @param table la table à afficher
     * @return l'ostream avec l'affichage
     */
    friend ostream &operator<<(ostream &os, const Table &table);

private :
    vector<Plat *> commande_;
    int id_;
    int nbPlaces_;
    int nbClientsATable_;
    Client *clientPrincipal_;
};

#endif // !TABLE_H
