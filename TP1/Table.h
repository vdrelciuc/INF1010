/*
* Titre : Table.h - Travail Pratique #1
* Date : 01 février 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"

const int MAXCAP = 5;

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
     * Destructeur par défaut
     */
    ~Table();

    /**
     * getId
     * Retourne l'id de la table
     * @return Id de la table
     */
    int getId() const;

    /**
     * getNbPlaces
     * Retourne le nombre de places disponibles à la table
     * @return Nombre de places disponibles à la table
     */
    int getNbPlaces() const;

    /**
     * estOccupe
     * Retourne si la table est occupée ou non
     * @return Si la table est occupée ou non
     */
    bool estOccupee() const;

    /**
     * libererTable
     * Libère la table en effacant la liste de commandes
     */
    void libererTable();

    /**
     * placerClient
     * Si la table est vide, va l'occuper
     */
    void placerClient();

    /**
     * setId
     * Définir l'ID de la table
     * @param id ID de la table
     */
    void setId(int id);

    /**
     * commander
     * Ajoute un plat à la liste de commandes de la table
     * @param plat Plat à ajouter à la commande
     */
    void commander(Plat *plat);

    /**
     * getChiffreAffaire
     * Calcule le chiffre d'affaires de la table
     * @return Le chiffre d'affaires de la table
     */
    double getChiffreAffaire();

    /**
     * afficher
     * Affiche la commande des clients assis à la table, si elle existe
     */
    void afficher() const;

private:
    Plat **commande_;
    unsigned int capacite_;
    unsigned int nbPlats_;

    int id_;
    unsigned int nbPlaces_;
    bool occupee_;
};

#endif // !TABLE_H
