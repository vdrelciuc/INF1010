/*
* Titre : GestionnaireGenerique.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#pragma once

#include <algorithm>
#include "Foncteur.h"

using namespace std;

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>;

template<typename T, typename C>
class GestionnaireGenerique {
public:

    /**
     * Getter pour le conteneur
     * @return conteneur_
     */
    C getConteneur() const {
        return conteneur_;
    };

    /**
     * Ajoute un élément au conteneur
     * @param t l'élément à ajouter
     */
    void ajouter(T t) {
        conteneur_.insert(t);
    };

    /**
     * Getter pour le nombre d'éléments dans le conteneur
     * @return le nombre d'éléments de conteneur_
     */
    int getNombreElements() const {
        return conteneur_.size();
    };

protected:
    C conteneur_;
};

