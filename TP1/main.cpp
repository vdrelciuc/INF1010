/*
* Titre : main.cpp - Travail Pratique #1
* Date : 01 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

/*
 * QUESTIONS D'ÉVALUATION DU TP1
 *
 * 1. Plat est lié à Menu par composition, puisqu'un plat ne peut exister que dans
 * un menu. Si un menu est effacé, on veut que tous ses plats disparaissent aussi.
 *
 * 2. Une méthode const ne modifiera pas les attributs de la classe dans laquelle
 * elle est appellée. Le terme 'const' nous indique donc que cette méthode est 'safe',
 * puisqu'elle n'affectera aucun attribut de manière indésirable.
 */

#include "Restaurant.h"

/**
 * Méthode main du programme
 * @return Code d'erreur d'exécution (0 si aucune erreur)
 */
int main() {

    // Creation du restaurant - avec le fichier donne - le nom : PolyFood - moment de la journee : soir.

    string fichier = "polyFood.txt";
    string nom = "PolyFood";
    Restaurant poly(fichier, nom, Soir);

    // Creer plusieurs clients -- des entiers

    int client1 = 1;
    int client2 = 5;
    int client3 = 15;
    int client4 = 3;
    int client5 = 2;

    // Placer les clients

    poly.placerClients(client1);
    poly.placerClients(client2);
    poly.placerClients(client3);
    poly.placerClients(client4);
    poly.placerClients(client5);

    // Commander des plats
    //Poisson - Table 1
    //Poulet - Table 2
    //Pizza - Table 2
    //Poulet - Table 4
    //Muffin - Table 4
    //Oeud - Table 4

    string poisson = "Poisson";
    string poulet = "Poulet";
    string pizza = "Pizza";
    string muffin = "Muffin";
    string oeud = "Oeud";   // Plat inexistant - exception à gérer

    poly.commanderPlat(poisson, 1);
    poly.commanderPlat(poulet, 2);
    poly.commanderPlat(pizza, 2);
    poly.commanderPlat(poulet, 4);
    poly.commanderPlat(muffin, 4);
    poly.commanderPlat(oeud, 4);

    // Afficher le restaurant
    poly.afficher();

    cout << "-------------------------------------------------" << endl;

    // Liberer les tables
    poly.libererTable(1);
    poly.libererTable(2);
    poly.libererTable(3);
    poly.libererTable(4);

    // Afficher le restaurant
    poly.afficher();

    return 0;
}