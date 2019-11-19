#pragma once  //? Ceci n'est pas dans le standard ISO C++ mais est support� par tous les compilateurs principaux; �a sert � remplacer les gardes d'inclusion.
//! \author Francois-R.Boyer@PolyMtl.ca
//! \date 2019-02
//! \file
//? NOTE: Les commentaires //? sont pour but �ducatifs et ne devraient pas se trouver dans un programme r�el.

#include <fstream>
#include <string>
#include <string_view>  //? (C++17) "string_view" se comporte similairement � "const string&" (il faut le voir comme une r�f�rence � un texte malgre qu'il n'y a pas de "&") mais est plus general.
#include <sstream>  //? Les istringstream et ostringstream sont des streams pour lire et ecrire dans des string.

using namespace std;

//! Permet la lecture d'un fichier en sections, chaque section etant une ligne qui debute par un s�parateur de section (par defaut "-") et suivie d'un titre de section.
//! Les espaces en d�but de lignes, incluant les lignes completement vides, ne sont pas importants et sont sautes.
class LectureFichierEnSections : public std::ifstream {
public:
    LectureFichierEnSections(const string &nomFichier, char separateurDeSection = '-');

    LectureFichierEnSections &allerASection(string_view titreSection);

    bool estFinFichier();

    bool estFinSection();

    std::string lireLigne();

    std::istringstream lecteurDeLigne();

private:
    std::streampos debutFichier_;
    char separateurDeSections_;
};
