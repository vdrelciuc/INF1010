/*
* Titre : Client.h - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <string_view>
#include <iostream>
#include "Table.h"
//#include "Restaurant.h"
#include "def.h"

using std::string, std::string_view, std::ostream;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepte en INF1010.

class Restaurant;

class Table;

class Client {
public:
    /**
     * Constructeur par defaut
     */
    Client();

    /**
     * Constructeur par parametres
     * @param nom Nom du client
     * @param prenom Prenom du client
     * @param tailleGroupe Taille du groupe
     */
    Client(string_view nom, string_view prenom, int tailleGroupe);

    /**
     * Destructeur
     */
    virtual ~Client() {};

    /**
     * getTailleGroupe
     * Retourne la taille du groupe
     * @return La taille du groupe
     */
    int getTailleGroupe() const;

    /**
     * getNom
     * Retourne le nom du client
     * @return Le nom du client
     */
    string getNom() const;

    /**
     * getPrenom
     * Retourne le prenom du client
     * @return Le prenom du client
     */
    string getPrenom() const;

    /**
     * getTable
     * Retourne la table du client
     * @return La table du client
     */
    Table *getTable() const;

    /**
     * setTable
     * Definit la table du client
     * @param ta La table du client
     */
    void setTable(Table *ta);

    /**
     * getNbPoints
     * Retourne le nombre de points du client
     * @return Le nombre de points du client
     */
    virtual int getNbPoints() const = 0;

    /**
     * afficherClient
     * Methode d'affichage des caracteristiques du client
     * @param os Le stream modifie
     */
    virtual void afficherClient(ostream &os) const = 0;

    /**
     * getReduction
     * Retourne le montant de la reduction a laquelle le client a droit
     * @param res Le restaurant
     * @param montant Le montant a payer
     * @param estLivraison Si le client a commande en livraison
     * @return Le montant de la reduction
     */
    virtual double getReduction(const Restaurant &res, double montant, bool estLivraison) = 0;

protected:
    string nom_;
    string prenom_;
    int tailleGroupe_;
    Table *tableOccupee_;
};

#endif

