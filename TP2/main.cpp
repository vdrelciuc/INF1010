/*
* Titre : main.cpp - Travail Pratique #2
* Date : 9 fevrier 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

/*
 * Reponses auz questions du TD2 :
 *
 * 1. L'operateur = et le constructeur par copie permettent de copier tous les attributs d'un objet dans un autre objet.
 *
 * 2. Le constructeur par copie permet de creer (instancier) un nouvel objet ayant les memes attributs que l'objet
 * pre-existant qui lui est passe en parametres, alors que l'operateur = permet de copier les attributs d'un objet
 * pre-existant dans un autre objet pre-existant.
 * */

#include "Restaurant.h"

using namespace std;

/**
 * main
 * Methode main du programme
 * @return Un code d'execution ou d'erreur (0 si bien compile)
 */
int main() {

	// Creation du restaurant
	Restaurant poly("polyFood.txt", "PolyFood", Soir);

	//creer plusieurs clients
	int nbclient1 = 1;
	int nbclient2 = 5;
	int nbclient3 = 15;
	int nbclient4 = 3;
	int nbclient5 = 2;

	// Placer les clients
	poly.placerClients(nbclient1);
	poly.placerClients(nbclient2);
	poly.placerClients(nbclient3);
	poly.placerClients(nbclient4);
	poly.placerClients(nbclient5);

	// Commander des plats
	poly.commanderPlat("Poisson", 1);
	poly.commanderPlat("Poulet", 2);
	poly.commanderPlat("Pizza", 2);
	poly.commanderPlat("Poulet", 4);
	poly.commanderPlat("Muffin", 4);
	poly.commanderPlat("Oeuf", 4);


	// Creation d'une copie du poly restaurant
	Restaurant poly2(poly);
	poly2.setNom("PolyFood2");

	// Affichage du restaurant poly
	cout << poly;

	cout << "--------------------------------------------------------------------------------------------------"
		<< endl;

	// Liberer les tables et calcule du chiffre d'affaire
	poly.libererTable(1);
	poly.libererTable(2);
	poly.libererTable(3);
	poly.libererTable(4);
	cout << poly;

	cout << "===================================================================================================="
		<< endl;

	// Le restaurant Poly2 ne doit pas encore avoir libere ses tables
	cout << poly2;

	poly2 = poly;

	cout << "--------------------------------------------------------------------------------------------------"
		<< endl;

	// Puisque poly2 = poly, le nom de poly2 est redevenu PolyFood. Pour eviter la confusion dans l'affichage, on le renomme PolyFood2
	poly2.setNom("PolyFood2");

	// Le restaurant Poly2 doit maintenant avoir toutes ses tables liberees
	cout << poly2;

	cout << "--------------------------------------------------------------------------------------------------";
}