/*
* Titre : Plat.h - Travail Pratique #1
* Date : 01 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std; 

class Plat {
public:
	/**
	 * Constructeur par défaut
	 * */
	Plat(); 

	/**
	 * Constructeur par paramètres
	 * @param nom le nom du plat
	 * @param prix le prix du plat
	 * @param cout le cout du plat
	 * */
	Plat(string nom, double prix, double cout);

	/**
	 * getNom
	 * Permet de récupérer le nom du Plat.
	 * @return le nom du plat
	 * */
	string getNom() const;

	/**
	 * getPrix
	 * Permet de récupérer le prix du Plat.
	 * @return le prix du plat
	 * */
	double getPrix() const;

	/**
	 * getCout
	 * Permet de récupérer le cout du Plat.
	 * @return le cout du plat
	 * */
	double getCout() const;

	/**
	 * setNom
	 * Permet de changer le nom du plat
	 * @param nom le nom à donner au plat
	 * */
	void setNom(string nom);

	/**
	 * setPrix
	 * Permet de changer le prix du plat
	 * @param prix le prix à donner au plat
	 * */ 
	void setPrix(double prix); 

	/**
	 * afficher
	 * Affiche le nom du plat avec son prix et son cout.
	 * */
	void afficher() const;

private: 
	string nom_; 
	double prix_; 
	double cout_; 
};

#endif // !PLAT_H
