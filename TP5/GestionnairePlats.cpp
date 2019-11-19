/*
* Titre : GestionnairePlats.cpp - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"

GestionnairePlats::GestionnairePlats(const string &nomFichier, TypeMenu type) : type_(type) {
    lirePlats(nomFichier, type);
}

GestionnairePlats::GestionnairePlats(GestionnairePlats *gestionnaire) : type_(gestionnaire->getType()) {
    conteneur_ = gestionnaire->getConteneur();
}

GestionnairePlats::~GestionnairePlats() {
    for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
}

Plat *GestionnairePlats::allouerPlat(Plat *plat) {
    return plat->clone();
}

TypeMenu GestionnairePlats::getType() const {
    return type_;
}

Plat *GestionnairePlats::trouverPlatMoinsCher() const {
    return (min_element(conteneur_.begin(), conteneur_.end(), FoncteurPlatMoinsCher()))->second;
}

Plat *GestionnairePlats::trouverPlatPlusCher() const {
    auto trouverPlusCher = [](pair<string, Plat *> pair1, pair<string, Plat *> pair2) {
        return pair1.second->getPrix() < pair2.second->getPrix();
    };

    return (max_element(conteneur_.begin(), conteneur_.end(), trouverPlusCher)->second);
}

Plat *GestionnairePlats::trouverPlat(const string &nom) const {
    return conteneur_.find(nom)->second;
}

vector<pair<string, Plat *>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup) {
    vector<pair<string, Plat *>> vect;

    copy(conteneur_.begin(), conteneur_.end(), back_inserter(vect));

    vect.erase(remove_if(vect.begin(), vect.end(), FoncteurIntervalle(borneInf, borneSup)), vect.end());

    return vect;
}

void GestionnairePlats::afficherPlats(ostream &os) {
    for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
        (it->second)->afficherPlat(os);
}

void GestionnairePlats::lirePlats(const string &nomFichier, TypeMenu type) {
    LectureFichierEnSections fichier{nomFichier};
    fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
    while (!fichier.estFinSection())
        ajouter(lirePlatDe(fichier));
}

pair<string, Plat *> GestionnairePlats::lirePlatDe(LectureFichierEnSections &fichier) {
    auto lectureLigne = fichier.lecteurDeLigne();
    Plat *plat;
    string nom, typeStr;
    TypePlat type;
    double prix, coutDeRevient;
    lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
    type = TypePlat(stoi(typeStr));
    double ecotaxe, vitamines, proteines, mineraux;
    switch (type) {
        case TypePlat::Bio:
            lectureLigne >> ecotaxe;
            plat = new PlatBio{nom, prix, coutDeRevient, ecotaxe};
            break;
        case TypePlat::BioVege:
            lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
            plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
            break;
        case TypePlat::Vege:
            lectureLigne >> vitamines >> proteines >> mineraux;
            plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
            break;
        default:
            plat = new Plat{nom, prix, coutDeRevient};
    }
    return pair<string, Plat *>(plat->getNom(), plat);
}


