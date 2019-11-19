/*
* Titre : Client.h - Travail Pratique #3
* Date : 21 février 2019
* Auteur : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef CLIENT
#define CLIENT

#include <string>
#include <iostream>

using namespace std;

enum StatutClient {
    Occasionnel, Fidele, Prestige
};

class Client {
public:
    /**
     * Constructeur par defaut
     */
    Client();

    /**
     * Constructeur par parametres
     * @param nom Nom du client
     * @param prenom Prenom du Client
     * @param tailleGroupe Nombre de personnes qui accompagnent le client
     */
    Client(string nom, string prenom, int tailleGroupe);

    /**
     * Destructeur
     */
    ~Client();

    /**
     * getStatut
     * Retourne le statut du client
     * @return Le statut du client
     */
    StatutClient getStatut() const;

    /**
     * getTailleGroupe
     * Retourne le nombre de gens qui accompagnent le client
     * @return Le nombre de gens qui accompagnent le client
     */
    int getTailleGroupe() const;

    /**
     * getNom
     * Retourne le nom du client
     * @return Le nom du client
     */
    string getNom() const;

    /**
     * getPrenom
     * Retourne le prenom du client
     * @return Le prenom du client
     */
    string getPrenom() const;

    /**
     * setStatut
     * Definit le statut du client
     * @param statutClient Le statut du client
     */
    void setStatut(StatutClient statutClient);

    /**
     * setTailleGroupe
     * Definit le nombre de gens qui accompagnent le client
     * @param tailleGroupe Le nombre de gebs qui accompagnent le client
     */
    void setTailleGroupe(int tailleGroupe);

    /**
     * setNom
     * Definit le nom du client
     * @param nom Le nom du client
     */
    void setNom(string nom);

    /**
     * setPrenom
     * Definit le prenom du client
     * @param prenom Prenom du client
     */
    void setPrenom(string prenom);

    /**
     * operator<<
     * Modifie un stream en fonction des donnees du client
     * @param os Le stream a modifier
     * @param client Le client dont on prend les donnees
     * @return Le stream modifie
     */
    friend ostream &operator<<(ostream &os, const Client &client);

private:
    /**
     * convertirStatutString
     * Convertit le statut d'un client en string
     * @return Le string du statut du client
     */
    string convertirStatutString() const;

protected:
    string nom_;
    string prenom_;
    int tailleGroupe_;
    StatutClient statut_;
};

#endif

