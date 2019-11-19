/*
* Titre : main.cpp - Travail pratique #6
* Date : 16 avril 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

/*
 * Reponses aux questions du TP6 :
 *
 * 1. Puisque le constructeur n'a pas fini de s'executer, le destructeur ne peut pas etre appele. Si de
 * la memoire a ete allouee avant l'erreur, elle ne sera jamais desallouee, ce qui cause un memory leak.
 *
 * 2. La vue est l'interface graphique du programme qui recoit les entrees de l'utilisateur. Les evenements lances
 * par les entrees de l'utilisateur sont traites dans le controleur, qui en fait l'interpretation. Le controleur met a jour
 * la vue et le modele. Le modele recupere les donnees du controleur, en fait leur traitement et informe la vue d'un changement
 * d'etat. La vue ira alors lire le nouvel etat du modele et se mettra a jour. Les logiciels construits dans Qt different de ce
 * patron de conception car ils n'utilisent pas de controleur. La vue et le modele interagissent directement.
 */

#include "mainwindow.h"
#include "Menu.h"
#include "Filtre.h"
#include "Commande.h"
#include <QString>
#include <QApplication>
#include "erreurfichierintrouvable.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString chemin = "E:\\TP6";
    try {
        Menu menu = Menu(chemin+FICHIER_POLYFOOD);

        Filtre filtre(&menu);
        Commande commande;
        MainWindow mainGui(&commande, &filtre, &menu);

        QObject::connect(&filtre, SIGNAL(choixFiltrageModifie()), &mainGui , SLOT(mettreAJourPlatsFiltres()));
        QObject::connect(&commande, SIGNAL(commandeModifie()), &mainGui, SLOT(mettreAJourPlatsCommande()));
        QObject::connect(&commande, SIGNAL(commandeModifie()), &mainGui, SLOT(mettreAJourPrix()));

        mainGui.show();
        return a.exec();

    } catch (ErreurFichierIntrouvable erreur) {
        QMessageBox mbox;
        mbox.setText(erreur.what());
        mbox.show();
        return a.exec();
    }

}
