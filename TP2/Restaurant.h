/*
* Titre : Restaurant.h - Travail Pratique #2
* Date : 6 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "Menu.h"

const int INTTABLES = 6;

class Restaurant {
public:
    
    /**
     * Constucteur par defaut
     * */
    Restaurant();

    /**
     * Constructeur par paramètres
     * @param &fichier est le fichier qui sera utiliser pour créer les menus
     * @param &nom sera le nom du restaurant
     * @param moment sera le moment de la journée auquel on crée le restaurant
     * */
    Restaurant(const string &fichier, const string &nom, TypeMenu moment);

    /**
     * Constructeur par copie
     * @param &restaurant est le restaurant que l'on veut copier
     * */
    Restaurant(const Restaurant &restaurant);

    /**
     * Destructeur
     * */
    ~Restaurant();

    /**
     * Permet de changer le type de menu utilisé
     * @param moment le moment de la journée
     * */
    void setMoment(TypeMenu moment);

    /**
     * Permet de changer le nom du restaurant
     * @param nom est le nouveau nom à donner au restaurant
     * */
    void setNom(string nom);

    /**
     * Permet de recevoir le nom du restaurant
     * @return le nom du restaurant
     * */
    string getNom() const;

    /**
     * Permet de recevoir le moment de la journée
     * @return le moment de la journée
     * */
    TypeMenu getMoment() const;

    /**
     * Permet de recevoir le chiffre d'affaire du restaurant
     * @return le chiffre d'affaire du restaurant
     * */
    double getChiffreAffaire() const;

    /**
     * Permet de recevoir les tables du restaurant
     * @return un vector avec les tables du restaurant
     * */
    vector<Table *> getTables() const;

    /**
     * Permet de recevoir le menu matin du restaurant
     * @return le menu matin du restaurant
     * */
    Menu *getMenuMatin() const;

    /**
     * Permet de recevoir le menu midi du restaurant
     * @return le menu midi du restaurant
     * */
    Menu *getMenuMidi() const;

    /**
     * Permet de recevoir le menu soir du restaurant
     * @return le menu soir du restaurant
     * */
    Menu *getMenuSoir() const;

    /**
     * Permet de lire les tables contenues sur le fichier
     * @param le fichier à lire
     * */
    void lireTable(const string &fichier);

    /**
     * Permet de libérer une table occupée
     * @param id l'ID de la table à vider
     * */
    void libererTable(int id);

    /**
     * Permet de commander un plat à la table
     * @param &nom le nom du plat à commander
     * @param idTable l'ID de la table à commander
     * */
    void commanderPlat(const string &nom, int idTable);

    /**
     * Permet de placer des clients sur une table
     * @param le nombre de clients à placer
     * */
    void placerClients(int nbClients);

    /**
     * Surcharge de l'opérateur += afin d'ajouter une table
     * @param *table pointeur de la table à ajouter
     * */
    Restaurant &operator+=(Table *table);

    /**
     * Surcharge de l'opérateur = afin de rendre le restaurant pareil à un autre
     * @param &restaurant est le restaurant à imiter
     * */
    Restaurant &operator=(const Restaurant &restaurant);

    /**
     * Surcharge de l'opérateur < qui compare les chiffres d'affaire de deux restaurants
     * @param &restaurant est le restaurant avec lequel nous devons comparer
     * @return true si le restaurant qui appelle a un plus petit chiffre d'affaire
     * @return false si le restaurant qui appelle a un plus gros, ou égal, chiffre d'affaire
     * */
    bool operator<(const Restaurant &restaurant) const;

    /**
     * Surcharge de l'opérateur << qui permet d'afficher des infos sur le restaurant
     * @param &os permet de stocker ce qu'il faut afficher
     * @param &restaurant désigne le restaurant dont on veut afficher les informations
     * @return os qui sera utilisé dans un cout
     * */
    friend ostream &operator<<(ostream &os, const Restaurant &restaurant);

private:
    string *nom_;

    double chiffreAffaire_;
    TypeMenu momentJournee_;

    //differents menus en fonction du moment de la journee
    Menu *menuMatin_;
    Menu *menuMidi_;
    Menu *menuSoir_;

    //liste des tables
    vector<Table *> tables_;
};

#endif // !RESTAURANT_H
