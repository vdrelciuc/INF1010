#pragma once  //? Ceci n'est pas dans le standard ISO C++ mais est support� par tous les compilateurs principaux; �a sert � remplacer les gardes d'inclusion.
/*
* Titre : LectureFichierEnSections.h - Travail Pratique #5
* Date : 6 avril 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#include <fstream>
#include <string>
#include <string_view>  //? (C++17) "string_view" se comporte similairement � "const string&" (il faut le voir comme une r�f�rence � un texte malgre qu'il n'y a pas de "&") mais est plus general.
#include <sstream>  //? Les istringstream et ostringstream sont des streams pour lire et ecrire dans des string.

using namespace std;

//! Permet la lecture d'un fichier en sections, chaque section etant une ligne qui debute par un s�parateur de section (par defaut "-") et suivie d'un titre de section.
//! Les espaces en d�but de lignes, incluant les lignes completement vides, ne sont pas importants et sont sautes.
class LectureFichierEnSections : public std::ifstream {
public:
    /**
     * Contructeur par paramètres
     * @param nomFichier le fichier à lire
     * @param separateurDeSection le caractère qui sépare les sections
     */
    LectureFichierEnSections(const string &nomFichier, char separateurDeSection = '-');

    /**
     * Méthode qui va jusqu'à la bonne section
     * @param titreSection le titre de la section
     * @return LectureFichierEnSection
     */
    LectureFichierEnSections &allerASection(string_view titreSection);

    /**
     * Getter la fin de fichier
     * @return true si le fichier est terminer
     */
    bool estFinFichier();

    /**
     * Getter pour la fin de section
     * @return true si la section est terminée
     */
    bool estFinSection();

    /**
     * Méthode qui lit une ligne
     * @return la ligne qui est lue
     */
    std::string lireLigne();

    /**
     * Méthode qui décortique une ligne
     * @return isstringstream
     */
    std::istringstream lecteurDeLigne();

private:
    std::streampos debutFichier_;
    char separateurDeSections_;
};
