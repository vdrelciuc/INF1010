/*
* Titre : GestionnaireTables.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#pragma once

#include "Table.h"
#include "Foncteur.h"
#include "GestionnaireGenerique.h"

#include <set>

class GestionnaireTables : public GestionnaireGenerique<Table *, set<Table *>> {
public:
    /**
     * Contructeur par défaut
     */
    GestionnaireTables() = default;

    /**
     * Destructeur
     */
    ~GestionnaireTables();

    /**
     * Méthode qui trouve une table par son id
     * @param id l'id de la table que l'on veut trouver
     * @return la table trouvée
     * @return nullptr si aucune table correspondante
     */
    Table *getTable(int id) const;

    /**
     * Méthode qui trouve la meilleur table pour le nombre de client
     * @param tailleGroupe la taille du groupe
     * @return la meilleur table pour le groupe
     * @return nullptr si aucune table ne peut satisfaire le groupe
     */
    Table *getMeilleureTable(int tailleGroupe) const;

    /**
     * Méthode qui lit les tables dans le fichier
     * @param nomFichier le fichier à lire
     */
    void lireTables(const string &nomFichier);

    /**
     * Surcharge d'opérateur pour l'ajout d'une table
     * @param table la table à ajouter
     * @return le nouveau gestionnaire de table
     */
    GestionnaireTables &operator+=(Table *table);

    /**
     * Méthode d'affichage
     * @param os l'ostream qui contient ce qu'il faut afficher
     */
    void afficherTables(ostream &os) const;
};