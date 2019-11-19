/*
* Titre : Restaurant.h - Travail Pratique #1
* Date : 01 février 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"

const int INTTABLES = 6;

class Restaurant {
public:
    /**
     * Constructeur par défaut
     */
    Restaurant();

    /**
     * Constructeur par paramètres
     * @param fichier Le fichier à lire
     * @param nom Le nom du restaurant
     * @param moment Le moment de la journée
     */
    Restaurant(string &fichier, string &nom, TypeMenu moment);

    /**
     * Destructeur par défaut
     */
    ~Restaurant();

    /**
     * setMoment
     * Définit le moment de la journée
     * @param moment Moment de la journée
     */
    void setMoment(TypeMenu moment);

    /**
     * getNom
     * Retourne le nom du restaurant
     * @return Le nom du restaurant
     */
    string getNom() const;

    /**
     * getMoment
     * Retourne le moment de la journée
     * @return Le moment de la journée
     */
    TypeMenu getMoment() const;

    /**
     * lireTable
     * Crée les tables du restaurant à partir des informations lues dans le fichier texte
     * @param fichier Le fichier texte à lire
     */
    void lireTable(string &fichier);

    /**
     * ajouterTable
     * Ajoute une table à la liste des tables
     * @param id ID de la table à ajouter
     * @param nbPlaces Nombre de places de la table à ajouter
     */
    void ajouterTable(int id, int nbPlaces);

    /**
     * libererTable
     * Libère la table et calcule le chiffre d'affaires de celle-ci
     * @param id ID de la table à libérer
     */
    void libererTable(int id);

    /**
     * commanderPlat
     * Cherche un plat dans le menu. Si le plat est trouvé, il est ajouté à la commande de la table
     * @param nom Le nom du plat à chercher dans le menu
     * @param idTable ID de la table de la commande
     */
    void commanderPlat(string &nom, int idTable);

    /**
     * placerClients
     * Place un nombre précis de clients à une table choisie de façon intelligente
     * @param nbClients Nombre de clients à placer
     */
    void placerClients(int nbClients);

    /**
     * afficher
     * Affiche diverses informations sur l'état des tables du restaurant et sur son menu
     */
    void afficher() const;

private:
    string *nom_;

    double chiffreAffaire_;
    TypeMenu momentJournee_;

    Menu *menuMatin_;
    Menu *menuMidi_;
    Menu *menuSoir_;

    unsigned int capaciteTables_;
    Table **tables_;
    unsigned int nbTables_;

};

#endif // !RESTAURANT_H
