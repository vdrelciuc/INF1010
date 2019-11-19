/*
* Titre : Table.h - Travail Pratique #2
* Date : 6 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef TABLE_H
#define TABLE_H

#include "Plat.h"
#include <vector>

class Table {
public:
    /**
     * Constructeur par défaut
     */
    Table();

    /**
     * Constructeur par paramètres
     * @param id ID de la table
     * @param nbPlaces Nombre de places à la table
     */
    Table(int id, int nbPlaces);

    /**
     * Constructeur par copie
     * @param la table que l'on veut copier
     * */
    Table(const Table &table);

    /**
     * Destructeur
     */
    ~Table();

    /**
     * getId
     * Retourne l'ID de la table
     * @return ID de la table
     */
    int getId() const;

    /**
     * getNbPlaces
     * Retourne le nombre de places disponibles à la table
     * @return Nombre de places disponibles
     */
    int getNbPlaces() const;

    /**
     * getnbClientsATable
     * Retourne le nombre de clients assis à la table
     * @return Nombre de clients à la table
     */
    int getnbClientATable() const;

    /**
     * estPleine
     * Retourne si la table est pleine ou non
     * @return Si la table est pleine ou non
     */
    bool estPleine() const;

    /**
     * estOccupee
     * Retourne si la table est occupée ou non
     * @return Si la table est occupée ou non
     */
    bool estOccupee() const;

    /**
     * getChiffreAffaire
     * Retourne le chiffre d'affaires de la table
     * @return Le chiffre d'affaires de la table
     */
    double getChiffreAffaire() const;

    /**
     * getCommande
     * Retourne la liste de commande de la table
     * @return La commande de la table
     */
    vector<Plat *> getCommande() const;

    /**
     * libererTable
     * Libère la table en effacant la liste de commandes
     */
    void libererTable();

    /**
     * placerClient
     * Si la table est vide, va l'occuper
     * @param nbClients Nombre de clients à placer à la table
     */
    void placerClient(int nbClients);

    /**
     * setId
     * Définir l'ID de la table
     * @param id DI de la table
     */
    void setId(int id);

    /**
     * commander
     * Ajoute un plat à la liste de commandes de la table
     * @param plat Plat à ajouter à la commande
     */
    void commander(Plat *plat);

    /**
     * Surcharge de l'opérateur << (ostream)
     * Passe les paramètres d'un plat dans un ostream
     * @param os Stream de données
     * @param table Table dont nous passons les paramètres dans le stream
     * @return Stream de données
     */
    friend ostream &operator<<(ostream &os, const Table &table);

private :
    vector<Plat *> commande_;
    int id_;
    int nbPlaces_;
    int nbClientsATable_;
};

#endif // !TABLE_H
