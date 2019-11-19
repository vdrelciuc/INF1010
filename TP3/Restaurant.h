/*
* Titre : Restaurant.h - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "ClientPrestige.h"

const int NB_ZONES_LIVR = 3;
const int INDEX_TABLE_LIVRAISON = 4;


class Restaurant {
public:
    /**
     * Constructeur par defaut
     */
    Restaurant();

    /**
     * Constructeur par parametres
     * @param fichier Fichier a lire
     * @param nom Nom du restaurant
     * @param moment Moment de la journee
     */
    Restaurant(const string &fichier, const string &nom, TypeMenu moment);

    /**
     * Constructeur par copie
     * @param restau Restaurant a copier
     */
    Restaurant(const Restaurant &restau);

    /**
     * Destructeur
     */
    ~Restaurant();

    /**
     * setMoment
     * Definit le moment de la journee
     * @param moment Le moment de la journee
     */
    void setMoment(TypeMenu moment);

    /**
     * setNom
     * Definit le nom du restaurant
     * @param nom Le nom du restaurant
     */
    void setNom(const string &nom);

    /**
     * getNom
     * Retourne le nom du restaurant
     * @return Le nom du restaurant
     */
    string getNom() const;

    /**
     * getMoment
     * Retourne le moment de la journee
     * @return Le moment de la journee
     */
    TypeMenu getMoment() const;

    /**
     * getFraisTransports
     * Retourne les frais de transport a un index precis
     * @param index Index du tableau des frais
     * @return Frais de transport
     */
    double getFraisTransports(int index) const;

    /**
     * lireTable
     * Lis les informations des tables depuis un fichier texte
     * @param fichier Fichier texte a lire
     */
    void lireTable(const string &fichier);

    /**
     * lireAdresses
     * Lis les informations sur les zones d'adresse depuis un fichier texte
     * @param fichier Le fichier texte a lire
     */
    void lireAdresses(const string &fichier);

    /**
     * operator+=
     * Ajoute une table dans un restaurant
     * @param table Table a ajouter
     * @return Restaurant avec une nouvelle table
     */
    Restaurant &operator+=(Table *table);

    /**
     * libererTable
     * Libere la table dont l'ID est passe en parametre
     * @param id ID de la table a liberer
     */
    void libererTable(int id);

    /**
     * commanderPlat
     * Ajoute un plat a la commande d'une des tables
     * @param nom Nom du plat a ajouter
     * @param idTable ID de la table ou le plat sera servi
     * @param type Type de plat (defaut: Regulier)
     * @param nbIngredients Nombre d'ingredients personnalises (defaut: 0)
     */
    void commanderPlat(const string &nom, int idTable, TypePlat type = Regulier, int nbIngredients = 0);

    /**
     * operator<
     * Retourne si le chiffre d'affaire du restaurant actuel est plus petit que celui du restaurant en parametres
     * @param restau Restaurant avec lequel on compare le chiffre d'affaire
     * @return Si le chiffre d'affaire du restaurant actuel est plus petit
     */
    bool operator<(const Restaurant &restau) const;

    /**
     * operator=
     * Operateur de copie d'un restaurant
     * @param restau Restaurant dont on copie les attributs
     * @return Restaurant avec les nouveaux attributs
     */
    Restaurant &operator=(const Restaurant &restau);

    /**
     * placerClients
     * Place un client et son groupe a la table optimale
     * @param client Client a placer
     */
    void placerClients(Client *client);

    /**
     * livrerClient
     * Livre une liste de plats a un client qui a droit a la livraison
     * @param client Client auquel on livre
     * @param nomPlats Nom des plats de sa commande
     */
    void livrerClient(Client *client, vector<string> nomPlats);

    /**
     * calculerReduction
     * Calcule le montant a deduire du tarif pour un client donne en fonction de ses privilleges
     * @param client Le client a qui on deduit un montant
     * @param montant Montant initial de la commande du client
     * @param livraison Si le client a demande a se faire livrer
     * @return Le montant a deduire
     */
    double calculerReduction(Client *client, double montant, bool livraison);

    /**
     * operator<<
     * Retourne un stream modifie par les informations du restaurant
     * @param os Stream a modifier
     * @param restau Restaurant dont on veut afficher les informations
     * @return Le stream modifie
     */
    friend ostream &operator<<(ostream &os, const Restaurant &restau);

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

    //Tarif des trois zones de livraison
    double fraisTransport_[NB_ZONES_LIVR];


};

#endif // !RESTAURANT_H
