/*
* Titre : Restaurant.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "Client.h"
#include "ClientPrestige.h"
#include "pointers.h"
#include <string_view>
#include <iostream>
#include "def.h"

using namespace std;

class Client;

class Table;

class Restaurant {
public:
    /**
     * Constructeur par défaut
     */
    Restaurant();

    /**
     * Constructeur par paramètres
     * @param nomFichier le nom du fichier contenant le menu
     * @param nom le nom du restaurant
     * @param moment le moment de la journée
     */
    Restaurant(const string &nomFichier, string_view nom, TypeMenu moment);

    /**
     * Constructeur par copie
     * @param autre le restaurant à copier
     */
    Restaurant(const Restaurant &autre) = delete;

    /**
     * Destructeur
     */
    ~Restaurant();

    /**
     * Setter pour le moment
     * @param moment le moment de la journee
     */
    void setMoment(TypeMenu moment);

    /**
     * Setter pour le nom
     * @param nom le nom du restaurant
     */
    void setNom(string_view nom);

    /**
     * Setter pour le chiffre d'affaire du restaurant
     * @param chiffre Le chiffre d'affaire du restaurant
     */
    void setChiffreAffaire(double chiffre);

    /**
     * Getter pour le nom
     * @return le nom du restaurant
     */
    string getNom() const;

    /**
     * Getter du moment
     * @return le moment de la journée
     */
    TypeMenu getMoment() const;

    /**
     * Getter pour les frais de livraison
     * @param index la zone de livraison
     * @return les frais de livraison
     */
    double getFraisLivraison(int index) const;

    /**
     * Getter pour le chiffre d'affaire
     * @return le chiffre d'affaire du restaurant
     */
    double getChiffreAffaire();

    /**
     * Fonction pour lire les tables du fichier
     * @param fichier le fichier qui contient les tables
     */
    void lireTables(const string &fichier);

    /**
     * Fonction qui lit les adresses dans le fichier
     * @param fichier le fichier qui contient les adresses
     */
    void lireAdresses(const string &fichier);

    /**
     * Surcharge d'opérateur pour ajouter une table
     * @param table la table à ajouter
     * @return le nouveau restaurant
     */
    Restaurant &operator+=(
            owner<Table *> table);

    /**
     * Fonction qui libère une table du restaurant
     * @param id l'id de la table à libérer
     */
    void libererTable(int id);

    /**
     * Fonction pour commander un plat
     * @param nom le nom du plat à commander
     * @param idTable l'id de la table qui commande
     */
    void commanderPlat(string_view nom, int idTable);

    /**
     * Surcharge d'opérateur pour l'opérateur "plus petit que"
     * @param restau Le restaurant a comparer
     * @return Si le restaurant actuel a un plus petit chiffre d'affaires
     */
    bool operator<(const Restaurant &restau) const;

    /**
     * Surcharge d'opérateur pour copier un restaurant
     * @param autre le restaurant à copier
     * @return le nouveau restaurant
     */
    Restaurant &operator=(
            const Restaurant &autre) = delete;

    /**
     * Fonction qui place des client à une table
     * @param client le client à ajouter
     * @return true si succès, false si restaurant plein
     */
    bool placerClients(Client *client);

    /**
     * Fonction pour livrer la table d'un client
     * @param client le client auquel livrer
     * @param nomPlats un vecteur contenant les plats à envoyer
     * @return true si succès, false si erreur
     */
    bool livrerClient(Client *client, const vector<string> &nomPlats);

    /**
     * Fonction qui calcule les réductions d'un client
     * @param client le client qui veut une réduction
     * @param montant le montant de la commande
     * @param livraison true si c'est une livraison
     * @return le montant de réduction
     */
    double calculerReduction(Client *client, double montant, bool livraison);

    /**
     * Getter pour les frais de livraison
     * @param zone la zone à livrer
     * @return les frais de livraison
     */
    double getFraisLivraison(ZoneHabitation zone) const;

    /**
     * Getter pour le menu
     * @param typeMenu le type de menu
     * @return un pointeur vers le menu
     */
    Menu *getMenu(TypeMenu typeMenu) const;

    /**
     * Fonction d'affichage du restaurant
     * @param os l'ostream qui contient l'affichage
     * @param restaurent le restaurant
     * @return l'ostream avec l'affichage
     */
    friend ostream &operator<<(ostream &os, const Restaurant &restaurent);

private:
    /**
     * Retourne le menu actuel du restaurant
     * @return Le menu actuel du restaurant
     */
    Menu *menuActuel() const;

    /**
     * Getter pour la table dont on connait l'id
     * @param id Id de la table qu'on cherche
     * @return Le pointeur vers la table trouvee
     */
    Table *getTable(int id) const;

    string nom_;

    TypeMenu momentJournee_;
    double chiffreAffaire_;

    // Differents menus en fonction du moment de la journ�e.
    owner<Menu *> menuMatin_;  //? "owner" est juste un indicateur que la classe est propri�taire des menus (et devra faire un "delete"), mais owner<Menu*> est �quivalent � Menu*; voir pointers.h .
    owner<Menu *> menuMidi_;
    owner<Menu *> menuSoir_;
    // Liste des tables.
    vector<owner<Table *>> tables_;  //? "owner" est juste un indicateur que la classe est propri�taire des tables (et devra faire un "delete"), mais owner<Table*> est �quivalent � Table*; voir pointers.h .

    // Tarif des trois zones de livraison.
    double fraisLivraison_[NB_ZONES_LIVR];
};

string getNomTypeMenu(TypeMenu typeMenu);

#endif // !RESTAURANT_H
