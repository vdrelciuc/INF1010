/*
* Titre : Restaurant.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "Client.h"
#include "ClientPrestige.h"
#include "pointers.h"
#include "GestionnaireTables.h"
#include "GestionnairePlats.h"
#include "def.h"

#include <string_view>
#include <iostream>

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
     * @param nomFichier le fichier à lire
     * @param nom le nom
     * @param moment moment de la journee
     */
    Restaurant(const string &nomFichier, string_view nom, TypeMenu moment);

    /**
     * Constructeur par copie
     * @param autre restaurant à copier
     */
    Restaurant(const Restaurant &autre) = delete;  //? Le programme ne fait jamais de copie de restaurant,
    //donc cette methode n"est jamais cree par defaut par le compilateur

    /**
     * Destructeur
     */
    ~Restaurant();

    /**
     * Setter du moment de la journée
     * @param moment le nouveau moment
     */
    void setMoment(TypeMenu moment);

    /**
     * Setter pour le nom
     * @param nom le nouveau nom
     */
    void setNom(string_view nom);

    /**
     * Setter pour le chiffre d'affaire
     * @param chiffre le nouveau chiffre d'affaire
     */
    void setChiffreAffaire(double chiffre);

    /**
     * Getter pour le nom
     * @return le nom
     */
    string getNom() const;

    /**
     * Getter pour le moment
     * @return le moment
     */
    TypeMenu getMoment() const;

    /**
     * Getter pour le chiffre d'affaire
     * @return le chiffre d'affaire
     */
    double getChiffreAffaire();

    /**
     * Getter pour les tables
     * @return le gestionnaire de tables
     */
    GestionnaireTables *getTables() const;

    /**
     * Getter pour le menu
     * @param typeMenu le type de menu
     * @return le gestionnaire de plats
     */
    GestionnairePlats *getMenu(TypeMenu typeMenu) const;

    /**
     * Getter pour les frais de livraison
     * @param zone la zone d'où vient le client
     * @return les frais de livraison
     */
    double getFraisLivraison(ZoneHabitation zone) const;

    /**
     * Getter pour le type de menu en string
     * @param typeMenu le type de menu
     * @return le string du type de menu
     */
    string getNomTypeMenu(TypeMenu typeMenu) const;

    /**
     * Méthode qui lit les adresses sur le fichier
     * @param fichier le fichier à lire
     */
    void lireAdresses(const string &fichier);

    /**
     * Méthode pour enlever les clients d'une table
     * @param id l'id de la table à vider
     */
    void libererTable(int id);

    /**
     * Commande un plat sur la table
     * @param nom le nom du plat à commander
     * @param idTable l'id de la table à commander
     */
    void commanderPlat(string nom, int idTable);

    /**
     * Surcharge d'opérateur pour comparer les chiffres d'affaire
     * @param restau le restaurant avec lequel comparer
     * @return true si ce restaurant a un plus gros chiffre d'affaire
     */
    bool operator<(const Restaurant &restau) const;

    /**
     * Surcharge d'opérateur pour copier un restaurant
     * @param autre le restaurant à copier
     * @return le nouveau restaurant
     */
    Restaurant &operator=(
            const Restaurant &autre) = delete;  //? Le programme ne fait jamais de copie de restaurant, donc cette fonction n'�tait pas test�e et par cons�quent probablement �rron�e.

    /**
     * Méthode qui place des clients sur une table
     * @param client le client principal à assigner
     * @return true si on a bien placer le client
     */
    bool placerClients(Client *client);

    /**
     * Livrer la commande du client
     * @param client le client à qui livrer la commande
     * @param nomPlats un vector avec les plats à livrer
     * @return true si la livraison se passe bien
     */
    bool livrerClient(Client *client, const vector<string> &nomPlats);

    /**
     * Calcule la réduction sur la commande d'un client
     * @param client le client qui reçoit la réduction
     * @param montant le montant de sa commande
     * @param livraison true si c'est une livraison
     * @return le montant de réduction
     */
    double calculerReduction(Client *client, double montant, bool livraison);

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient l'affichage
     * @param restau le restaurant qui doit être afficher
     * @return l'ostream contenant l'affichage
     */
    friend ostream &operator<<(ostream &os, const Restaurant &restau);

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient l'affichage
     * @param restaurent le restaurant qui doit être afficher
     * @return l'ostream contenant l'affichage
     */
    friend ostream &operator<<(ostream &os, const Restaurant &restaurent);

private:
    /**
     * Getter pour le menu actuel
     * @return le menu actuel
     */
    GestionnairePlats *menuActuel() const;

    /**
     * Getter pour une table
     * @param id l'id de la table
     * @return la table trouvée
     * @return nullptr si la table n'existe pas
     */
    Table *getTable(int id) const;

    string nom_;
    TypeMenu momentJournee_;
    double chiffreAffaire_;

    GestionnairePlats *menuMatin_;
    GestionnairePlats *menuMidi_;
    GestionnairePlats *menuSoir_;

    GestionnaireTables *tables_;

    // Tarif des trois zones de livraison.
    double fraisLivraison_[NB_ZONES_LIVR];
};


#endif // !RESTAURANT_H
