/*
* Titre : Table.h - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
#include "PlatCustom.h"
#include "ClientPrestige.h"
#include <vector>

class Table {
public:
    /**
     * Constructeur par defaut
     */
    Table();

    /**
     * Constructeur par parametres
     * @param id ID de la table
     * @param nbPlaces Nombre de places disponibles a la table
     */
    Table(int id, int nbPlaces);

    /**
     * getId
     * Retourne l'ID de la table
     * @return ID de la table
     */
    int getId() const;

    /**
     * getNbPlaces
     * Retourne le nombre de places a la table
     * @return Le nombre de places a la table
     */
    int getNbPlaces() const;

    /**
     * estOccupee
     * Retourne si la table est occupee ou non
     * @return Si la table est occupee ou non
     */
    bool estOccupee() const;

    /**
     * estPleine
     * Retourne si la table est pleine ou non
     * @return Si la table est pleine ou non
     */
    bool estPleine() const;

    /**
     * getNbClientsATable
     * Retourne le nombre de clients a la table
     * @return Le nombre de clients a la table
     */
    int getNbClientsATable() const;

    /**
     * getCommande
     * Retourne la commande des clients de la table
     * @return La commande des clients de la table
     */
    vector<Plat *> getCommande() const;

    /**
     * getClientPrincipal
     * Retourne le client principal de la table
     * @return Le client principal de la table
     */
    Client *getClientPrincipal() const;

    /**
     * getChiffreAffaire
     * Retourne le chiffre d'affaire de la table
     * @return Le chiffre d'affaire de la table
     */
    double getChiffreAffaire() const;

    /**
     * getMontantAPayer
     * Retourne le montant a payer par le client
     * @return Le montant a payer par le client
     */
    double getMontantAPayer() const;

    /**
     * libererTable
     * Libere la table de ses clients et efface leur commande
     */
    void libererTable();

    /**
     * placerClients
     * Place les clients a table
     * @param nbClients Nombre de clients a placer a table
     */
    void placerClients(int nbClients);

    /**
     * setId
     * Definit l'ID de la table
     * @param id ID de la table
     */
    void setId(int id);

    /**
     * setClientPrincipal
     * Definit le client principal de la table
     * @param clientPrincipal Le client principal de la table
     */
    void setClientPrincipal(Client *clientPrincipal);

    /**
     * commander
     * Ajoute un plat a la commande de la table
     * @param plat Le plat a ajouter a la commande
     */
    void commander(Plat *plat);

    /**
     * operator<<
     * Retourne un stream avec les informations de la table
     * @param os Stream a modifier
     * @param table Table dont on desire les informations
     * @return Stream modifie
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
