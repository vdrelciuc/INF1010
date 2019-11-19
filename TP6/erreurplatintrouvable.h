/*
* Titre : erreurplatintrouvable.h - Travail pratique #6
* Date : 16 avril 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef ERREURPLATINTROUVABLE_H
#define ERREURPLATINTROUVABLE_H

#include <QString>
#include <QException>

using namespace std;

class ErreurPlatIntrouvable: public QException
{
public:
    ErreurPlatIntrouvable(QString s) : s_(s){}
    virtual QString what() { return s_; }
private :
    QString s_;
};

#endif // ERREURPLATINTROUVABLE_H
