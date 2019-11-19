/*
* Titre : main.cpp - Travail Pratique #4
* Date : 22 mars 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

/*
 * Reponse aux deux questions du TD :
 *
 * 1. Voir fichier DiagrammeDeClasse.pdf
 *
 * 2. Une classe ayant au moins une methode abstraite est une classe abstraite.
 * Une classe possedant seulement des fonctions virtuelles pures est une interface.
 */

#include "Restaurant.h"
#include "ClientOccasionnel.h"
#include "ClientRegulier.h"
#include "ClientPrestige.h"
#include "debogageMemoire.hpp"
#include "Menu.h"
#include "Boisson.h"
#include "def.h"
#include<vector>

using namespace std;

int main() {
    initDebogageMemoire();

    vector<pair<string, bool>> tests;
    vector<Client *> clients;

    // Creer le restaurant
    Restaurant poly("polyFood.txt", "PolyFood", TypeMenu::Soir);
    Menu *menu1 = new Menu(*poly.getMenu(TypeMenu::Matin));
    cout << "================Exemple de menu===============" << endl;
    cout << *menu1;

    // Creer plusieurs clients
    clients.push_back(new ClientOccasionnel("Martin", "b", 1));
    clients.push_back(new ClientOccasionnel("Amy", "wh", 15));
    clients.push_back(new ClientRegulier("John", "sm", 5, 105));
    clients.push_back(new ClientRegulier("Moussa", "T", 3, 45));
    clients.push_back(new ClientPrestige("Andree", "F", 2, 150, ZoneHabitation::Zone2));
    clients.push_back(new ClientPrestige("Marie", "C", 1, 225, ZoneHabitation::Zone1));

    // Placer les clients dans le restaurant
    for (int i = 0; i < clients.size(); i++)
        if (poly.placerClients(clients[i]))
            cout << clients[i]->getNom() << " a une place au resto " << endl;
        else
            cout << clients[i]->getNom() << " n'a pas une place au resto " << endl;


    // Commander des plats
    if (clients[0]->getTable() != nullptr)
        poly.commanderPlat("Pates", clients[0]->getTable()->getId());
    if (clients[1]->getTable() != nullptr)
        poly.commanderPlat("Poulet", clients[1]->getTable()->getId());
    if (clients[2]->getTable() != nullptr)
        poly.commanderPlat("Pates", clients[2]->getTable()->getId());
    if (clients[3]->getTable() != nullptr)
        poly.commanderPlat("Poisson", clients[3]->getTable()->getId());
    if (clients[4]->getTable() != nullptr)
        poly.commanderPlat("Poisson", clients[4]->getTable()->getId());
    if (clients[5]->getTable() != nullptr) {
        poly.commanderPlat("Muffin", clients[5]->getTable()->getId());
        poly.commanderPlat("Pizza", clients[5]->getTable()->getId());
    }

    // Afficher le restaurant avec aucun chiffre d'affaire
    cout << poly;

    // Liberer les tables du restaurant
    for (int i = 0; i < clients.size(); i++)
        if (clients[i]->getTable() != nullptr)
            poly.libererTable(clients[i]->getTable()->getId());

    // Afficher le restaurant avec le chiffre d'affaire
    cout << "Le chiffre d'affaire du restaurant " << poly.getNom() << " est " << poly.getChiffreAffaire() << endl;;

    vector<string> commandeMartin;
    commandeMartin.push_back("Poisson");
    commandeMartin.push_back("Muffin");
    vector<string> commandeMarie;
    commandeMarie.push_back("Pates");
    commandeMarie.push_back("Poulet");
    commandeMarie.push_back("Pizza");

    // Tests livraison client
    cout << "==================Livraisons=================" << endl;
    //Ne devrait pas pouvoir commander
    if (poly.livrerClient(clients[0], commandeMartin))
        cout << "Le client " << clients[0]->getNom() << " a ete livre" << endl;
    else
        cout << "Le client " << clients[0]->getNom() << " n est pas admissible a la livraison" << endl;
    //Doit pouvoir commander
    if (poly.livrerClient(clients[5], commandeMarie))
        cout << "Le client " << clients[5]->getNom() << " a ete livre" << endl;
    else
        cout << "Le client " << clients[0]->getNom() << " n est pas admissible a la livraison" << endl;

    // Afficher le restaurant avec le chiffre d'affaire avec la livraison
    cout << "Le chiffre d'affaire du restaurant " << poly.getNom() << " est " << poly.getChiffreAffaire() << endl;;

    // Creer un autre restaurant
    Restaurant poly2("polyFood.txt", "PolyFood2", TypeMenu::Midi);

    // Assigner un chiffre d'affaire a Poly2
    poly2.setChiffreAffaire(553.78);

    // Comparer les chiffres d'affaires entre les deux restaurants
    if (poly.getChiffreAffaire() < poly2.getChiffreAffaire())
        cout << "polyFodd2 gagne plus d'argent" << endl;
    else
        cout << "polyFodd gagne plus d'argent" << endl;


    // Creer des plats vege et des boissons
    vector<Taxable *> listeTaxable;
    listeTaxable.push_back(new Boisson("coke", 2.2));
    listeTaxable.push_back(new PlatVege("Saucisse", 7.2));
    listeTaxable.push_back(new Boisson("7UP", 1.5));
    listeTaxable.push_back(new PlatVege("Noix", 3.2));
    listeTaxable.push_back(new Boisson("soda", 0.80));
    listeTaxable.push_back(new PlatVege("Carotte", 1.2));
    listeTaxable.push_back(new Boisson("pepsi", 2.5));

    // Calcul de la taxe a donner au gouvernement
    double sommeTaxe = 0.0;
    double taxe;
    Boisson *b;
    PlatVege *v;
    for (size_t i = 0; i < listeTaxable.size(); i++) {
        taxe = listeTaxable[i]->getTaxe();
        b = dynamic_cast<Boisson *>(listeTaxable[i]);
        v = dynamic_cast<PlatVege *>(listeTaxable[i]);
        if (b)
            sommeTaxe += taxe * (b->getPrix());
        if (v)
            sommeTaxe += taxe * (v->getPrix());
    }
    cout << "la taxe a paye est " << sommeTaxe << endl;

    // Nettoyer la memoire
    for (size_t i = 0; i < clients.size(); i++) {
        delete clients[i];
        clients[i] = nullptr;
    }

    for (int i = 0; i < listeTaxable.size(); i++) {
        delete listeTaxable[i];
        listeTaxable[i] = nullptr;
    }

    return 0;
}
