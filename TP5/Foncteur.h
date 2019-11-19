/*
* Titre : Foncteur.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#pragma once

#include <algorithm>
#include "Plat.h"
#include "Table.h"

using namespace std;

/**
 * Foncteur qui compare le prix de deux plat
 * return true si le plat1 est plus petit
 */
class FoncteurPlatMoinsCher {
public:
    bool operator()(pair<string, Plat *> pair1, pair<string, Plat *> pair2) {
        return pair1.second->getPrix() < pair2.second->getPrix();
    }

};

/**
 * Foncteur qui compare le prix d'un plat à un intervalle de prix
 * return true si le prix est dans l'intervalle
 */
class FoncteurIntervalle {
public:
    FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup) {};

    bool operator()(pair<string, Plat *> pair1) {
        return !((borneInf_ <= pair1.second->getPrix()) && (pair1.second->getPrix() <= borneSup_));
    }

private:
    double borneInf_;
    double borneSup_;
};
