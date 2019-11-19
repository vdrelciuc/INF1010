/*
* Titre : Client.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_H
#define CLIENT_H

#include "Table.h"
#include "def.h"

#include <string>
#include <string_view>
#include <iostream>

using namespace std;

class Restaurant;

class Table;

class Client {
public:
    /**
     * Constructeur par défaut
     */
    Client();

    /**
     * Constructeur par paramètres
     * @param nom le nom
     * @param prenom le prénom
     * @param tailleGroupe la taille du groupe
     */
    Client(string_view nom, string_view prenom, int tailleGroupe);

    /**
     * Destructeur
     */
    virtual ~Client() {};

    /**
     * Getter pour tailleGroupe
     * @return la taille du groupe
     */
    int getTailleGroupe() const;

    /**
     * Getter pour le nom
     * @return le nom
     */
    string getNom() const;

    /**
     * Getter pour le prénom
     * @return le prénom
     */
    string getPrenom() const;

    /**
     * Getter pour la table
     * @return la table
     */
    Table *getTable() const;

    /**
     * Setter pour la table
     * @param table la table à assigner
     */
    void setTable(Table *table);

    /**
     * Getter pour le nombre de point
     * @return le nombre de point
     */
    virtual int getNbPoints() const = 0;

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient ce qu'il faut afficher
     */
    virtual void afficherClient(ostream &os) const = 0;

    /**
     * Getter pour la réduction
     * @param res le restaurant
     * @param montant le montant de la commande
     * @param estLivraison true si c'est une livraison
     * @return la réduction donnée au client
     */
    virtual double getReduction(const Restaurant &res, double montant, bool estLivraison) = 0;

protected:
    string nom_;
    string prenom_;
    int tailleGroupe_;
    Table *tableOccupee_;
};

#endif

